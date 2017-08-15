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
    
    
    
    //########################################
    // W and DY K-factor files
    //########################################
    //    TFile * KFactor= TFile::Open("../interface/pileup-hists/kfactors.root");
    //    TH1F * WLO= (TH1F *) KFactor->Get("WJets_LO/inv_pt");
    //    TH1F * WNLO= (TH1F *) KFactor->Get("EWKcorr/W");
    //    TH1F * ZLO= (TH1F *) KFactor->Get("ZJets_LO/inv_pt");
    //    TH1F * ZNLO= (TH1F *) KFactor->Get("EWKcorr/Z");
    //
    
    TFile * KFactor= TFile::Open("../interface/NewKFactor/kfactor_vjet_qcd/kfactor_24bins.root");
    
    //Old
//    TH1F * WLO= (TH1F *) KFactor->Get("WJets_LO/inv_pt");
//    TH1F * WNLO= (TH1F *) KFactor->Get("EWKcorr/W");
//    TH1F * ZLO= (TH1F *) KFactor->Get("ZJets_LO/inv_pt");
//    TH1F * ZNLO= (TH1F *) KFactor->Get("EWKcorr/Z");
//    
    
    
    TH1F * WLO= (TH1F *) KFactor->Get("WJets_LO/inv_pt");
    TH1F * WNLO= (TH1F *) KFactor->Get("WJets_012j_NLO/nominal");
    TH1F * ZLO= (TH1F *) KFactor->Get("DYJets_LO/inv_pt");
    TH1F * ZNLO= (TH1F *) KFactor->Get("DYJets_012j_NLO/nominal");
    
    
    
    for (int k = 0; k < input.size(); k++) {
        
        //std::string input = *(argv + 2);
        TFile *f_Double = TFile::Open(input[k].c_str());
        cout << "\n  Now is running on ------->   " << std::string(f_Double->GetName()) << "\n";
        
        std::string InputROOT= std::string(f_Double->GetName());
        TFile * myFile = TFile::Open(f_Double->GetName());
        TH1F * HistoTot = (TH1F*) myFile->Get("hcount");
        
        TTree *Run_Tree = (TTree*) f_Double->Get("EventTree");
        
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(6);
        
        
        
        size_t isWJets = InputROOT.find("WJets");
        size_t isDYJets = InputROOT.find("DYJets");
        size_t isFXFX = InputROOT.find("FXFX");
        
        
        std::string ROOTLoc= "../ROOT80X/FXFX/";
        //                vector<float> DY_Events = DY_HTBin(ROOTLoc);
        //                vector<float> W_Events = W_HTBin(ROOTLoc);
        vector<float> W_EventsNLO ;
        vector<float> Z_EventsNLO ;
        if (isFXFX !=string::npos){
            W_EventsNLO = W_PTBinNLO(ROOTLoc); //This is for the NLO samples (as the stat is too low we do not use them)
            Z_EventsNLO = Z_PTBinNLO(ROOTLoc);
        }
        
        
        
        //########################################   General Info
        Run_Tree->SetBranchAddress("isData", &isData);
        Run_Tree->SetBranchAddress("run", &run);
        Run_Tree->SetBranchAddress("lumis", &lumis);
        Run_Tree->SetBranchAddress("event", &event);
        Run_Tree->SetBranchAddress("genWeight",&genWeight);
        
        Run_Tree->SetBranchAddress("nMC", &nMC);
        Run_Tree->SetBranchAddress("mcPID", &mcPID);
        Run_Tree->SetBranchAddress("mcStatus", &mcStatus);
        Run_Tree->SetBranchAddress("mcPt", &mcPt );
        Run_Tree->SetBranchAddress("mcEta", &mcEta );
        Run_Tree->SetBranchAddress("mcPhi", &mcPhi );
        Run_Tree->SetBranchAddress("mcE", &mcE );
        Run_Tree->SetBranchAddress("mcMass", &mcMass );
        Run_Tree->SetBranchAddress("mcMomPID", &mcMomPID );
        Run_Tree->SetBranchAddress("mcGMomPID", &mcGMomPID );
        
        Run_Tree->SetBranchAddress("jetGenJetEn", &jetGenJetEn );
        Run_Tree->SetBranchAddress("jetGenJetPt", &jetGenJetPt );
        Run_Tree->SetBranchAddress("jetGenJetEta", &jetGenJetEta );
        Run_Tree->SetBranchAddress("jetGenJetPhi", &jetGenJetPhi );
        Run_Tree->SetBranchAddress("genMET", &genMET );
        Run_Tree->SetBranchAddress("genMETPhi", &genMETPhi );
        
        Run_Tree->SetBranchAddress("genHT",&genHT);
        Run_Tree->SetBranchAddress("mcMomPt", &mcMomPt );
        
        
        
        
        //###############################################################################################
        //  Weight Calculation
        //###############################################################################################
        float MuMass= 0.10565837;
        float eleMass= 0.000511;
        float LeptonPtCut_=60;
        float TauPtCut_=20;
        float JetPtCut=100;
        float BJetPtCut=30;
        float SimpleJetPtCut=30;
        float ElectronPtCut_=15;
        
        
        
        
        Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
        cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
        for (Int_t i = 0; i < nentries_wtn; i++) {
            //        for (Int_t i = 0; i < 100000; i++) {
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
            
            float GenTopPt=0;
            float GenAntiTopPt=0;
            float TopPtReweighting = 1;
            float WBosonPt=0;
            float WBosonKFactor=1;
            float ZBosonPt=0;
            float ZBosonKFactor=1;
            int modPDGId=-10;
            int AntimodPDGId=-10;
            
            TLorentzVector GenMu4Momentum,GenAntiMu4Momentum,GenLep4MomentumW,GenLep4MomentumZ;
            vector <TLorentzVector>  LepsfromW;
            vector <TLorentzVector>  LepsfromZ;
            
            LepsfromW.clear();
            LepsfromZ.clear();
            
            
            bool thereisLepton=false ; bool  thereisJet=false ; bool  thereisMet=false;
            
            float genZbosonPt=0;
            float genWbosonPt=0;
            
            for (int igen=0;igen < nMC; igen++){
                
                if (fabs(mcPID->at(igen)) ==24   && mcStatus->at(igen) ==22)  WBosonPt= mcPt->at(igen); // In inclusive we have status 62||22||44 while in HTbins we have just 22
                if (fabs(mcPID->at(igen)) ==23)  ZBosonPt= mcPt->at(igen); //FIXME somethime we do not have Z in the DY events
                
                
                
                
                if (( fabs(mcPID->at(igen)) ==11  ||  fabs(mcPID->at(igen)) ==13 || fabs(mcPID->at(igen)) ==15 )  &&  ((mcMomPID->at(igen))== fabs(mcPID->at(igen)) ||  (mcMomPID->at(igen))==24)        ){
                    GenLep4MomentumW.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen)); modPDGId=mcMomPID->at(igen);
                    LepsfromW.push_back(GenLep4MomentumW);
                    genWbosonPt=mcMomPt->at(igen);
                }
                
                
                
                if (( fabs(mcPID->at(igen)) ==11  ||  fabs(mcPID->at(igen)) ==13 || fabs(mcPID->at(igen)) ==15 )  &&  ((mcMomPID->at(igen))== fabs(mcPID->at(igen)) || (mcMomPID->at(igen))== 23        )){
                    GenLep4MomentumZ.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen)); modPDGId=mcMomPID->at(igen);
                    LepsfromZ.push_back(GenLep4MomentumZ);
                    genZbosonPt=mcMomPt->at(igen);
                }
                
                
                
                //Lepton Requirement
                if  (( fabs(mcPID->at(igen)) ==11  ||  fabs(mcPID->at(igen)) ==13 || fabs(mcPID->at(igen)) ==15 ) && mcPt->at(igen) > 60 && fabs(mcEta->at(igen)) < 2.4 )  thereisLepton=true;
            }
            
            
            // JET requirement
            for (int jjet=0; jjet < jetGenJetPt->size() ;jjet++){
                if (jetGenJetPt->at(jjet) > 100 && fabs(jetGenJetEta->at(jjet)) < 2.4 ) thereisJet=true;
            }
            
            // MET requirement
            if (genMET > 100) thereisMet=true;
            
            
            
            if  (!thereisLepton && !thereisJet && !thereisMet) continue;
            
            
            if (isWJets!= string::npos) {
                WBosonKFactor=Get_W_Z_BosonKFactor(WBosonPt,WLO,WNLO);  //Swtch ON only for LO Madgraph sample
            }
            if (isDYJets!= string::npos) {
                
                
                if (LepsfromZ.size() ==2)             ZBosonPt= (LepsfromZ[0]+LepsfromZ[1]).Pt();
                
                ZBosonKFactor=Get_W_Z_BosonKFactor(ZBosonPt,ZLO,ZNLO);  //Swtch ON only for LO Madgraph sample
            }
            
            //###############################################################################################
            float LumiWeight = 1;
            float GetGenWeight=1;
            float PUWeight = 1;
            
            
            if (HistoTot){
                
                if (isFXFX !=string::npos) {
                    LumiWeight = weightCalc_Stitching(HistoTot, InputROOT, WBosonPt,ZBosonPt,W_EventsNLO, Z_EventsNLO);}
                
                else{
                    LumiWeight = weightCalc(HistoTot, InputROOT);
                }
            }
            
            GetGenWeight=genWeight;
            
            
            
            
            
            
            
            
            //############################################################################################
            //   Making Plots
            //############################################################################################
            float TotalWeight= LumiWeight * GetGenWeight;
            
            plotFill("_WBosonPt",WBosonPt,150,0,1500,TotalWeight);
            plotFill("_WBosonPt_KFactor",WBosonPt,150,0,1500,TotalWeight*WBosonKFactor);
            
            plotFill("_ZBosonPt",ZBosonPt,150,0,1500,TotalWeight);
            plotFill("_ZBosonPt_KFactor",ZBosonPt,150,0,1500,TotalWeight*ZBosonKFactor);
            
            
        } //End of Tree
    }//End of file
    //##############  end of dielectron
    
    //        }
    //
    //    }
    
    fout->cd();
    
    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
    
    for (; iMap1 != jMap1; ++iMap1)
        nplot1(iMap1->first)->Write();
    
    map<string, TH2F*>::const_iterator iMap2 = myMap2->begin();
    map<string, TH2F*>::const_iterator jMap2 = myMap2->end();
    
    for (; iMap2 != jMap2; ++iMap2)
        nplot2(iMap2->first)->Write();
    
    fout->Close();
    
    
}
