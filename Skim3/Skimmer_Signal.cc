#define Skimmer_cxx
#include "Skimmer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TLorentzVector.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <TMath.h>
#include <string>
#include <sstream>
using namespace std;


void Skimmer::Loop(TString outputName, int skm)
{
    
    
    TH1F* hEvents = (TH1F*)gDirectory->Get("ggNtuplizer/hEvents");
    //    TH1F* hPU     = (TH1F*)gDirectory->Get("ggNtuplizer/hPU");
    //    TH1F* hPUTrue = (TH1F*)gDirectory->Get("ggNtuplizer/hPUTrue");
    //TH1F* hEvents = (TH1F*)gDirectory->Get("hEvents");
    //TH1F* hPU     = (TH1F*)gDirectory->Get("hPU");
    //TH1F* hPUTrue = (TH1F*)gDirectory->Get("hPUTrue");
    
    TFile* file = TFile::Open(outputName, "RECREATE");
    TTree* MyNewTree = fChain->CloneTree(0);
    
    fChain->SetBranchStatus("*",0);
    fChain->SetBranchStatus("hasGoodVtx",1);
    fChain->SetBranchStatus("vt*",1);
    fChain->SetBranchStatus("EventTag",1);
    fChain->SetBranchStatus("run",1);
    fChain->SetBranchStatus("event",1);
    fChain->SetBranchStatus("lumis",1);
    fChain->SetBranchStatus("isData",1);
    fChain->SetBranchStatus("HLT*",1);
    fChain->SetBranchStatus("gen*",1);
    fChain->SetBranchStatus("pdf*",1);
    fChain->SetBranchStatus("pthat",1);
    fChain->SetBranchStatus("processID",1);
    fChain->SetBranchStatus("rho*",1);
    fChain->SetBranchStatus("pu*",1);
    fChain->SetBranchStatus("mc*",1);
    fChain->SetBranchStatus("pfMET*",1);
    fChain->SetBranchStatus("n*",1);
    fChain->SetBranchStatus("c*",1);
    fChain->SetBranchStatus("jet*",1);
    fChain->SetBranchStatus("AK8*",0);
    fChain->SetBranchStatus("ele*",1);
    fChain->SetBranchStatus("mu*",1);
    fChain->SetBranchStatus("pho",0);
    fChain->SetBranchStatus("tau*",1);
   fChain->SetBranchStatus("m*",1); 
    
    TH1F* hcount = new TH1F("hcount", "", 10, 1, 10);
    
    if (fChain == 0) return;
    
    Long64_t nentries = fChain->GetEntriesFast();
    Long64_t nbytes = 0, nb = 0;
    float MuMass= 0.10565837;
    float eleMass= 0.000511;
    
    
    for (int jentry=0; jentry<nentries;jentry++) {
        
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        
        
        if(jentry % 10000 == 0) cout << "Processed " << jentry << " events out of " <<nentries<<endl;
        hcount->Fill(1);
        hcount->Fill(2,genWeight);
        
        
        bool isMuJet=0;
        bool isEleJet=0;
        
        TLorentzVector elei4Momentum, Jet4Momentum;
        
  
        if(pfMET < 100) continue;
        hcount->Fill(3);

        //MuJet
        for (int iele = 0; iele < nEle; ++iele){
            if (elePt->at(iele) > 60 &&  fabs(eleEta->at(iele)) < 2.5){
                
                // bool eleMVAId_i= false;
                // if (fabs (eleSCEta->at(iele)) <= 0.8 && eleIDMVA->at(iele) >   0.941  ) eleMVAId_i= true;
                // else if (fabs (eleSCEta->at(iele)) >  0.8 &&fabs (eleSCEta->at(iele)) <=  1.5 && eleIDMVA->at(iele) >   0.899  ) eleMVAId_i= true;
                // else if ( fabs (eleSCEta->at(iele)) >=  1.5 && eleIDMVA->at(iele) >  0.758  ) eleMVAId_i= true;
                // else eleMVAId_i= false;
                // if (eleMVAId_i) continue;

                bool eleMVAId_i= false;
                if (fabs (eleSCEta->at(iele)) <= 0.8 && eleIDMVA->at(iele) >  -0.870 ) eleMVAId_i= true;
                else if (fabs (eleSCEta->at(iele)) >  0.8 &&fabs (eleSCEta->at(iele)) <=  1.5 && eleIDMVA->at(iele) >   -0.838 ) eleMVAId_i= true;
                else if ( fabs (eleSCEta->at(iele)) >=  1.5 && eleIDMVA->at(iele) >  -0.763 ) eleMVAId_i= true;
                else eleMVAId_i= false;
                if (!(eleMVAId_i)) continue;                
                
                
                elei4Momentum.SetPtEtaPhiM(elePt->at(iele),eleEta->at(iele),elePhi->at(iele),eleMass);
                
                
                
                for (int ijet = 0; ijet < nJet; ++ijet){
Jet4Momentum.SetPtEtaPhiM(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
	if (jetPt->at(ijet) > 100 &&  fabs(jetEta->at(ijet)) < 3.0   && Jet4Momentum.DeltaR(elei4Momentum) > 0.5 ){
                            isEleJet=1;
                            break;
                            
                        }
                    }
                }
            }





        
        if(!(isEleJet)) continue;
        hcount->Fill(4);

        
        
        MyNewTree->Fill();
    }
    
    MyNewTree->AutoSave();
    hEvents->Write();
    hcount->Write();
    file->Close();
}

int main(int argc, char* argv[]){
    
    string FinaName=argv[1];
    stringstream ss(FinaName);
    
    string token;
    string M;
    int count=0;
    string realName;
    while (getline(ss,token, '/'))
    {
        count++;
        cout<< token <<endl;
        if (count == 5) {
            cout<<"   ----->    5   "<<token<<"  _____   \n";
            realName=token;
        }
        M=token;
    }
    
    TString outputName = "skimed_"+realName+M;
    cout<<" outputName is ---> "<<outputName<<"\n";
    
    //Skimmer t("root://cmsxrootd.fnal.gov//store/user/snyderc3/DM_Electron/"+FinaName);
    Skimmer t("root://cmsxrootd.fnal.gov//store/user/oneogi/Moriond17/SignalPrivate/"+FinaName);

    //FinaName.erase(FinaName.begin(),FinaName.end()-10);
    //  Skimmer t("root://cmsxrootd.fnal.gov//"+FinaName);
    t.Loop(outputName, 0);
    return 0;
}









