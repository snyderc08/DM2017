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

void  SayHi(){
    
    std::cout<<"Hi  ---->\n";
};


#include <string>
#include <ostream>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH1.h"
#include "TH2.h"
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



#include <stdlib.h>
#include "cJSON.h"

////using namespace std;
//
///* Parse text to JSON, then render back to text, and print! */
//void doit(char *text)
//{
//    char *out;cJSON *json;
//
//    json=cJSON_Parse(text);
//    if (!json) {printf("Error before: [%s]\n",cJSON_GetErrorPtr());}
//    else
//    {
//        out=cJSON_Print(json);
//        cJSON_Delete(json);
////        if (std::string(out)==std::string("	},")) printf("%s\n",out);
//        std::cout<<out<<"\n";
//        std::cout << "The size of the chars is: "
//        << strlen( out )
//        << " chars (including null)\n";
////        printf("%s\n",out);
//        free(out);
//    }
//}
//
///* Read a file, parse, render back, etc. */
//void dofile(char *filename)
//{
//    FILE *f;long len;char *data;
//
//    f=fopen(filename,"rb");fseek(f,0,SEEK_END);len=ftell(f);fseek(f,0,SEEK_SET);
//    data=(char*)malloc(len+1);fread(data,1,len,f);data[len]='\0';fclose(f);
//    doit(data);
//    free(data);
//}


double intersection(
                    double y2, double y1, double x2, double x1) {
//    // y = ax + b
//    // y11 = am1 + b
//    // y12 = am2 + b
//    double a1 = (y11 - y12)/(m1 - m2);
//    double b1 = y11 - a1*m1;
//    
//    double a2 = (y21 - y22)/(m1 - m2);
//    double b2 = y21 - a2*m1;
//    
//    // overlap: a1*m + b1 = a2*m + b2 => (a1 - a2)*m = (b2 - b1)
//    double m = (b2 - b1)/(a1 - a2);
//    if ( m > m2 || m < m1 ) return 0;
    
   float  m = (y1-y2 + y2*x1-y1*x2 )/(x1-x2);
    cout << y2<<  "  "   <<y1<<  "  "   <<x2<<  "  "   <<x1<<  "  "   <<m<<"\n";
    return m;
}




void DMLimit_2D_Proj(){
    
    
    //  This part is for calculating the DM relic density band
    
    
    char buffer[1024] ;
    char *record,*line,*rec1,*rec2,*subtoken, *savedEndd1;
    char *recordHigh,*lineHigh,*rec1High,*rec2High,*subtokenHigh, *savedEndd1High;
    
    const Int_t nrelic = 700;
    vector <float> x__;
    vector <float> ymax__;
    vector <float> ymin__;
    
    FILE *HighContour = fopen("Felix_Uppercontour_Delta01.csv","r");
    while((lineHigh=fgets(buffer,sizeof(buffer),HighContour))!=NULL)
    {
        
        
        recordHigh = strtok(lineHigh,";");
        subtokenHigh = strtok_r(recordHigh, ",",&savedEndd1High);
        
        
        
        x__.push_back(atof(recordHigh));
        ymax__.push_back(atof(savedEndd1High));
        
        
        
    }
    
    
    FILE *LowContour = fopen("Felix_Lowercontour_Delta01.csv","r");
    while((line=fgets(buffer,sizeof(buffer),LowContour))!=NULL)
    {
        
        
        record = strtok(line,";");
        subtoken = strtok_r(record, ",",&savedEndd1);
        
        
        ymin__.push_back(atof(savedEndd1));
        
        
        
    }
    
    
    
    
    
    ///////////////
    
    
    const Int_t n = 800;
    Double_t x[n], y[n],ymin[n], ymax[n];
    Int_t i;
    for (i=0;i<n;i++) {
        x[i] = i+750;
        
        if (i < 50){
            ymax[i] = ymax__[0];
            ymin[i] = ymin__[0];
        }
        else if (i > 750){
            ymax[i] = ymax__[700];
            ymin[i] = ymin__[700];
            
        }
        else{
        
        ymax[i] = ymax__[i-50];
        ymin[i] = ymin__[i-50];
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;
    //=========Macro generated from canvas: can2/can2
    //=========  (Wed Oct 14 14:57:25 2015) by ROOT version5.32/04
    //   TCanvas *can2 = new TCanvas("can2", "can2",183,30,800,746);
    TCanvas* can2 = new TCanvas("can2", "can2",800,800);
    SayHi();
    gStyle->SetOptStat(0);
//    gStyle->SetLogz();
    gStyle->SetOptTitle(0);
    can2->Range(-20.96775,-3.205128,785.4839,48.07692);
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
    
    
    
    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",8,750,1550,9,275,725);
    hlimitxsec2->SetBinContent(3,1,0.289267); // Bin_1_LQ_1000_DM_300_X_330
    hlimitxsec2->SetBinContent(3,2,0.357916); // Bin_2_LQ_1000_DM_350_X_385
    hlimitxsec2->SetBinContent(3,3,0.570024); // Bin_3_LQ_1000_DM_400_X_440
    hlimitxsec2->SetBinContent(3,4,1.955956); // Bin_4_LQ_1000_DM_450_X_495
    hlimitxsec2->SetBinContent(4,1,0.429365); // Bin_5_LQ_1100_DM_300_X_330
    hlimitxsec2->SetBinContent(4,2,0.502002); // Bin_6_LQ_1100_DM_350_X_385
    hlimitxsec2->SetBinContent(4,3,0.624842); // Bin_7_LQ_1100_DM_400_X_440
    hlimitxsec2->SetBinContent(4,4,1.059760); // Bin_8_LQ_1100_DM_450_X_495
    hlimitxsec2->SetBinContent(4,5,3.996423); // Bin_9_LQ_1100_DM_500_X_550
    hlimitxsec2->SetBinContent(5,1,0.648521); // Bin_10_LQ_1200_DM_300_X_330
    hlimitxsec2->SetBinContent(5,2,0.679644); // Bin_11_LQ_1200_DM_350_X_385
    hlimitxsec2->SetBinContent(5,3,0.775329); // Bin_12_LQ_1200_DM_400_X_440
    hlimitxsec2->SetBinContent(5,4,1.021201); // Bin_13_LQ_1200_DM_450_X_495
    hlimitxsec2->SetBinContent(5,5,1.815251); // Bin_14_LQ_1200_DM_500_X_550
    hlimitxsec2->SetBinContent(5,6,8.659575); // Bin_15_LQ_1200_DM_550_X_595
    hlimitxsec2->SetBinContent(6,1,1.005002); // Bin_16_LQ_1300_DM_300_X_330
    hlimitxsec2->SetBinContent(6,2,1.072459); // Bin_17_LQ_1300_DM_350_X_385
    hlimitxsec2->SetBinContent(6,3,1.159178); // Bin_18_LQ_1300_DM_400_X_440
    hlimitxsec2->SetBinContent(6,4,1.363192); // Bin_19_LQ_1300_DM_450_X_495
    hlimitxsec2->SetBinContent(6,5,1.702000); // Bin_20_LQ_1300_DM_500_X_550
    hlimitxsec2->SetBinContent(6,6,3.288107); // Bin_21_LQ_1300_DM_550_X_605
    hlimitxsec2->SetBinContent(6,7,17.578915); // Bin_22_LQ_1300_DM_600_X_660
    hlimitxsec2->SetBinContent(7,1,1.587571); // Bin_23_LQ_1400_DM_300_X_330
    hlimitxsec2->SetBinContent(7,2,1.735148); // Bin_24_LQ_1400_DM_350_X_385
    hlimitxsec2->SetBinContent(7,3,1.666867); // Bin_25_LQ_1400_DM_400_X_440
    hlimitxsec2->SetBinContent(7,4,1.969599); // Bin_26_LQ_1400_DM_450_X_495
    hlimitxsec2->SetBinContent(7,5,2.132185); // Bin_27_LQ_1400_DM_500_X_550
    hlimitxsec2->SetBinContent(7,6,2.996720); // Bin_28_LQ_1400_DM_550_X_605
    hlimitxsec2->SetBinContent(7,7,5.895601); // Bin_29_LQ_1400_DM_600_X_660
    hlimitxsec2->SetBinContent(7,8,36.070465); // Bin_30_LQ_1400_DM_650_X_715
    hlimitxsec2->SetBinContent(8,1,2.651493); // Bin_31_LQ_1500_DM_300_X_330
    hlimitxsec2->SetBinContent(8,2,2.673876); // Bin_32_LQ_1500_DM_350_X_385
    hlimitxsec2->SetBinContent(8,3,2.685360); // Bin_33_LQ_1500_DM_400_X_440
    hlimitxsec2->SetBinContent(8,4,2.913223); // Bin_34_LQ_1500_DM_450_X_495
    hlimitxsec2->SetBinContent(8,5,3.213208); // Bin_35_LQ_1500_DM_500_X_550
    hlimitxsec2->SetBinContent(8,6,3.718067); // Bin_36_LQ_1500_DM_550_X_605
    hlimitxsec2->SetBinContent(8,7,5.056447); // Bin_37_LQ_1500_DM_600_X_660
    hlimitxsec2->SetBinContent(8,8,10.852397); // Bin_38_LQ_1500_DM_650_X_715
    hlimitxsec2->SetBinContent(8,9,81.125696); // Bin_39_LQ_1500_DM_700_X_770
    hlimitxsec2->SetBinContent(1,1,0.156922); // Bin_40_LQ_800_DM_300_X_330
    hlimitxsec2->SetBinContent(1,2,0.397192); // Bin_41_LQ_800_DM_350_X_385
    hlimitxsec2->SetBinContent(2,1,0.196409); // Bin_42_LQ_900_DM_300_X_330
    hlimitxsec2->SetBinContent(2,2,0.316031); // Bin_43_LQ_900_DM_350_X_385
    hlimitxsec2->SetBinContent(2,3,0.921189); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    
    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit->SetBinContent(3,1,0.289267); // Bin_1_LQ_1000_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(3,2,0.357916); // Bin_2_LQ_1000_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(3,3,0.570024); // Bin_3_LQ_1000_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(3,4,1.955956); // Bin_4_LQ_1000_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(4,1,0.429365); // Bin_5_LQ_1100_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(4,2,0.502002); // Bin_6_LQ_1100_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(4,3,0.624842); // Bin_7_LQ_1100_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(4,4,1.059760); // Bin_8_LQ_1100_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(4,5,3.996423); // Bin_9_LQ_1100_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(5,1,0.648521); // Bin_10_LQ_1200_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(5,2,0.679644); // Bin_11_LQ_1200_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(5,3,0.775329); // Bin_12_LQ_1200_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(5,4,1.021201); // Bin_13_LQ_1200_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(5,5,1.815251); // Bin_14_LQ_1200_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(5,6,8.659575); // Bin_15_LQ_1200_DM_550_X_595
    ExpctedExclusionLimit->SetBinContent(6,1,1.005002); // Bin_16_LQ_1300_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(6,2,1.072459); // Bin_17_LQ_1300_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(6,3,1.159178); // Bin_18_LQ_1300_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(6,4,1.363192); // Bin_19_LQ_1300_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(6,5,1.702000); // Bin_20_LQ_1300_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(6,6,3.288107); // Bin_21_LQ_1300_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(6,7,17.578915); // Bin_22_LQ_1300_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(7,1,1.587571); // Bin_23_LQ_1400_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(7,2,1.735148); // Bin_24_LQ_1400_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(7,3,1.666867); // Bin_25_LQ_1400_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(7,4,1.969599); // Bin_26_LQ_1400_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(7,5,2.132185); // Bin_27_LQ_1400_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(7,6,2.996720); // Bin_28_LQ_1400_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(7,7,5.895601); // Bin_29_LQ_1400_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(7,8,36.070465); // Bin_30_LQ_1400_DM_650_X_715
    ExpctedExclusionLimit->SetBinContent(8,1,2.651493); // Bin_31_LQ_1500_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(8,2,2.673876); // Bin_32_LQ_1500_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(8,3,2.685360); // Bin_33_LQ_1500_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(8,4,2.913223); // Bin_34_LQ_1500_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(8,5,3.213208); // Bin_35_LQ_1500_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(8,6,3.718067); // Bin_36_LQ_1500_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(8,7,5.056447); // Bin_37_LQ_1500_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(8,8,10.852397); // Bin_38_LQ_1500_DM_650_X_715
    ExpctedExclusionLimit->SetBinContent(8,9,81.125696); // Bin_39_LQ_1500_DM_700_X_770
    ExpctedExclusionLimit->SetBinContent(1,1,0.156922); // Bin_40_LQ_800_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(1,2,0.397192); // Bin_41_LQ_800_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(2,1,0.196409); // Bin_42_LQ_900_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(2,2,0.316031); // Bin_43_LQ_900_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(2,3,0.921189); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    
    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
    ObservedExclusionLimit->SetBinContent(3,1,0.289279); // Bin_1_LQ_1000_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(3,2,0.358996); // Bin_2_LQ_1000_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(3,3,0.573282); // Bin_3_LQ_1000_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(3,4,1.954438); // Bin_4_LQ_1000_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(4,1,0.429176); // Bin_5_LQ_1100_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(4,2,0.501960); // Bin_6_LQ_1100_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(4,3,0.623935); // Bin_7_LQ_1100_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(4,4,1.060401); // Bin_8_LQ_1100_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(4,5,4.010880); // Bin_9_LQ_1100_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(5,1,0.650662); // Bin_10_LQ_1200_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(5,2,0.680276); // Bin_11_LQ_1200_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(5,3,0.773067); // Bin_12_LQ_1200_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(5,4,1.024859); // Bin_13_LQ_1200_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(5,5,1.813006); // Bin_14_LQ_1200_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(5,6,8.648865); // Bin_15_LQ_1200_DM_550_X_595
    ObservedExclusionLimit->SetBinContent(6,1,1.005866); // Bin_16_LQ_1300_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(6,2,1.066548); // Bin_17_LQ_1300_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(6,3,1.156335); // Bin_18_LQ_1300_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(6,4,1.363991); // Bin_19_LQ_1300_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(6,5,1.699921); // Bin_20_LQ_1300_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(6,6,3.304206); // Bin_21_LQ_1300_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(6,7,17.600988); // Bin_22_LQ_1300_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(7,1,1.589347); // Bin_23_LQ_1400_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(7,2,1.734787); // Bin_24_LQ_1400_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(7,3,1.667313); // Bin_25_LQ_1400_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(7,4,1.974958); // Bin_26_LQ_1400_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(7,5,2.138360); // Bin_27_LQ_1400_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(7,6,2.999591); // Bin_28_LQ_1400_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(7,7,5.894277); // Bin_29_LQ_1400_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(7,8,36.131412); // Bin_30_LQ_1400_DM_650_X_715
    ObservedExclusionLimit->SetBinContent(8,1,2.651585); // Bin_31_LQ_1500_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(8,2,2.681157); // Bin_32_LQ_1500_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(8,3,2.684866); // Bin_33_LQ_1500_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(8,4,2.911914); // Bin_34_LQ_1500_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(8,5,3.210345); // Bin_35_LQ_1500_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(8,6,3.731346); // Bin_36_LQ_1500_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(8,7,5.043845); // Bin_37_LQ_1500_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(8,8,10.850439); // Bin_38_LQ_1500_DM_650_X_715
    ObservedExclusionLimit->SetBinContent(8,9,81.122662); // Bin_39_LQ_1500_DM_700_X_770
    ObservedExclusionLimit->SetBinContent(1,1,0.157372); // Bin_40_LQ_800_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(1,2,0.397613); // Bin_41_LQ_800_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(2,1,0.196651); // Bin_42_LQ_900_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(2,2,0.315818); // Bin_43_LQ_900_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(2,3,0.921190); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
//    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",8,750,1550,9,275,725);
//    hlimitxsec2->SetBinContent(3,1,0.351417); // Bin_1_LQ_1000_DM_300_X_330
//    hlimitxsec2->SetBinContent(3,2,0.432444); // Bin_2_LQ_1000_DM_350_X_385
//    hlimitxsec2->SetBinContent(3,3,0.693576); // Bin_3_LQ_1000_DM_400_X_440
//    hlimitxsec2->SetBinContent(3,4,2.369618); // Bin_4_LQ_1000_DM_450_X_495
//    hlimitxsec2->SetBinContent(4,1,0.526082); // Bin_5_LQ_1100_DM_300_X_330
//    hlimitxsec2->SetBinContent(4,2,0.615724); // Bin_6_LQ_1100_DM_350_X_385
//    hlimitxsec2->SetBinContent(4,3,0.765482); // Bin_7_LQ_1100_DM_400_X_440
//    hlimitxsec2->SetBinContent(4,4,1.294904); // Bin_8_LQ_1100_DM_450_X_495
//    hlimitxsec2->SetBinContent(4,5,4.932040); // Bin_9_LQ_1100_DM_500_X_550
//    hlimitxsec2->SetBinContent(5,1,0.808582); // Bin_10_LQ_1200_DM_300_X_330
//    hlimitxsec2->SetBinContent(5,2,0.850290); // Bin_11_LQ_1200_DM_350_X_385
//    hlimitxsec2->SetBinContent(5,3,0.968330); // Bin_12_LQ_1200_DM_400_X_440
//    hlimitxsec2->SetBinContent(5,4,1.275441); // Bin_13_LQ_1200_DM_450_X_495
//    hlimitxsec2->SetBinContent(5,5,2.256606); // Bin_14_LQ_1200_DM_500_X_550
//    hlimitxsec2->SetBinContent(5,6,10.765040); // Bin_15_LQ_1200_DM_550_X_595
//    hlimitxsec2->SetBinContent(6,1,1.253056); // Bin_16_LQ_1300_DM_300_X_330
//    hlimitxsec2->SetBinContent(6,2,1.328568); // Bin_17_LQ_1300_DM_350_X_385
//    hlimitxsec2->SetBinContent(6,3,1.435996); // Bin_18_LQ_1300_DM_400_X_440
//    hlimitxsec2->SetBinContent(6,4,1.695678); // Bin_19_LQ_1300_DM_450_X_495
//    hlimitxsec2->SetBinContent(6,5,2.115530); // Bin_20_LQ_1300_DM_500_X_550
//    hlimitxsec2->SetBinContent(6,6,4.113957); // Bin_21_LQ_1300_DM_550_X_605
//    hlimitxsec2->SetBinContent(6,7,21.825030); // Bin_22_LQ_1300_DM_600_X_660
//    hlimitxsec2->SetBinContent(7,1,1.996068); // Bin_23_LQ_1400_DM_300_X_330
//    hlimitxsec2->SetBinContent(7,2,2.189250); // Bin_24_LQ_1400_DM_350_X_385
//    hlimitxsec2->SetBinContent(7,3,2.084843); // Bin_25_LQ_1400_DM_400_X_440
//    hlimitxsec2->SetBinContent(7,4,2.482688); // Bin_26_LQ_1400_DM_450_X_495
//    hlimitxsec2->SetBinContent(7,5,2.683054); // Bin_27_LQ_1400_DM_500_X_550
//    hlimitxsec2->SetBinContent(7,6,3.780746); // Bin_28_LQ_1400_DM_550_X_605
//    hlimitxsec2->SetBinContent(7,7,7.381484); // Bin_29_LQ_1400_DM_600_X_660
//    hlimitxsec2->SetBinContent(7,8,45.219534); // Bin_30_LQ_1400_DM_650_X_715
//    hlimitxsec2->SetBinContent(8,1,3.341380); // Bin_31_LQ_1500_DM_300_X_330
//    hlimitxsec2->SetBinContent(8,2,3.386909); // Bin_32_LQ_1500_DM_350_X_385
//    hlimitxsec2->SetBinContent(8,3,3.389716); // Bin_33_LQ_1500_DM_400_X_440
//    hlimitxsec2->SetBinContent(8,4,3.700075); // Bin_34_LQ_1500_DM_450_X_495
//    hlimitxsec2->SetBinContent(8,5,4.045106); // Bin_35_LQ_1500_DM_500_X_550
//    hlimitxsec2->SetBinContent(8,6,4.712867); // Bin_36_LQ_1500_DM_550_X_605
//    hlimitxsec2->SetBinContent(8,7,6.410546); // Bin_37_LQ_1500_DM_600_X_660
//    hlimitxsec2->SetBinContent(8,8,13.704839); // Bin_38_LQ_1500_DM_650_X_715
//    hlimitxsec2->SetBinContent(8,9,102.654198); // Bin_39_LQ_1500_DM_700_X_770
//    hlimitxsec2->SetBinContent(1,1,0.189051); // Bin_40_LQ_800_DM_300_X_330
//    hlimitxsec2->SetBinContent(1,2,0.475843); // Bin_41_LQ_800_DM_350_X_385
//    hlimitxsec2->SetBinContent(2,1,0.236178); // Bin_42_LQ_900_DM_300_X_330
//    hlimitxsec2->SetBinContent(2,2,0.379473); // Bin_43_LQ_900_DM_350_X_385
//    hlimitxsec2->SetBinContent(2,3,1.109187); // Bin_44_LQ_900_DM_400_X_440
//    
//    
//    
//    
//    
//    
//    
//    
//    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
//    ExpctedExclusionLimit->SetBinContent(3,1,0.351417); // Bin_1_LQ_1000_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(3,2,0.432444); // Bin_2_LQ_1000_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(3,3,0.693576); // Bin_3_LQ_1000_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(3,4,2.369618); // Bin_4_LQ_1000_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(4,1,0.526082); // Bin_5_LQ_1100_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(4,2,0.615724); // Bin_6_LQ_1100_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(4,3,0.765482); // Bin_7_LQ_1100_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(4,4,1.294904); // Bin_8_LQ_1100_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(4,5,4.932040); // Bin_9_LQ_1100_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(5,1,0.808582); // Bin_10_LQ_1200_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(5,2,0.850290); // Bin_11_LQ_1200_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(5,3,0.968330); // Bin_12_LQ_1200_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(5,4,1.275441); // Bin_13_LQ_1200_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(5,5,2.256606); // Bin_14_LQ_1200_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(5,6,10.765040); // Bin_15_LQ_1200_DM_550_X_595
//    ExpctedExclusionLimit->SetBinContent(6,1,1.253056); // Bin_16_LQ_1300_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(6,2,1.328568); // Bin_17_LQ_1300_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(6,3,1.435996); // Bin_18_LQ_1300_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(6,4,1.695678); // Bin_19_LQ_1300_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(6,5,2.115530); // Bin_20_LQ_1300_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(6,6,4.113957); // Bin_21_LQ_1300_DM_550_X_605
//    ExpctedExclusionLimit->SetBinContent(6,7,21.825030); // Bin_22_LQ_1300_DM_600_X_660
//    ExpctedExclusionLimit->SetBinContent(7,1,1.996068); // Bin_23_LQ_1400_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(7,2,2.189250); // Bin_24_LQ_1400_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(7,3,2.084843); // Bin_25_LQ_1400_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(7,4,2.482688); // Bin_26_LQ_1400_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(7,5,2.683054); // Bin_27_LQ_1400_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(7,6,3.780746); // Bin_28_LQ_1400_DM_550_X_605
//    ExpctedExclusionLimit->SetBinContent(7,7,7.381484); // Bin_29_LQ_1400_DM_600_X_660
//    ExpctedExclusionLimit->SetBinContent(7,8,45.219534); // Bin_30_LQ_1400_DM_650_X_715
//    ExpctedExclusionLimit->SetBinContent(8,1,3.341380); // Bin_31_LQ_1500_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(8,2,3.386909); // Bin_32_LQ_1500_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(8,3,3.389716); // Bin_33_LQ_1500_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(8,4,3.700075); // Bin_34_LQ_1500_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(8,5,4.045106); // Bin_35_LQ_1500_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(8,6,4.712867); // Bin_36_LQ_1500_DM_550_X_605
//    ExpctedExclusionLimit->SetBinContent(8,7,6.410546); // Bin_37_LQ_1500_DM_600_X_660
//    ExpctedExclusionLimit->SetBinContent(8,8,13.704839); // Bin_38_LQ_1500_DM_650_X_715
//    ExpctedExclusionLimit->SetBinContent(8,9,102.654198); // Bin_39_LQ_1500_DM_700_X_770
//    ExpctedExclusionLimit->SetBinContent(1,1,0.189051); // Bin_40_LQ_800_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(1,2,0.475843); // Bin_41_LQ_800_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(2,1,0.236178); // Bin_42_LQ_900_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(2,2,0.379473); // Bin_43_LQ_900_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(2,3,1.109187); // Bin_44_LQ_900_DM_400_X_440
//    
//    
//    
//    
//    
//    
//    
//    
//    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
//    ObservedExclusionLimit->SetBinContent(3,1,0.350587); // Bin_1_LQ_1000_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(3,2,0.434727); // Bin_2_LQ_1000_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(3,3,0.694180); // Bin_3_LQ_1000_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(3,4,2.372185); // Bin_4_LQ_1000_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(4,1,0.525558); // Bin_5_LQ_1100_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(4,2,0.615725); // Bin_6_LQ_1100_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(4,3,0.763280); // Bin_7_LQ_1100_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(4,4,1.299469); // Bin_8_LQ_1100_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(4,5,4.928505); // Bin_9_LQ_1100_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(5,1,0.810263); // Bin_10_LQ_1200_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(5,2,0.850487); // Bin_11_LQ_1200_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(5,3,0.966514); // Bin_12_LQ_1200_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(5,4,1.278265); // Bin_13_LQ_1200_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(5,5,2.257691); // Bin_14_LQ_1200_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(5,6,10.770218); // Bin_15_LQ_1200_DM_550_X_595
//    ObservedExclusionLimit->SetBinContent(6,1,1.252248); // Bin_16_LQ_1300_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(6,2,1.326680); // Bin_17_LQ_1300_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(6,3,1.435970); // Bin_18_LQ_1300_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(6,4,1.694571); // Bin_19_LQ_1300_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(6,5,2.112679); // Bin_20_LQ_1300_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(6,6,4.109361); // Bin_21_LQ_1300_DM_550_X_605
//    ObservedExclusionLimit->SetBinContent(6,7,21.917441); // Bin_22_LQ_1300_DM_600_X_660
//    ObservedExclusionLimit->SetBinContent(7,1,1.996648); // Bin_23_LQ_1400_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(7,2,2.182570); // Bin_24_LQ_1400_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(7,3,2.091246); // Bin_25_LQ_1400_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(7,4,2.481505); // Bin_26_LQ_1400_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(7,5,2.693388); // Bin_27_LQ_1400_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(7,6,3.766953); // Bin_28_LQ_1400_DM_550_X_605
//    ObservedExclusionLimit->SetBinContent(7,7,7.418351); // Bin_29_LQ_1400_DM_600_X_660
//    ObservedExclusionLimit->SetBinContent(7,8,45.420752); // Bin_30_LQ_1400_DM_650_X_715
//    ObservedExclusionLimit->SetBinContent(8,1,3.348933); // Bin_31_LQ_1500_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(8,2,3.386598); // Bin_32_LQ_1500_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(8,3,3.391184); // Bin_33_LQ_1500_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(8,4,3.688397); // Bin_34_LQ_1500_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(8,5,4.059832); // Bin_35_LQ_1500_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(8,6,4.727298); // Bin_36_LQ_1500_DM_550_X_605
//    ObservedExclusionLimit->SetBinContent(8,7,6.419037); // Bin_37_LQ_1500_DM_600_X_660
//    ObservedExclusionLimit->SetBinContent(8,8,13.718699); // Bin_38_LQ_1500_DM_650_X_715
//    ObservedExclusionLimit->SetBinContent(8,9,102.511257); // Bin_39_LQ_1500_DM_700_X_770
//    ObservedExclusionLimit->SetBinContent(1,1,0.188800); // Bin_40_LQ_800_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(1,2,0.475919); // Bin_41_LQ_800_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(2,1,0.236541); // Bin_42_LQ_900_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(2,2,0.379028); // Bin_43_LQ_900_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(2,3,1.109902); // Bin_44_LQ_900_DM_400_X_440
//
////    Double_t XS[6] = {2.9E-1,6.563E-02,1.92E-02,6.030E-03,0.00209,0.000801};
    
    
    
    cout<<"************** "<<hlimitxsec2->GetBinContent(5,1)<<"\n\n\n\n\n";
    
    Double_t WMass[8] = {
        800,
        900,
        1000,
        1100,
        1200,
        1300,
        1400,
        1500};
    
    
    Double_t NuMass[8] = {
        300,
        350,
        400,
        450,
        500,
        550,
        600,
        650,
    };
    
    
    
    vector <float> exclusion_expected;
    vector <float> exclusion_observed;
    exclusion_expected.clear();
    exclusion_observed.clear();
    
    
    //    for (int ii =1 ; ii < ExpctedExclusionLimit->GetXaxis()->GetNbins()+1; ii++){
    //        for (int jj =1 ; jj < ExpctedExclusionLimit->GetYaxis()->GetNbins()+1; jj++){
    //
    //            ExpctedExclusionLimit->SetBinContent(ii,jj, hlimitxsec2->GetBinContent(ii,jj)/(XS[ii-1]*1000));
    //            cout<<ii<<" "<< jj<< " "<< ExpctedExclusionLimit->GetBinContent(ii,jj)<<"\n";
    //
    //        }
    //
    //
    //    }
    
    
    
    for (int jj =1 ; jj < 9; jj++){
        float ExpLim =(NuMass[jj]+NuMass[jj+1])/2. ;
        float ObsLim =WMass[jj]/2 ;
        float ExpLim_low=0;
//        float ObsLim =0;
        
        for (int ii =1; ii < 9; ii++){
            
            if (ExpctedExclusionLimit->GetBinContent(jj,ii)< 1) continue;
            
//            cout<<"ExpctedExclusionLimit->GetBinContent("<<jj<<","<<ii<<")= "<<ExpctedExclusionLimit->GetBinContent(jj,ii)<<"\n";
//            ExpLim= hlimitxsec2->GetBinContent(jj+1,ii+1);
//            ExpLim_low= hlimitxsec2->GetBinContent(jj+1,ii);
            
            
            
//            cout << "ExpctedExclusionLimit->GetBinContent(<<"<<ii<<"  "<<jj<<")= "<<ExpctedExclusionLimit->GetBinContent(ii,jj)<<"\n";
//            
//            
             ExpLim = intersection(NuMass[ii-1], NuMass[ii-2], ExpctedExclusionLimit->GetBinContent(jj,ii), ExpctedExclusionLimit->GetBinContent(jj,ii-1));
            cout<< WMass[jj-1] << "   "<<ii<<"  ExpLim="<<ExpLim<<"\n";
            break;
//             ObsLim = intersection(NuMass[ii-1], NuMass[ii], 1, 1, ObservedExclusionLimit->GetBinContent(ii,jj), ObservedExclusionLimit->GetBinContent(ii+1,jj));
            
            
//            if (ExpLim) break;
        }
//            if (ExpLim && ExpLim < 1500) {
        
//            cout <<WMass[jj] <<" Exp="<<ExpLim<< "    &&&&&&&  ExpLim_low="<<ExpLim_low<<"\n";
        
                
//                if (ExpLim > NuMass[jj-1] &&  ObsLim > NuMass[jj-1]){
                exclusion_expected.push_back(ExpLim);
                exclusion_observed.push_back(ObsLim);
//                }
            
//        }
    }
    
    for (int x=0; x<8;x++){
        cout<<"x==== "<<x << "   "<<exclusion_expected[x]<<"\n";
    }
    
    
//    cout<<exclusion_expected.size()<<"    "<<exclusion_observed.size()<<"\n";

    
 
    
    
    Int_t ck;   // for color index setting
    ck = TColor::GetColor("#000099");
    hlimitxsec2->SetLineColor(ck);
    hlimitxsec2->GetYaxis()->SetTitle("M_{DM} (GeV)");
    hlimitxsec2->GetXaxis()->SetNdivisions(505);
    hlimitxsec2->GetXaxis()->SetLabelFont(42);
    hlimitxsec2->GetXaxis()->SetLabelOffset(0.007);
    hlimitxsec2->GetXaxis()->SetLabelSize(0.035);
    hlimitxsec2->GetXaxis()->SetTitleSize(0.05);
    hlimitxsec2->GetXaxis()->SetTitleFont(42);
    hlimitxsec2->GetXaxis()->SetTitle("M_{LQ} (GeV)");
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
    gStyle->SetPalette(74);
//    hlimitxsec2->Draw("COLZ ");
    hlimitxsec2->Draw("textCOLZ");
    hlimitxsec2->GetZaxis()->SetTitle("Measured #sigma_{95% CL} / #sigma_{th}");
    
    
    TF1 *fa1 = new TF1("fa1","x/2.1",750,1550);
    fa1->SetLineColor(9);
    fa1->SetLineWidth(5);
    fa1->Draw("same");
    
    
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
    Graph_Graph_Graph11->SetLineColor(cj);
    Graph_Graph_Graph11->GetXaxis()->SetNdivisions(505);
    Graph_Graph_Graph11->GetXaxis()->SetLabelFont(42);
    Graph_Graph_Graph11->GetXaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11->GetXaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11->GetXaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11->GetXaxis()->SetTitleFont(42);
    Graph_Graph_Graph11->GetYaxis()->SetNdivisions(505);
    Graph_Graph_Graph11->GetYaxis()->SetLabelFont(42);
    Graph_Graph_Graph11->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11->GetYaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11->GetYaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11->GetYaxis()->SetTitleFont(42);
    Graph_Graph_Graph11->GetZaxis()->SetNdivisions(505);
    Graph_Graph_Graph11->GetZaxis()->SetLabelFont(42);
    Graph_Graph_Graph11->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11->GetZaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11->GetZaxis()->SetTitleFont(42);
//    Graph_Graph_Graph11->SetLogz();
    gre->SetHistogram(Graph_Graph_Graph11);
    gre->SetMarkerSize(1);
    gre->SetMarkerStyle(21);
//    gre->Draw("cp");
    
    
    
    
    
    
    TGraphErrors *greExp = new TGraphErrors(exclusion_observed.size()-2);
    greExp->SetName("Graph");
    greExp->SetTitle("Graph");
    greExp->SetFillColor(1);
    greExp->SetLineStyle(2);
    greExp->SetLineWidth(3);

    for (int kk=0;kk<8;kk++){
        
        
        cout <<"====>"<<kk << "  "<< exclusion_expected[kk] << "  "<< WMass[kk]<<"\n";
        
        greExp->SetPoint(kk, WMass[kk],exclusion_expected[kk] );
        greExp->SetPointError(kk,0,0);
        cout <<"Exp----->"<<kk<< " " <<exclusion_expected[kk]<< " "  <<WMass[kk]<<"\n";
        
    }
    
    
    TH1F *Graph_Graph_Graph11Exp = new TH1F("Graph_Graph_Graph11Exp","Graph",1100,1000,3250);
    Graph_Graph_Graph11Exp->SetDirectory(0);
    Graph_Graph_Graph11Exp->SetStats(0);
    
    Int_t ci;
    ci = TColor::GetColor("#000099");
    Graph_Graph_Graph11Exp->SetLineColor(ci);
    Graph_Graph_Graph11Exp->GetXaxis()->SetNdivisions(505);
    Graph_Graph_Graph11Exp->GetXaxis()->SetLabelFont(42);
    Graph_Graph_Graph11Exp->GetXaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11Exp->GetXaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11Exp->GetXaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11Exp->GetXaxis()->SetTitleFont(42);
    Graph_Graph_Graph11Exp->GetYaxis()->SetNdivisions(505);
    Graph_Graph_Graph11Exp->GetYaxis()->SetLabelFont(42);
    Graph_Graph_Graph11Exp->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11Exp->GetYaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11Exp->GetYaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11Exp->GetYaxis()->SetTitleFont(42);
    Graph_Graph_Graph11Exp->GetZaxis()->SetNdivisions(505);
    Graph_Graph_Graph11Exp->GetZaxis()->SetLabelFont(42);
    Graph_Graph_Graph11Exp->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11Exp->GetZaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11Exp->GetZaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11Exp->GetZaxis()->SetTitleFont(42);
    greExp->SetHistogram(Graph_Graph_Graph11Exp);
    
    greExp->SetMarkerSize(1);
    greExp->SetMarkerStyle(21);
    greExp->Draw("cp");
    
    
    
    
    
    
//    TLatex* tx = new TLatex(1600,.9101,"CMS");
//    tx->SetTextSize(0.05);
//    tx->Draw("SAME");
//    TLatex* tx2 = new TLatex(3000,.9101,"12.9 fb^{-1} (13 TeV)");
//    tx2->SetTextSize(0.04);
//    tx2->Draw("SAME");
    
    
    
//    
    TPaveText *pt = new TPaveText(0.1072864,0.9618663,0.4080402,0.9820056,"brNDC");
    
    pt->SetBorderSize(0);
    
    pt->SetFillColor(0);
    
    pt->SetLineColor(0);
    pt->SetTextSize(0.05);
    
    
    TText *textL = pt->AddText("CMS Preliminary");
//    textL->SetTextFont(42);
    pt->Draw();
    
    TText *textL2 = pt->AddText("                                                                                           35.9 fb^{-1} (13 TeV)");
    pt->SetTextSize(0.04);
    pt->Draw("samep");
    
    
    
    
    
    TGraph *grmin = new TGraph(n,x,ymin);
    TGraph *grmax = new TGraph(n,x,ymax);
    TGraph *gr    = new TGraph(n,x,y);
    TGraph *grshade = new TGraph(2*n);
    for (i=0;i<n;i++) {
        grshade->SetPoint(i,x[i],ymax[i]);
        grshade->SetPoint(n+i,x[n-i-1],ymin[n-i-1]);
    }
    grshade->SetFillStyle(3013);
    grshade->SetFillColor(4);
//    grshade->SetLineColor(9);
    grshade->SetLineWidth(0);
    grshade->Draw("f");
//    grmin->Draw("l");
//    grmax->Draw("l");
//    gr->SetLineWidth(0);
//    gr->SetLineColor(9);
//    gr->SetMarkerColor(9);
//    gr->SetMarkerStyle(21);
//    gr->Draw("CP");
    
    

    
    
    TLegend *legendr = new TLegend(0.15,0.83,0.47,0.93,NULL,"brNDC");
    legendr->SetShadowColor(0);
    legendr->SetBorderSize(0);
    legendr->SetFillColor(0);
    legendr->AddEntry(gre,"Observed","L");
    legendr->AddEntry(greExp, "Expected", "L");
    legendr->AddEntry(grshade, "Relic Density + APV (3#sigma)", "lf");
    legendr->SetFillStyle(0);
    legendr->SetTextSize(.034);
    
    legendr->SetTextFont(42);
    
    legendr->SetFillColor(0);
    
    legendr->SetBorderSize(0);
    
    legendr->Draw();
    
    
    
    
    
    
    
    
    TText *text = new TText(4900,1404.522,"Measured Cross section UL at 95% CL [fb]");
    text->SetTextFont(42);
    text->SetTextSize(0.04748603);
    text->SetTextAngle(90);
    text->Draw();
    can2->Modified();
    can2->cd();
    can2->SetSelected(can2);
    can2->SaveAs("lim2D_proj_4.pdf");
    can2->SaveAs("lim2D_proj_4.C");
    //     dofile("rhw.json");
    
}
