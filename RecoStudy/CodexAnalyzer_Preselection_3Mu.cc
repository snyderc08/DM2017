////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  This code is to pre-select the events. This ise used as a base for background estimation, ...
// To run this code one first needs to compile it:
//1) ./Mask.sh   CodexAnalyzer_Preselection.cc
//2)  ./CodexAnalyzer_Preselection.exe  output.root   input.root
// To run this on all data and MC samples run the following:
// source RunFullSamples_PreSelection.sh
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    TH2F * HistoEleMVAIdIso90_EffMC= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_EffMC2D");
    TH2F * HistoEleMVAIdIso90_EffData= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_EffData2D");
    
    //########################################
    // W and DY K-factor files  (Bin-based K-factor)
    //########################################
    //    TFile * KFactor= TFile::Open("../interface/pileup-hists/kfactors.root");
    //    TH1F * WLO= (TH1F *) KFactor->Get("WJets_LO/inv_pt");
    //    TH1F * WNLO_ewk= (TH1F *) KFactor->Get("EWKcorr/W");
    //    TH1F * ZLO= (TH1F *) KFactor->Get("ZJets_LO/inv_pt");
    //    TH1F * ZNLO_ewk= (TH1F *) KFactor->Get("EWKcorr/Z");
    //  The above root is the old one from MonoJet   (it is similar to the following ones)
    
    
    TFile * KFactor= TFile::Open("../interface/NewKFactor/kfactor_vjet_qcd/kfactor_24bins.root");
    
    TH1F * WLO= (TH1F *) KFactor->Get("WJets_LO/inv_pt");
    TH1F * WNLO_ewk= (TH1F *) KFactor->Get("EWKcorr/W");
    TH1F * WNLO_qcd= (TH1F *) KFactor->Get("WJets_012j_NLO/nominal");
    
    TH1F * ZLO= (TH1F *) KFactor->Get("DYJets_LO/inv_pt");
    TH1F * ZNLO_ewk= (TH1F *) KFactor->Get("EWKcorr/DY");
    TH1F * ZNLO_qcd= (TH1F *) KFactor->Get("DYJets_012j_NLO/nominal");
    
    
    //        std::string ROOTLoc= "/Users/abdollah1/GIT_abdollah110/DM2016/ROOT80X/";
    //        vector<float> DY_Events = DY_HTBin(ROOTLoc);
    //        vector<float> W_Events = W_HTBin(ROOTLoc);
    //        vector<float> W_EventsNLO = W_PTBinNLO(ROOTLoc); //This is for the NLO samples (as the stat is too low we do not use them)
    //        vector<float> W_EventsNLO = W_HTBin(ROOTLoc);
    
    
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
    // Btagging scale factor and uncertainties
    //########################################
    
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
    
    
    
    //###############################################################################################
    //  Fix Parameters
    //###############################################################################################
    float MuMass= 0.10565837;
    float eleMass= 0.000511;
    float LeptonPtCut_=60;
    float TauPtCut_=20;
    float JetPtCut=100;
    float BJetPtCut=30;
    float SimpleJetPtCut=30;
    float ElectronPtCut_=15;
    float CSVCut=   0.9535   ;                  //  https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation80XReReco
    float LeptonIsoCut=0.15;
    
    //########################################################################################################################################################
    //########################################################################################################################################################
    //########################################################################################################################################################
    //########################################################################################################################################################
    //########################################################################################################################################################
    //                                                  Loop over inout ROOT files
    //########################################################################################################################################################
    //########################################################################################################################################################
    //########################################################################################################################################################
    //########################################################################################################################################################
    //########################################################################################################################################################
    for (int k = 0; k < input.size(); k++) {
        
        TFile *f_Double = TFile::Open(input[k].c_str());
        cout << "\n  Now is running on ------->   " << std::string(f_Double->GetName()) << "\n";
        
        std::string InputROOT= std::string(f_Double->GetName());
        TFile * myFile = TFile::Open(f_Double->GetName());
        TH1F * HistoTot = (TH1F*) myFile->Get("hcount");
        
        //        TTree *Run_Tree = (TTree*) f_Double->Get("ggNtuplizer/EventTree");
        TTree *Run_Tree = (TTree*) f_Double->Get("EventTree");
        
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(6);
        
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
        
        //########################################################################################################################################################
        //########################################################################################################################################################
        //########################################################################################################################################################
        //                                                  Loop over Events in each ROOT files
        //########################################################################################################################################################
        //########################################################################################################################################################
        //########################################################################################################################################################
        
        Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
        cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
        for (Int_t i = 0; i < nentries_wtn; i++) {
            //        for (Int_t i = 0; i < 100000; i++) {
            Run_Tree->GetEntry(i);
            if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
            fflush(stdout);
            
            
            //###############################################################################################
            //  MET Filters (only on Data)
            //###############################################################################################
            if (isData && (metFilters!=1536)) continue;
            
            //###############################################################################################
            //  This part is to avoid of the duplicate of mu-j pai from one events
            //###############################################################################################
            std::vector<string> HistNamesFilled;
            HistNamesFilled.clear();
            
            //###############################################################################################
            //  TOP pT Reweighting & W-Kfactor  & Z-Kfactor
            //###############################################################################################
            
            float GenTopPt=0;
            float GenAntiTopPt=0;
            float TopPtReweighting = 1;
            float WBosonPt=0;
            float WBosonKFactor=1;
            float ZBosonPt=0;
            float ZBosonKFactor=1;
            int modPDGId=-10;
            int AntimodPDGId=-10;
            
            TLorentzVector GenMu4Momentum,GenAntiMu4Momentum;
            
            for (int igen=0;igen < nMC; igen++){
                if (mcPID->at(igen) == 6 && mcStatus->at(igen) ==62) GenTopPt=mcPt->at(igen) ;
                if (mcPID->at(igen) == -6 && mcStatus->at(igen) ==62) GenAntiTopPt=mcPt->at(igen);
                if (fabs(mcPID->at(igen)) ==24   && mcStatus->at(igen) ==22)  WBosonPt= mcPt->at(igen); // In inclusive we have status 62||22||44 while in HTbins we have just 22
                if (fabs(mcPID->at(igen)) ==23)  ZBosonPt= mcPt->at(igen); //FIXME somethime we do not have Z in the DY events
                if ( mcPID->at(igen) ==13  )  {GenMu4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen)); modPDGId=mcMomPID->at(igen);}
                if ( mcPID->at(igen) ==-13  )  {GenAntiMu4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen)); AntimodPDGId=mcMomPID->at(igen);}
                
            }
            if (ZBosonPt ==0)
                ZBosonPt=(GenMu4Momentum+GenAntiMu4Momentum).Pt();  //This is a temp solution to the above problem
            
            //######################## Top Pt Reweighting
            size_t isTTJets = InputROOT.find("TTJets");
            if (isTTJets!= string::npos) TopPtReweighting = compTopPtWeight(GenTopPt, GenAntiTopPt);
            
            //######################## W K-factor
            size_t isWJets = InputROOT.find("WJets");
            //            if (isWJets!= string::npos) WBosonKFactor=Get_W_Z_BosonKFactor(WBosonPt,WLO,WNLO_ewk);  //Swtch ON only for LO Madgraph sample
            if (isWJets!= string::npos) WBosonKFactor= kf_W_1 + kf_W_2 * WBosonPt;
            
            //######################## Z K-factor
            size_t isDYJets = InputROOT.find("DYJets");
            //            if (isDYJets!= string::npos) ZBosonKFactor=Get_W_Z_BosonKFactor(ZBosonPt,ZLO,ZNLO_ewk);  //Swtch ON only for LO Madgraph sample
            if (isDYJets!= string::npos) ZBosonKFactor= kf_Z_1 + kf_Z_2 * ZBosonPt;
            
            //###############################################################################################
            //  Lumi, GEN & PileUp Weight
            //###############################################################################################
            
            float LumiWeight = 1;
            float GetGenWeight=1;
            float PUWeight = 1;
            
            if (!isData){
                
                //######################## Lumi Weight
                //                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT, genHT,WBosonPt, W_Events, DY_Events,W_EventsNLO);
                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT);
                
                //######################## Gen Weight
                GetGenWeight=genWeight;
                
                //######################## PileUp Weight
                int puNUmmc=int(puTrue->at(0)*10);
                int puNUmdata=int(puTrue->at(0)*10);
                float PUMC_=HistoPUMC->GetBinContent(puNUmmc+1);
                float PUData_=HistoPUData->GetBinContent(puNUmdata+1);
                if (PUMC_ ==0)
                    cout<<"PUMC_ is zero!!! & num pileup= "<< puTrue->at(0)<<"\n";
                else
                    PUWeight= PUData_/PUMC_;
                
            }
            
            
            //############################################################################################
            //   Final Total Weight
            //############################################################################################
            float TotalWeight_withTopPtRW = LumiWeight * GetGenWeight * PUWeight * TopPtReweighting * WBosonKFactor * ZBosonKFactor ;
            float TotalWeight_NoTopPtRW = LumiWeight * GetGenWeight * PUWeight * WBosonKFactor * ZBosonKFactor ;
            
            //###############################################################################################
            //###############################################################################################
            //###############################################################################################
            //                                      Doing  Analysis
            //###############################################################################################
            //###############################################################################################
            //###############################################################################################
            
            
            //###########       Trigger Requirement ###########################################################
            //            else if (name.find("HLT_IsoMu24_v")   != string::npos) bitEleMuX = 19;
            //            else if (name.find("HLT_IsoTkMu24_v") != string::npos) bitEleMuX = 20;
            
            bool PassTrigger = ((HLTEleMuX >> 20 & 1) == 1 || (HLTEleMuX >> 19 & 1) == 1 );
            
            if (! PassTrigger) continue;
            
            //###########       tau Veto   ###########################################################
            int numTau=0;
            //###########       Ele Veto   ###########################################################
            //            https://twiki.cern.ch/twiki/bin/view/CMS/MultivariateElectronIdentificationRun2#Recommended_MVA_recipes_for_2016
            int numElectron=0;
            //###########       bJet Veto   ###########################################################
            int numBJet=0;
            int numlightJet=0;
            float EffJet =1;
            float SF=1;
            float P_Data_P_mc=1;
            float FinalBTagSF=1;
            bool  METisCloseToJet=false;
            
            
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
            if (numBJet > 0) continue;
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
            //###########       Loop over MuJet events   #################################################
            //############################################################################################
            TLorentzVector Mui_4Momentum, Muj_4Momentum,Muk_4Momentum;
            
            for  (int imu=0 ; imu < nMu; imu++){
                
                float IsoMu_i=muPFChIso->at(imu)/muPt->at(imu);
                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                    IsoMu_i= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                
                bool MuPtCut_i = muPt->at(imu) > 30 && fabs(muEta->at(imu)) < 2.4 ;
                bool MuIdIso_i=( (muIDbit->at(imu) >> 2 & 1) && IsoMu_i < 0.15); //Tight Muon Id
                
                
                if (! MuPtCut_i || !MuIdIso_i ) continue;
                
                float MuonCor_i=getCorrFactorMuon80X_TriMu(isData,  muPt->at(imu), muEta->at(imu) , HistoMuId,HistoMuIso,HistoMuTrg,HistoMuTrack);
                Mui_4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
                
            
                for  (int jmu=imu+1 ; jmu < nMu; jmu++){
                    
                    float IsoMu_j=muPFChIso->at(jmu)/muPt->at(jmu);
                    if ( (muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu) )  > 0.0)
                        IsoMu_j= ( muPFChIso->at(jmu)/muPt->at(jmu) + muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu))/muPt->at(jmu);
                    
                    bool MuPtCut_j = muPt->at(jmu) > 30 && fabs(muEta->at(jmu)) < 2.4 ;
                    bool MuIdIso_j=( (muIDbit->at(jmu) >> 2 & 1) && IsoMu_j < 0.15); //Tight Muon Id
                    
                    
                    if (! MuPtCut_j || !MuIdIso_j ) continue;
                    
                    float MuonCor_j=getCorrFactorMuon80X_TriMu(isData,  muPt->at(jmu), muEta->at(jmu) , HistoMuId,HistoMuIso,HistoMuTrg,HistoMuTrack);
                    Muj_4Momentum.SetPtEtaPhiM(muPt->at(jmu),muEta->at(jmu),muPhi->at(jmu),MuMass);
                    
                    
                    for  (int kmu=jmu+1 ; kmu < nMu; kmu++){
                        
                        float IsoMu_k=muPFChIso->at(kmu)/muPt->at(kmu);
                        if ( (muPFNeuIso->at(kmu) + muPFPhoIso->at(kmu) - 0.5* muPFPUIso->at(kmu) )  > 0.0)
                            IsoMu_k= ( muPFChIso->at(kmu)/muPt->at(kmu) + muPFNeuIso->at(kmu) + muPFPhoIso->at(kmu) - 0.5* muPFPUIso->at(kmu))/muPt->at(kmu);
                        
                        bool MuPtCut_k = muPt->at(kmu) > 10 && fabs(muEta->at(kmu)) < 2.4 ;
                        bool MuIdIso_k=( (muIDbit->at(kmu) >> 2 & 1) && IsoMu_k < 0.15); //Tight Muon Id
                        
                        
                        if (! MuPtCut_k || !MuIdIso_k ) continue;
                        
                        float MuonCor_k=getCorrFactorMuon80X_TriMu(isData,  muPt->at(kmu), muEta->at(kmu) , HistoMuId,HistoMuIso,HistoMuTrg,HistoMuTrack);
                        Muk_4Momentum.SetPtEtaPhiM(muPt->at(kmu),muEta->at(kmu),muPhi->at(kmu),MuMass);
                        
                    
                        float M_ij=100;
                        float M_ik=100;
                        float M_jk=100;
                        float M_Zboson=0;
                        float M_Wboson=0;
                        
                        if (muCharge->at(imu) * muCharge->at(jmu) < 0)  M_ij = fabs((Mui_4Momentum+Muj_4Momentum).M()-91);
                        if (muCharge->at(imu) * muCharge->at(kmu) < 0)  M_ik = fabs((Mui_4Momentum+Muk_4Momentum).M()-91);
                        if (muCharge->at(jmu) * muCharge->at(kmu) < 0)  M_jk = fabs((Muj_4Momentum+Muk_4Momentum).M()-91);
                        
                 
                        if (M_ij < M_ik && M_ij < M_jk) {M_Zboson=(Mui_4Momentum+Muj_4Momentum).M(); M_Wboson=TMass_F(Muk_4Momentum.Pt(), Muk_4Momentum.Px(),Muk_4Momentum.Py() , pfMET, pfMETPhi);}
                        if (M_ik < M_ij && M_ik < M_jk) {M_Zboson=(Mui_4Momentum+Muk_4Momentum).M(); M_Wboson=TMass_F(Muj_4Momentum.Pt(), Muj_4Momentum.Px(),Muj_4Momentum.Py() , pfMET, pfMETPhi);}
                        if (M_jk < M_ij && M_jk < M_ik) {M_Zboson=(Muj_4Momentum+Muk_4Momentum).M(); M_Wboson=TMass_F(Mui_4Momentum.Pt(), Mui_4Momentum.Px(),Mui_4Momentum.Py() , pfMET, pfMETPhi);}
                    
                    
                    //###############################################################################################
                    //  Top Pt Reweighting Cat: The SF is meant to correct only the shape of the pt(top) distribution- not the amount of generated events ( you have to consider that the average weight is not 1 ! ) So we define two category for ttbar events
                    
                    //###############################################################################################
                    int size_topPtRW =2;
                    
                    float TotalWeight[2] = {TotalWeight_withTopPtRW,TotalWeight_NoTopPtRW};
                    std::string topPtRW[2] = {"", "_NoTopRW"};
                    
                    if (isTTJets == string::npos) size_topPtRW = 1; // If the sample in not ttbar, don't care about new category
                    
                    //###############################################################################################
                    
                    std::string CHL="TriMu";
                    
                    
                    
                    
                    
                                                    for (int itopRW = 0; itopRW < size_topPtRW; itopRW++) {
                                                        
                                                        
                                                        
                                                        ////////////////////////////////////   Naming the Histogram
                                                        float FullWeight = TotalWeight[itopRW] * MuonCor_i *MuonCor_j *MuonCor_k * FinalBTagSF;
                                                        std::string FullStringName = topPtRW[itopRW];
                                                        
                                                        
                                                        
                                                        //##################
                                                        //This check is used to make sure that each event is just filled once for any of the categories ==> No doube-counting of events  (this is specially important for ttbar events where we have many jets and leptons)
                                                        if (!( std::find(HistNamesFilled.begin(), HistNamesFilled.end(), FullStringName) != HistNamesFilled.end())){
                                                            HistNamesFilled.push_back(FullStringName);
                                                            //##################
                                                            
                                                            
                                                            plotFill("pfMET"+FullStringName, pfMET,500,0,500,FullWeight);
                                                            plotFill("M_Zboson"+FullStringName, M_Zboson,500,0,500,FullWeight);
                                                            plotFill("M_Wboson"+FullStringName, M_Wboson,500,0,500,FullWeight);
                                                            
                                                            
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
