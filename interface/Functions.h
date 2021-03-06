#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "math.h"
#include "TGaxis.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TInterpreter.h"
#include "TSystem.h"
#include "TNtuple.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TFrame.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include "TLorentzVector.h"
#include "../interface/CodexAnalyzer.h"
#include "../interface/WeightCalculator.h"
#include "../interface/Corrector.h"
#include "../interface/makeHisto.h"



float deltaPhi(float a, float b) {
    float result = a - b;
    while (result > M_PI) result -= 2 * M_PI;
    while (result <= -M_PI) result += 2 * M_PI;
    return fabs(result);
}

float TMass_F(float pt3lep, float px3lep, float py3lep, float met, float metPhi) {
    return sqrt(pow(pt3lep + met, 2) - pow(px3lep + met * cos(metPhi), 2) - pow(py3lep + met * sin(metPhi), 2));
}

float TMass_FNew(float pt3lep, float philep, float met, float metPhi) {
    return sqrt(2*pt3lep * met *(1-cos(deltaPhi(metPhi,philep))));
}



float dR_(float ieta, float iphi, float jeta, float jphi){
    
    float deta=ieta-jeta;
    float dphi=deltaPhi(iphi,jphi);
    return sqrt(pow(deta,2)+pow(dphi,2));
}




TTree *  Xttree( TFile * f_Double){
    
//            TTree *Run_Tree = (TTree*) f_Double->Get("ggNtuplizer/EventTree");
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
    Run_Tree->SetBranchAddress("mcStatusFlag",&mcStatusFlag);
    
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
    Run_Tree->SetBranchAddress("jetP4Smear",&jetP4Smear);
    Run_Tree->SetBranchAddress("jetP4SmearUp",&jetP4SmearUp);
    Run_Tree->SetBranchAddress("jetP4SmearDo",&jetP4SmearDo);
    
    
    //########################################   MET Info
    Run_Tree->SetBranchAddress("pfMET",&pfMET);
    Run_Tree->SetBranchAddress("pfMET_T1UESUp",&pfMET_T1UESUp);
    Run_Tree->SetBranchAddress("pfMET_T1UESDo",&pfMET_T1UESDo);
    Run_Tree->SetBranchAddress("pfMET_T1JESUp",&pfMET_T1JESUp);
    Run_Tree->SetBranchAddress("pfMET_T1JESDo",&pfMET_T1JESDo);
    
    Run_Tree->SetBranchAddress("pfMETPhi",&pfMETPhi);
    Run_Tree->SetBranchAddress("pfMETPhi_T1UESUp",&pfMETPhi_T1UESUp);
    Run_Tree->SetBranchAddress("pfMETPhi_T1UESDo",&pfMETPhi_T1UESDo);
    Run_Tree->SetBranchAddress("pfMETPhi_T1JESUp",&pfMETPhi_T1JESUp);
    Run_Tree->SetBranchAddress("pfMETPhi_T1JESDo",&pfMETPhi_T1JESDo);
    
    Run_Tree->SetBranchAddress("metFilters",&metFilters);
    Run_Tree->SetBranchAddress("genHT",&genHT);
    
    Run_Tree->SetBranchAddress("pdfSystWeight",&pdfSystWeight);
    Run_Tree->SetBranchAddress("pdfSystWeightId",&pdfSystWeightId);
    Run_Tree->SetBranchAddress("pdfWeight",&pdfWeight);
    
    
    return Run_Tree;
}





//########################################
// Pileup files
//########################################


TH1F *  HistPUData(){
    TFile * PUData= TFile::Open("../interface/pileup-hists/dataMoriondPU.root");
    TH1F * HistoPUData= (TH1F *) PUData->Get("pileup");
    HistoPUData->Scale(1.0/HistoPUData->Integral());
    return HistoPUData;
}



TH1F *  HistPUMC(){
    TFile * PUMC= TFile::Open("../interface/pileup-hists/mcMoriondPU.root");
    TH1F * HistoPUMC= (TH1F *) PUMC->Get("pileup");
    HistoPUMC->Scale(1.0/HistoPUMC->Integral());
    return HistoPUMC;
}


//########################################
// Muon Id, Iso, Trigger and Tracker Eff files
//########################################

TH2F**  FuncHistMuId(){
    
    TFile * MuCorrId_BCDEF= TFile::Open(("../interface/pileup-hists/ID_EfficienciesAndSF_BCDEF.root"));
    TH2F * HistoMuId_BCDEF= (TH2F *) MuCorrId_BCDEF->Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
    
    TFile * MuCorrId_GH= TFile::Open(("../interface/pileup-hists/ID_EfficienciesAndSF_GH.root"));
    TH2F * HistoMuId_GH= (TH2F *) MuCorrId_GH->Get("MC_NUM_TightID_DEN_genTracks_PAR_pt_eta/pt_abseta_ratio");
    
    static TH2F* HistoMuId[2]={HistoMuId_BCDEF, HistoMuId_GH};
    
    return  HistoMuId;
}


TH2F**  FuncHistMuIso(){
    
    TFile * MuCorrIso_BCDEF= TFile::Open(("../interface/pileup-hists/Iso_EfficienciesAndSF_BCDEF.root"));
    TH2F * HistoMuIso_BCDEF= (TH2F *) MuCorrIso_BCDEF->Get("TightISO_TightID_pt_eta/pt_abseta_ratio");
    
    TFile * MuCorrIso_GH= TFile::Open(("../interface/pileup-hists/Iso_EfficienciesAndSF_GH.root"));
    TH2F * HistoMuIso_GH= (TH2F *) MuCorrIso_GH->Get("TightISO_TightID_pt_eta/pt_abseta_ratio");
    
    static  TH2F* HistoMuIso[2]={HistoMuIso_BCDEF,HistoMuIso_GH};
    
    return HistoMuIso;
}



TH2F**  FuncHistMuTrigger(){
    
    TFile * MuCorrTrg_BCDEF= TFile::Open(("../interface/pileup-hists/Trigger_EfficienciesAndSF_RunBtoF.root"));
        TH2F * HistoMuTrg_BCDEF= (TH2F *) MuCorrTrg_BCDEF->Get("Mu50_OR_TkMu50_PtEtaBins/pt_abseta_ratio");
//    TH1F * HistoMuTrg_BCDEF= (TH1F *) MuCorrTrg_BCDEF->Get("Mu50_OR_TkMu50_EtaBins/eta_ratio");
    
    TFile * MuCorrTrg_GH= TFile::Open(("../interface/pileup-hists/Trigger_EfficienciesAndSF_Period4.root"));
        TH2F * HistoMuTrg_GH= (TH2F *) MuCorrTrg_GH->Get("Mu50_OR_TkMu50_PtEtaBins/pt_abseta_ratio");
//    TH1F * HistoMuTrg_GH= (TH1F *) MuCorrTrg_GH->Get("Mu50_OR_TkMu50_EtaBins/eta_ratio");
    
    static TH2F* HistoMuTrg[2]={HistoMuTrg_BCDEF, HistoMuTrg_GH};
    
    return HistoMuTrg;
}


TGraphAsymmErrors * FuncHistMuTrack(){
    
    TFile * MuCorrTrack= TFile::Open(("../interface/pileup-hists/Tracking_EfficienciesAndSF_BCDEFGH.root"));
    TGraphAsymmErrors * HistoMuTrack= (TGraphAsymmErrors *) MuCorrTrack->Get("ratio_eff_eta3_dr030e030_corr");
    
    return HistoMuTrack;
}




//########################################
// Electron MVA IdIso files
//########################################
TH2F * FuncHistEleMVAId(std::string type){
    
    
    TFile * EleCorrMVAIdIso90= TFile::Open(("../interface/pileup-hists/egammaEffi.txt_EGM2D.root"));
    TH2F * HistoEleMVAIdIso90= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_SF2D");
    TH2F * HistoEleMVAIdIso90_EffMC= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_EffMC2D");
    TH2F * HistoEleMVAIdIso90_EffData= (TH2F *) EleCorrMVAIdIso90->Get("EGamma_EffData2D");
    
    if (type.find("Tot") != string::npos)
        return HistoEleMVAIdIso90;
    else if (type.find("MC") != string::npos)
        return HistoEleMVAIdIso90_EffMC;
    else if (type.find("Data") != string::npos)
        return HistoEleMVAIdIso90_EffData;
    else
        return 0;
    
}




// Not Used anymore
//    TFile * KFactor= TFile::Open("../interface/NewKFactor/kfactor_vjet_qcd/kfactor_24bins.root");
//
//    TH1F * WLO= (TH1F *) KFactor->Get("WJets_LO/inv_pt");
//    TH1F * WNLO_ewk= (TH1F *) KFactor->Get("EWKcorr/W");
//    TH1F * WNLO_qcd= (TH1F *) KFactor->Get("WJets_012j_NLO/nominal");
//
//    TH1F * ZLO= (TH1F *) KFactor->Get("DYJets_LO/inv_pt");
//    TH1F * ZNLO_ewk= (TH1F *) KFactor->Get("EWKcorr/DY");
//    TH1F * ZNLO_qcd= (TH1F *) KFactor->Get("DYJets_012j_NLO/nominal");



//########################################
// Btagging scale factor and uncertainties
//########################################

TH2F **  FuncHistBTagSF(){
    TFile * TTEff= TFile::Open(("OutFiles_BTagSF/TTJets.root"));
    TH2F * TTSF0_btagged= (TH2F *) TTEff->Get("BSF_FLV0_Btagged");
    TH2F * TTSF0_total= (TH2F *) TTEff->Get("BSF_FLV0_Total");
    TH2F * TTSF5_btagged= (TH2F *) TTEff->Get("BSF_FLV5_Btagged");
    TH2F * TTSF5_total= (TH2F*) TTEff->Get("BSF_FLV5_Total");
    
    static TH2F * Btagg_TT[4]={TTSF0_btagged,TTSF0_total,TTSF5_btagged,TTSF5_total};
    
    return Btagg_TT;
}

//        TFile * DataEff= TFile::Open(("OutFiles_BTagSF/Data.root"));
//        TH2F * DataSF0_btagged= (TH2F *) DataEff->Get("BSF_FLV0_Btagged");
//        TH2F * DataSF0_total= (TH2F *) DataEff->Get("BSF_FLV0_Total");
//        TH2F * DataSF5_btagged= (TH2F *) DataEff->Get("BSF_FLV5_Btagged");
//        TH2F * DataSF5_total= (TH2F *) DataEff->Get("BSF_FLV5_Total");




//########################################
// W and DY K-factor files  (FIT-based K-factor)
//########################################

TFile * kfactorW=TFile::Open("../interface/kfactor_W.root");
TH1F* HistkfactorW= (TH1F*) kfactorW->Get("KFcator");
float kf_W_1=HistkfactorW->GetBinContent(1);
float kf_W_2=HistkfactorW->GetBinContent(2);


TFile * kfactorWUp=TFile::Open("../interface/kfactor_monoJet_WUp.root");
TH1F* HistkfactorWUp= (TH1F*) kfactorWUp->Get("KFcator");
float kf_W_1Up=HistkfactorWUp->GetBinContent(1);
float kf_W_2Up=HistkfactorWUp->GetBinContent(2);

TFile * kfactorWDown=TFile::Open("../interface/kfactor_monoJet_WDown.root");
TH1F* HistkfactorWDown= (TH1F*) kfactorWDown->Get("KFcator");
float kf_W_1Down=HistkfactorWDown->GetBinContent(1);
float kf_W_2Down=HistkfactorWDown->GetBinContent(2);



TFile * kfactorZ=TFile::Open("../interface/kfactor_Z.root");
TH1F* HistkfactorZ= (TH1F*) kfactorZ->Get("KFcator");
float kf_Z_1=HistkfactorZ->GetBinContent(1);
float kf_Z_2=HistkfactorZ->GetBinContent(2);


TFile * kfactorZUp=TFile::Open("../interface/kfactor_monoJet_ZUp.root");
TH1F* HistkfactorZUp= (TH1F*) kfactorZUp->Get("KFcator");
float kf_Z_1Up=HistkfactorZUp->GetBinContent(1);
float kf_Z_2Up=HistkfactorZUp->GetBinContent(2);

TFile * kfactorZDown=TFile::Open("../interface/kfactor_monoJet_ZDown.root");
TH1F* HistkfactorZDown= (TH1F*) kfactorZDown->Get("KFcator");
float kf_Z_1Down=HistkfactorZDown->GetBinContent(1);
float kf_Z_2Down=HistkfactorZDown->GetBinContent(2);



float FuncBosonKFactor(std::string X){
    
    if (X.find("W1Cen") != string::npos)
        return kf_W_1;
    else if (X.find("W2Cen") != string::npos)
        return kf_W_2;
    else if (X.find("W1Up") != string::npos)
        return kf_W_1Up;
    else if (X.find("W2Up") != string::npos)
        return kf_W_2Up;
    else if (X.find("W1Down") != string::npos)
        return kf_W_1Down;
    else if (X.find("W2Down") != string::npos)
        return kf_W_2Down;
    
    else if (X.find("Z1Cen") != string::npos)
        return kf_Z_1;
    else if (X.find("Z2Cen") != string::npos)
        return kf_Z_2;
    else if (X.find("Z1Up") != string::npos)
        return kf_Z_1Up;
    else if (X.find("Z2Up") != string::npos)
        return kf_Z_2Up;
    else if (X.find("Z1Down") != string::npos)
        return kf_Z_1Down;
    else if (X.find("Z2Down") != string::npos)
        return kf_Z_2Down;
    
    
    else
        return 0;
}






//###########       Tau Veto   ###########################################################


int getNumTau(){
    
    
    int numTau=0;
    for  (int itau=0 ; itau < nTau; itau++){
        
        if (tauPt->at(itau) < 20  || fabs(tauEta->at(itau)) > 2.3 ) continue;
        
        bool TauIdIso =  taupfTausDiscriminationByDecayModeFinding->at(itau) > 0.5 && tauByLooseMuonRejection3->at(itau) > 0 && tauByMVA6LooseElectronRejection->at(itau) > 0 && tauByLooseIsolationMVArun2v1DBoldDMwLT->at(itau) > 0;
        
        if (!TauIdIso) continue;
        numTau++;
    }
    return numTau;
}




//###########       Z boson Veto   ###########################################################
float MuMass= 0.10565837;
float eleMass= 0.000511;

int getNumZBoson(){
    
    
    
    
    int numZboson=0;
    for (int xmu=0; xmu< nMu; xmu++){
        for (int ymu=xmu+1; ymu< nMu; ymu++){
            
            TLorentzVector Mu4Momentum_0,Mu4Momentum_1,Z4Momentum;
            Mu4Momentum_0.SetPtEtaPhiM(muPt->at(xmu),muEta->at(xmu),muPhi->at(xmu),MuMass);
            Mu4Momentum_1.SetPtEtaPhiM(muPt->at(ymu),muEta->at(ymu),muPhi->at(ymu),MuMass);
            Z4Momentum=Mu4Momentum_1+Mu4Momentum_0;
            
            float IsoMu1=muPFChIso->at(xmu)/muPt->at(xmu);
            if ( (muPFNeuIso->at(xmu) + muPFPhoIso->at(xmu) - 0.5* muPFPUIso->at(xmu) )  > 0.0)
                IsoMu1= ( muPFChIso->at(xmu)/muPt->at(xmu) + muPFNeuIso->at(xmu) + muPFPhoIso->at(xmu) - 0.5* muPFPUIso->at(xmu))/muPt->at(xmu);
            
            float IsoMu2=muPFChIso->at(ymu)/muPt->at(ymu);
            if ( (muPFNeuIso->at(ymu) + muPFPhoIso->at(ymu) - 0.5* muPFPUIso->at(ymu) )  > 0.0)
                IsoMu2= ( muPFChIso->at(ymu)/muPt->at(ymu) + muPFNeuIso->at(ymu) + muPFPhoIso->at(ymu) - 0.5* muPFPUIso->at(ymu))/muPt->at(ymu);
            
            if ( muPt->at(xmu) > 60 && muPt->at(ymu) > 15 &&  (muIDbit->at(xmu) >> 1 & 1) & (muIDbit->at(ymu) >> 1 & 1) & IsoMu1 < 0.25  && IsoMu2 < 0.25 && Z4Momentum.M() > 80 && Z4Momentum.M()< 100  && (muCharge->at(xmu) * muCharge->at(ymu) < 0))
                numZboson++;
        }
    }
    
    return numZboson;
    
}



//-----------------------------------------------------------------------------
// AM: recipe for top quark Pt reweighting taken from https://twiki.cern.ch/twiki/bin/viewauth/CMS/TopPtReweighting

float compTopPtWeight(float topPt) {
    //Updated values for 13 TeV
    const float a =  0.0615  ;
    const float b =  -0.0005 ;
    //    const float a =  0.148 ;
    //    const float b =  -0.00129;
    //    const float a = 0.156;
    //    const float b = -0.00137;
    return TMath::Exp(a + b * topPt);
}

float compTopPtWeight(float top1Pt, float top2Pt) {
    //std::cout << "<compTopPtWeight>:" << std::endl;
    float topPtWeight2 = compTopPtWeight(top1Pt) * compTopPtWeight(top2Pt);
    //std::cout << " top1Pt = " << top1Pt << ", top2Pt = " << top2Pt << ": topPtWeight2 = " << topPtWeight2 << std::endl;
    return ( topPtWeight2 > 0.) ? TMath::Sqrt(topPtWeight2) : 0.;
}





vector<float>  GeneratorInfo(){
    
    vector<float>    infoGen;
    infoGen.clear();
    
    
    
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
    
    for (int igen=0;igen < nMC; igen++){
        
        //Top Pt
        if (mcPID->at(igen) == 6 && mcStatus->at(igen) ==62) GenTopPt=mcPt->at(igen) ;
        if (mcPID->at(igen) == -6 && mcStatus->at(igen) ==62) GenAntiTopPt=mcPt->at(igen);
        
        
        //W Pt
        if (fabs(mcPID->at(igen)) ==24   && mcStatus->at(igen) ==22)  {WBosonPt= mcPt->at(igen); WBosonMass=mcMass->at(igen);}
        if ( fabs(mcPID->at(igen)) ==13 && mcStatus->at(igen) ==1 )  {MUGEN4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));}
        if ( fabs(mcPID->at(igen)) ==14  && mcStatus->at(igen) ==1)  {NUGEN4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen));}
        
        //Z Pt
        if (fabs(mcPID->at(igen)) ==23)  ZBosonPt= mcPt->at(igen); //FIXME somethime we do not have Z in the DY events
        if ( mcPID->at(igen) ==13  )  {GenMu4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen)); modPDGId=mcMomPID->at(igen);}
        if ( mcPID->at(igen) ==-13  )  {GenAntiMu4Momentum.SetPtEtaPhiM(mcPt->at(igen),mcEta->at(igen),mcPhi->at(igen),mcMass->at(igen)); AntimodPDGId=mcMomPID->at(igen);}
        
        
    }
    
    
    TopPtReweighting=compTopPtWeight(GenTopPt, GenAntiTopPt);
    
    if (ZBosonPt ==0)
        ZBosonPt=(GenMu4Momentum+GenAntiMu4Momentum).Pt();  //This is a temp solution to the above problem
    
    if (WBosonPt==0)
        WBosonPt = (MUGEN4Momentum+NUGEN4Momentum).Pt();
    
    
    //######################## Top Pt Reweighting
    infoGen.push_back(TopPtReweighting);
    
    //######################## W Pt
    infoGen.push_back(WBosonPt);
    
    //######################## Z Pt
    infoGen.push_back(ZBosonPt);
    
    //######################## W Mass
    infoGen.push_back(WBosonMass);
    
    return infoGen;
    
}




//###########       bJet Veto   ###########################################################

//float BJetPtCut=30;
//float SimpleJetPtCut=30;
//float ElectronPtCut_=15;
//float CSVCut=   0.9535   ;                  //  https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation80XReReco


float FuncFinalBTagSF(bool isData, TH2F ** Btagg_TT, float BJetPtCut, float CSVCut){
    
    
    float EffJet =1;
    float SF=1;
    float P_Data_P_mc=1;
    float FinalBTagSF=1;
    
    if (isData) return 1;
    for (int ijet= 0 ; ijet < nJet ; ijet++){
        
        float HadronFlavor= isData ? 1 : jetHadFlvr->at(ijet);
        
        if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > BJetPtCut && fabs(jetEta->at(ijet)) < 2.4 ){
            
            
            if ( jetCSV2BJetTags->at(ijet) >  CSVCut ){
                EffJet= getBtagEfficiency( isData, 1,  jetPt->at(ijet), fabs(jetEta->at(ijet)), Btagg_TT);
                SF= GetBJetSF(isData, jetPt->at(ijet), jetPt->at(ijet), HadronFlavor);
                P_Data_P_mc=SF*EffJet/EffJet;
                
                
            }
            else{
                EffJet= getBtagEfficiency( isData, 0,  jetPt->at(ijet), fabs(jetEta->at(ijet)), Btagg_TT);
                SF=GetBJetSF(isData,jetPt->at(ijet), jetPt->at(ijet), HadronFlavor);
                P_Data_P_mc=(1-SF*EffJet)/(1-EffJet);
                
            }
        FinalBTagSF *=P_Data_P_mc;
        }
        
//        FinalBTagSF *=P_Data_P_mc; //BUG at May 17th
    }
    return FinalBTagSF;
}





int numBJets(float BJetPtCut,float CSVCut){
    int numBJet=0;
    for (int ijet= 0 ; ijet < nJet ; ijet++){
        if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > BJetPtCut && fabs(jetEta->at(ijet)) < 2.4  && jetCSV2BJetTags->at(ijet) >  CSVCut)
            numBJet++;
    }
    return numBJet;
}



int numJets(float SimpleJetPtCut){
    int numJet=0;
    for (int ijet= 0 ; ijet < nJet ; ijet++){
        if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > SimpleJetPtCut && fabs(jetEta->at(ijet)) < 2.4 )
            numJet++;
    }
    return numJet;
}


//###########       W PDF + alpha s   ###########################################################


float W_PDFAlphaS(float wMass, float sign){
    
    if (wMass < 400) return (1+sign/100.*1.734);
    if (wMass < 600) return (1+sign/100.*1.906);
    if (wMass < 800) return (1+sign/100.*2.279);
    if (wMass < 1000) return (1+sign/100.*2.679);
    if (wMass < 1200) return (1+sign/100.*3.284);
    if (wMass < 1400) return (1+sign/100.* 3.669);
    if (wMass < 1600) return (1+sign/100.* 4.046);
    if (wMass < 1800) return (1+sign/100.* 4.801);
    if (wMass < 2000) return (1+sign/100.* 5.088);
    if (wMass < 2200) return (1+sign/100.* 5.562);
    if (wMass < 2400) return (1+sign/100.* 5.825);
    if (wMass < 2600) return (1+sign/100.* 6.238);
    if (wMass < 2800) return (1+sign/100.* 6.684);
    if (wMass < 3000) return (1+sign/100.* 7.268);
    if (wMass < 3200) return (1+sign/100.* 7.743);
    if (wMass < 3400) return (1+sign/100.* 8.547);
    if (wMass < 3600) return (1+sign/100.* 9.326);
    if (wMass < 3800) return (1+sign/100.* 10.05);
    if (wMass < 4000) return (1+sign/100.* 9.782);
    else return (1+sign/100.* 10.00);
    
}


