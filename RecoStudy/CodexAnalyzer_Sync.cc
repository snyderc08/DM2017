////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  This code is to pre-select the events. This ise used as a base for background estimation, ...
// To run this code one first needs to compile it:
//1) ./Mask.sh   CodexAnalyzer_Preselection.cc
//2)  ./CodexAnalyzer_Preselection.exe  output.root   input.root
// To run this on all data and MC samples run the following:
// source RunFullSamples_PreSelection.sh
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "../interface/CodexAnalyzer.h"
//#include "../interface/WeightCalculator.h"
//#include "../interface/Corrector.h"
#include "../interface/Functions.h"
//#include "../interface/makeHisto.h"
#include <string>
#include <ostream>
#include <vector>
#include "GeneralizedEndpoint.h"


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
    TH1F *  HistoPUData =HistPUData();
    TH1F * HistoPUMC=HistPUMC();
    
    //########################################
    // Muon Id, Iso, Trigger and Tracker Eff files
    //########################################
    TH2F** HistoMuId=FuncHistMuId();
    TH2F** HistoMuIso=FuncHistMuIso();
    TH1F** HistoMuTrg=FuncHistMuTrigger();
    TGraphAsymmErrors * HistoMuTrack=FuncHistMuTrack();
    
    //########################################
    // Electron MVA IdIso files
    //########################################
    TH2F * HistoEleMVAIdIso90= FuncHistEleMVAId("Tot");
    TH2F * HistoEleMVAIdIso90_EffMC= FuncHistEleMVAId("MC");
    TH2F * HistoEleMVAIdIso90_EffData= FuncHistEleMVAId("Data");
    
    //########################################
    // W and DY K-factor files  (Bin-based K-factor)
    //########################################
    std::string ROOTLocHT= "/Users/abdollah1/GIT_abdollah110/DM2017/ROOT80X/SampleLQ2/";
    vector<float> W_HTBinROOTFiles = W_HTBin(ROOTLocHT);
    vector<float> W_MassBinROOTFiles = W_MassBin(ROOTLocHT);
    vector<float> WTauNu_MassBinROOTFiles = WTauNu_MassBin(ROOTLocHT);
    TFile * MassDepKFactor=TFile::Open("../interface/k_fakNNLO_use.root");
    TH1F* HistMassDepKFactor= (TH1F*) MassDepKFactor->Get("k_fak_mean");
    
    //########################################
    // Btagging scale factor and uncertainties
    //########################################
    TH2F ** Btagg_TT=FuncHistBTagSF();
    
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
        
        TTree *  Run_Tree;
        Run_Tree= Xttree(f_Double);
        
//        //########################################   General Info
//        Run_Tree->SetBranchAddress("isData", &isData);
//        Run_Tree->SetBranchAddress("run", &run);
//        Run_Tree->SetBranchAddress("lumis", &lumis);
//        Run_Tree->SetBranchAddress("event", &event);
//        Run_Tree->SetBranchAddress("genWeight",&genWeight);
//        Run_Tree->SetBranchAddress("HLTEleMuX", &HLTEleMuX);
//        Run_Tree->SetBranchAddress("puTrue", &puTrue);
//        Run_Tree->SetBranchAddress("nVtx",&nVtx);
//        
//        //########################################   MC Info
//        Run_Tree->SetBranchAddress("nMC", &nMC);
//        Run_Tree->SetBranchAddress("mcPID", &mcPID);
//        Run_Tree->SetBranchAddress("mcStatus", &mcStatus);
//        Run_Tree->SetBranchAddress("mcPt", &mcPt );
//        Run_Tree->SetBranchAddress("mcEta", &mcEta );
//        Run_Tree->SetBranchAddress("mcPhi", &mcPhi );
//        Run_Tree->SetBranchAddress("mcE", &mcE );
//        Run_Tree->SetBranchAddress("mcMass", &mcMass );
//        Run_Tree->SetBranchAddress("mcMomPID", &mcMomPID );
//        Run_Tree->SetBranchAddress("mcGMomPID", &mcGMomPID );
//        
//        //########################################   Tau Info
//        Run_Tree->SetBranchAddress("nTau", &nTau);
//        Run_Tree->SetBranchAddress("tauPt"  ,&tauPt);
//        Run_Tree->SetBranchAddress("tauEta"  ,&tauEta);
//        Run_Tree->SetBranchAddress("tauPhi"  ,&tauPhi);
//        Run_Tree->SetBranchAddress("tauMass"  ,&tauMass);
//        Run_Tree->SetBranchAddress("tauCharge"  ,&tauCharge);
//        Run_Tree->SetBranchAddress("taupfTausDiscriminationByDecayModeFinding", &taupfTausDiscriminationByDecayModeFinding);
//        Run_Tree->SetBranchAddress("tauByTightMuonRejection3", &tauByTightMuonRejection3);
//        Run_Tree->SetBranchAddress("tauByLooseMuonRejection3", &tauByLooseMuonRejection3);
//        Run_Tree->SetBranchAddress("tauByMVA6MediumElectronRejection"  ,&tauByMVA6MediumElectronRejection);
//        Run_Tree->SetBranchAddress("tauByLooseCombinedIsolationDeltaBetaCorr3Hits",&tauByLooseCombinedIsolationDeltaBetaCorr3Hits);
//        Run_Tree->SetBranchAddress("tauByMediumCombinedIsolationDeltaBetaCorr3Hits",&tauByMediumCombinedIsolationDeltaBetaCorr3Hits);
//        Run_Tree->SetBranchAddress("tauByMVA6LooseElectronRejection", &tauByMVA6LooseElectronRejection);
//        Run_Tree->SetBranchAddress("tauDxy",&tauDxy);
//        Run_Tree->SetBranchAddress("tauDecayMode",&tauDecayMode);
//        Run_Tree->SetBranchAddress("tauByLooseIsolationMVArun2v1DBoldDMwLT",&tauByLooseIsolationMVArun2v1DBoldDMwLT);
//        Run_Tree->SetBranchAddress("tauByVLooseIsolationMVArun2v1DBoldDMwLT",&tauByVLooseIsolationMVArun2v1DBoldDMwLT);
//        
//        //########################################   Mu Info
//        Run_Tree->SetBranchAddress("nMu", &nMu);
//        Run_Tree->SetBranchAddress("muPt"  ,&muPt);
//        Run_Tree->SetBranchAddress("muEta"  ,&muEta);
//        Run_Tree->SetBranchAddress("muPhi"  ,&muPhi);
//        Run_Tree->SetBranchAddress("muIsoTrk", &muIsoTrk);
//        Run_Tree->SetBranchAddress("muCharge",&muCharge);
//        Run_Tree->SetBranchAddress("muIDbit",&muIDbit);//NEW
//        Run_Tree->SetBranchAddress("muPFChIso", &muPFChIso);
//        Run_Tree->SetBranchAddress("muPFPhoIso", &muPFPhoIso);
//        Run_Tree->SetBranchAddress("muPFNeuIso", &muPFNeuIso);
//        Run_Tree->SetBranchAddress("muPFPUIso", &muPFPUIso);
//        Run_Tree->SetBranchAddress("muD0",&muD0);
//        Run_Tree->SetBranchAddress("muDz",&muDz);
//        
//        //########################################   Ele Info
//        Run_Tree->SetBranchAddress("nEle", &nEle);
//        Run_Tree->SetBranchAddress("elePt"  ,&elePt);
//        Run_Tree->SetBranchAddress("eleEta"  ,&eleEta);
//        Run_Tree->SetBranchAddress("elePhi"  ,&elePhi);
//        Run_Tree->SetBranchAddress("elePFChIso", &elePFChIso);
//        Run_Tree->SetBranchAddress("eleIDMVA", &eleIDMVA);//NEW
//        Run_Tree->SetBranchAddress("eleCharge",&eleCharge);
//        Run_Tree->SetBranchAddress("eleSCEta",&eleSCEta);
//        Run_Tree->SetBranchAddress("elePFChIso", &elePFChIso);
//        Run_Tree->SetBranchAddress("elePFPhoIso", &elePFPhoIso);
//        Run_Tree->SetBranchAddress("elePFNeuIso", &elePFNeuIso);
//        Run_Tree->SetBranchAddress("elePFPUIso", &elePFPUIso);
//        Run_Tree->SetBranchAddress("eleD0",&eleD0);
//        Run_Tree->SetBranchAddress("eleDz",&eleDz);
//        Run_Tree->SetBranchAddress("eleMissHits", &eleMissHits);
//        Run_Tree->SetBranchAddress("eleConvVeto", &eleConvVeto);
//        Run_Tree->SetBranchAddress("eleSCEta", &eleSCEta );
//        
//        //########################################   Jet Info
//        Run_Tree->SetBranchAddress("nJet",&nJet);
//        Run_Tree->SetBranchAddress("jetPt",&jetPt);
//        Run_Tree->SetBranchAddress("jetEta",&jetEta);
//        Run_Tree->SetBranchAddress("jetPhi",&jetPhi);
//        Run_Tree->SetBranchAddress("jetEn",&jetEn);
//        Run_Tree->SetBranchAddress("jetCSV2BJetTags",&jetCSV2BJetTags);
//        Run_Tree->SetBranchAddress("jetPFLooseId",&jetPFLooseId);
//        Run_Tree->SetBranchAddress("jetPUID",&jetPUID);
//        Run_Tree->SetBranchAddress("jetRawPt",&jetRawPt);
//        Run_Tree->SetBranchAddress("jetJECUnc",&jetJECUnc);
//        Run_Tree->SetBranchAddress("jetRawEn",&jetRawEn);
//        Run_Tree->SetBranchAddress("jetHadFlvr",&jetHadFlvr);
//        Run_Tree->SetBranchAddress("jetCHF",&jetCHF);
//        Run_Tree->SetBranchAddress("jetNHF",&jetNHF);
//        Run_Tree->SetBranchAddress("jetCEF",&jetCEF);
//        Run_Tree->SetBranchAddress("jetNEF",&jetNEF);
//        Run_Tree->SetBranchAddress("jetNCH",&jetNCH);
//        Run_Tree->SetBranchAddress("jetNNP",&jetNNP);
//        
//        
//        //########################################   MET Info
//        Run_Tree->SetBranchAddress("pfMET",&pfMET);
//        Run_Tree->SetBranchAddress("pfMETPhi",&pfMETPhi);
//        Run_Tree->SetBranchAddress("metFilters",&metFilters);
//        Run_Tree->SetBranchAddress("genHT",&genHT);
        
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
            //                    for (Int_t i = 0; i < 100; i++) {
            Run_Tree->GetEntry(i);
//            if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
            fflush(stdout);
            
//            283820:1419:1795563972
            
            if(event==1077480676 && lumis==1864 && run==283408) cout<<"beforeMETFLITER--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //                    Evt: 1419040739, Lumi: 865, Run: 276935
            if(event==1366286307 && lumis==808 && run==276542) cout<<"beforeMETFLITER--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //                    vt: 1795563972, Lumi: 1419, Run: 283820,
            if(event==1795563972 && lumis==1419 && run==283820) cout<<"beforeMETFLITER--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            if( lumis==1419 && run==283820) cout<<"#######beforeMETFLITER--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //###############################################################################################
            //  MET Filters (only on Data)
            //###############################################################################################
                        if (isData && (metFilters!=1536)) continue;
            
            
            if(event==1077480676 && lumis==1864 && run==283408) cout<<"beforeTRigger--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //                    Evt: 1419040739, Lumi: 865, Run: 276935
            if(event==1366286307 && lumis==808 && run==276542) cout<<"beforeTRigger--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //                    vt: 1795563972, Lumi: 1419, Run: 283820,
            if(event==1795563972 && lumis==1419 && run==283820) cout<<"beforeTRigger--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //###########       Trigger Requirement ###########################################################
                        bool PassTrigger =((HLTEleMuX >> 21 & 1) == 1 || (HLTEleMuX >> 41 & 1) == 1); //   else if (name.find("HLT_Mu50_v") != string::npos) bitEleMuX = 21;
            if (! PassTrigger) continue;
            
            //###############################################################################################
            //  This part is to avoid of the duplicate of mu-j pair from one events
            //###############################################################################################
            std::vector<string> HistNamesFilled;
            HistNamesFilled.clear();
            
//            //###############################################################################################
//            //  GenInfo
//            //###############################################################################################
//            vector<float>  genInfo=GeneratorInfo();
//            
//            //            //######################## Top Pt Reweighting
//            float TopPtReweighting = 1;
//            size_t isTTJets = InputROOT.find("TTJets");
//            if (isTTJets!= string::npos) TopPtReweighting = genInfo[0];
//            
//            //            //######################## W K-factor
//            float WBosonPt=0;
//            float WBosonMass=0;
//            float WBosonKFactor=1;
//            
//            WBosonPt=genInfo[1];
//            WBosonMass=genInfo[3];
//            
//            size_t isWJetsToLNu_Inc = InputROOT.find("WJetsToLNu_Inc");
//            size_t isWJets = InputROOT.find("WJets");
//            //            size_t isWToMuTauNu = (InputROOT.find("WToLNu") || InputROOT.find("WToTauNu"));  size_t in NOT BOOLEAN!!!!!!
//            size_t isWToLNu = (InputROOT.find("WToLNu") );
//            size_t isWToTauNu = (InputROOT.find("WToTauNu") );
//            
//            if (WBosonMass > 100 && (isWToLNu!= string::npos || isWToTauNu!=string::npos)) WBosonKFactor=HistMassDepKFactor->GetBinContent(int(WBosonMass)/10 +1); //Mass binned K-factor
//            if (WBosonMass <= 100 && isWJets!= string::npos  )WBosonKFactor= FuncBosonKFactor("W1") + FuncBosonKFactor("W2") * WBosonPt; //HT binned & inclusive K-factor
//            
//            //................................................................................................................
//            //................................................................................................................
//            if (isWJets!= string::npos && WBosonMass > 100) continue;
//            if (isWJetsToLNu_Inc!= string::npos && genHT > 70.0) continue;
//            //................................................................................................................
//            //................................................................................................................
//            
//            //            //######################## Z K-factor
//            float ZBosonPt=0;
//            float ZBosonKFactor=1;
//            size_t isDYJets = InputROOT.find("DYJets");
//            ZBosonPt=genInfo[2];
//            if (isDYJets!= string::npos) ZBosonKFactor= FuncBosonKFactor("Z1") + FuncBosonKFactor("Z2") * ZBosonPt;
//            
//            
//            //###############################################################################################
//            //  Lumi, GEN & PileUp Weight
//            //###############################################################################################
//            
//            float LumiWeight = 1;
//            float GetGenWeight=1;
//            float PUWeight = 1;
//            
//            if (!isData){
//                
//                //######################## Lumi Weight
//                //                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT,genHT,WBosonPt, W_Events, DY_Events,W_EventsNLO);
//                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT,genHT, W_HTBinROOTFiles, WBosonMass, W_MassBinROOTFiles,WTauNu_MassBinROOTFiles);
//                
//                //######################## Gen Weight
//                GetGenWeight=genWeight;
//                
//                //######################## PileUp Weight
//                int puNUmmc=int(puTrue->at(0)*10);
//                int puNUmdata=int(puTrue->at(0)*10);
//                float PUMC_=HistoPUMC->GetBinContent(puNUmmc+1);
//                float PUData_=HistoPUData->GetBinContent(puNUmdata+1);
//                if (PUMC_ ==0)
//                    cout<<"PUMC_ is zero!!! & num pileup= "<< puTrue->at(0)<<"\n";
//                else
//                    PUWeight= PUData_/PUMC_;
//            }
            
            
//            //############################################################################################
//            //   Final Total Weight
//            //############################################################################################
//            float TotalWeight_withTopPtRW = LumiWeight * GetGenWeight * PUWeight * TopPtReweighting * WBosonKFactor * ZBosonKFactor ;
//            float TotalWeight_NoTopPtRW = LumiWeight * GetGenWeight * PUWeight * WBosonKFactor * ZBosonKFactor ;
            

            
            //###############################################################################################
            //###############################################################################################
            //###############################################################################################
            //                                      Doing  Analysis
            //###############################################################################################
            //###############################################################################################
            //###############################################################################################
            
            
            if(event==1077480676 && lumis==1864 && run==283408) cout<<"--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //                    Evt: 1419040739, Lumi: 865, Run: 276935
            if(event==1366286307 && lumis==808 && run==276542) cout<<"--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";
            
            //                    vt: 1795563972, Lumi: 1419, Run: 283820,
            if(event==1795563972 && lumis==1419 && run==283820) cout<<"--------->Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", Met: "<<pfMET <<"\n";

            
            
            
            //###########       Trigger Requirement ###########################################################
//            bool PassTrigger = 1;
//            bool PassTrigger = ((HLTEleMuX >> 21 & 1) == 1 || (HLTEleMuX >> 41 & 1) == 1); //   else if (name.find("HLT_Mu50_v") != string::npos) bitEleMuX = 21;
//            if (! PassTrigger) continue;
            if (pfMET < 100) continue;
            
            //###########       numTau   ###########################################################
            int numTau= getNumTau();
            
            //###########       Ele Veto   ###########################################################
            //            https://twiki.cern.ch/twiki/bin/view/CMS/MultivariateElectronIdentificationRun2#Recommended_MVA_recipes_for_2016
            int numElectron=0;
            float ElectronCor=1;
            TLorentzVector Ele4Momentum;
            float ElectronEffVeto=1;
            Ele4Momentum.SetPtEtaPhiM(0,0,0,0);
            for  (int jele=0 ; jele < nEle; jele++){
                
                if ( elePt->at(jele) < 15 || fabs(eleEta->at(jele)) > 2.5) continue;
                
                bool eleMVAIdExtra= false;
                if (fabs (eleSCEta->at(jele)) <= 0.8 && eleIDMVA->at(jele) >   0.837  ) eleMVAIdExtra= true;
                else if (fabs (eleSCEta->at(jele)) >  0.8 &&fabs (eleSCEta->at(jele)) <=  1.5 && eleIDMVA->at(jele) >   0.715  ) eleMVAIdExtra= true;
                else if ( fabs (eleSCEta->at(jele)) >=  1.5 && eleIDMVA->at(jele) >  0.357  ) eleMVAIdExtra= true;
                else eleMVAIdExtra= false;
                
                
                
                if (!(eleMVAIdExtra )) {
                    ElectronEffVeto= ElectronEffVeto * getEffVetoMVA90WPElectron80X(isData,  elePt->at(jele),eleSCEta->at(jele),    HistoEleMVAIdIso90 , HistoEleMVAIdIso90_EffMC,HistoEleMVAIdIso90_EffData);
                    continue;
                }
                
                ElectronCor=getCorrFactorMVA90WPElectron80X(isData,  elePt->at(jele),eleSCEta->at(jele),    HistoEleMVAIdIso90 );
                Ele4Momentum.SetPtEtaPhiM(elePt->at(jele),eleEta->at(jele),elePhi->at(jele),eleMass);
                numElectron++;
                
                break;
            }
            //###########       BTag SF   ###########################################################
            float FinalBTagSF=FuncFinalBTagSF(isData,Btagg_TT);
            
            //###########       numBJet   ###########################################################
            int numBJet=numBJets();
            
            //###########       numJet   ###########################################################
            int numJet=numJets();
            
            //###########       numZboson   ###########################################################
            int numZboson = getNumZBoson();
            

//            if (numTau+numZboson + numElectron  + numBJet > 0) continue;
            if (numZboson + numElectron  + numBJet > 0) continue;
            
            
            
            
            //
//            //###############################################################################################
//            //  Some Histogram Filling
//            //###############################################################################################
//            plotFill("_WeightLumi",LumiWeight,1000,0,10);
//            plotFill("_TopPtReweighting",TopPtReweighting,100,0,2);
//            plotFill("_WeightPU",PUWeight,100,0,5);
//            plotFill("_TotalWeight_withTopPtRW",TotalWeight_withTopPtRW,50,0,2);
//            plotFill("_TotalWeight_NoTopPtRW",TotalWeight_NoTopPtRW,50,0,2);
//            plotFill("_nVtx_NoPUCorr",nVtx,60,0,60);
//            plotFill("_nVtx_PUCorr",nVtx,60,0,60,PUWeight);
//            plotFill("_WBosonPt",WBosonPt,150,0,1500,PUWeight);
//            plotFill("_FinalBTagSF", FinalBTagSF,200,0,2);
//            
//            for (int qq=0; qq < 60;qq++){
//                if ((HLTEleMuX >> qq & 1) == 1)
//                    plotFill("_HLT",qq,60,0,60);
//            }
//            
//            
//            
//            
//            
//            //############################################################################################
//            //###########       Loop over MuJet events   #################################################
//            //############################################################################################
//            
//            for  (int xmu=0 ; xmu < nMu; xmu++){
//                if ( muPt->at(xmu) > 60 ) numMuon++;
////                if ( muPt->at(xmu) > 50 && (muIDbit->at(xmu) >> 0 & 1)) numMuon++;
//            }
            
            vector <TLorentzVector> muCollection;
            muCollection.clear();
            TLorentzVector XMu4Momentum;
            
            for  (int xmu=0 ; xmu < nMu; xmu++){
                
                float IsoMu=muPFChIso->at(xmu)/muPt->at(xmu);
                if ( (muPFNeuIso->at(xmu) + muPFPhoIso->at(xmu) - 0.5* muPFPUIso->at(xmu) )  > 0.0)
                    IsoMu= ( muPFChIso->at(xmu)/muPt->at(xmu) + muPFNeuIso->at(xmu) + muPFPhoIso->at(xmu) - 0.5* muPFPUIso->at(xmu))/muPt->at(xmu);
                
                bool MuPtCutX = muPt->at(xmu) > LeptonPtCut_ && fabs(muEta->at(xmu)) < 2.4 && (muIDbit->at(xmu) >> 2 & 1) &&  IsoMu < 0.15 ;
            
                XMu4Momentum.SetPtEtaPhiM(muPt->at(xmu),muEta->at(xmu),muPhi->at(xmu),MuMass);
                if (MuPtCutX) muCollection.push_back(XMu4Momentum);

            }
            
                    
                    
                
            TLorentzVector Mu4Momentum, Jet4Momentum,KJet4Momentum,LQ4Momentum,Mu24Momentum, MuScaleCorr4Momentum;
            bool hasonemuon=1;
            for  (int imu=0 ; imu < nMu; imu++){
                
                float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                    IsoMu= ( muPFChIso->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                
                bool MuPtCut = muPt->at(imu) > LeptonPtCut_ && fabs(muEta->at(imu)) < 2.4 ;
//                bool MuPtCut = muPt->at(imu) > LeptonPtCut_ && fabs(muEta->at(imu)) < 2.1 ;
                bool MuIdIso=( (muIDbit->at(imu) >> 2 & 1)  && fabs(muD0->at(imu)) < 0.045 && fabs(muDz->at(imu)) < 0.2 &&  IsoMu < 0.15); //Tight Muon Id
//                                bool MuIdIso=( (muIDbit->at(imu) >> 2 & 1)); //Tight Muon Id
                
                
                if(event==1366286307 && lumis==808 && run==276542) cout<<"Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", MuPt: "<<muPt->at(imu) <<", MuEta: "<<muEta->at(imu)  <<", MuIso: "<<IsoMu << "fabs(muD0->at(imu)):"<<fabs(muD0->at(imu))<<" fabs(muDz->at(imu)):"<<fabs(muDz->at(imu))  <<   "id "<<(muIDbit->at(imu) >> 2 & 1) <<", Met: "<<pfMET <<"\n";
                
                
                if (! MuPtCut || !MuIdIso ) continue;
                
                //                if (muCharge->at(imu) < 0) continue;
                
//                float muptX = GeneralizedEndpoint().GeneralizedEndpointPt(muPt->at(imu),muCharge->at(imu),muEta->at(imu),(muPhi->at(imu)*180/TMath::Pi()),-1,0);
                
//                cout<<muPt->at(imu) << "   x= "<<muptX<<"\n";
                
                float MuonCor=getCorrFactorMuon80X(isData,  muPt->at(imu), muEta->at(imu) , HistoMuId,HistoMuIso,HistoMuTrg,HistoMuTrack);
                
                
                Mu4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
//                MuScaleCorr4Momentum.SetPtEtaPhiM(muptX,muEta->at(imu),muPhi->at(imu),MuMass);
                
                

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
                
                
                
//                //###########    Compute recoHT and ST  ###########################################################
//                float recoHT=0;
//
//                for  (int qmu=0 ; qmu < nMu; qmu++){
//                   if (event==9261)  cout<<"Evt: "<<event <<", MuPt: "<<muPt->at(qmu) <<", MuEta: "<<muEta->at(qmu)<<"\n";
//                }
//                for (int kjet= 0 ; kjet < nJet ; kjet++){
//                    if (event==9261) cout <<", jetPt: "<<jetPt->at(kjet) <<", jetEta: "<<jetEta->at(kjet) <<"\n";
//                }
//
//                    KJet4Momentum.SetPtEtaPhiE(jetPt->at(kjet),jetEta->at(kjet),jetPhi->at(kjet),jetEn->at(kjet));
//                    if (jetPFLooseId->at(kjet) > 0.5 && jetPt->at(kjet) > 30 && fabs(jetEta->at(kjet)) < 2.4 && KJet4Momentum.DeltaR(Mu4Momentum) > 0.5)
//                        recoHT += jetPt->at(kjet);
//                }
//                float ST=recoHT+muPt->at(imu);
                
                //###########    loop over  Jet    ###########################################################
                for (int ijet= 0 ; ijet < nJet ; ijet++){
                    
                    Jet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                    
                    bool goodJet = (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > JetPtCut && fabs(jetEta->at(ijet)) < 3.0 && Jet4Momentum.DeltaR(Mu4Momentum) > 0.5);
//                    bool goodJet = (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > JetPtCut && fabs(jetEta->at(ijet)) < 2.4 && Jet4Momentum.DeltaR(Mu4Momentum) > 0.5);
                    
//                    for (int numMux=0; numMux < muCollection.size(); numMux++){
//                        if (muCollection[numMux].DeltaR(Jet4Momentum) < 0.3)
//                            goodJet=false;
//                            }
                    
                    
                    if(event==1366286307 && lumis==808 && run==276542) cout<<"Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", MuPt: "<<muPt->at(imu) <<", MuEta: "<<muEta->at(imu)  <<", MuIso: "<<IsoMu <<", Met: "<<pfMET <<", jetPt: "<<jetPt->at(ijet) <<", jetEta: "<<jetEta->at(ijet) <<", DR: "<<Jet4Momentum.DeltaR(Mu4Momentum) <<"\n";
                    
                    
                    
                    if (! goodJet) continue;
                    
                    
                    
                    ///////////////////////////***************** Temp
                    //                    if  (jetPt->at(ijet) > 200) break;
                    
                    
                    LQ4Momentum=Jet4Momentum + Mu4Momentum;
                    
                    //                    bool isThisJetElectron= Jet4Momentum.DeltaR(Ele4Momentum) < 0.5;
                    //###############################################################################################
                    //  Isolation Categorization
                    //###############################################################################################
                    bool LepPassIsolation= IsoMu < 0.15;
                    
                    const int size_isoCat = 2;
                    bool Isolation = LepPassIsolation;
                    bool AntiIsolation =  !LepPassIsolation;
                    //                    bool Total = 1;
                    
                    bool Iso_category[size_isoCat] = {Isolation, AntiIsolation};
                    std::string iso_Cat[size_isoCat] = {"_Iso", "_AntiIso"};
                    //###############################################################################################
                    //  MT Categorization
                    //###############################################################################################
                    float tmass_MuMet= TMass_F(muPt->at(imu), muPt->at(imu)*cos(muPhi->at(imu)),muPt->at(imu)*sin(muPhi->at(imu)) , pfMET, pfMETPhi);
                    float tmass_JetMet= TMass_F(jetPt->at(ijet), jetPt->at(ijet)*cos(jetPhi->at(ijet)),jetPt->at(ijet)*sin(jetPhi->at(ijet)) , pfMET, pfMETPhi);
                    float tmass_LQMet= TMass_F(LQ4Momentum.Pt(), LQ4Momentum.Px(),LQ4Momentum.Py(), pfMET, pfMETPhi);
                    
                    
                    //                    const int size_mTCat = 11;
                    const int size_mTCat = 5;
                    //
                    //                    bool NoMT = 1;
                    //                    bool HighMT = (tmass_MuMet > 100);
                    //                    bool MT50To150=(tmass_MuMet > 50 && tmass_MuMet <= 150);
                    //                    bool MT150To200=(tmass_MuMet > 150 && tmass_MuMet <= 200);
                    //                    bool MT200To250=(tmass_MuMet > 200 && tmass_MuMet <= 250);
                    //                    bool MT250To300=(tmass_MuMet > 250 && tmass_MuMet <= 300);
                    //                    bool MT300To350=(tmass_MuMet > 300 && tmass_MuMet <= 350);
                    //                    bool MTMore200=tmass_MuMet > 200 ;
                    //                    bool MTMore300=tmass_MuMet > 300 ;
                    //                    bool MTMore400=tmass_MuMet > 400 ;
                    //                    bool MTMore500=tmass_MuMet > 500 ;
                    
                    bool NoMT = 1;
                    bool HighMT = (tmass_MuMet > 100);
                    bool MT50To150=(tmass_MuMet > 50 && tmass_MuMet <= 150);
                    //                    bool MT150To200=(tmass_MuMet > 150 && tmass_MuMet <= 200);
                    //                    bool MT200To250=(tmass_MuMet > 200 && tmass_MuMet <= 250);
                    //                    bool MT250To300=(tmass_MuMet > 250 && tmass_MuMet <= 300);
                    //                    bool MT300To350=(tmass_MuMet > 300 && tmass_MuMet <= 350);
                    //                    bool MTMore200=tmass_MuMet > 200 ;
                    bool MTMore300=tmass_MuMet > 300 ;
                    //                    bool MTMore400=tmass_MuMet > 400 ;
                    bool MTMore500=tmass_MuMet > 500 ;
                    
                    
                    //                    bool MT_category[size_mTCat] = {NoMT,HighMT,MT50To150,MT150To200,MT200To250,MT250To300,MT300To350,MTMore200,MTMore300,MTMore400,MTMore500};
                    //                    std::string MT_Cat[size_mTCat] = {"_NoMT","_HighMT","_MT50To150","_MT150to200","_MT200to250","_MT250to300","_MT300to350","_MT200","_MT300","_MT400","_MT500"};
                    bool MT_category[size_mTCat] = {NoMT,HighMT,MT50To150,MTMore300,MTMore500};
                    std::string MT_Cat[size_mTCat] = {"_NoMT","_HighMT","_MT50To150","_MT300","_MT500"};
                    
                 
                    
                    if(event==1077480676 && lumis==1864 && run==283408) cout<<"Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", MuPt: "<<muPt->at(imu) <<", MuEta: "<<muEta->at(imu)  <<", MuIso: "<<IsoMu <<", Met: "<<pfMET <<", jetPt: "<<jetPt->at(ijet) <<", jetEta: "<<jetEta->at(ijet) <<", DR: "<<Jet4Momentum.DeltaR(Mu4Momentum) << ", mT: "<< tmass_MuMet<<"\n";
                    
//                    Evt: 1419040739, Lumi: 865, Run: 276935
                    if(event==1366286307 && lumis==808 && run==276542) cout<<"Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", MuPt: "<<muPt->at(imu) <<", MuEta: "<<muEta->at(imu)  <<", MuIso: "<<IsoMu <<", Met: "<<pfMET <<", jetPt: "<<jetPt->at(ijet) <<", jetEta: "<<jetEta->at(ijet) <<", DR: "<<Jet4Momentum.DeltaR(Mu4Momentum) << ", mT: "<< tmass_MuMet<<"\n";
                    
//                    vt: 1795563972, Lumi: 1419, Run: 283820,
                    if(event==1795563972 && lumis==1419 && run==283820) cout<<"Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", MuPt: "<<muPt->at(imu) <<", MuEta: "<<muEta->at(imu)  <<", MuIso: "<<IsoMu <<", Met: "<<pfMET <<", jetPt: "<<jetPt->at(ijet) <<", jetEta: "<<jetEta->at(ijet) <<", DR: "<<Jet4Momentum.DeltaR(Mu4Momentum) << ", mT: "<< tmass_MuMet<<"\n";
                    
                    
                    
                    
//                    if (hasonemuon && MTMore500) cout<<"Evt: "<<event <<",  Lumi: "<<lumis <<", Run: "<<run <<", MuPt: "<<muPt->at(imu) <<", MuEta: "<<muEta->at(imu)  <<", MuIso: "<<IsoMu <<", Met: "<<pfMET <<", jetPt: "<<jetPt->at(ijet) <<", jetEta: "<<jetEta->at(ijet) <<", DR: "<<Jet4Momentum.DeltaR(Mu4Momentum) <<"\n";
                    
                        if (hasonemuon && MTMore500) plotFill("_LQMass",LQ4Momentum.M(),200,0,2000,1);
                    hasonemuon=0;
                    break;
//                    
//                    if (hasonemuon && MTMore500) cout<<"Evt: "<<event <<",  Lumis: "<<lumi <<", Run: "<<run <<", MuPt: "<<muPt->at(imu) <<", MuEta: "<<muEta->at(imu)  <<", MuIso: "<<IsoMu <<", muPFChIso: "<<   muPFChIso->at(imu)  <<", muPFNeuIso: "<<  muPFNeuIso->at(imu)  <<", muPFPhoIso: "<<   muPFPhoIso->at(imu) <<", muPFPUIso: "<<   muPFPUIso->at(imu)  <<", Met: "<<pfMET <<", jetPt: "<<jetPt->at(ijet) <<", jetEta: "<<jetEta->at(ijet) <<", DR: "<<Jet4Momentum.DeltaR(Mu4Momentum) << "  HLT" <<(HLTEleMuX >> 21 & 1) << " . "<<
                    
                    //###############################################################################################
                    //  dPhi Jet_MET Categorization
                    //###############################################################################################
                    //                    const int size_jetMetPhi = 2;
                    //                    bool lowDPhi = (deltaPhi(Jet4Momentum.Phi(),pfMETPhi) < 0.5 || deltaPhi(Mu4Momentum.Phi(),pfMETPhi) < 0.5 );
                    //                    bool HighDPhi = (deltaPhi(Jet4Momentum.Phi(),pfMETPhi) >= 0.5 && deltaPhi(Mu4Momentum.Phi(),pfMETPhi) >= 0.5  );
                    //
                    //                    bool jetMetPhi_category[size_jetMetPhi] = {lowDPhi,HighDPhi};
                    //                    std::string jetMetPhi_Cat[size_jetMetPhi] = {"_LowDPhi", "_HighDPhi"};
                    //
                    const int size_jetMetPhi = 1;
                    //                    bool lowDPhi = (deltaPhi(Jet4Momentum.Phi(),pfMETPhi) < 0.5 || deltaPhi(Mu4Momentum.Phi(),pfMETPhi) < 0.5 );
//                    bool HighDPhi = (deltaPhi(Jet4Momentum.Phi(),pfMETPhi) >= 0.5 && deltaPhi(Mu4Momentum.Phi(),pfMETPhi) >= 0.5  );
                    bool HighDPhi = 1;
                    
                    bool jetMetPhi_category[size_jetMetPhi] = {HighDPhi};
                    std::string jetMetPhi_Cat[size_jetMetPhi] = {"_HighDPhi"};
                    
                    //###############################################################################################
                    //  TTbar & DY control region Categorization
                    //###############################################################################################
                    const int size_CR = 3;
                    
                    bool signalRegion = 1;//XXX
//                    bool signalRegion = numZboson + numElectron  < 1  && numBJet < 1;
                    bool TTcontrolRegion_DiLep =1;
                    if (TTcontrolRegion_DiLep) FinalBTagSF=1;
                    bool TTcontrolRegion_SingleLep = 1;
                    
                    bool region_category[size_CR] = {signalRegion,TTcontrolRegion_DiLep,TTcontrolRegion_SingleLep};
                    std::string region_Cat[size_CR] = {"", "_ttbarCRDiLep","_ttbarCRSingleLep"};
                    
                    //###############################################################################################
                    //  Top Pt Reweighting Cat: The SF is meant to correct only the shape of the pt(top) distribution- not the amount of generated events ( you have to consider that the average weight is not 1 ! ) So we define two category for ttbar events
                    
//                    //###############################################################################################
                    int size_topPtRW =1;
                    
                    float TotalWeight[1] = {1};
                    std::string topPtRW[1] = {""};
                    
//                    if (isTTJets == string::npos) size_topPtRW = 1; // If the sample in not ttbar, don't care about new category
                    
                    //###############################################################################################
//                    cout<<"Event: "<<event <<", Lumi: "<<lumis <<", Run: "<<run <<"\n";
                    std::string CHL="MuJet";
                    
//                    plotFill("Weight_Mu", MuonCor,200,0,2);
//                    plotFill("Weight_Ele", ElectronCor,200,0,2);
//                    plotFill("TotalWeight_Mu",TotalWeight[0]*MuonCor,1000,0,10);
//                    plotFill("TotalNonLumiWeight_Mu",TotalWeight[0]*MuonCor/LumiWeight,200,0,2);
                    
                    
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
//                                                        float FullWeight = TotalWeight[itopRW] * MuonCor *ElectronCor * FinalBTagSF;
                                                        float FullWeight = TotalWeight[itopRW] ;
                                                        std::string FullStringName = topPtRW[itopRW] + MT_Cat[imt] + jetMetPhi_Cat[jpt] +  region_Cat[iCR] + iso_Cat[iso]  ;
                                                        
                                                        
                                                        
                                                        
                                                        //##################
                                                        //This check is used to make sure that each event is just filled once for any of the categories ==> No doube-counting of events  (this is specially important for ttbar events where we have many jets and leptons)
                                                        if (!( std::find(HistNamesFilled.begin(), HistNamesFilled.end(), FullStringName) != HistNamesFilled.end())){
                                                            HistNamesFilled.push_back(FullStringName);
                                                            
                                                            //                                                            if (LQ4Momentum.M() > 1100 && LQ4Momentum.M() < 1400 && jetPt->at(ijet) < 200){
                                                            //                                                                if (LQ4Momentum.M() > 1100 && muPt->at(imu) < 300){
                                                            //                                                                    if ( pfMET < 300){
                                                            if (1){
                                                                cout<<"Event: "<<event <<", Lumi: "<<lumis <<", Run: "<<run <<"\n";
                                                                //##################
                                                                //                                                            plotFill(CHL+"_ElectronEffVeto"+FullStringName,ElectronEffVeto,300,0,3);
//                                                                plotFill(CHL+"_tmass_MuMet"+FullStringName,tmass_MuMet,200,0,2000,FullWeight);
                                                                plotFill(CHL+"_MET"+FullStringName,pfMET,200,0,2000,1);
//                                                                plotFill(CHL+"_JetPt"+FullStringName,jetPt->at(ijet) ,2000,0,2000,FullWeight);
//                                                                plotFill(CHL+"_JetEta"+FullStringName,jetEta->at(ijet),120,-3,3,FullWeight);
//                                                                plotFill(CHL+"_LepPt"+FullStringName,muPt->at(imu),2000,0,2000,FullWeight);
////                                                                plotFill(CHL+"_LepPtX"+FullStringName,muptX,2000,0,2000,FullWeight);
//                                                                plotFill(CHL+"_LepPtDifference"+FullStringName,(muptX-muPt->at(imu))/muPt->at(imu),400,.2,2,FullWeight);
//                                                                plotFill(CHL+"_LepEta"+FullStringName,muEta->at(imu),100,-2.5,2.5,FullWeight);
//                                                                plotFill(CHL+"_LepPtSubLeading"+FullStringName,SecondMuPt,2000,0,2000,FullWeight);
//                                                                
//                                                                //                                                            plotFill(CHL+"_CloseJetLepPt"+FullStringName,CLoseJetMuPt,2000,0,2000,FullWeight);
//                                                                //
//                                                                //                                                            //                                                                    plotFill(CHL+"_nVtx"+FullStringName,nVtx,50,0,50,FullWeight);
//                                                                //                                                            //                                                                    plotFill(CHL+"_nVtx_NoPU"+FullStringName,nVtx,50,0,50,FullWeight/ PUWeight);
//                                                                //
//                                                                plotFill(CHL+"_tmass_LQMet"+FullStringName,tmass_LQMet,200,0,2000,FullWeight);
                                                                plotFill(CHL+"_LQMass"+FullStringName,LQ4Momentum.M(),200,0,2000,1);
//                                                                plotFill(CHL+"_LQMassCorrMuScale"+FullStringName,(Jet4Momentum + MuScaleCorr4Momentum).M(),200,0,2000,FullWeight);
//                                                                plotFill(CHL+"_LQMassDifference"+FullStringName,((Jet4Momentum + MuScaleCorr4Momentum).M() - LQ4Momentum.M())/LQ4Momentum.M(),200,-.1,.1,FullWeight);
//                                                                if (fabs(muEta->at(imu)) < 1.5) plotFill(CHL+"_LQMassDifference_Barrel"+FullStringName,((Jet4Momentum + MuScaleCorr4Momentum).M() - LQ4Momentum.M())/LQ4Momentum.M(),200,-.1,.1,FullWeight);
//                                                                if (fabs(muEta->at(imu)) > 1.5) plotFill(CHL+"_LQMassDifference_EndCap"+FullStringName,((Jet4Momentum + MuScaleCorr4Momentum).M() - LQ4Momentum.M())/LQ4Momentum.M(),200,-.1,.1,FullWeight);
//                                                                plotFill(CHL+"_dPhi_Jet_Met"+FullStringName,deltaPhi(Jet4Momentum.Phi(),pfMETPhi),160,0,3.2,FullWeight);
//                                                                plotFill(CHL+"_dPhi_Mu_Met"+FullStringName,deltaPhi(Mu4Momentum.Phi(),pfMETPhi),160,0,3.2,FullWeight);
//                                                                plotFill(CHL+"_dPhi_Mu_Jet"+FullStringName,deltaPhi(Mu4Momentum.Phi(),Jet4Momentum.Phi()),160,0,3.2,FullWeight);
//                                                                //
//                                                                
//                                                                plotFill(CHL+"_BosonKFactor"+FullStringName,ZBosonKFactor*WBosonKFactor,200,0,2,FullWeight);
//                                                                plotFill(CHL+"_WBosonPt"+FullStringName,WBosonPt,150,0,1500,FullWeight);
//                                                                plotFill(CHL+"_ZBosonPt"+FullStringName,ZBosonPt,150,0,1500,FullWeight);
//                                                                plotFill(CHL+"_NumJet"+FullStringName,numJet,10,0,10,FullWeight);
//                                                                plotFill(CHL+"_NumBJet"+FullStringName,numBJet,10,0,10,FullWeight);
//                                                                plotFill(CHL+"_WBosonMass"+FullStringName,WBosonMass,200,0,2000,FullWeight);
//                                                                plotFill(CHL+"_genHT"+FullStringName,genHT,200,0,2000,FullWeight);
//                                                                plotFill(CHL+"_recoHT"+FullStringName,recoHT,300,0,3000,FullWeight);
//                                                                plotFill(CHL+"_ST"+FullStringName,recoHT+muPt->at(imu),300,0,3000,FullWeight);
//                                                                //                                                            plotFill("_FinalBTagSF"+FullStringName, FinalBTagSF,200,0,2);
//                                                                plotFill(CHL+"_dR_Mu_Jet"+FullStringName,Jet4Momentum.DeltaR(Mu4Momentum),500,0,5,FullWeight);
//                                                                plotFill(CHL+"_dEta_Mu_Jet"+FullStringName,Jet4Momentum.Eta() - Mu4Momentum.Eta(),1000,-5,5,FullWeight);
//                                                                
////                                                                plotFill(CHL+"_numMuon"+FullStringName,numMuon,10,0,10);
////                                                                
////                                                                plotFill(CHL+"_JetPhi"+FullStringName,jetPhi->at(ijet) ,640,-3.2,3.2,FullWeight);
////                                                                plotFill(CHL+"_LepPhi"+FullStringName,muPhi->at(imu) ,640,-3.2,3.2,FullWeight);
////                                                                plotFill(CHL+"_METPhi"+FullStringName,pfMETPhi ,640,-3.2,3.2,FullWeight);
//                                                                
//                                                                plotFill(CHL+"_jetCHF"+FullStringName, jetCHF->at(ijet),100,0,1,FullWeight);
//                                                                plotFill(CHL+"_jetNHF"+FullStringName, jetNHF->at(ijet),100,0,1,FullWeight);
//                                                                plotFill(CHL+"_jetCEF"+FullStringName, jetCEF->at(ijet),100,0,1,FullWeight);
//                                                                plotFill(CHL+"_jetNEF"+FullStringName, jetNEF->at(ijet),100,0,1,FullWeight);
//                                                                plotFill(CHL+"_jetNCH"+FullStringName, jetNCH->at(ijet),100,0,1,FullWeight);
//                                                                plotFill(CHL+"_jetNNP"+FullStringName, jetNNP->at(ijet),100,0,1,FullWeight);
                                                                
                                                                
                                                                
                                                                
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
