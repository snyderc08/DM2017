#include "../interface/CodexAnalyzer.h"
#include "../interface/WeightCalculator.h"
#include "../interface/Corrector.h"
#include "../interface/Functions.h"
#include "../interface/makeHisto.h"
#include <string>
#include <ostream>
#include <vector>


int main(int argc, char** argv) {
    using namespace std;
    
    std::string out = *(argv + 1);
    
    cout << "\n\n\n OUTPUT NAME IS:    " << out << endl;     //PRINTING THE OUTPUT name
    TFile *fout = TFile::Open(out.c_str(), "RECREATE");
    
    myMap1 = new std::map<std::string, TH1F*>();
    myMap2 = new map<string, TH2F*>();
    
    std::vector<string> input;
    for (int f = 2; f < argc; f++) {
        input.push_back(*(argv + f));
        cout << "\n INPUT NAME IS:   " << input[f - 2] << "\n";
    }
    
    
    
    Float_t Ptbins[] = {0,50,70,100,140,200,300,600,1000};
    Float_t Etabins[] = {0,0.8,1.5,2.5};
    Int_t  Ptbin_ = sizeof(Ptbins)/sizeof(Float_t) - 1; // or just = 9
    Int_t  Etabin_ = sizeof(Etabins)/sizeof(Float_t) - 1; // or just = 9
    TH2F* BSF_FLV0_Total = new TH2F("BSF_FLV0_Total","BSF_FLV0_Total", Ptbin_, Ptbins, Etabin_, Etabins);
    TH2F* BSF_FLV0_Btagged = new TH2F("BSF_FLV0_Btagged","BSF_FLV0_Btagged", Ptbin_, Ptbins, Etabin_, Etabins);
    TH2F* BSF_FLV5_Total = new TH2F("BSF_FLV5_Total","BSF_FLV5_Total", Ptbin_, Ptbins, Etabin_, Etabins);
    TH2F* BSF_FLV5_Btagged = new TH2F("BSF_FLV5_Btagged","BSF_FLV5_Btagged", Ptbin_, Ptbins, Etabin_, Etabins);
    
    
    for (int k = 0; k < input.size(); k++) {
        
        //std::string input = *(argv + 2);
        TFile *f_Double = TFile::Open(input[k].c_str());
        cout << "\n  Now is running on ------->   " << std::string(f_Double->GetName()) << "\n";
        
        std::string InputROOT= std::string(f_Double->GetName());
        TFile * myFile = TFile::Open(f_Double->GetName());
        TH1F * HistoTot = (TH1F*) myFile->Get("hcount");
        
        //        TTree *Run_Tree = (TTree*) f_Double->Get("ggNtuplizer/EventTree");
        TTree *Run_Tree = (TTree*) f_Double->Get("EventTree");
        
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(6);
        
        
        

        
//        TFile * TTSF= TFile::Open(("test_tt_light.root"));
//        TH2F * HistoBtagSFnum= (TH2F *) TTSF->Get("BSF_FLV0_Btagged");
//        TH2F * HistoBtagSFden= (TH2F *) TTSF->Get("BSF_FLV0_Total");

        
        
        
        
        
        //########################################   General Info
        Run_Tree->SetBranchAddress("isData", &isData);
        Run_Tree->SetBranchAddress("run", &run);
        Run_Tree->SetBranchAddress("lumis", &lumis);
        Run_Tree->SetBranchAddress("event", &event);
        Run_Tree->SetBranchAddress("genWeight",&genWeight);
        Run_Tree->SetBranchAddress("HLTEleMuX", &HLTEleMuX);
        Run_Tree->SetBranchAddress("puTrue", &puTrue);
        Run_Tree->SetBranchAddress("nVtx",&nVtx);
        
  
      
        
        //########################################   Jet Info
        Run_Tree->SetBranchAddress("nJet",&nJet);
        Run_Tree->SetBranchAddress("jetPt",&jetPt);
        Run_Tree->SetBranchAddress("jetEta",&jetEta);
        Run_Tree->SetBranchAddress("jetPhi",&jetPhi);
        Run_Tree->SetBranchAddress("jetEn",&jetEn);
        Run_Tree->SetBranchAddress("jetCSV2BJetTags",&jetCSV2BJetTags);
        Run_Tree->SetBranchAddress("jetPFLooseId",&jetPFLooseId);
        Run_Tree->SetBranchAddress("jetPUID",&jetPUID);
        Run_Tree->SetBranchAddress("jetRawPt",&jetRawPt);
        Run_Tree->SetBranchAddress("jetJECUnc",&jetJECUnc);
        Run_Tree->SetBranchAddress("jetRawEn",&jetRawEn);
        Run_Tree->SetBranchAddress("jetHadFlvr",&jetHadFlvr);
        
              //###############################################################################################
        //  Weight Calculation
        //###############################################################################################
        float WSCALEFACTORE=1.00;
        float WSF_mutau=1.0;
        float WSF_etau=1.0;
        float MuMass= 0.10565837;
        float eleMass= 0.000511;
        float LeptonPtCut_=60;
        float TauPtCut_=20;
        float JetPtCut=100;
        float BJetPtCut=30;
        float SimpleJetPtCut=30;
        float ElectronPtCut_=15;
        float CSVCut=   0.9535   ;                  //  https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation80XReReco
//        float CSVCut=  0.460  ;    // loose is 0.460                 //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation80X
        float LeptonIsoCut=0.15;
        
        
        Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
        cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
        for (Int_t i = 0; i < nentries_wtn; i++) {
            //            for (Int_t i = 0; i < 100000; i++) {
            Run_Tree->GetEntry(i);
            if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
            fflush(stdout);
            
            if (isData && (metFilters!=1536)) continue;
            std::vector<string> HistNamesFilled;
            HistNamesFilled.clear();
            //###############################################################################################
            //  Weight Calculation
            //###############################################################################################
            //###############################################################################################
            //############ Top Reweighting & W boson SCale Factor
           
         
            //###########       bJet Veto   ###########################################################
            int numBJet=0;
            for (int ijet= 0 ; ijet < nJet ; ijet++){
                
                if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > BJetPtCut && fabs(jetEta->at(ijet)) < 2.4 ){
                    
                    
                    
//                    cout <<"Here is SF =====> "<< getBtagSF( isData,  jetPt->at(ijet), fabs(jetEta->at(ijet)), HistoBtagSFnum , HistoBtagSFden);
                    
                    
                    
                    if (jetHadFlvr->at(ijet)==0)  BSF_FLV0_Total->Fill(jetPt->at(ijet),fabs(jetEta->at(ijet)));
                    if (jetHadFlvr->at(ijet)==4)  BSF_FLV5_Total->Fill(jetPt->at(ijet),fabs(jetEta->at(ijet)));
                    if (jetHadFlvr->at(ijet)==5)  BSF_FLV5_Total->Fill(jetPt->at(ijet),fabs(jetEta->at(ijet)));
                    
                    if (jetHadFlvr->at(ijet)==0 && jetCSV2BJetTags->at(ijet)>CSVCut)  BSF_FLV0_Btagged->Fill(jetPt->at(ijet),fabs(jetEta->at(ijet)));
                    if (jetHadFlvr->at(ijet)==4 && jetCSV2BJetTags->at(ijet)>CSVCut)  BSF_FLV5_Btagged->Fill(jetPt->at(ijet),fabs(jetEta->at(ijet)));
                    if (jetHadFlvr->at(ijet)==5 && jetCSV2BJetTags->at(ijet)>CSVCut)  BSF_FLV5_Btagged->Fill(jetPt->at(ijet),fabs(jetEta->at(ijet)));
                        
                }
            }
            
       
            
            //############################################################################################
            //###########       Loop over MuJet events   #################################################
            //############################################################################################
         //End of file
            //##############  end of dielectron
            
        }
        
    }
    
    fout->cd();
    
    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
    
    for (; iMap1 != jMap1; ++iMap1)
        nplot1(iMap1->first)->Write();
    
    map<string, TH2F*>::const_iterator iMap2 = myMap2->begin();
    map<string, TH2F*>::const_iterator jMap2 = myMap2->end();
    
    for (; iMap2 != jMap2; ++iMap2)
        nplot2(iMap2->first)->Write();
    
    BSF_FLV0_Total->Write();
    BSF_FLV0_Btagged->Write();
    BSF_FLV5_Total->Write();
    BSF_FLV5_Btagged->Write();
    
    fout->Close();
    
    
}
