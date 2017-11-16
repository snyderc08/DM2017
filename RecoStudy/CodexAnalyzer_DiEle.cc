// This code is used for the Ersatz study where we select a dieleon and then replace one eleon with MET
// This code can be run twice one with shifting the S mass to W mass and once without that [Note the correct one is to scale the mass]
//Ele4Momentum_i=(80.3/91.2)*Ele4Momentum_i;
//Ele4Momentum_j=(80.3/91.2)*Ele4Momentum_j;
// The output will be stored in 2 different directory and then the Step6_PreSelectionPlotter_DiMu.py is run and  then the plots are made with CodexAnalyzer_DiMu.cc



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
    // Pileup files
    //########################################
    TFile * PUData= TFile::Open("../interface/pileup-hists/dataMoriondPU.root");
    TH1F * HistoPUData= (TH1F *) PUData->Get("pileup");
    HistoPUData->Scale(1.0/HistoPUData->Integral());
    
    TFile * PUMC= TFile::Open("../interface/pileup-hists/mcMoriondPU.root");
    TH1F * HistoPUMC= (TH1F *) PUMC->Get("pileup");
    HistoPUMC->Scale(1.0/HistoPUMC->Integral());
    
    
    //########################################
    // Muon Id, Iso, Trigger and Tracker Eff files
    //########################################
    TFile * MuCorrId_BCDEF= TFile::Open(("../interface/pileup-hists/ID_EfficienciesAndSF_BCDEF.root"));
    TH2F * HistoMuId_BCDEF= (TH2F *) MuCorrId_BCDEF->Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
    
    TFile * MuCorrId_GH= TFile::Open(("../interface/pileup-hists/ID_EfficienciesAndSF_GH.root"));
    TH2F * HistoMuId_GH= (TH2F *) MuCorrId_GH->Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
    
    TFile * MuCorrIso_BCDEF= TFile::Open(("../interface/pileup-hists/Iso_EfficienciesAndSF_BCDEF.root"));
    TH2F * HistoMuIso_BCDEF= (TH2F *) MuCorrIso_BCDEF->Get("TightISO_TightID_pt_eta/pt_abseta_ratio");
    
    TFile * MuCorrIso_GH= TFile::Open(("../interface/pileup-hists/Iso_EfficienciesAndSF_GH.root"));
    TH2F * HistoMuIso_GH= (TH2F *) MuCorrIso_GH->Get("TightISO_TightID_pt_eta/pt_abseta_ratio");
    
    TFile * MuCorrTrg_BCDEF= TFile::Open(("../interface/pileup-hists/Trigger_EfficienciesAndSF_RunBtoF.root"));
    TH2F * HistoMuTrg_BCDEF= (TH2F *) MuCorrTrg_BCDEF->Get("Mu50_OR_TkMu50_PtEtaBins/pt_abseta_ratio");
    
    TFile * MuCorrTrg_GH= TFile::Open(("../interface/pileup-hists/Trigger_EfficienciesAndSF_Period4.root"));
    TH2F * HistoMuTrg_GH= (TH2F *) MuCorrTrg_GH->Get("Mu50_OR_TkMu50_PtEtaBins/pt_abseta_ratio");
    
    TFile * MuCorrTrack= TFile::Open(("../interface/pileup-hists/Tracking_EfficienciesAndSF_BCDEFGH.root"));
    TGraphAsymmErrors * HistoMuTrack= (TGraphAsymmErrors *) MuCorrTrack->Get("ratio_eff_eta3_dr030e030_corr");
    
    TH2F* HistoMuId[2]={HistoMuId_BCDEF, HistoMuId_GH};
    TH2F* HistoMuIso[2]={HistoMuIso_BCDEF,HistoMuIso_GH};
    TH2F* HistoMuTrg[2]={HistoMuTrg_BCDEF, HistoMuTrg_GH};
    
    
    //########################################
    // Electron MVA IdIso files
    //########################################
    TFile * EleCorrMVAIdIso90= TFile::Open(("../interface/pileup-hists/egammaEffi.txt_EGM2D.root"));
    TH2F * HistoEleMVAIdIso90= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_SF2D");
    
    
    
    //########################################
    // W and DY K-factor files  (FIT-based K-factor)
    //########################################
    
    TFile * kfactorW=TFile::Open("../interface/kfactor_W.root");
    TH1F* HistkfactorW= (TH1F*) kfactorW->Get("KFcator");
    float kf_W_1=HistkfactorW->GetBinContent(1);
    float kf_W_2=HistkfactorW->GetBinContent(2);
    
    TFile * kfactorZ=TFile::Open("../interface/kfactor_Z.root");
    TH1F* HistkfactorZ= (TH1F*) kfactorZ->Get("KFcator");
    float kf_Z_1=HistkfactorZ->GetBinContent(1);
    float kf_Z_2=HistkfactorZ->GetBinContent(2);
    
    
    
    
    
    //########################################
    // W and DY K-factor files
    //########################################
    TFile * KFactor= TFile::Open("../interface/pileup-hists/kfactors.root");
    TH1F * WLO= (TH1F *) KFactor->Get("WJets_LO/inv_pt");
    TH1F * WNLO= (TH1F *) KFactor->Get("EWKcorr/W");
    TH1F * ZLO= (TH1F *) KFactor->Get("ZJets_LO/inv_pt");
    TH1F * ZNLO= (TH1F *) KFactor->Get("EWKcorr/Z");
    
    
    
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
        
        
        //        std::string ROOTLoc= "/Users/abdollah1/GIT_abdollah110/DM2016/ROOT80X/";
        //        vector<float> DY_Events = DY_HTBin(ROOTLoc);
        //        vector<float> W_Events = W_HTBin(ROOTLoc);
        //        vector<float> W_EventsNLO = W_PTBinNLO(ROOTLoc); //This is for the NLO samples (as the stat is too low we do not use them)
        //        vector<float> W_EventsNLO = W_HTBin(ROOTLoc);
        
        
        
        TFile * TTEff= TFile::Open(("OutFiles_BTagSF/TTJets.root"));
        TH2F * TTSF0_btagged= (TH2F *) TTEff->Get("BSF_FLV0_Btagged");
        TH2F * TTSF0_total= (TH2F *) TTEff->Get("BSF_FLV0_Total");
        TH2F * TTSF5_btagged= (TH2F *) TTEff->Get("BSF_FLV5_Btagged");
        TH2F * TTSF5_total= (TH2F*) TTEff->Get("BSF_FLV5_Total");
        
        TH2F * Btagg_TT[4]={TTSF0_btagged,TTSF0_total,TTSF5_btagged,TTSF5_total};
        
        //        TFile * DataEff= TFile::Open(("OutFiles_BTagSF/Data.root"));
        //        TH2F * DataSF0_btagged= (TH2F *) DataEff->Get("BSF_FLV0_Btagged");
        //        TH2F * DataSF0_total= (TH2F *) DataEff->Get("BSF_FLV0_Total");
        //        TH2F * DataSF5_btagged= (TH2F *) DataEff->Get("BSF_FLV5_Btagged");
        //        TH2F * DataSF5_total= (TH2F *) DataEff->Get("BSF_FLV5_Total");
        
        
        
        
        
        //########################################   General Info
        Run_Tree->SetBranchAddress("isData", &isData);
        Run_Tree->SetBranchAddress("run", &run);
        Run_Tree->SetBranchAddress("lumis", &lumis);
        Run_Tree->SetBranchAddress("event", &event);
        Run_Tree->SetBranchAddress("genWeight",&genWeight);
        Run_Tree->SetBranchAddress("HLTEleMuX", &HLTEleMuX);
        Run_Tree->SetBranchAddress("puTrue", &puTrue);
        Run_Tree->SetBranchAddress("nVtx",&nVtx);
        
        //########################################   MC Info
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
        
        
        //########################################   Tau Info
        Run_Tree->SetBranchAddress("nTau", &nTau);
        Run_Tree->SetBranchAddress("tauPt"  ,&tauPt);
        Run_Tree->SetBranchAddress("tauEta"  ,&tauEta);
        Run_Tree->SetBranchAddress("tauPhi"  ,&tauPhi);
        Run_Tree->SetBranchAddress("tauMass"  ,&tauMass);
        Run_Tree->SetBranchAddress("tauCharge"  ,&tauCharge);
        Run_Tree->SetBranchAddress("taupfTausDiscriminationByDecayModeFinding", &taupfTausDiscriminationByDecayModeFinding);
        Run_Tree->SetBranchAddress("tauByTightMuonRejection3", &tauByTightMuonRejection3);
        Run_Tree->SetBranchAddress("tauByLooseMuonRejection3", &tauByLooseMuonRejection3);
        Run_Tree->SetBranchAddress("tauByMVA6MediumElectronRejection"  ,&tauByMVA6MediumElectronRejection);
        Run_Tree->SetBranchAddress("tauByLooseCombinedIsolationDeltaBetaCorr3Hits",&tauByLooseCombinedIsolationDeltaBetaCorr3Hits);
        Run_Tree->SetBranchAddress("tauByMediumCombinedIsolationDeltaBetaCorr3Hits",&tauByMediumCombinedIsolationDeltaBetaCorr3Hits);
        Run_Tree->SetBranchAddress("tauByMVA6LooseElectronRejection", &tauByMVA6LooseElectronRejection);
        Run_Tree->SetBranchAddress("tauDxy",&tauDxy);
        Run_Tree->SetBranchAddress("tauDecayMode",&tauDecayMode);
        Run_Tree->SetBranchAddress("tauByLooseIsolationMVArun2v1DBoldDMwLT",&tauByLooseIsolationMVArun2v1DBoldDMwLT);
        Run_Tree->SetBranchAddress("tauByVLooseIsolationMVArun2v1DBoldDMwLT",&tauByVLooseIsolationMVArun2v1DBoldDMwLT);
        
        //########################################   Mu Info
        Run_Tree->SetBranchAddress("nMu", &nMu);
        Run_Tree->SetBranchAddress("muPt"  ,&muPt);
        Run_Tree->SetBranchAddress("muEta"  ,&muEta);
        Run_Tree->SetBranchAddress("muPhi"  ,&muPhi);
        Run_Tree->SetBranchAddress("muIsoTrk", &muIsoTrk);
        Run_Tree->SetBranchAddress("muCharge",&muCharge);
        Run_Tree->SetBranchAddress("muIDbit",&muIDbit);//NEW
        Run_Tree->SetBranchAddress("muPFChIso", &muPFChIso);
        Run_Tree->SetBranchAddress("muPFPhoIso", &muPFPhoIso);
        Run_Tree->SetBranchAddress("muPFNeuIso", &muPFNeuIso);
        Run_Tree->SetBranchAddress("muPFPUIso", &muPFPUIso);
        Run_Tree->SetBranchAddress("muD0",&muD0);
        Run_Tree->SetBranchAddress("muDz",&muDz);
        
        //########################################   Ele Info
        Run_Tree->SetBranchAddress("nEle", &nEle);
        Run_Tree->SetBranchAddress("elePt"  ,&elePt);
        Run_Tree->SetBranchAddress("eleEta"  ,&eleEta);
        Run_Tree->SetBranchAddress("elePhi"  ,&elePhi);
        Run_Tree->SetBranchAddress("elePFChIso", &elePFChIso);
        Run_Tree->SetBranchAddress("eleIDMVA", &eleIDMVA);//NEW
        Run_Tree->SetBranchAddress("eleCharge",&eleCharge);
        Run_Tree->SetBranchAddress("eleSCEta",&eleSCEta);
        Run_Tree->SetBranchAddress("elePFChIso", &elePFChIso);
        Run_Tree->SetBranchAddress("elePFPhoIso", &elePFPhoIso);
        Run_Tree->SetBranchAddress("elePFNeuIso", &elePFNeuIso);
        Run_Tree->SetBranchAddress("elePFPUIso", &elePFPUIso);
        Run_Tree->SetBranchAddress("eleD0",&eleD0);
        Run_Tree->SetBranchAddress("eleDz",&eleDz);
        Run_Tree->SetBranchAddress("eleMissHits", &eleMissHits);
        Run_Tree->SetBranchAddress("eleConvVeto", &eleConvVeto);
        Run_Tree->SetBranchAddress("eleSCEta", &eleSCEta );
        
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
        
        //########################################   MET Info
        Run_Tree->SetBranchAddress("pfMET",&pfMET);
        Run_Tree->SetBranchAddress("pfMETPhi",&pfMETPhi);
        Run_Tree->SetBranchAddress("metFilters",&metFilters);
        Run_Tree->SetBranchAddress("genHT",&genHT);
        
        
        //###############################################################################################
        //  Weight Calculation
        //###############################################################################################
        float MuMass= 0.10565837;
        float eleMass= 0.000511;
        float LeptonPtCut_=30; // specific for diMu
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
            
            TLorentzVector GenEle4Momentum,GenAntiEle4Momentum;
            
            for (int igen=0;igen < nMC; igen++){
                if (mcPID->at(igen) == 6 && mcStatus->at(igen) ==62) GenTopPt=mcPt->at(igen) ;
                if (mcPID->at(igen) == -6 && mcStatus->at(igen) ==62) GenAntiTopPt=mcPt->at(igen);
                if (fabs(mcPID->at(igen)) ==24   && mcStatus->at(igen) ==22)  WBosonPt= mcPt->at(igen); // In inclusive we have status 62||22||44 while in HTbins we have just 22
                if (fabs(mcPID->at(igen)) ==23)  ZBosonPt= mcPt->at(igen); //FIXME somethime we do not have Z in the DY events
                if ( mcPID->at(igen) ==11  )  GenEle4Momentum.SetPtEtaPhiE(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));
                if ( mcPID->at(igen) ==-11  )  GenAntiEle4Momentum.SetPtEtaPhiE(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));
                
            }
            if (ZBosonPt ==0)
                ZBosonPt=(GenEle4Momentum+GenAntiEle4Momentum).Pt();  //This is a temp solution to the above problem
            
            
            size_t isTTJets = InputROOT.find("TTJets");
            if (isTTJets!= string::npos) TopPtReweighting = compTopPtWeight(GenTopPt, GenAntiTopPt);
//            size_t isWJets = InputROOT.find("WJets");
//            if (isWJets!= string::npos) WBosonKFactor=Get_W_Z_BosonKFactor(WBosonPt,WLO,WNLO);  //Swtch ON only for LO Madgraph sample
//            size_t isDYJets = InputROOT.find("DYJets");
//            if (isDYJets!= string::npos) ZBosonKFactor=Get_W_Z_BosonKFactor(ZBosonPt,ZLO,ZNLO);  //Swtch ON only for LO Madgraph sample
            
            //######################## W K-factor
            size_t isWJets = InputROOT.find("WJets");
            //            if (isWJets!= string::npos) WBosonKFactor=Get_W_Z_BosonKFactor(WBosonPt,WLO,WNLO_ewk);  //Swtch ON only for LO Madgraph sample
            if (isWJets!= string::npos) WBosonKFactor= kf_W_1 + kf_W_2 * WBosonPt;
            
            //######################## Z K-factor
            size_t isDYJets = InputROOT.find("DYJets");
            //            if (isDYJets!= string::npos) ZBosonKFactor=Get_W_Z_BosonKFactor(ZBosonPt,ZLO,ZNLO_ewk);  //Swtch ON only for LO Madgraph sample
            if (isDYJets!= string::npos) ZBosonKFactor= kf_Z_1 + kf_Z_2 * ZBosonPt;
            
            
            
            //###############################################################################################
            float LumiWeight = 1;
            float GetGenWeight=1;
            float PUWeight = 1;
            
            if (!isData){
                
                //                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT, genHT,WBosonPt, W_Events, DY_Events,W_EventsNLO);
                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT);
                GetGenWeight=genWeight;
                
                int puNUmmc=int(puTrue->at(0)*10);
                int puNUmdata=int(puTrue->at(0)*10);
                float PUMC_=HistoPUMC->GetBinContent(puNUmmc+1);
                float PUData_=HistoPUData->GetBinContent(puNUmdata+1);
                if (PUMC_ ==0)
                    cout<<"PUMC_ is zero!!! & num pileup= "<< puTrue->at(0)<<"\n";
                else
                    PUWeight= PUData_/PUMC_;
                
            }
            
            
            
            
            //###############################################################################################
            //  Doing  Analysis
            //###############################################################################################
            //###########       Trigger Requirement ###########################################################
            //            else if (name.find("HLT_IsoMu24_v")   != string::npos) bitEleMuX = 19;
            //            else if (name.find("HLT_IsoTkMu24_v") != string::npos) bitEleMuX = 20;

//            else if (name.find("HLT_Ele27_eta2p1_WPTight_Gsf_v")                      != string::npos) bitEleMuX =  1;
//            else if (name.find("HLT_Ele27_eta2p1_WPLoose_Gsf_v")                      != string::npos) bitEleMuX =  2;
//            else if (name.find("HLT_Ele32_eta2p1_WPTight_Gsf_v")                      != string::npos) bitEleMuX =  3;
//            else if (name.find("HLT_Ele27_WPTight_Gsf_v")                             != string::npos) bitEleMuX =  4;
            
            bool PassTrigger = ((HLTEleMuX >> 4 & 1) == 1);
            if (! PassTrigger) continue;
            
            //###########       tau Veto   ###########################################################
            int numTau=0;
            for  (int itau=0 ; itau < nTau; itau++){
                
                if (tauPt->at(itau) < TauPtCut_  || fabs(tauEta->at(itau)) > 2.3 ) continue;
                
                bool TauIdIso =  taupfTausDiscriminationByDecayModeFinding->at(itau) > 0.5 && tauByLooseMuonRejection3->at(itau) > 0 && tauByMVA6LooseElectronRejection->at(itau) > 0 && tauByLooseIsolationMVArun2v1DBoldDMwLT->at(itau) > 0;
                
                if (!TauIdIso) continue;
                numTau++;
            }
            //###########       Muon Veto   ###########################################################
            
            int numMuon=0;
            TLorentzVector Mu4Momentum;
            Mu4Momentum.SetPtEtaPhiM(0,0,0,0);
            
            for  (int imu=0 ; imu < nMu; imu++){
                
                float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                    IsoMu= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                
                bool MuPtCut = muPt->at(imu) > 15 && fabs(muEta->at(imu)) < 2.4 ;
                bool MuIdIso=( (muIDbit->at(imu) >> 2 & 1)  && fabs(muD0->at(imu)) < 0.045 && fabs(muDz->at(imu)) < 0.2 && IsoMu < 0.15); //Tight Muon Id
                
                
                if (! MuPtCut || !MuIdIso ) continue;
                
                numMuon++;
                
                Mu4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
                
                break;
                
            }
            
            //###########       bJet Veto   ###########################################################
            int numBJet=0;
            int numlightJet=0;
            float EffJet =1;
            float SF=1;
            float P_Data_P_mc=1;
            float FinalBTagSF=1;
            
            
            for (int ijet= 0 ; ijet < nJet ; ijet++){
                
                float HadronFlavor= isData ? 1 : jetHadFlvr->at(ijet);
                
                if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > BJetPtCut && fabs(jetEta->at(ijet)) < 2.4 ){
                    
                    
                    if ( jetCSV2BJetTags->at(ijet) >  CSVCut ){
                        numBJet++;
                        EffJet= getBtagEfficiency( isData, 1,  jetPt->at(ijet), fabs(jetEta->at(ijet)), Btagg_TT);
                        SF= GetBJetSF(isData, jetPt->at(ijet), jetPt->at(ijet), HadronFlavor);
                        P_Data_P_mc=SF*EffJet/EffJet;
                        
                        
                    }
                    else{
                        EffJet= getBtagEfficiency( isData, 0,  jetPt->at(ijet), fabs(jetEta->at(ijet)), Btagg_TT);
                        numlightJet++;
                        SF=GetBJetSF(isData,jetPt->at(ijet), jetPt->at(ijet), HadronFlavor);
                        P_Data_P_mc=(1-SF*EffJet)/(1-EffJet);
                        
                    }
                    
                }
                
                FinalBTagSF *=P_Data_P_mc;
            }
            if (isData) FinalBTagSF=1;
            
            int numJet=0;
            for (int ijet= 0 ; ijet < nJet ; ijet++){
                if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > SimpleJetPtCut && fabs(jetEta->at(ijet)) < 2.4 )
                    numJet++;
            }
            
            //###########       Z boson Veto   ###########################################################
            int numZboson=0;
            //############################################################################################
            //   Final Total Weight
            //############################################################################################
            float TotalWeight_withTopPtRW = LumiWeight * GetGenWeight * PUWeight * TopPtReweighting * WBosonKFactor * ZBosonKFactor ;
            float TotalWeight_NoTopPtRW = LumiWeight * GetGenWeight * PUWeight * WBosonKFactor * ZBosonKFactor ;
            
            //###############################################################################################
            //  Some Histogram Filling
            //###############################################################################################
            plotFill("_WeightLumi",LumiWeight,1000,0,10);
            plotFill("_TopPtReweighting",TopPtReweighting,100,0,2);
            plotFill("_WeightPU",PUWeight,100,0,5);
            plotFill("_TotalWeight_withTopPtRW",TotalWeight_withTopPtRW,50,0,2);
            plotFill("_TotalWeight_NoTopPtRW",TotalWeight_NoTopPtRW,50,0,2);
            plotFill("_nVtx_NoPUCorr",nVtx,60,0,60);
            plotFill("_nVtx_PUCorr",nVtx,60,0,60,PUWeight);
            plotFill("_WBosonPt",WBosonPt,150,0,1500,PUWeight);
            plotFill("_FinalBTagSF", FinalBTagSF,200,0,2);
            
            for (int qq=0; qq < 60;qq++){
                if ((HLTEleMuX >> qq & 1) == 1)
                    plotFill("_HLT",qq,60,0,60);
            }
            
            //############################################################################################
            //###########       Loop over diElectron events   #################################################
            //############################################################################################
            
            TLorentzVector Ele4Momentum_i,Ele4Momentum_j,DiEle4Momentum, Jet4Momentum,LQ4Momentum;
            
            //###########      Second eleon   ###########################################################
            for  (int iele=0 ; iele < nEle; iele++){
                
                
                
                bool eleMVAIdExtra_i= false;
                if (fabs (eleSCEta->at(iele)) <= 0.8 && eleIDMVA->at(iele) >   0.837  ) eleMVAIdExtra_i= true;
                else if (fabs (eleSCEta->at(iele)) >  0.8 &&fabs (eleSCEta->at(iele)) <=  1.5 && eleIDMVA->at(iele) >   0.715  ) eleMVAIdExtra_i= true;
                else if ( fabs (eleSCEta->at(iele)) >=  1.5 && eleIDMVA->at(iele) >  0.357  ) eleMVAIdExtra_i= true;
                else eleMVAIdExtra_i= false;
                
                bool ElePtCut = elePt->at(iele) > LeptonPtCut_ && fabs(eleEta->at(iele)) < 2.5 ;
                bool EleIdIso=eleMVAIdExtra_i; //Tight Muon Id
                
                
                if (! ElePtCut || !EleIdIso ) continue;
                
                
                float ElectronCor_i=getCorrFactorMVA90WPElectron80X(isData,  elePt->at(iele),eleSCEta->at(iele),    HistoEleMVAIdIso90 );
                
                
                Ele4Momentum_i.SetPtEtaPhiM(elePt->at(iele),eleEta->at(iele),elePhi->at(iele),eleMass);
                
                
                
                //###########      Second eleon   ###########################################################
                for  (int jele=iele+1 ; jele < nEle; jele++){
                    
                    
                    bool eleMVAIdExtra_j= false;
                    if (fabs (eleSCEta->at(jele)) <= 0.8 && eleIDMVA->at(jele) >   0.837  ) eleMVAIdExtra_j= true;
                    else if (fabs (eleSCEta->at(jele)) >  0.8 &&fabs (eleSCEta->at(jele)) <=  1.5 && eleIDMVA->at(jele) >   0.715  ) eleMVAIdExtra_j= true;
                    else if ( fabs (eleSCEta->at(jele)) >=  1.5 && eleIDMVA->at(jele) >  0.357  ) eleMVAIdExtra_j= true;
                    else eleMVAIdExtra_j= false;
                    
                    
                    
                    
                    bool ElePtCut = elePt->at(jele) > LeptonPtCut_ && fabs(eleEta->at(jele)) < 2.5 ;
                    bool EleIdIso= eleMVAIdExtra_j; //Tight Muon Id
                    
                    
                    if (! ElePtCut || !EleIdIso ) continue;
                    
                    
                    float ElectronCor_j=getCorrFactorMVA90WPElectron80X(isData,  elePt->at(jele),eleSCEta->at(jele),    HistoEleMVAIdIso90 );
                    
                    Ele4Momentum_j.SetPtEtaPhiM(elePt->at(jele),eleEta->at(jele),elePhi->at(jele),eleMass);
                    
                    
                    
                    
                    if (eleCharge->at(iele) * eleCharge->at(jele) > 0)  continue;
                    TLorentzVector diele4mom = Ele4Momentum_i+ Ele4Momentum_j;
                    if (diele4mom.M() < 80 || diele4mom.M() > 100) continue;
                    
                    
                    
                    
                    
   
                    
                    
                    
                    
                    DiEle4Momentum=Ele4Momentum_i+Ele4Momentum_j;
                    float denom1=sqrt(DiEle4Momentum.Px()*DiEle4Momentum.Px()+DiEle4Momentum.Py()*DiEle4Momentum.Py()+DiEle4Momentum.Pz()*DiEle4Momentum.Pz()+DiEle4Momentum.M()*DiEle4Momentum.M());
                    
                    Ele4Momentum_i.Boost(-DiEle4Momentum.Px()/denom1,-DiEle4Momentum.Py()/denom1,-DiEle4Momentum.Pz()/denom1);
                    Ele4Momentum_j.Boost(-DiEle4Momentum.Px()/denom1,-DiEle4Momentum.Py()/denom1,-DiEle4Momentum.Pz()/denom1);
                    
//                    cout <<"Check whether it is on rest mass "<< (Ele4Momentum_i+Ele4Momentum_j).Pt()<<"\n";

//   Just disabled this to address Adish comments
//                    Ele4Momentum_i=(80.3/91.2)*Ele4Momentum_i;
//                    Ele4Momentum_j=(80.3/91.2)*Ele4Momentum_j;
                    
                    TLorentzVector newDiEle4Momentum=Ele4Momentum_i+Ele4Momentum_j;
                    
                    float denom2=sqrt(DiEle4Momentum.Px()*DiEle4Momentum.Px()+DiEle4Momentum.Py()*DiEle4Momentum.Py()+DiEle4Momentum.Pz()*DiEle4Momentum.Pz()+newDiEle4Momentum.M()*newDiEle4Momentum.M());
                    
                    Ele4Momentum_i.Boost(DiEle4Momentum.Px()/denom2,DiEle4Momentum.Py()/denom2,DiEle4Momentum.Pz()/denom2);
                    Ele4Momentum_j.Boost(DiEle4Momentum.Px()/denom2,DiEle4Momentum.Py()/denom2,DiEle4Momentum.Pz()/denom2);
                    
                    
                    TLorentzVector GoodElectron, BadElectron;
                    if (event%2 ==0 ) {
                        GoodElectron=Ele4Momentum_i;
                        BadElectron=Ele4Momentum_j;
                    }
                    else{
                        GoodElectron=Ele4Momentum_j;
                        BadElectron=Ele4Momentum_i;
                    }
                    
                    
// I just test how the excess look like if we do not add one eleon to MET
//                    float newMET_x = pfMET * TMath::Cos(pfMETPhi) + BadElectron.Px() ;
//                    float newMET_y = pfMET * TMath::Sin(pfMETPhi) + BadElectron.Py() ;
                    float newMET_x = pfMET * TMath::Cos(pfMETPhi) ;
                    float newMET_y = pfMET * TMath::Sin(pfMETPhi) ;
                    
                    float newMET = sqrt (pow(newMET_x,2)+ pow(newMET_y,2));
                    
                    float newMETPhi = atan(newMET_y / newMET_x);
                    if (newMETPhi > (TMath::Pi() / 2)) newMETPhi += TMath::Pi();
                    if (newMETPhi < (-TMath::Pi() / 2)) newMETPhi -= TMath::Pi();
                    
                    
                    
                    
                    //###########    loop over  Jet    ###########################################################
                    
                    for (int ijet= 0 ; ijet < nJet ; ijet++){
                        
                        Jet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                        
                        
                        bool goodJet = (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > JetPtCut && fabs(jetEta->at(ijet)) < 2.4 && Jet4Momentum.DeltaR(GoodElectron) > 0.5);
                        if (! goodJet) continue;
                        
                        
                        
                        bool isThisJetMuon= Jet4Momentum.DeltaR(Mu4Momentum) < 0.5;
                        
                        
                        
                        LQ4Momentum=Jet4Momentum + GoodElectron;
                        //###############################################################################################
                        //  Isolation Categorization
                        //###############################################################################################
                        
                        const int size_isoCat = 1;
                        bool Isolation = 1;
                        
                        bool Iso_category[size_isoCat] = {Isolation};
                        std::string iso_Cat[size_isoCat] = {"_Iso"};
                        //###############################################################################################
                        //  MT Categorization
                        //###############################################################################################
                        float tmass_EleMet= TMass_F(GoodElectron.Pt(), GoodElectron.Px(),GoodElectron.Py() , newMET, newMETPhi);
                        
                        const int size_mTCat = 5;
                        
                        bool NoMT = 1;
                        bool LoWMT = (tmass_EleMet < 40);
                        bool HighMT = (tmass_EleMet > 100);
                        bool MTTo150=(tmass_EleMet > 150 );
                        bool MTTo200=(tmass_EleMet > 200 );
                        
                        bool MT_category[size_mTCat] = {NoMT,LoWMT,HighMT,MTTo150,MTTo200};
                        std::string MT_Cat[size_mTCat] = {"_NoMT", "_LowMT","_HighMT","_MT150","_MT200"};
                        
                        float tmass_JetMet= TMass_F(jetPt->at(ijet), jetPt->at(ijet)*cos(jetPhi->at(ijet)),jetPt->at(ijet)*sin(jetPhi->at(ijet)) , newMET, newMETPhi);
                        float tmass_LQMet= TMass_F(LQ4Momentum.Pt(), LQ4Momentum.Px(),LQ4Momentum.Py(), newMET, newMETPhi);
                        
                        //###############################################################################################
                        //  dPhi Jet_MET Categorization
                        //###############################################################################################
                        const int size_jetMetPhi = 2;
                        bool lowDPhi = (deltaPhi(Jet4Momentum.Phi(),newMETPhi) < 0.5);
                        bool HighDPhi = (deltaPhi(Jet4Momentum.Phi(),newMETPhi) >= 0.5);
                        
                        bool jetMetPhi_category[size_jetMetPhi] = {lowDPhi,HighDPhi};
                        std::string jetMetPhi_Cat[size_jetMetPhi] = {"_LowDPhi", "_HighDPhi"};
                        
                        //###############################################################################################
                        //  LQ eta Categorization
                        //###############################################################################################
                        //                    const int size_lqEta = 3;
                        //                    bool BarrelLQ = (fabs(LQ4Momentum.Eta()) < 1.5);
                        //                    bool EndcapLQ = (fabs(LQ4Momentum.Eta()) >= 1.5 && fabs(LQ4Momentum.Eta()) <= 3 );
                        //                    bool TotLQ = fabs(LQ4Momentum.Eta()) <= 3;
                        //
                        //                    bool lqEta_category[size_lqEta] = {BarrelLQ,EndcapLQ,TotLQ};
                        //                    std::string lqEta_Cat[size_lqEta] = {"_Barrel", "_Endcap","_TotEta"};
                        const int size_lqEta = 1;
                        //                    bool BarrelLQ = (fabs(LQ4Momentum.Eta()) < 1.5);
                        //                    bool EndcapLQ = (fabs(LQ4Momentum.Eta()) >= 1.5 && fabs(LQ4Momentum.Eta()) <= 3 );
                        bool TotLQ = 1;
                        
                        bool lqEta_category[size_lqEta] = {TotLQ};
                        std::string lqEta_Cat[size_lqEta] = {""};
                        
                        
                        //###############################################################################################
                        //  TTbar & DY control region Categorization
                        //###############################################################################################
                        const int size_CR = 3;
                        bool signalRegion = numTau+numZboson + numMuon  < 1  && numBJet < 1;
                        //                    bool signalRegion = numTau+numZboson + numElectron  < 1;
                        bool TTcontrolRegion_DiLep = (numTau <1 && numZboson < 1 && numMuon > 0 && !isThisJetMuon );
                        if (TTcontrolRegion_DiLep) FinalBTagSF=1;
                        bool TTcontrolRegion_SingleLep = (numTau+numZboson + numMuon  < 1  && numBJet >= 1);
                        //                    bool DYcontrolRegion = (numTau <1 && numZboson > 0 && numElectron < 1 );
                        //                    bool region_category[size_CR] = {signalRegion,TTcontrolRegion,DYcontrolRegion};
                        //                    std::string region_Cat[size_CR] = {"", "_ttbarCR","_DYCR"};
                        bool region_category[size_CR] = {signalRegion,TTcontrolRegion_DiLep,TTcontrolRegion_SingleLep};
                        std::string region_Cat[size_CR] = {"", "_ttbarCRDiLep","_ttbarCRSingleLep"};
                        
                        //###############################################################################################
                        //  Top Pt Reweighting Cat: The SF is meant to correct only the shape of the pt(top) distribution- not the amount of generated events ( you have to consider that the average weight is not 1 ! ) So we define two category for ttbar events
                        
                        //###############################################################################################
                        int size_topPtRW =2;
                        
                        float TotalWeight[2] = {TotalWeight_withTopPtRW,TotalWeight_NoTopPtRW};
                        std::string topPtRW[2] = {"", "_NoTopRW"};
                        
                        if (isTTJets == string::npos) size_topPtRW = 1; // If the sample in not ttbar, don't care about new category
                        
                        //###############################################################################################
                        
                        
                        
                        
                        std::string CHL="EleJet";
                        
                        plotFill("Weight_Ele_i", ElectronCor_i,200,0,2);
                        plotFill("Weight_Ele_j", ElectronCor_j,200,0,2);
//                        plotFill("TotalWeight_Ele",TotalWeight[0]*ElectronCor,1000,0,10);
//                        plotFill("TotalNonLumiWeight_Ele",TotalWeight[0]*ElectronCor/LumiWeight,200,0,2);
                        
                        
                        for (int iso = 0; iso < size_isoCat; iso++) {
                            if (Iso_category[iso]) {
                                for (int imt = 0; imt < size_mTCat; imt++) {
                                    if (MT_category[imt]) {
                                        for (int jpt = 0; jpt < size_jetMetPhi; jpt++) {
                                            if (jetMetPhi_category[jpt]) {
                                                for (int ieta = 0; ieta < size_lqEta; ieta++) {
                                                    if (lqEta_category[ieta]) {
                                                        for (int iCR = 0; iCR < size_CR; iCR++) {
                                                            if (region_category[iCR]) {
                                                                for (int itopRW = 0; itopRW < size_topPtRW; itopRW++) {
                                                                    
                                                                    
                                                                    float FullWeight = TotalWeight[itopRW] * ElectronCor_i * ElectronCor_j * FinalBTagSF;
                                                                    std::string FullStringName = topPtRW[itopRW] + MT_Cat[imt] + jetMetPhi_Cat[jpt] + lqEta_Cat[ieta] + region_Cat[iCR] + iso_Cat[iso]  ;
                                                                    
                                                                    
                                                                    
                                                                    //##################
                                                                    //This check is used to make sure that each event is just filled once for any of the categories ==> No doube-counting of events  (this is specially important for ttbar events where we have many jets and leptons)
                                                                    if (!( std::find(HistNamesFilled.begin(), HistNamesFilled.end(), FullStringName) != HistNamesFilled.end())){
                                                                        HistNamesFilled.push_back(FullStringName);
                                                                        
                                                                        plotFill(CHL+"_tmass_EleMet"+FullStringName,tmass_EleMet,200,0,2000,FullWeight);
                                                                        plotFill(CHL+"_MET"+FullStringName,newMET,200,0,2000,FullWeight);
                                                                        
                                                                        plotFill(CHL+"_JetPt"+FullStringName,jetPt->at(ijet) ,2000,0,2000,FullWeight);
                                                                        plotFill(CHL+"_JetEta"+FullStringName,jetEta->at(ijet),120,-3,3,FullWeight);
                                                                        plotFill(CHL+"_LepPt"+FullStringName,GoodElectron.Pt(),2000,0,2000,FullWeight);
                                                                        plotFill(CHL+"_LepEta"+FullStringName,GoodElectron.Eta(),100,-2.5,2.5,FullWeight);
                                                                        //                                                                    plotFill(CHL+"_CloseJetLepPt"+FullStringName,CLoseJetMuPt,1000,0,1000,FullWeight);
                                                                        
                                                                        
                                                                        plotFill(CHL+"_LQMass"+FullStringName,LQ4Momentum.M(),200,0,2000,FullWeight);
                                                                        plotFill(CHL+"_ZMass"+FullStringName,DiEle4Momentum.M(),200,0,200,FullWeight);
                                                                        plotFill(CHL+"_WMass"+FullStringName,newDiEle4Momentum.M(),200,0,200,FullWeight);
                                                                        
                                                                        
                                                                        
                                                                        
                                                                        plotFill(CHL+"_dPhi_Jet_Met"+FullStringName,deltaPhi(Jet4Momentum.Phi(),newMETPhi),160,0,3.2,FullWeight);
                                                                        plotFill(CHL+"_dPhi_Ele_Met"+FullStringName,deltaPhi(GoodElectron.Phi(),newMETPhi),160,0,3.2,FullWeight);
                                                                        plotFill(CHL+"_dPhi_Ele_Jet"+FullStringName,deltaPhi(GoodElectron.Phi(),Jet4Momentum.Phi()),160,0,3.2,FullWeight);
                                                                        
                                                                        plotFill(CHL+"_BosonKFactor"+FullStringName,ZBosonKFactor*WBosonKFactor,200,0,2,FullWeight);
                                                                        plotFill(CHL+"_WBosonPt"+FullStringName,WBosonPt,150,0,1500,FullWeight);
                                                                        plotFill(CHL+"_ZBosonPt"+FullStringName,ZBosonPt,150,0,1500,FullWeight);
                                                                        plotFill("_FinalBTagSF"+FullStringName, FinalBTagSF,200,0,2);
                                                                        
                                                                    }
                                                                }
                                                                
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    //###############################################################################################
                    //  Doing EleTau Analysis
                    //###############################################################################################
                    
                    
                } //End of Tree
            }//End of file
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
    
    fout->Close();
    
    
}
