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
        cout <<"INPUT NAME IS:   " << input[f - 2] << "\n";
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
    //    TH2F * HistoMuTrg_BCDEF= (TH2F *) MuCorrTrg_BCDEF->Get("Mu50_OR_TkMu50_PtEtaBins/pt_abseta_ratio");
    TH1F * HistoMuTrg_BCDEF= (TH1F *) MuCorrTrg_BCDEF->Get("Mu50_OR_TkMu50_EtaBins/eta_ratio");
    
    TFile * MuCorrTrg_GH= TFile::Open(("../interface/pileup-hists/Trigger_EfficienciesAndSF_Period4.root"));
    //    TH2F * HistoMuTrg_GH= (TH2F *) MuCorrTrg_GH->Get("Mu50_OR_TkMu50_PtEtaBins/pt_abseta_ratio");
    TH1F * HistoMuTrg_GH= (TH1F *) MuCorrTrg_GH->Get("Mu50_OR_TkMu50_EtaBins/eta_ratio");
    
    TFile * MuCorrTrack= TFile::Open(("../interface/pileup-hists/Tracking_EfficienciesAndSF_BCDEFGH.root"));
    TGraphAsymmErrors * HistoMuTrack= (TGraphAsymmErrors *) MuCorrTrack->Get("ratio_eff_eta3_dr030e030_corr");
    
    TH2F* HistoMuId[2]={HistoMuId_BCDEF, HistoMuId_GH};
    TH2F* HistoMuIso[2]={HistoMuIso_BCDEF,HistoMuIso_GH};
    TH1F* HistoMuTrg[2]={HistoMuTrg_BCDEF, HistoMuTrg_GH};
    
    //########################################
    // Electron MVA IdIso files and now trigger from https://github.com/CMS-HTT/LeptonEfficiencies/tree/master/Electron
    //########################################
    TFile * EleCorrMVAIdIso90= TFile::Open(("../interface/pileup-hists/egammaEffi.txt_EGM2D.root"));
    TH2F * HistoEleMVAIdIso90= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_SF2D");
    TH2F * HistoEleMVAIdIso90_EffMC= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_EffMC2D");
    TH2F * HistoEleMVAIdIso90_EffData= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_EffData2D");
    
    
    TFile * EleCorrMVAIdIso80= TFile::Open(("../interface/pileup-hists/egammaEffi.txt_EGM2D_Tight.root"));
    TH2F * HistoEleMVAIdIso80= (TH2F *) EleCorrMVAIdIso80->Get("EGamma_SF2D");
    TH2F * HistoEleMVAIdIso80_EffMC= (TH2F *) EleCorrMVAIdIso80->Get("EGamma_EffMC2D");
    TH2F * HistoEleMVAIdIso80_EffData= (TH2F *) EleCorrMVAIdIso80->Get("EGamma_EffData2D");
    
    
    
    TFile * Ele25WPTightTrigger= TFile::Open("../interface/pileup-hists/ElectronTriger2016BToH_Ele25WPTight_eff.root");
    
    TGraphAsymmErrors * EleTrgEffLt1p48_MC= (TGraphAsymmErrors *) Ele25WPTightTrigger->Get("ZMassEtaLt1p48_MC");
    TGraphAsymmErrors * EleTrgEff1p48to2p1_MC= (TGraphAsymmErrors *) Ele25WPTightTrigger->Get("ZMassEta1p48to2p1_MC");
    TGraphAsymmErrors * EleTrgEffGt2p1_MC= (TGraphAsymmErrors *) Ele25WPTightTrigger->Get("ZMassEtaGt2p1_MC");
    
    TGraphAsymmErrors * EleTrgEffLt1p48_Data= (TGraphAsymmErrors *) Ele25WPTightTrigger->Get("ZMassEtaLt1p48_Data");
    TGraphAsymmErrors * EleTrgEff1p48to2p1_Data= (TGraphAsymmErrors *) Ele25WPTightTrigger->Get("ZMassEta1p48to2p1_Data");
    TGraphAsymmErrors * EleTrgEffGt2p1_Data= (TGraphAsymmErrors *) Ele25WPTightTrigger->Get("ZMassEtaGt2p1_Data");
    
    
    TGraphAsymmErrors* HistoEleTrg[6]={EleTrgEffLt1p48_MC, EleTrgEff1p48to2p1_MC,EleTrgEffGt2p1_MC,EleTrgEffLt1p48_Data,EleTrgEff1p48to2p1_Data, EleTrgEffGt2p1_Data};
    
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
    
    
    std::string ROOTLocHT= "/Users/abdollah1/GIT_abdollah110/DM2017/ROOT80X/SampleLQ1/";
//    std::string ROOTLocMass= "/Users/abdollah1/GIT_abdollah110/DM2017/ROOT80X/SampleLQ1/";
    //        vector<float> DY_Events = DY_HTBin(ROOTLoc);
    vector<float> W_HTBinROOTFiles = W_HTBin(ROOTLocHT);
    vector<float> W_MassBinROOTFiles = W_MassBin(ROOTLocHT);
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
    
    
    TFile * MassDepKFactor=TFile::Open("../interface/k_fakNNLO_use_Ele.root");
    TH1F* HistMassDepKFactor= (TH1F*) MassDepKFactor->Get("k_fak_mean");
    //    TH1F* HistMassDepKFactor= (TH1F*) MassDepKFactor->Get("k_fakm");
    
    
    
    
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
    float EleMass= 0.000511;
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
            float WBosonMass=0;
            
            TLorentzVector GenMu4Momentum,GenAntiMu4Momentum, WGEN4Momentum, MUGEN4Momentum, NUGEN4Momentum;
            vector <TLorentzVector> LepFromW;
            vector <TLorentzVector> NuetrinoFromW;
            for (int igen=0;igen < nMC; igen++){
                
                //Top pt correction
                if (mcPID->at(igen) == 6 && mcStatus->at(igen) ==62) GenTopPt=mcPt->at(igen) ;
                if (mcPID->at(igen) == -6 && mcStatus->at(igen) ==62) GenAntiTopPt=mcPt->at(igen);
                
                //W Mass
                if (fabs(mcPID->at(igen)) ==24   && mcStatus->at(igen) ==22)  {WBosonPt= mcPt->at(igen); WBosonMass=mcMass->at(igen);}
                if ( fabs(mcPID->at(igen)) ==11 && mcStatus->at(igen) ==1 )  {MUGEN4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));LepFromW.push_back(MUGEN4Momentum);}
                if ( fabs(mcPID->at(igen)) ==12  && mcStatus->at(igen) ==1)  {NUGEN4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));NuetrinoFromW.push_back(NUGEN4Momentum);}
                
                //DY sample
                if (fabs(mcPID->at(igen)) ==23)  ZBosonPt= mcPt->at(igen); //FIXME somethime we do not have Z in the DY events
                if ( mcPID->at(igen) ==11  )  {GenMu4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));}
                if ( mcPID->at(igen) ==-11  )  {GenAntiMu4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));}
                
                
            }
            
            if (LepFromW.size()> 0 && NuetrinoFromW.size()>0)
                WGEN4Momentum=LepFromW[0]+NuetrinoFromW[0];
            
            if (ZBosonPt ==0)
                ZBosonPt=(GenMu4Momentum+GenAntiMu4Momentum).Pt();  //This is a temp solution to the above problem
            
            if (WBosonPt==0)
                WBosonPt = WGEN4Momentum.Pt();
            
            
            //######################## Top Pt Reweighting
            size_t isTTJets = InputROOT.find("TTJets");
            if (isTTJets!= string::npos) TopPtReweighting = compTopPtWeight(GenTopPt, GenAntiTopPt);
            
            //######################## W K-factor
            size_t isWJetsToLNu_Inc = InputROOT.find("WJetsToLNu_Inc");
            size_t isWJets = InputROOT.find("WJets");
            size_t isWToMuNu = InputROOT.find("WToLNu");
            
            //   if (isWJets!= string::npos) WBosonKFactor=Get_W_Z_BosonKFactor(WBosonPt,WLO,WNLO_ewk);  //Swtch ON only for LO Madgraph sample
            //            if (isWJets!= string::npos || isWToMuNu!= string::npos ) WBosonKFactor= kf_W_1 + kf_W_2 * WBosonPt;
            
            if (isWJets!= string::npos || isWToMuNu!= string::npos )WBosonKFactor=HistMassDepKFactor->GetBinContent(int(WBosonMass)/10 +1); //Mass binned K-factor
            
            //######################## Z K-factor
            size_t isDYJets = InputROOT.find("DYJets");
            //            if (isDYJets!= string::npos) ZBosonKFactor=Get_W_Z_BosonKFactor(ZBosonPt,ZLO,ZNLO_ewk);  //Swtch ON only for LO Madgraph sample
            if (isDYJets!= string::npos) ZBosonKFactor= kf_Z_1 + kf_Z_2 * ZBosonPt;
            
            
            
            //................................................................................................................
            //................................................................................................................
            if (isWJets!= string::npos && WBosonMass > 100) continue;
            if (isWJetsToLNu_Inc!= string::npos && genHT > 70.0) continue;
            
            //................................................................................................................
            //................................................................................................................
            //###############################################################################################
            //  Lumi, GEN & PileUp Weight
            //###############################################################################################
            
            float LumiWeight = 1;
            float GetGenWeight=1;
            float PUWeight = 1;
            
            if (!isData){
                
                //######################## Lumi Weight
                //                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT, genHT,WBosonPt, W_Events, DY_Events,W_EventsNLO);
                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT,genHT, W_HTBinROOTFiles, WBosonMass, W_MassBinROOTFiles);
                
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
            //            bool PassTrigger = (HLTEleMuX >> 21 & 1) == 1; //   else if (name.find("HLT_Mu50_v") != string::npos) bitEleMuX = 21;
            //            else if (name.find("HLT_Ele27_eta2p1_WPTight_Gsf_v")                      != string::npos) bitEleMuX =  1;
            //            else if (name.find("HLT_Ele27_eta2p1_WPLoose_Gsf_v")                      != string::npos) bitEleMuX =  2;
            //            else if (name.find("HLT_Ele32_eta2p1_WPTight_Gsf_v")                      != string::npos) bitEleMuX =  3;
            //            else if (name.find("HLT_Ele27_WPTight_Gsf_v")                             != string::npos) bitEleMuX =  4;
            
            bool PassTrigger = ((HLTEleMuX >> 0 & 1) == 1);
            
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
            //            https://twiki.cern.ch/twiki/bin/view/CMS/MultivariateElectronIdentificationRun2#Recommended_MVA_recipes_for_2016
            int numMuon=0;
            float ElectronCor=1;
            float MuonCor=1;
            TLorentzVector Mu4Momentum;
            float ElectronEffVeto=1;
            Mu4Momentum.SetPtEtaPhiM(0,0,0,0);
            
            
            for  (int imu=0 ; imu < nMu; imu++){
                
                float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                    IsoMu= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                
                bool MuPtCut = muPt->at(imu) > 15 && fabs(muEta->at(imu)) < 2.4 ;
                bool MuIdIso=( (muIDbit->at(imu) >> 2 & 1)  && fabs(muD0->at(imu)) < 0.045 && fabs(muDz->at(imu)) < 0.2 && IsoMu < 0.15); //Tight Muon Id
                
                
                if (! MuPtCut || !MuIdIso ) continue;
                
                Mu4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
                numMuon++;
                //            float MuonCor=getCorrFactorMuon80X(isData,  muPt->at(imu), muEta->at(imu) , HistoMuId,HistoMuIso,HistoMuTrg,HistoMuTrack);
                break;
                
            }
            
            
            
            
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
            if (nEle > 1){
                TLorentzVector Ele4Momentum_1,Ele4Momentum_0,Z4Momentum;
                Ele4Momentum_0.SetPtEtaPhiM(elePt->at(0),eleEta->at(0),elePhi->at(0),EleMass);
                Ele4Momentum_1.SetPtEtaPhiM(elePt->at(1),eleEta->at(1),elePhi->at(1),EleMass);
                Z4Momentum=Ele4Momentum_1+Ele4Momentum_0;
                
                
                
                bool eleMVA_i= false;
                if (fabs (eleSCEta->at(0)) <= 0.8 && eleIDMVA->at(0) >   0.941  ) eleMVA_i= true;
                else if (fabs (eleSCEta->at(0)) >  0.8 &&fabs (eleSCEta->at(0)) <=  1.5 && eleIDMVA->at(0) >   0.899  ) eleMVA_i= true;
                else if ( fabs (eleSCEta->at(0)) >=  1.5 && eleIDMVA->at(0) >  0.758  ) eleMVA_i= true;
                else eleMVA_i= false;
                
                
                bool eleMVA_j= false;
                if (fabs (eleSCEta->at(1)) <= 0.8 && eleIDMVA->at(1) >   0.941  ) eleMVA_j= true;
                else if (fabs (eleSCEta->at(1)) >  0.8 &&fabs (eleSCEta->at(1)) <=  1.5 && eleIDMVA->at(1) >   0.899  ) eleMVA_j= true;
                else if ( fabs (eleSCEta->at(1)) >=  1.5 && eleIDMVA->at(1) >  0.758  ) eleMVA_j= true;
                else eleMVA_j= false;
                
                
                
                if ( elePt->at(0) > 60 && elePt->at(1) > 15 && fabs(eleEta->at(0)) < 2.5 && fabs(eleEta->at(1)) < 2.5 && Z4Momentum.M() > 80 && Z4Momentum.M()< 100 && eleMVA_i && eleMVA_j ) numZboson++;
            }
            
            
            
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
            //###########       Loop over EleJet events   #################################################
            //############################################################################################
            TLorentzVector Ele4Momentum, Jet4Momentum,KJet4Momentum,LQ4Momentum,Mu24Momentum;
            
            
            
            
            for  (int iele=0 ; iele < nEle; iele++){
                
                if ( elePt->at(iele) < 60 || fabs(eleEta->at(iele)) > 2.1) continue;
                
                //                cout <<elePt->at(iele)  << "     "  << eleIDMVA->at(iele)  <<"\n";
                
                bool eleMVAIdExtra= false;
                if (fabs (eleSCEta->at(iele)) <= 0.8 && eleIDMVA->at(iele) >   0.941  ) eleMVAIdExtra= true;
                else if (fabs (eleSCEta->at(iele)) >  0.8 &&fabs (eleSCEta->at(iele)) <=  1.5 && eleIDMVA->at(iele) >   0.899  ) eleMVAIdExtra= true;
                else if ( fabs (eleSCEta->at(iele)) >=  1.5 && eleIDMVA->at(iele) >  0.758  ) eleMVAIdExtra= true;
                else eleMVAIdExtra= false;
                
                
                
                if (!(eleMVAIdExtra )) continue;
                
                
                ElectronCor=getCorrFactorMVA80WPElectron80X(isData,  elePt->at(iele),eleSCEta->at(iele), HistoEleMVAIdIso80 ,HistoEleTrg);
                Ele4Momentum.SetPtEtaPhiM(elePt->at(iele),eleEta->at(iele),elePhi->at(iele),EleMass);
                
                
                
                //
                //
                //
                //                //###########      Finding the closest jet near mu   ###########################################################
                //                if (nMu > 1) Mu24Momentum.SetPtEtaPhiE(muPt->at(1), muEta->at(1), muPhi->at(1), MuMass);
                //
                //                float CLoseJetMuPt=muPt->at(imu);
                //                float CLoseJetMuEta=muEta->at(imu);
                //
                //                if (MuPtCut && MuIdIso ){
                //
                //                    double Refer_R_jetmu = 5;
                //
                //                    for (int kjet= 0 ; kjet < nJet ; kjet++){
                //                        KJet4Momentum.SetPtEtaPhiE(jetPt->at(kjet),jetEta->at(kjet),jetPhi->at(kjet),jetEn->at(kjet));
                //
                //
                //                        if (KJet4Momentum.DeltaR(Mu4Momentum) < Refer_R_jetmu) {
                //                            Refer_R_jetmu = KJet4Momentum.DeltaR(Mu4Momentum);
                //                            if (Refer_R_jetmu < 0.5 && jetPt->at(kjet)  >= muPt->at(imu)) {
                //                                CLoseJetMuPt = jetPt->at(kjet);
                //                                CLoseJetMuEta = jetEta->at(kjet);
                //
                //                            }
                //                        }
                //                    }
                //                }
                
                
                //###########    Compute recoHT and ST  ###########################################################
                float recoHT=0;
                
                for (int kjet= 0 ; kjet < nJet ; kjet++){
                    
                    KJet4Momentum.SetPtEtaPhiE(jetPt->at(kjet),jetEta->at(kjet),jetPhi->at(kjet),jetEn->at(kjet));
                    if (jetPFLooseId->at(kjet) > 0.5 && jetPt->at(kjet) > 30 && fabs(jetEta->at(kjet)) < 2.4 && KJet4Momentum.DeltaR(Ele4Momentum) > 0.5)
                        recoHT += jetPt->at(kjet);
                }
                float ST=recoHT+elePt->at(iele);
                
                
                //###########    loop over  Jet    ###########################################################
                
                for (int ijet= 0 ; ijet < nJet ; ijet++){
                    
                    Jet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                    
                    
                    bool goodJet = (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > JetPtCut && fabs(jetEta->at(ijet)) < 2.4 && Jet4Momentum.DeltaR(Ele4Momentum) > 0.5);
                    if (! goodJet) continue;
                    
                    LQ4Momentum=Jet4Momentum + Ele4Momentum;
                    
//                    bool isThisJetMuon= Jet4Momentum.DeltaR(Mu4Momentum) < 0.5;
                    //###############################################################################################
                    //  Isolation Categorization
                    //###############################################################################################
                    bool LepPassIsolation= 1;
                    
                    const int size_isoCat = 1;
                    bool Isolation = LepPassIsolation;
                    //                    bool AntiIsolation =  !LepPassIsolation;
                    //                    bool Total = 1;
                    
                    bool Iso_category[size_isoCat] = {Isolation};
                    std::string iso_Cat[size_isoCat] = {"_Iso"};
                    //###############################################################################################
                    //  MT Categorization
                    //###############################################################################################
                    float tmass_eleMet= TMass_F(elePt->at(iele), elePt->at(iele)*cos(elePhi->at(iele)),elePt->at(iele)*sin(elePhi->at(iele)) , pfMET, pfMETPhi);
                    float tmass_JetMet= TMass_F(jetPt->at(ijet), jetPt->at(ijet)*cos(jetPhi->at(ijet)),jetPt->at(ijet)*sin(jetPhi->at(ijet)) , pfMET, pfMETPhi);
                    float tmass_LQMet= TMass_F(LQ4Momentum.Pt(), LQ4Momentum.Px(),LQ4Momentum.Py(), pfMET, pfMETPhi);
                    
                    
                    //                    const int size_mTCat = 11;
                    const int size_mTCat = 5;
                    //
                    //                    bool NoMT = 1;
                    //                    bool HighMT = (tmass_eleMet > 100);
                    //                    bool MT50To150=(tmass_eleMet > 50 && tmass_eleMet <= 150);
                    //                    bool MT150To200=(tmass_eleMet > 150 && tmass_eleMet <= 200);
                    //                    bool MT200To250=(tmass_eleMet > 200 && tmass_eleMet <= 250);
                    //                    bool MT250To300=(tmass_eleMet > 250 && tmass_eleMet <= 300);
                    //                    bool MT300To350=(tmass_eleMet > 300 && tmass_eleMet <= 350);
                    //                    bool MTMore200=tmass_eleMet > 200 ;
                    //                    bool MTMore300=tmass_eleMet > 300 ;
                    //                    bool MTMore400=tmass_eleMet > 400 ;
                    //                    bool MTMore500=tmass_eleMet > 500 ;
                    
                    bool NoMT = 1;
                    bool HighMT = (tmass_eleMet > 100);
                    bool MT50To150=(tmass_eleMet > 50 && tmass_eleMet <= 150);
                    //                    bool MT150To200=(tmass_eleMet > 150 && tmass_eleMet <= 200);
                    //                    bool MT200To250=(tmass_eleMet > 200 && tmass_eleMet <= 250);
                    //                    bool MT250To300=(tmass_eleMet > 250 && tmass_eleMet <= 300);
                    //                    bool MT300To350=(tmass_eleMet > 300 && tmass_eleMet <= 350);
                    //                    bool MTMore200=tmass_eleMet > 200 ;
                    bool MTMore300=tmass_eleMet > 300 ;
                    //                    bool MTMore400=tmass_eleMet > 400 ;
                    bool MTMore500=tmass_eleMet > 500 ;
                    
                    
                    //                    bool MT_category[size_mTCat] = {NoMT,HighMT,MT50To150,MT150To200,MT200To250,MT250To300,MT300To350,MTMore200,MTMore300,MTMore400,MTMore500};
                    //                    std::string MT_Cat[size_mTCat] = {"_NoMT","_HighMT","_MT50To150","_MT150to200","_MT200to250","_MT250to300","_MT300to350","_MT200","_MT300","_MT400","_MT500"};
                    bool MT_category[size_mTCat] = {NoMT,HighMT,MT50To150,MTMore300,MTMore500};
                    std::string MT_Cat[size_mTCat] = {"_NoMT","_HighMT","_MT50To150","_MT300","_MT500"};

                    //###############################################################################################
                    //  dPhi Jet_MET Categorization
                    //###############################################################################################
                    const int size_jetMetPhi = 1;
//                    bool lowDPhi = (deltaPhi(Jet4Momentum.Phi(),pfMETPhi) < 0.5 || deltaPhi(Ele4Momentum.Phi(),pfMETPhi) < 0.5 );
                    bool HighDPhi = (deltaPhi(Jet4Momentum.Phi(),pfMETPhi) >= 0.5 && deltaPhi(Ele4Momentum.Phi(),pfMETPhi) >= 0.5  );
                    
//                    bool jetMetPhi_category[size_jetMetPhi] = {lowDPhi,HighDPhi};
//                    std::string jetMetPhi_Cat[size_jetMetPhi] = {"_LowDPhi", "_HighDPhi"};
                    bool jetMetPhi_category[size_jetMetPhi] = {HighDPhi};
                    std::string jetMetPhi_Cat[size_jetMetPhi] = {"_HighDPhi"};
                    
                    //###############################################################################################
                    //  TTbar & DY control region Categorization
                    //###############################################################################################
                    const int size_CR = 3;
                    
                    bool signalRegion = numTau+numZboson + numMuon +numBJet < 1;
                    bool TTcontrolRegion_DiLep = (numTau <1 && numZboson < 1 && numMuon > 0);
                    if (TTcontrolRegion_DiLep) FinalBTagSF=1;
                    bool TTcontrolRegion_SingleLep = (numTau+numZboson + numMuon  < 1  && numBJet >= 1);
                    
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
                    
                    plotFill("Weight_ele", MuonCor,200,0,2);
                    plotFill("Weight_Ele", ElectronCor,200,0,2);
                    plotFill("TotalWeight_Mu",TotalWeight[0]*MuonCor,1000,0,10);
                    plotFill("TotalNonLumiWeight_Mu",TotalWeight[0]*MuonCor/LumiWeight,200,0,2);
                    
                    
                    for (int iso = 0; iso < size_isoCat; iso++) {
                        if (Iso_category[iso]) {
                            for (int imt = 0; imt < size_mTCat; imt++) {
                                if (MT_category[imt]) {
                                    for (int jpt = 0; jpt < size_jetMetPhi; jpt++) {
                                        if (jetMetPhi_category[jpt]) {
                                            for (int iCR = 0; iCR < size_CR; iCR++) {
                                                if (region_category[iCR]) {
                                                    for (int itopRW = 0; itopRW < size_topPtRW; itopRW++) {
                                                        
                                                        
                                                        
                                                        ////////////////////////////////////   Naming the Histogram
                                                        float FullWeight = TotalWeight[itopRW] * MuonCor *ElectronCor * FinalBTagSF;
                                                        std::string FullStringName = topPtRW[itopRW] + MT_Cat[imt] + jetMetPhi_Cat[jpt] +  region_Cat[iCR] + iso_Cat[iso]  ;
                                                        
                                                        if (LQ4Momentum.M() > 1100 && LQ4Momentum.M() < 1400 ){
//                                                            if (1){
                                                        
                                                            
                                                            //##################
                                                            //This check is used to make sure that each event is just filled once for any of the categories ==> No doube-counting of events  (this is specially important for ttbar events where we have many jets and leptons)
                                                            if (!( std::find(HistNamesFilled.begin(), HistNamesFilled.end(), FullStringName) != HistNamesFilled.end())){
                                                                HistNamesFilled.push_back(FullStringName);
                                                                //##################
                                                                //                                                            plotFill(CHL+"_ElectronEffVeto"+FullStringName,ElectronEffVeto,300,0,3);
                                                                plotFill(CHL+"_tmass_EleMet"+FullStringName,tmass_eleMet,200,0,2000,FullWeight);
                                                                plotFill(CHL+"_MET"+FullStringName,pfMET,200,0,2000,FullWeight);
                                                                plotFill(CHL+"_JetPt"+FullStringName,jetPt->at(ijet) ,2000,0,2000,FullWeight);
                                                                plotFill(CHL+"_JetEta"+FullStringName,jetEta->at(ijet),120,-3,3,FullWeight);
                                                                plotFill(CHL+"_LepPt"+FullStringName,elePt->at(iele),2000,0,2000,FullWeight);
                                                                plotFill(CHL+"_LepEta"+FullStringName,eleEta->at(iele),100,-2.5,2.5,FullWeight);
                                                                //                                                            plotFill(CHL+"_CloseJetLepPt"+FullStringName,CLoseJetelePt,2000,0,2000,FullWeight);
                                                                
                                                                //                                                                    plotFill(CHL+"_nVtx"+FullStringName,nVtx,50,0,50,FullWeight);
                                                                //                                                                    plotFill(CHL+"_nVtx_NoPU"+FullStringName,nVtx,50,0,50,FullWeight/ PUWeight);
                                                                
                                                                plotFill(CHL+"_tmass_LQMet"+FullStringName,tmass_LQMet,200,0,2000,FullWeight);
                                                                plotFill(CHL+"_LQMass"+FullStringName,LQ4Momentum.M(),200,0,2000,FullWeight);
                                                                plotFill(CHL+"_LQEta"+FullStringName,LQ4Momentum.Eta(),500,-5,5,FullWeight);
                                                                
                                                                plotFill(CHL+"_dPhi_Jet_Met"+FullStringName,deltaPhi(Jet4Momentum.Phi(),pfMETPhi),160,0,3.2,FullWeight);
                                                                plotFill(CHL+"_dPhi_Ele_Met"+FullStringName,deltaPhi(Ele4Momentum.Phi(),pfMETPhi),160,0,3.2,FullWeight);
                                                                //                                                            if (nEle > 1) plotFill(CHL+"_dPhi_Ele2_Met"+FullStringName,deltaPhi(Ele24Momentum.Phi(),pfMETPhi),160,0,3.2,FullWeight);
                                                                plotFill(CHL+"_dPhi_Ele_Jet"+FullStringName,deltaPhi(Ele4Momentum.Phi(),Jet4Momentum.Phi()),160,0,3.2,FullWeight);
                                                                
                                                                plotFill(CHL+"_BosonKFactor"+FullStringName,ZBosonKFactor*WBosonKFactor,200,0,2,FullWeight);
                                                                plotFill(CHL+"_WBosonPt"+FullStringName,WBosonPt,150,0,1500,FullWeight);
                                                                plotFill(CHL+"_ZBosonPt"+FullStringName,ZBosonPt,150,0,1500,FullWeight);
                                                                plotFill(CHL+"_NumJet"+FullStringName,numJet,10,0,10,FullWeight);
                                                                plotFill(CHL+"_NumBJet"+FullStringName,numBJet,10,0,10,FullWeight);
                                                                
                                                                
                                                                
                                                                plotFill(CHL+"_recoHT"+FullStringName,recoHT,300,0,3000,FullWeight);
                                                                plotFill(CHL+"_ST"+FullStringName,recoHT+elePt->at(iele),300,0,3000,FullWeight);
                                                                plotFill(CHL+"_dR_Mu_Jet"+FullStringName,Jet4Momentum.DeltaR(Ele4Momentum),500,0,5,FullWeight);
                                                                plotFill(CHL+"_dEta_Mu_Jet"+FullStringName,Jet4Momentum.Eta() - Ele4Momentum.Eta(),1000,-5,5,FullWeight);
                                                                
                                                                
                                                                
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
