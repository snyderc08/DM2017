#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "TLegend.h"
#include "TPolyLine.h"
#include "TPad.h"
#include "TLatex.h"
#include "TMath.h"
#include "stdio.h"
#include "TBox.h"
#include "TPave.h"
#include "TPaveText.h"
#include "TColor.h"
#include "TGraphErrors.h"
#include <TPaletteAxis.h>
#include <iostream>     // std::cout, std::ostream, std::ios
#include <fstream>      // std::filebuf
#include <string>


template <typename T> string tostr(const T& t) {
    ostringstream os;
    os<<t;
    return os.str();
}


double intersection(double m1, double m2,
                    double y11, double y12, double y21, double y22) {
    // y = ax + b
    // y11 = am1 + b
    // y12 = am2 + b
    double a1 = (y11 - y12)/(m1 - m2);
    double b1 = y11 - a1*m1;
    
    double a2 = (y21 - y22)/(m1 - m2);
    double b2 = y21 - a2*m1;
    
    // overlap: a1*m + b1 = a2*m + b2 => (a1 - a2)*m = (b2 - b1)
    double m = (b2 - b1)/(a1 - a2);
    cout<< m1<< "  "<< m2<<"  "<<y11<<"  "<<  y12<<"  "<< y21<<"  "<<  y22<< " ---> m=  "<<  m <<"  \n";
    if ( m > m2 || m < m1 ) return 0;
    //    if ( m > m2 ) return 0;
    return m;
}




void Limit_2D_RHW(){
    using namespace std;
    //=========Macro generated from canvas: can2/can2
    //=========  (Wed Oct 14 14:57:25 2015) by ROOT version5.32/04
    //   TCanvas *can2 = new TCanvas("can2", "can2",183,30,800,746);
    TCanvas* can2 = new TCanvas("c1", "c1",0,45,600,600);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    //    can2->Range(-20.96775,-3.205128,785.4839,48.07692);
    can2->SetFillColor(0);
    can2->SetBorderMode(0);
    can2->SetBorderSize(2);
    can2->SetTickx(1);
    can2->SetTicky(1);
    
    can2->SetBottomMargin(0.16);
    
    can2->SetLeftMargin(0.15);
    
    can2->SetRightMargin(0.23);
    
    can2->SetTopMargin(0.06);
    
    can2->SetFrameFillColor(1);
    can2->SetFrameFillStyle(0);
    can2->SetFrameLineStyle(0);
    can2->SetFrameBorderMode(0);
    can2->SetFrameFillColor(1);
    can2->SetFrameFillStyle(0);
    can2->SetFrameLineStyle(0);
    can2->SetFrameBorderMode(0);
    can2->SetLogz();
    
    
    
    
    
    
    
    
    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",6,1250,4250,12,875,3875);
    hlimitxsec2->SetBinContent( 1 , 1 , 36.7736816406 ); // 800_300
    hlimitxsec2->SetBinContent( 2 , 2 , 42.2058105469 ); // 900_350
    hlimitxsec2->SetBinContent( 3 , 3 , 17.0440673828 ); // 2000_MNu-1000
//    hlimitxsec2->SetBinContent( 2 , 2 , 15.8233642578 ); // 2000_MNu-1250
//    hlimitxsec2->SetBinContent( 2 , 3 , 14.6179199219 ); // 2000_MNu-1500
//    hlimitxsec2->SetBinContent( 2 , 4 , 16.7083740234 ); // 2000_MNu-1750
//    hlimitxsec2->SetBinContent( 3 , 1 , 10.1013183594 ); // 2500_MNu-1000
//    hlimitxsec2->SetBinContent( 3 , 2 , 8.92639160156 ); // 2500_MNu-1250
//    hlimitxsec2->SetBinContent( 3 , 3 , 8.17108154297 ); // 2500_MNu-1500
//    hlimitxsec2->SetBinContent( 3 , 4 , 7.88116455078 ); // 2500_MNu-1750
//    hlimitxsec2->SetBinContent( 3 , 5 , 7.63702392578 ); // 2500_MNu-2000
//    hlimitxsec2->SetBinContent( 3 , 6 , 8.30841064453 ); // 2500_MNu-2250
//    hlimitxsec2->SetBinContent( 4 , 1 , 7.32040405273 ); // 3000_MNu-1000
//    hlimitxsec2->SetBinContent( 4 , 2 , 6.25228881836 ); // 3000_MNu-1250
//    hlimitxsec2->SetBinContent( 4 , 3 , 5.58853149414 ); // 3000_MNu-1500
//    hlimitxsec2->SetBinContent( 4 , 4 , 5.22232055664 ); // 3000_MNu-1750
//    hlimitxsec2->SetBinContent( 4 , 5 , 4.71878051758 ); // 3000_MNu-2000
//    hlimitxsec2->SetBinContent( 4 , 6 , 4.61196899414 ); // 3000_MNu-2250
//    hlimitxsec2->SetBinContent( 4 , 7 , 4.54330444336 ); // 3000_MNu-2500
//    hlimitxsec2->SetBinContent( 4 , 8 , 5.24520874023 ); // 3000_MNu-2750
//    hlimitxsec2->SetBinContent( 5 , 1 , 6.8244934082 ); // 3500_MNu-1000
//    hlimitxsec2->SetBinContent( 5 , 2 , 5.42068481445 ); // 3500_MNu-1250
//    hlimitxsec2->SetBinContent( 5 , 3 , 4.80270385742 ); // 3500_MNu-1500
//    hlimitxsec2->SetBinContent( 5 , 4 , 4.37164306641 ); // 3500_MNu-1750
//    hlimitxsec2->SetBinContent( 5 , 5 , 4.00924682617 ); // 3500_MNu-2000
//    hlimitxsec2->SetBinContent( 5 , 6 , 3.7784576416 ); // 3500_MNu-2250
//    hlimitxsec2->SetBinContent( 5 , 7 , 3.58581542969 ); // 3500_MNu-2500
//    hlimitxsec2->SetBinContent( 5 , 8 , 3.61824035645 ); // 3500_MNu-2750
//    hlimitxsec2->SetBinContent( 5 , 9 , 3.61251831055 ); // 3500_MNu-3000
//    hlimitxsec2->SetBinContent( 5 , 10 , 4.18472290039 ); // 3500_MNu-3250
//    hlimitxsec2->SetBinContent( 6 , 1 , 7.38143920898 ); // 4000_MNu-1000
//    hlimitxsec2->SetBinContent( 6 , 2 , 5.69152832031 ); // 4000_MNu-1250
//    hlimitxsec2->SetBinContent( 6 , 3 , 4.81414794922 ); // 4000_MNu-1500
//    hlimitxsec2->SetBinContent( 6 , 4 , 4.32586669922 ); // 4000_MNu-1750
//    hlimitxsec2->SetBinContent( 6 , 5 , 3.96347045898 ); // 4000_MNu-2000
//    hlimitxsec2->SetBinContent( 6 , 6 , 3.68118286133 ); // 4000_MNu-2250
//    hlimitxsec2->SetBinContent( 6 , 7 , 3.44657897949 ); // 4000_MNu-2500
//    hlimitxsec2->SetBinContent( 6 , 8 , 3.40270996094 ); // 4000_MNu-2750
//    hlimitxsec2->SetBinContent( 6 , 9 , 3.27491760254 ); // 4000_MNu-3000
//    hlimitxsec2->SetBinContent( 6 , 10 , 3.21388244629 ); // 4000_MNu-3250
//    hlimitxsec2->SetBinContent( 6 , 11 , 3.34358215332 ); // 4000_MNu-3500
//    hlimitxsec2->SetBinContent( 6 , 12 , 3.86428833008 ); // 4000_MNu-3750
    
    
    
    
    
    
    
    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit->SetBinContent( 1 , 1 , 0.126805798761 ); // 1500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 1 , 2 , 0.145537277748 ); // 1500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 2 , 1 , 0.259699335408 ); // 2000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 2 , 2 , 0.241099562057 ); // 2000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 2 , 3 , 0.222732285873 ); // 2000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 2 , 4 , 0.254584397736 ); // 2000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 3 , 1 , 0.526110331217 ); // 2500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 3 , 2 , 0.464916229248 ); // 2500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 3 , 3 , 0.425577163696 ); // 2500_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 3 , 4 , 0.410477320353 ); // 2500_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 3 , 5 , 0.397761662801 ); // 2500_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 3 , 6 , 0.432729721069 ); // 2500_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 4 , 1 , 1.21399735535 ); // 3000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 4 , 2 , 1.03686381731 ); // 3000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 4 , 3 , 0.926787975811 ); // 3000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 4 , 4 , 0.866056477055 ); // 3000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 4 , 5 , 0.782550666265 ); // 3000_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 4 , 6 , 0.764837312461 ); // 3000_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 4 , 7 , 0.753450156444 ); // 3000_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 4 , 8 , 0.869852195727 ); // 3000_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 5 , 1 , 3.26530785081 ); // 3500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 5 , 2 , 2.59362909782 ); // 3500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 5 , 3 , 2.29794442939 ); // 3500_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 5 , 4 , 2.09169524708 ); // 3500_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 5 , 5 , 1.91829991683 ); // 3500_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 5 , 6 , 1.80787446967 ); // 3500_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 5 , 7 , 1.71570116253 ); // 3500_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 5 , 8 , 1.73121548155 ); // 3500_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 5 , 9 , 1.72847766055 ); // 3500_MNu-3000
    ExpctedExclusionLimit->SetBinContent( 5 , 10 , 2.00225976095 ); // 3500_MNu-3250
    ExpctedExclusionLimit->SetBinContent( 6 , 1 , 9.21527991134 ); // 4000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 6 , 2 , 7.10552848978 ); // 4000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 6 , 3 , 6.01017222125 ); // 4000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 6 , 4 , 5.40058264572 ); // 4000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 6 , 5 , 4.94815288263 ); // 4000_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 6 , 6 , 4.59573390927 ); // 4000_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 6 , 7 , 4.30284516791 ); // 4000_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 6 , 8 , 4.24807735448 ); // 4000_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 6 , 9 , 4.08853633276 ); // 4000_MNu-3000
    ExpctedExclusionLimit->SetBinContent( 6 , 10 , 4.01233763582 ); // 4000_MNu-3250
    ExpctedExclusionLimit->SetBinContent( 6 , 11 , 4.17425986682 ); // 4000_MNu-3500
    ExpctedExclusionLimit->SetBinContent( 6 , 12 , 4.8243300001 ); // 4000_MNu-3750
    
    
    
    
    
    
    
    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
    ObservedExclusionLimit->SetBinContent( 1 , 1 , 0.0950307813835 ); // 1500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 1 , 2 , 0.10411667902 ); // 1500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 2 , 1 , 0.261020243298 ); // 2000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 2 , 2 , 0.246039425294 ); // 2000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 2 , 3 , 0.242039646103 ); // 2000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 2 , 4 , 0.280198430338 ); // 2000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 3 , 1 , 0.627917893487 ); // 2500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 3 , 2 , 0.548818389725 ); // 2500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 3 , 3 , 0.503434819895 ); // 2500_MNu-1500
    ObservedExclusionLimit->SetBinContent( 3 , 4 , 0.49001636764 ); // 2500_MNu-1750
    ObservedExclusionLimit->SetBinContent( 3 , 5 , 0.447376110257 ); // 2500_MNu-2000
    ObservedExclusionLimit->SetBinContent( 3 , 6 , 0.482911528781 ); // 2500_MNu-2250
    ObservedExclusionLimit->SetBinContent( 4 , 1 , 1.37117271551 ); // 3000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 4 , 2 , 1.19948551417 ); // 3000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 4 , 3 , 1.06336148981 ); // 3000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 4 , 4 , 0.982686014038 ); // 3000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 4 , 5 , 0.86955472597 ); // 3000_MNu-2000
    ObservedExclusionLimit->SetBinContent( 4 , 6 , 0.839443716863 ); // 3000_MNu-2250
    ObservedExclusionLimit->SetBinContent( 4 , 7 , 0.818356396888 ); // 3000_MNu-2500
    ObservedExclusionLimit->SetBinContent( 4 , 8 , 0.936254041373 ); // 3000_MNu-2750
    ObservedExclusionLimit->SetBinContent( 5 , 1 , 3.80769703634 ); // 3500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 5 , 2 , 2.96112011129 ); // 3500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 5 , 3 , 2.60040562123 ); // 3500_MNu-1500
    ObservedExclusionLimit->SetBinContent( 5 , 4 , 2.39352890711 ); // 3500_MNu-1750
    ObservedExclusionLimit->SetBinContent( 5 , 5 , 2.10939712902 ); // 3500_MNu-2000
    ObservedExclusionLimit->SetBinContent( 5 , 6 , 2.0032994527 ); // 3500_MNu-2250
    ObservedExclusionLimit->SetBinContent( 5 , 7 , 1.85492759262 ); // 3500_MNu-2500
    ObservedExclusionLimit->SetBinContent( 5 , 8 , 1.86335874013 ); // 3500_MNu-2750
    ObservedExclusionLimit->SetBinContent( 5 , 9 , 1.84123123965 ); // 3500_MNu-3000
    ObservedExclusionLimit->SetBinContent( 5 , 10 , 2.16386453388 ); // 3500_MNu-3250
    ObservedExclusionLimit->SetBinContent( 6 , 1 , 10.8314092636 ); // 4000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 6 , 2 , 8.06335449207 ); // 4000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 6 , 3 , 6.85797626702 ); // 4000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 6 , 4 , 6.22107128551 ); // 4000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 6 , 5 , 5.46303578685 ); // 4000_MNu-2000
    ObservedExclusionLimit->SetBinContent( 6 , 6 , 5.051333824 ); // 4000_MNu-2250
    ObservedExclusionLimit->SetBinContent( 6 , 7 , 4.66172013909 ); // 4000_MNu-2500
    ObservedExclusionLimit->SetBinContent( 6 , 8 , 4.62821358741 ); // 4000_MNu-2750
    ObservedExclusionLimit->SetBinContent( 6 , 9 , 4.40761294997 ); // 4000_MNu-3000
    ObservedExclusionLimit->SetBinContent( 6 , 10 , 4.39137604584 ); // 4000_MNu-3250
    ObservedExclusionLimit->SetBinContent( 6 , 11 , 4.50247326165 ); // 4000_MNu-3500
    ObservedExclusionLimit->SetBinContent( 6 , 12 , 5.1747618871 ); // 4000_MNu-3750
    
    
    
    
    Double_t XS[6] = {2.9E-1,6.563E-02,1.92E-02,6.030E-03,0.00209,0.000801};
    
    
    Double_t WMass[7] = {
        1500,
        2000,
        2500,
        3000,
        3500,
        4000,
        4001};
    
    
    Double_t NuMass[12] = {
        1000,
        1250,
        1500,
        1750,
        2000,
        2250,
        2500,
        2750,
        3000,
        3250,
        3500,
        3750
    };
    
    
    
    vector <float> exclusion_expected;
    vector <float> exclusion_observed;
    exclusion_expected.clear();
    exclusion_observed.clear();
    
    
    
    
    for (int jj =1 ; jj < ExpctedExclusionLimit->GetYaxis()->GetNbins()+1; jj++){
        float ExpLim =0;
        float ObsLim =0;
        
        for (int ii =1 ; ii < ExpctedExclusionLimit->GetXaxis()->GetNbins()+1; ii++){
            
            
            
            ExpLim = intersection(WMass[ii-1], WMass[ii], 1, 1, ExpctedExclusionLimit->GetBinContent(ii,jj), ExpctedExclusionLimit->GetBinContent(ii+1,jj));
            
            
            if (ExpLim) break;
        }
        
        
        for (int ii =1 ; ii < ObservedExclusionLimit->GetXaxis()->GetNbins()+1; ii++){
            
            
            
            ObsLim = intersection(WMass[ii-1], WMass[ii], 1, 1, ObservedExclusionLimit->GetBinContent(ii,jj), ObservedExclusionLimit->GetBinContent(ii+1,jj));
            
            
            if (ObsLim) break;
        }
        
        
        if (ExpLim && ExpLim < 4000) {
            
            cout <<NuMass[jj-1] <<" Exp="<<ExpLim<< "    &&&&&&&  Obs="<<ObsLim<<"\n";
            
            
            //                if (ExpLim > NuMass[jj-1] &&  ObsLim > NuMass[jj-1]){
            exclusion_expected.push_back(ExpLim);
            exclusion_observed.push_back(ObsLim);
            //                }
            
        }
    }
    
    
    cout<<exclusion_expected.size()<<"    "<<exclusion_observed.size()<<"\n";
    
 
    
    Int_t ck;   // for color index setting
    ck = TColor::GetColor("#000099");
    hlimitxsec2->SetLineColor(ck);
    hlimitxsec2->GetYaxis()->SetTitle("M_{N_{#tau}} [GeV]");
    hlimitxsec2->GetXaxis()->SetNdivisions(505);
    hlimitxsec2->GetXaxis()->SetLabelFont(42);
    hlimitxsec2->GetXaxis()->SetLabelOffset(0.007);
    hlimitxsec2->GetXaxis()->SetLabelSize(0.035);
    hlimitxsec2->GetXaxis()->SetTitleSize(0.05);
    hlimitxsec2->GetXaxis()->SetTitleFont(42);
    hlimitxsec2->GetXaxis()->SetTitle("M_{W_{R}} [GeV]");
    hlimitxsec2->GetYaxis()->SetNdivisions(505);
    hlimitxsec2->GetYaxis()->SetLabelFont(42);
    hlimitxsec2->GetYaxis()->SetLabelOffset(0.007);
    hlimitxsec2->GetYaxis()->SetLabelSize(0.035);
    hlimitxsec2->GetYaxis()->SetTitleSize(0.05);
    hlimitxsec2->GetYaxis()->SetTitleFont(42);
    hlimitxsec2->GetZaxis()->SetNdivisions(505);
    hlimitxsec2->GetZaxis()->SetLabelFont(42);
    hlimitxsec2->GetZaxis()->SetLabelOffset(0.007);
    hlimitxsec2->GetZaxis()->SetLabelSize(0.035);
    hlimitxsec2->GetZaxis()->SetTitleSize(0.045);
    hlimitxsec2->GetZaxis()->SetTitleFont(42);
    hlimitxsec2->GetZaxis()->SetRangeUser(2, 43);
    gStyle->SetPalette(74);
    hlimitxsec2->Draw("COLZ");
    
    
    
    
    
    TGraphErrors *gre = new TGraphErrors(exclusion_observed.size()-2);
    gre->SetName("Graph");
    gre->SetTitle("Graph");
    gre->SetFillColor(1);
    //    gre->SetLineStyle(10);
    gre->SetLineWidth(4);
    for (int kk=0;kk<exclusion_observed.size()-2;kk++){
        
        gre->SetPoint(kk, exclusion_observed[kk], NuMass[kk]);
        gre->SetPointError(kk,0,0);
        cout <<"Obs----->"<<kk<< " " <<exclusion_observed[kk]<< " "  <<NuMass[kk]<<"\n";
        
    }
    TH1F *Graph_Graph_Graph11 = new TH1F("Graph_Graph_Graph11","Graph",12,875,3875);
    Graph_Graph_Graph11->SetDirectory(0);
    Graph_Graph_Graph11->SetStats(0);
    cj = TColor::GetColor("#000099");
    gre->SetHistogram(Graph_Graph_Graph11);
//    gre->Draw("c");
    
    
    
    
    
    
    TGraphErrors *greExp = new TGraphErrors(exclusion_observed.size()-2);
    greExp->SetName("Graph");
    greExp->SetTitle("Graph");
    greExp->SetFillColor(1);
    greExp->SetLineStyle(2);
    greExp->SetLineWidth(3);
    for (int kk=0;kk<exclusion_expected.size()-2;kk++){
        
        greExp->SetPoint(kk, exclusion_expected[kk], NuMass[kk]);
        greExp->SetPointError(kk,0,0);
        cout <<"Exp----->"<<kk<< " " <<exclusion_expected[kk]<< " "  <<NuMass[kk]<<"\n";
        
    }
    TH1F *Graph_Graph_Graph11Exp = new TH1F("Graph_Graph_Graph11Exp","Graph",1100,1000,3250);
    Graph_Graph_Graph11Exp->SetDirectory(0);
    Graph_Graph_Graph11Exp->SetStats(0);
    greExp->SetHistogram(Graph_Graph_Graph11Exp);
//    greExp->Draw("c");
    
    
    
    
    TLegend *legendr = new TLegend(0.18,0.65,0.47,0.80,NULL,"brNDC");
    legendr->SetShadowColor(0);
    legendr->SetBorderSize(0);
    legendr->SetFillColor(0);
    legendr->AddEntry(gre,"Observed","L");
    legendr->AddEntry(greExp, "Expected", "L");
    legendr->SetFillStyle(0);
    legendr->SetTextSize(.04);
    legendr->SetTextFont(42);
    legendr->SetFillColor(0);
    legendr->SetBorderSize(0);
    legendr->Draw();
    
    
    
    float lowX=0.5;
    float lowY=0.85;
    TPaveText * lumi  = new TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC");
    lumi->SetBorderSize(   0 );
    lumi->SetFillStyle(    0 );
    lumi->SetTextAlign(   12 );
    lumi->SetTextColor(    1 );
    lumi->SetTextSize(0.04);
    lumi->SetTextFont (   42 );
    lumi->AddText("12.9 fb^{-1} (13 TeV)");
    lumi->Draw();
    
    
    lowX=0.18;
    lowY=0.75;
    TPaveText * lumi1  = new TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC");
    lumi1->SetTextFont(61);
    lumi1->SetTextSize(0.05);
    lumi1->SetBorderSize(   0 );
    lumi1->SetFillStyle(    0 );
    lumi1->SetTextAlign(   12 );
    lumi1->SetTextColor(    1 );
    lumi1->AddText("CMS");
    lumi1->Draw();
    
    
    
    
    
    TText *text = new TText(4900,904.522,"Cross section upper limit at 95% CL [fb]");
    text->SetTextFont(42);
    text->SetTextSize(0.04748603);
    text->SetTextAngle(90);
    text->Draw();
    can2->Modified();
    can2->cd();
    can2->SetSelected(can2);
    can2->SaveAs("limit_2D_RHW.pdf");
    
}

