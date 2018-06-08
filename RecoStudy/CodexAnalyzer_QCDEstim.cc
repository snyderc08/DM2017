#include "../interface/Functions.h"
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
        cout <<"INPUT NAME IS:   " << input[f - 2] << "\n";
    }
        
    
        
        
        //###############################################################################################
        //  Weight Calculation
        //###############################################################################################
        float WSCALEFACTORE=1.00;  //measured July 4th from WEstimaOutPut/_16_80X
        float WSF_mutau=1.0;
        float WSF_etau=1.0;
        float MuMass= 0.10565837;
        float eleMass= 0.000511;
        float LeptonPtCut_=40;
        float TauPtCut_=20;
        float JetPtCut=40; // used to be 50 for QCD
        float BJetPtCut=20;
        float ElectronPtCut_=15;
        float CSVCut= 0.935 ;    // loose is 0.460                 //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation74X
        float LeptonIsoCut=0.15;
        
        
    for (int k = 0; k < input.size(); k++) {
        
        TFile *f_Double = TFile::Open(input[k].c_str());
        cout << "\n  Now is running on ------->   " << std::string(f_Double->GetName()) << "\n";
        
        std::string InputROOT= std::string(f_Double->GetName());
        TFile * myFile = TFile::Open(f_Double->GetName());
        TH1F * HistoTot = (TH1F*) myFile->Get("hcount");
        
        TTree *  Run_Tree;
        Run_Tree= Xttree(f_Double);
        
        //#####################################################################
        //#####################################################################
        //                           Loop over Events in each ROOT files
        //#####################################################################
        //#####################################################################
        Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
        cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
        for (Int_t i = 0; i < nentries_wtn; i++) {
            //                    for (Int_t i = 0; i < 10000; i++) {
            Run_Tree->GetEntry(i);
            if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
            fflush(stdout);
            
            
            
            //###############################################################################################
            //  This part is to avoid of the duplicate of mu-j pair from one events
            //###############################################################################################
            std::vector<string> HistNamesFilled;
            HistNamesFilled.clear();
            
            
            //############################################################################################
            //###########       Loop over MuJet events   #################################################
            //############################################################################################
        
            for  (int imu=0 ; imu < nMu; imu++){
                
                
                float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                    IsoMu= ( muPFChIso->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
//                    IsoMu= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu); //BUGGY
                
                bool MuPtCut = muPt->at(imu) > LeptonPtCut_ && fabs(muEta->at(imu)) < 2.4 ;
                bool MuIdIso= (muIDbit->at(imu) >> 2 & 1);
                
                if (! MuPtCut || !MuIdIso ) continue;
                
                
                
                
                TLorentzVector Mu4Momentum, Tau4Momentum, Jet4Momentum,ExtraMu4Momentum, ExtraEle4Momentum,KJet4Momentum,LQ;
                Mu4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
                
                
                
                
                //###########      Finding the close jet near mu   ###########################################################
                
                float CLoseJetMuPt=muPt->at(imu);
                float CLoseJetMuEta=muEta->at(imu);
                
                if (MuPtCut && MuIdIso ){
                    
                    double Refer_R_jetmu = 5;
                    
                    for (int kjet= 0 ; kjet < nJet ; kjet++){
                        KJet4Momentum.SetPtEtaPhiE(jetPt->at(kjet),jetEta->at(kjet),jetPhi->at(kjet),jetEn->at(kjet));
                        
                        
                        if (KJet4Momentum.DeltaR(Mu4Momentum) < Refer_R_jetmu) {
                            Refer_R_jetmu = KJet4Momentum.DeltaR(Mu4Momentum);
                            if (Refer_R_jetmu < 0.5 && jetPt->at(kjet)  >= muPt->at(imu)) {
                                CLoseJetMuPt = jetPt->at(kjet);
                                CLoseJetMuEta = jetEta->at(kjet);
                            }
                        }
                    }
                }
                
                //###########    loop over  Jet    ###########################################################
                // Finding Leading Jet
                TLorentzVector LeadJet4Momentum;
                for (int ijet= 0 ; ijet < nJet ; ijet++){
                    bool goodJet = (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > JetPtCut && fabs(jetEta->at(ijet)) < 3.0  && Jet4Momentum.DeltaR(Mu4Momentum) > 0.5 );
                    if ( goodJet) {
                        LeadJet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                        break;
                    }
                }
                
                
                //###########    loop over  Jet    ###########################################################
                
                for (int ijet= 0 ; ijet < nJet ; ijet++){
                    
                    Jet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                    
                    
                    bool goodJet = (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > JetPtCut && fabs(jetEta->at(ijet)) < 3.0  && Jet4Momentum.DeltaR(Mu4Momentum) > 0.5 );
                    if (! goodJet) continue;
                    
                    LQ=Jet4Momentum + Mu4Momentum;
                    
                    
                    //###############################################################################################
                    //  Isolation Categorization
                    //###############################################################################################
                    //###############################################################################################
                    
                    
                    bool LepPassIsolation= IsoMu < LeptonIsoCut;
                    
                    const int size_isoCat = 4;
                    bool Isolation = LepPassIsolation;
                    bool AntiIsolation =  !LepPassIsolation;
                    bool Total = 1;
                    bool LooseIso = IsoMu < 0.25;
                    
                    bool Iso_category[size_isoCat] = {Isolation, AntiIsolation,Total,LooseIso};
                    std::string iso_Cat[size_isoCat] = {"_Iso", "_AntiIso","_Total","_LooseIso"};
                    //###############################################################################################
                    //  MT Categorization
                    //###############################################################################################
                    float tmass_MuMet= TMass_F(muPt->at(imu), muPt->at(imu)*cos(muPhi->at(imu)),muPt->at(imu)*sin(muPhi->at(imu)) , pfMET, pfMETPhi);
                    const int size_mTCat = 3;
                    bool NoMT = 1;
                    bool LoWMT = tmass_MuMet < 50;
                    bool HighMT = tmass_MuMet > 50;
                    
                    bool MT_category[size_mTCat] = {NoMT,LoWMT,HighMT};
                    std::string MT_Cat[size_mTCat] = {"_NoMT", "_LowMT","_HighMT"};
                    
                    float tmass_JetMet= TMass_F(jetPt->at(ijet), jetPt->at(ijet)*cos(jetPhi->at(ijet)),jetPt->at(ijet)*sin(jetPhi->at(ijet)) , pfMET, pfMETPhi);
                    float tmass_LQMet= TMass_F(LQ.Pt(), LQ.Px(),LQ.Py(), pfMET, pfMETPhi);
                    
                    
                    //###############################################################################################
                    //  Jet Pt Categorization
                    //###############################################################################################
                    const int size_jetMetPhi = 3;
//                    TLorentzVector  LeadJet4Momentum;
//                    LeadJet4Momentum.SetPtEtaPhiE(jetPt->at(0),jetEta->at(0),jetPhi->at(0),jetEn->at(0));
                    bool lowDPhi = deltaPhi(LeadJet4Momentum.Phi(),pfMETPhi) < 0.5;
                    bool HighDPhi = deltaPhi(LeadJet4Momentum.Phi(),pfMETPhi) > 0.5;
                    bool RelaxDphi = 1;
                    
                    
                    bool jetMetPhi_category[size_jetMetPhi] = {lowDPhi,HighDPhi,RelaxDphi};
                    std::string jetMetPhi_Cat[size_jetMetPhi] = {"_LowDPhi", "_HighDPhi","_RelaxDPhi"};
                    
                    
                    //###############################################################################################
                    
                    std::string CHL="MuJet";
                    
                    
                        for (int iso = 0; iso < size_isoCat; iso++) {
                            if (Iso_category[iso]) {
                                for (int imt = 0; imt < size_mTCat; imt++) {
                                    if (MT_category[imt]) {
                                        for (int jpt = 0; jpt < size_jetMetPhi; jpt++) {
                                            if (jetMetPhi_category[jpt]) {
                                                
                                                        
                                                
                                                        
                                                        float FullWeight = 1;
                                                        std::string FullStringName = MT_Cat[imt] + jetMetPhi_Cat[jpt]+ iso_Cat[iso] ;
                                                
                                                if (!( std::find(HistNamesFilled.begin(), HistNamesFilled.end(), FullStringName) != HistNamesFilled.end())){
                                                    HistNamesFilled.push_back(FullStringName);
                                                    
                                                    
                                                        plotFill(CHL+"_tmass_MuMet"+FullStringName,tmass_MuMet,100,0,500,FullWeight);
                                                        plotFill(CHL+"_tmass_JetMet"+FullStringName,tmass_JetMet,100,0,500,FullWeight);
                                                        plotFill(CHL+"_tmass_LQMet"+FullStringName,tmass_LQMet,100,0,500,FullWeight);
                                                        
                                                        plotFill(CHL+"_JetPt"+FullStringName,jetPt->at(ijet) ,100,0,500,FullWeight);
                                                        plotFill(CHL+"_JetEta"+FullStringName,jetEta->at(ijet),100,-2.5,2.5,FullWeight);
                                                        plotFill(CHL+"_LepPt"+FullStringName,muPt->at(imu),1000,0,1000,FullWeight);
                                                        plotFill(CHL+"_LepEta"+FullStringName,muEta->at(imu),100,-2.5,2.5,FullWeight);
                                                        plotFill(CHL+"_CloseJetLepPt"+FullStringName,CLoseJetMuPt,1000,0,1000,FullWeight);
                                                        plotFill(CHL+"_CloseJetLepEta"+FullStringName,CLoseJetMuEta,100,-2.5,2.5,FullWeight);
                                                        
                                                        plotFill(CHL+"_MET"+FullStringName,pfMET,100,0,500,FullWeight);
                                                        plotFill(CHL+"_LQMass"+FullStringName,LQ.M(),200,0,1000,FullWeight);
                                                        plotFill(CHL+"_dPhi_Jet_Met"+FullStringName,deltaPhi(Jet4Momentum.Phi(),pfMETPhi),200,0,4,FullWeight);
                                                        plotFill(CHL+"_dPhi_Mu_Met"+FullStringName,deltaPhi(Mu4Momentum.Phi(),pfMETPhi),200,0,4,FullWeight);
                                                }
                                               
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    //qcd control region   MET > 100 && MT > 150  && Jet < 100 && jet > 50;
                    //qcd
                    
                    //###############################################################################################
                    //  Doing EleTau Analysis
                    //###############################################################################################
                    
                    
                } //End of Tree
            }//End of file
            //##############  end of dielectron
            
        }
        
    }
    
    fout->cd();
    //    BG_Tree->Write();
    
    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
    
    for (; iMap1 != jMap1; ++iMap1)
        nplot1(iMap1->first)->Write();

    
    fout->Close();
    
    
}
