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




void DMLimit_2D_Org(){
    
    
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
    hlimitxsec2->SetBinContent(3,1,0.455768); // Bin_1_LQ_1000_DM_300_X_330
    hlimitxsec2->SetBinContent(3,2,0.561257); // Bin_2_LQ_1000_DM_350_X_385
    hlimitxsec2->SetBinContent(3,3,0.901368); // Bin_3_LQ_1000_DM_400_X_440
    hlimitxsec2->SetBinContent(3,4,3.074375); // Bin_4_LQ_1000_DM_450_X_495
    hlimitxsec2->SetBinContent(4,1,0.706327); // Bin_5_LQ_1100_DM_300_X_330
    hlimitxsec2->SetBinContent(4,2,0.828546); // Bin_6_LQ_1100_DM_350_X_385
    hlimitxsec2->SetBinContent(4,3,1.032697); // Bin_7_LQ_1100_DM_400_X_440
    hlimitxsec2->SetBinContent(4,4,1.745866); // Bin_8_LQ_1100_DM_450_X_495
    hlimitxsec2->SetBinContent(4,5,6.656249); // Bin_9_LQ_1100_DM_500_X_550
    hlimitxsec2->SetBinContent(5,1,1.131463); // Bin_10_LQ_1200_DM_300_X_330
    hlimitxsec2->SetBinContent(5,2,1.194525); // Bin_11_LQ_1200_DM_350_X_385
    hlimitxsec2->SetBinContent(5,3,1.351003); // Bin_12_LQ_1200_DM_400_X_440
    hlimitxsec2->SetBinContent(5,4,1.788160); // Bin_13_LQ_1200_DM_450_X_495
    hlimitxsec2->SetBinContent(5,5,3.146435); // Bin_14_LQ_1200_DM_500_X_550
    hlimitxsec2->SetBinContent(5,6,15.009930); // Bin_15_LQ_1200_DM_550_X_595
    hlimitxsec2->SetBinContent(6,1,1.692904); // Bin_16_LQ_1300_DM_300_X_330
    hlimitxsec2->SetBinContent(6,2,1.787432); // Bin_17_LQ_1300_DM_350_X_385
    hlimitxsec2->SetBinContent(6,3,1.943497); // Bin_18_LQ_1300_DM_400_X_440
    hlimitxsec2->SetBinContent(6,4,2.294152); // Bin_19_LQ_1300_DM_450_X_495
    hlimitxsec2->SetBinContent(6,5,2.864236); // Bin_20_LQ_1300_DM_500_X_550
    hlimitxsec2->SetBinContent(6,6,5.551548); // Bin_21_LQ_1300_DM_550_X_605
    hlimitxsec2->SetBinContent(6,7,29.637882); // Bin_22_LQ_1300_DM_600_X_660
    hlimitxsec2->SetBinContent(7,1,2.701655); // Bin_23_LQ_1400_DM_300_X_330
    hlimitxsec2->SetBinContent(7,2,2.934933); // Bin_24_LQ_1400_DM_350_X_385
    hlimitxsec2->SetBinContent(7,3,2.830149); // Bin_25_LQ_1400_DM_400_X_440
    hlimitxsec2->SetBinContent(7,4,3.321285); // Bin_26_LQ_1400_DM_450_X_495
    hlimitxsec2->SetBinContent(7,5,3.616290); // Bin_27_LQ_1400_DM_500_X_550
    hlimitxsec2->SetBinContent(7,6,5.070032); // Bin_28_LQ_1400_DM_550_X_605
    hlimitxsec2->SetBinContent(7,7,9.969797); // Bin_29_LQ_1400_DM_600_X_660
    hlimitxsec2->SetBinContent(7,8,60.783466); // Bin_30_LQ_1400_DM_650_X_715
    hlimitxsec2->SetBinContent(8,1,4.771025); // Bin_31_LQ_1500_DM_300_X_330
    hlimitxsec2->SetBinContent(8,2,4.804488); // Bin_32_LQ_1500_DM_350_X_385
    hlimitxsec2->SetBinContent(8,3,4.807234); // Bin_33_LQ_1500_DM_400_X_440
    hlimitxsec2->SetBinContent(8,4,5.301879); // Bin_34_LQ_1500_DM_450_X_495
    hlimitxsec2->SetBinContent(8,5,5.760897); // Bin_35_LQ_1500_DM_500_X_550
    hlimitxsec2->SetBinContent(8,6,6.789513); // Bin_36_LQ_1500_DM_550_X_605
    hlimitxsec2->SetBinContent(8,7,9.221587); // Bin_37_LQ_1500_DM_600_X_660
    hlimitxsec2->SetBinContent(8,8,19.606445); // Bin_38_LQ_1500_DM_650_X_715
    hlimitxsec2->SetBinContent(8,9,146.498830); // Bin_39_LQ_1500_DM_700_X_770
    hlimitxsec2->SetBinContent(1,1,0.265416); // Bin_40_LQ_800_DM_300_X_330
    hlimitxsec2->SetBinContent(1,2,0.668540); // Bin_41_LQ_800_DM_350_X_385
    hlimitxsec2->SetBinContent(2,1,0.309223); // Bin_42_LQ_900_DM_300_X_330
    hlimitxsec2->SetBinContent(2,2,0.500481); // Bin_43_LQ_900_DM_350_X_385
    hlimitxsec2->SetBinContent(2,3,1.447583); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    
    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit->SetBinContent(3,1,0.455768); // Bin_1_LQ_1000_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(3,2,0.561257); // Bin_2_LQ_1000_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(3,3,0.901368); // Bin_3_LQ_1000_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(3,4,3.074375); // Bin_4_LQ_1000_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(4,1,0.706327); // Bin_5_LQ_1100_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(4,2,0.828546); // Bin_6_LQ_1100_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(4,3,1.032697); // Bin_7_LQ_1100_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(4,4,1.745866); // Bin_8_LQ_1100_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(4,5,6.656249); // Bin_9_LQ_1100_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(5,1,1.131463); // Bin_10_LQ_1200_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(5,2,1.194525); // Bin_11_LQ_1200_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(5,3,1.351003); // Bin_12_LQ_1200_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(5,4,1.788160); // Bin_13_LQ_1200_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(5,5,3.146435); // Bin_14_LQ_1200_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(5,6,15.009930); // Bin_15_LQ_1200_DM_550_X_595
    ExpctedExclusionLimit->SetBinContent(6,1,1.692904); // Bin_16_LQ_1300_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(6,2,1.787432); // Bin_17_LQ_1300_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(6,3,1.943497); // Bin_18_LQ_1300_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(6,4,2.294152); // Bin_19_LQ_1300_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(6,5,2.864236); // Bin_20_LQ_1300_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(6,6,5.551548); // Bin_21_LQ_1300_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(6,7,29.637882); // Bin_22_LQ_1300_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(7,1,2.701655); // Bin_23_LQ_1400_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(7,2,2.934933); // Bin_24_LQ_1400_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(7,3,2.830149); // Bin_25_LQ_1400_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(7,4,3.321285); // Bin_26_LQ_1400_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(7,5,3.616290); // Bin_27_LQ_1400_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(7,6,5.070032); // Bin_28_LQ_1400_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(7,7,9.969797); // Bin_29_LQ_1400_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(7,8,60.783466); // Bin_30_LQ_1400_DM_650_X_715
    ExpctedExclusionLimit->SetBinContent(8,1,4.771025); // Bin_31_LQ_1500_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(8,2,4.804488); // Bin_32_LQ_1500_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(8,3,4.807234); // Bin_33_LQ_1500_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(8,4,5.301879); // Bin_34_LQ_1500_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(8,5,5.760897); // Bin_35_LQ_1500_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(8,6,6.789513); // Bin_36_LQ_1500_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(8,7,9.221587); // Bin_37_LQ_1500_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(8,8,19.606445); // Bin_38_LQ_1500_DM_650_X_715
    ExpctedExclusionLimit->SetBinContent(8,9,146.498830); // Bin_39_LQ_1500_DM_700_X_770
    ExpctedExclusionLimit->SetBinContent(1,1,0.265416); // Bin_40_LQ_800_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(1,2,0.668540); // Bin_41_LQ_800_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(2,1,0.309223); // Bin_42_LQ_900_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(2,2,0.500481); // Bin_43_LQ_900_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(2,3,1.447583); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    
    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
    ObservedExclusionLimit->SetBinContent(3,1,0.627694); // Bin_1_LQ_1000_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(3,2,0.812876); // Bin_2_LQ_1000_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(3,3,1.261352); // Bin_3_LQ_1000_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(3,4,4.311174); // Bin_4_LQ_1000_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(4,1,1.447804); // Bin_5_LQ_1100_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(4,2,1.682118); // Bin_6_LQ_1100_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(4,3,2.146287); // Bin_7_LQ_1100_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(4,4,3.562252); // Bin_8_LQ_1100_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(4,5,13.676567); // Bin_9_LQ_1100_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(5,1,2.663917); // Bin_10_LQ_1200_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(5,2,2.774754); // Bin_11_LQ_1200_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(5,3,3.233928); // Bin_12_LQ_1200_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(5,4,4.259983); // Bin_13_LQ_1200_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(5,5,7.463413); // Bin_14_LQ_1200_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(5,6,35.603887); // Bin_15_LQ_1200_DM_550_X_595
    ObservedExclusionLimit->SetBinContent(6,1,4.135331); // Bin_16_LQ_1300_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(6,2,4.439102); // Bin_17_LQ_1300_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(6,3,4.714419); // Bin_18_LQ_1300_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(6,4,5.545396); // Bin_19_LQ_1300_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(6,5,6.945842); // Bin_20_LQ_1300_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(6,6,13.527641); // Bin_21_LQ_1300_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(6,7,71.284506); // Bin_22_LQ_1300_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(7,1,5.022571); // Bin_23_LQ_1400_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(7,2,5.704358); // Bin_24_LQ_1400_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(7,3,5.441522); // Bin_25_LQ_1400_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(7,4,6.563731); // Bin_26_LQ_1400_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(7,5,6.834740); // Bin_27_LQ_1400_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(7,6,9.890691); // Bin_28_LQ_1400_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(7,7,19.491144); // Bin_29_LQ_1400_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(7,8,118.557737); // Bin_30_LQ_1400_DM_650_X_715
    ObservedExclusionLimit->SetBinContent(8,1,6.307447); // Bin_31_LQ_1500_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(8,2,6.374525); // Bin_32_LQ_1500_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(8,3,6.267375); // Bin_33_LQ_1500_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(8,4,7.273345); // Bin_34_LQ_1500_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(8,5,7.957724); // Bin_35_LQ_1500_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(8,6,8.868176); // Bin_36_LQ_1500_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(8,7,11.556570); // Bin_37_LQ_1500_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(8,8,25.823450); // Bin_38_LQ_1500_DM_650_X_715
    ObservedExclusionLimit->SetBinContent(8,9,191.675692); // Bin_39_LQ_1500_DM_700_X_770
    ObservedExclusionLimit->SetBinContent(1,1,0.257720); // Bin_40_LQ_800_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(1,2,0.647283); // Bin_41_LQ_800_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(2,1,0.289174); // Bin_42_LQ_900_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(2,2,0.455181); // Bin_43_LQ_900_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(2,3,1.336313); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    TH2D *ExpctedExclusionLimit2sigmaPlus = new TH2D("ExpctedExclusionLimit2sigmaPlus","ExpctedExclusionLimit2sigmaPlus",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(3,1,0.916381); // Bin_1_LQ_1000_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(3,2,1.131365); // Bin_2_LQ_1000_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(3,3,1.812320); // Bin_3_LQ_1000_DM_400_X_440
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(3,4,6.181440); // Bin_4_LQ_1000_DM_450_X_495
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(4,1,1.432570); // Bin_5_LQ_1100_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(4,2,1.680455); // Bin_6_LQ_1100_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(4,3,2.089270); // Bin_7_LQ_1100_DM_400_X_440
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(4,4,3.540960); // Bin_8_LQ_1100_DM_450_X_495
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(4,5,13.500182); // Bin_9_LQ_1100_DM_500_X_550
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(5,1,2.328549); // Bin_10_LQ_1200_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(5,2,2.458331); // Bin_11_LQ_1200_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(5,3,2.780363); // Bin_12_LQ_1200_DM_400_X_440
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(5,4,3.680031); // Bin_13_LQ_1200_DM_450_X_495
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(5,5,6.475358); // Bin_14_LQ_1200_DM_500_X_550
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(5,6,30.890412); // Bin_15_LQ_1200_DM_550_X_595
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(6,1,3.562914); // Bin_16_LQ_1300_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(6,2,3.761858); // Bin_17_LQ_1300_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(6,3,4.081056); // Bin_18_LQ_1300_DM_400_X_440
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(6,4,4.817380); // Bin_19_LQ_1300_DM_450_X_495
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(6,5,6.028118); // Bin_20_LQ_1300_DM_500_X_550
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(6,6,11.683879); // Bin_21_LQ_1300_DM_550_X_605
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(6,7,62.376376); // Bin_22_LQ_1300_DM_600_X_660
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,1,5.748164); // Bin_23_LQ_1400_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,2,6.212827); // Bin_24_LQ_1400_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,3,6.004324); // Bin_25_LQ_1400_DM_400_X_440
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,4,7.046296); // Bin_26_LQ_1400_DM_450_X_495
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,5,7.716198); // Bin_27_LQ_1400_DM_500_X_550
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,6,10.756364); // Bin_28_LQ_1400_DM_550_X_605
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,7,21.272888); // Bin_29_LQ_1400_DM_600_X_660
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(7,8,129.695706); // Bin_30_LQ_1400_DM_650_X_715
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,1,10.122003); // Bin_31_LQ_1500_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,2,10.170403); // Bin_32_LQ_1500_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,3,10.198822); // Bin_33_LQ_1500_DM_400_X_440
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,4,11.158423); // Bin_34_LQ_1500_DM_450_X_495
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,5,12.151928); // Bin_35_LQ_1500_DM_500_X_550
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,6,14.289321); // Bin_36_LQ_1500_DM_550_X_605
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,7,19.520762); // Bin_37_LQ_1500_DM_600_X_660
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,8,41.504001); // Bin_38_LQ_1500_DM_650_X_715
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(8,9,310.805663); // Bin_39_LQ_1500_DM_700_X_770
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(1,1,0.519471); // Bin_40_LQ_800_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(1,2,1.308464); // Bin_41_LQ_800_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(2,1,0.612383); // Bin_42_LQ_900_DM_300_X_330
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(2,2,0.988516); // Bin_43_LQ_900_DM_350_X_385
    ExpctedExclusionLimit2sigmaPlus->SetBinContent(2,3,2.884954); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    
    TH2D *ExpctedExclusionLimit2sigmaMinus = new TH2D("ExpctedExclusionLimit2sigmaMinus","ExpctedExclusionLimit2sigmaMinus",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(3,1,0.237676); // Bin_1_LQ_1000_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(3,2,0.292687); // Bin_2_LQ_1000_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(3,3,0.470049); // Bin_3_LQ_1000_DM_400_X_440
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(3,4,1.603238); // Bin_4_LQ_1000_DM_450_X_495
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(4,1,0.366959); // Bin_5_LQ_1100_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(4,2,0.428837); // Bin_6_LQ_1100_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(4,3,0.534501); // Bin_7_LQ_1100_DM_400_X_440
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(4,4,0.907032); // Bin_8_LQ_1100_DM_450_X_495
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(4,5,3.445129); // Bin_9_LQ_1100_DM_500_X_550
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(5,1,0.581201); // Bin_10_LQ_1200_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(5,2,0.611261); // Bin_11_LQ_1200_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(5,3,0.693972); // Bin_12_LQ_1200_DM_400_X_440
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(5,4,0.918528); // Bin_13_LQ_1200_DM_450_X_495
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(5,5,1.616235); // Bin_14_LQ_1200_DM_500_X_550
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(5,6,7.710179); // Bin_15_LQ_1200_DM_550_X_595
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(6,1,0.862984); // Bin_16_LQ_1300_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(6,2,0.904189); // Bin_17_LQ_1300_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(6,3,0.983136); // Bin_18_LQ_1300_DM_400_X_440
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(6,4,1.160518); // Bin_19_LQ_1300_DM_450_X_495
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(6,5,1.448900); // Bin_20_LQ_1300_DM_500_X_550
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(6,6,2.819145); // Bin_21_LQ_1300_DM_550_X_605
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(6,7,15.108373); // Bin_22_LQ_1300_DM_600_X_660
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,1,1.356104); // Bin_23_LQ_1400_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,2,1.473199); // Bin_24_LQ_1400_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,3,1.420602); // Bin_25_LQ_1400_DM_400_X_440
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,4,1.667129); // Bin_26_LQ_1400_DM_450_X_495
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,5,1.815208); // Bin_27_LQ_1400_DM_500_X_550
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,6,2.544918); // Bin_28_LQ_1400_DM_550_X_605
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,7,5.004371); // Bin_29_LQ_1400_DM_600_X_660
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(7,8,30.629168); // Bin_30_LQ_1400_DM_650_X_715
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,1,2.413468); // Bin_31_LQ_1500_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,2,2.430395); // Bin_32_LQ_1500_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,3,2.431784); // Bin_33_LQ_1500_DM_400_X_440
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,4,2.682005); // Bin_34_LQ_1500_DM_450_X_495
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,5,2.936707); // Bin_35_LQ_1500_DM_500_X_550
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,6,3.434539); // Bin_36_LQ_1500_DM_550_X_605
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,7,4.664826); // Bin_37_LQ_1500_DM_600_X_660
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,8,9.918104); // Bin_38_LQ_1500_DM_650_X_715
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(8,9,74.107806); // Bin_39_LQ_1500_DM_700_X_770
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(1,1,0.140484); // Bin_40_LQ_800_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(1,2,0.353856); // Bin_41_LQ_800_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(2,1,0.162463); // Bin_42_LQ_900_DM_300_X_330
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(2,2,0.261970); // Bin_43_LQ_900_DM_350_X_385
    ExpctedExclusionLimit2sigmaMinus->SetBinContent(2,3,0.760547); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
//    
//    
//    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",8,750,1550,9,275,725);
//    hlimitxsec2->SetBinContent(3,1,0.455768); // Bin_1_LQ_1000_DM_300_X_330
//    hlimitxsec2->SetBinContent(3,2,0.564937); // Bin_2_LQ_1000_DM_350_X_385
//    hlimitxsec2->SetBinContent(3,3,0.901368); // Bin_3_LQ_1000_DM_400_X_440
//    hlimitxsec2->SetBinContent(3,4,3.074375); // Bin_4_LQ_1000_DM_450_X_495
//    hlimitxsec2->SetBinContent(4,1,0.694604); // Bin_5_LQ_1100_DM_300_X_330
//    hlimitxsec2->SetBinContent(4,2,0.809051); // Bin_6_LQ_1100_DM_350_X_385
//    hlimitxsec2->SetBinContent(4,3,1.000551); // Bin_7_LQ_1100_DM_400_X_440
//    hlimitxsec2->SetBinContent(4,4,1.707212); // Bin_8_LQ_1100_DM_450_X_495
//    hlimitxsec2->SetBinContent(4,5,6.495857); // Bin_9_LQ_1100_DM_500_X_550
//    hlimitxsec2->SetBinContent(5,1,1.084549); // Bin_10_LQ_1200_DM_300_X_330
//    hlimitxsec2->SetBinContent(5,2,1.138624); // Bin_11_LQ_1200_DM_350_X_385
//    hlimitxsec2->SetBinContent(5,3,1.294434); // Bin_12_LQ_1200_DM_400_X_440
//    hlimitxsec2->SetBinContent(5,4,1.703413); // Bin_13_LQ_1200_DM_450_X_495
//    hlimitxsec2->SetBinContent(5,5,3.032537); // Bin_14_LQ_1200_DM_500_X_550
//    hlimitxsec2->SetBinContent(5,6,14.466584); // Bin_15_LQ_1200_DM_550_X_595
//    hlimitxsec2->SetBinContent(6,1,1.682675); // Bin_16_LQ_1300_DM_300_X_330
//    hlimitxsec2->SetBinContent(6,2,1.782096); // Bin_17_LQ_1300_DM_350_X_385
//    hlimitxsec2->SetBinContent(6,3,1.931963); // Bin_18_LQ_1300_DM_400_X_440
//    hlimitxsec2->SetBinContent(6,4,2.280853); // Bin_19_LQ_1300_DM_450_X_495
//    hlimitxsec2->SetBinContent(6,5,2.846824); // Bin_20_LQ_1300_DM_500_X_550
//    hlimitxsec2->SetBinContent(6,6,5.520961); // Bin_21_LQ_1300_DM_550_X_605
//    hlimitxsec2->SetBinContent(6,7,29.468037); // Bin_22_LQ_1300_DM_600_X_660
//    hlimitxsec2->SetBinContent(7,1,2.720223); // Bin_23_LQ_1400_DM_300_X_330
//    hlimitxsec2->SetBinContent(7,2,2.954053); // Bin_24_LQ_1400_DM_350_X_385
//    hlimitxsec2->SetBinContent(7,3,2.850293); // Bin_25_LQ_1400_DM_400_X_440
//    hlimitxsec2->SetBinContent(7,4,3.365421); // Bin_26_LQ_1400_DM_450_X_495
//    hlimitxsec2->SetBinContent(7,5,3.668137); // Bin_27_LQ_1400_DM_500_X_550
//    hlimitxsec2->SetBinContent(7,6,5.104878); // Bin_28_LQ_1400_DM_550_X_605
//    hlimitxsec2->SetBinContent(7,7,10.065660); // Bin_29_LQ_1400_DM_600_X_660
//    hlimitxsec2->SetBinContent(7,8,61.624760); // Bin_30_LQ_1400_DM_650_X_715
//    hlimitxsec2->SetBinContent(8,1,4.571540); // Bin_31_LQ_1500_DM_300_X_330
//    hlimitxsec2->SetBinContent(8,2,4.634718); // Bin_32_LQ_1500_DM_350_X_385
//    hlimitxsec2->SetBinContent(8,3,4.631145); // Bin_33_LQ_1500_DM_400_X_440
//    hlimitxsec2->SetBinContent(8,4,5.039595); // Bin_34_LQ_1500_DM_450_X_495
//    hlimitxsec2->SetBinContent(8,5,5.552922); // Bin_35_LQ_1500_DM_500_X_550
//    hlimitxsec2->SetBinContent(8,6,6.491073); // Bin_36_LQ_1500_DM_550_X_605
//    hlimitxsec2->SetBinContent(8,7,8.810215); // Bin_37_LQ_1500_DM_600_X_660
//    hlimitxsec2->SetBinContent(8,8,18.819564); // Bin_38_LQ_1500_DM_650_X_715
//    hlimitxsec2->SetBinContent(8,9,140.197805); // Bin_39_LQ_1500_DM_700_X_770
//    hlimitxsec2->SetBinContent(1,1,0.241203); // Bin_40_LQ_800_DM_300_X_330
//    hlimitxsec2->SetBinContent(1,2,0.610862); // Bin_41_LQ_800_DM_350_X_385
//    hlimitxsec2->SetBinContent(2,1,0.304353); // Bin_42_LQ_900_DM_300_X_330
//    hlimitxsec2->SetBinContent(2,2,0.486383); // Bin_43_LQ_900_DM_350_X_385
//    hlimitxsec2->SetBinContent(2,3,1.425023); // Bin_44_LQ_900_DM_400_X_440
//    
//    
//    
//    
//    
//    
//    
//    
//    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
//    ExpctedExclusionLimit->SetBinContent(3,1,0.455768); // Bin_1_LQ_1000_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(3,2,0.564937); // Bin_2_LQ_1000_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(3,3,0.901368); // Bin_3_LQ_1000_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(3,4,3.074375); // Bin_4_LQ_1000_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(4,1,0.694604); // Bin_5_LQ_1100_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(4,2,0.809051); // Bin_6_LQ_1100_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(4,3,1.000551); // Bin_7_LQ_1100_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(4,4,1.707212); // Bin_8_LQ_1100_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(4,5,6.495857); // Bin_9_LQ_1100_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(5,1,1.084549); // Bin_10_LQ_1200_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(5,2,1.138624); // Bin_11_LQ_1200_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(5,3,1.294434); // Bin_12_LQ_1200_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(5,4,1.703413); // Bin_13_LQ_1200_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(5,5,3.032537); // Bin_14_LQ_1200_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(5,6,14.466584); // Bin_15_LQ_1200_DM_550_X_595
//    ExpctedExclusionLimit->SetBinContent(6,1,1.682675); // Bin_16_LQ_1300_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(6,2,1.782096); // Bin_17_LQ_1300_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(6,3,1.931963); // Bin_18_LQ_1300_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(6,4,2.280853); // Bin_19_LQ_1300_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(6,5,2.846824); // Bin_20_LQ_1300_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(6,6,5.520961); // Bin_21_LQ_1300_DM_550_X_605
//    ExpctedExclusionLimit->SetBinContent(6,7,29.468037); // Bin_22_LQ_1300_DM_600_X_660
//    ExpctedExclusionLimit->SetBinContent(7,1,2.720223); // Bin_23_LQ_1400_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(7,2,2.954053); // Bin_24_LQ_1400_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(7,3,2.850293); // Bin_25_LQ_1400_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(7,4,3.365421); // Bin_26_LQ_1400_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(7,5,3.668137); // Bin_27_LQ_1400_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(7,6,5.104878); // Bin_28_LQ_1400_DM_550_X_605
//    ExpctedExclusionLimit->SetBinContent(7,7,10.065660); // Bin_29_LQ_1400_DM_600_X_660
//    ExpctedExclusionLimit->SetBinContent(7,8,61.624760); // Bin_30_LQ_1400_DM_650_X_715
//    ExpctedExclusionLimit->SetBinContent(8,1,4.571540); // Bin_31_LQ_1500_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(8,2,4.634718); // Bin_32_LQ_1500_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(8,3,4.631145); // Bin_33_LQ_1500_DM_400_X_440
//    ExpctedExclusionLimit->SetBinContent(8,4,5.039595); // Bin_34_LQ_1500_DM_450_X_495
//    ExpctedExclusionLimit->SetBinContent(8,5,5.552922); // Bin_35_LQ_1500_DM_500_X_550
//    ExpctedExclusionLimit->SetBinContent(8,6,6.491073); // Bin_36_LQ_1500_DM_550_X_605
//    ExpctedExclusionLimit->SetBinContent(8,7,8.810215); // Bin_37_LQ_1500_DM_600_X_660
//    ExpctedExclusionLimit->SetBinContent(8,8,18.819564); // Bin_38_LQ_1500_DM_650_X_715
//    ExpctedExclusionLimit->SetBinContent(8,9,140.197805); // Bin_39_LQ_1500_DM_700_X_770
//    ExpctedExclusionLimit->SetBinContent(1,1,0.241203); // Bin_40_LQ_800_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(1,2,0.610862); // Bin_41_LQ_800_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(2,1,0.304353); // Bin_42_LQ_900_DM_300_X_330
//    ExpctedExclusionLimit->SetBinContent(2,2,0.486383); // Bin_43_LQ_900_DM_350_X_385
//    ExpctedExclusionLimit->SetBinContent(2,3,1.425023); // Bin_44_LQ_900_DM_400_X_440
//    
//    
//    
//    
//    
//    
//    
//    
//    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
//    ObservedExclusionLimit->SetBinContent(3,1,0.455122); // Bin_1_LQ_1000_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(3,2,0.563717); // Bin_2_LQ_1000_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(3,3,0.901334); // Bin_3_LQ_1000_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(3,4,3.079050); // Bin_4_LQ_1000_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(4,1,0.693179); // Bin_5_LQ_1100_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(4,2,0.809452); // Bin_6_LQ_1100_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(4,3,1.003621); // Bin_7_LQ_1100_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(4,4,1.705248); // Bin_8_LQ_1100_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(4,5,6.476988); // Bin_9_LQ_1100_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(5,1,1.088472); // Bin_10_LQ_1200_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(5,2,1.138085); // Bin_11_LQ_1200_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(5,3,1.295614); // Bin_12_LQ_1200_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(5,4,1.710284); // Bin_13_LQ_1200_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(5,5,3.025239); // Bin_14_LQ_1200_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(5,6,14.431773); // Bin_15_LQ_1200_DM_550_X_595
//    ObservedExclusionLimit->SetBinContent(6,1,1.683858); // Bin_16_LQ_1300_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(6,2,1.783394); // Bin_17_LQ_1300_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(6,3,1.929469); // Bin_18_LQ_1300_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(6,4,2.283249); // Bin_19_LQ_1300_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(6,5,2.841702); // Bin_20_LQ_1300_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(6,6,5.527242); // Bin_21_LQ_1300_DM_550_X_605
//    ObservedExclusionLimit->SetBinContent(6,7,29.465344); // Bin_22_LQ_1300_DM_600_X_660
//    ObservedExclusionLimit->SetBinContent(7,1,2.724051); // Bin_23_LQ_1400_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(7,2,2.959837); // Bin_24_LQ_1400_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(7,3,2.852007); // Bin_25_LQ_1400_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(7,4,3.371213); // Bin_26_LQ_1400_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(7,5,3.664063); // Bin_27_LQ_1400_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(7,6,5.115353); // Bin_28_LQ_1400_DM_550_X_605
//    ObservedExclusionLimit->SetBinContent(7,7,10.092594); // Bin_29_LQ_1400_DM_600_X_660
//    ObservedExclusionLimit->SetBinContent(7,8,61.688905); // Bin_30_LQ_1400_DM_650_X_715
//    ObservedExclusionLimit->SetBinContent(8,1,4.585766); // Bin_31_LQ_1500_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(8,2,4.618387); // Bin_32_LQ_1500_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(8,3,4.636107); // Bin_33_LQ_1500_DM_400_X_440
//    ObservedExclusionLimit->SetBinContent(8,4,5.055634); // Bin_34_LQ_1500_DM_450_X_495
//    ObservedExclusionLimit->SetBinContent(8,5,5.534441); // Bin_35_LQ_1500_DM_500_X_550
//    ObservedExclusionLimit->SetBinContent(8,6,6.476050); // Bin_36_LQ_1500_DM_550_X_605
//    ObservedExclusionLimit->SetBinContent(8,7,8.803995); // Bin_37_LQ_1500_DM_600_X_660
//    ObservedExclusionLimit->SetBinContent(8,8,18.804006); // Bin_38_LQ_1500_DM_650_X_715
//    ObservedExclusionLimit->SetBinContent(8,9,140.529515); // Bin_39_LQ_1500_DM_700_X_770
//    ObservedExclusionLimit->SetBinContent(1,1,0.240868); // Bin_40_LQ_800_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(1,2,0.610170); // Bin_41_LQ_800_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(2,1,0.304091); // Bin_42_LQ_900_DM_300_X_330
//    ObservedExclusionLimit->SetBinContent(2,2,0.487558); // Bin_43_LQ_900_DM_350_X_385
//    ObservedExclusionLimit->SetBinContent(2,3,1.426267); // Bin_44_LQ_900_DM_400_X_440
//
//    
    
    
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
    vector <float> exclusion_expectedPlus2;
    vector <float> exclusion_expectedMinus2;
    vector <float> exclusion_observed;
    exclusion_expected.clear();
    exclusion_expectedPlus2.clear();
    exclusion_expectedMinus2.clear();
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
        float ExpLimPlus2 =(NuMass[jj]+NuMass[jj+1])/2. ;
        float ExpLimMinus2 =(NuMass[jj]+NuMass[jj+1])/2. ;
        float ObsLim =(NuMass[jj]+NuMass[jj+1])/2. ;
        float ExpLim_low=0;
        float ExpLim_lowPlus2=0;
        float ExpLim_lowMinus2=0;
        float ObsLim_low =0;
        
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
        
        
        
        
        for (int ii =1; ii < 9; ii++){
            
            if (ObservedExclusionLimit->GetBinContent(jj,ii)< 1) continue;
            
            //            cout<<"ExpctedExclusionLimit->GetBinContent("<<jj<<","<<ii<<")= "<<ExpctedExclusionLimit->GetBinContent(jj,ii)<<"\n";
            //            ExpLim= hlimitxsec2->GetBinContent(jj+1,ii+1);
            //            ExpLim_low= hlimitxsec2->GetBinContent(jj+1,ii);
            
            
            
            //            cout << "ExpctedExclusionLimit->GetBinContent(<<"<<ii<<"  "<<jj<<")= "<<ExpctedExclusionLimit->GetBinContent(ii,jj)<<"\n";
            //
            //
            ObsLim = intersection(NuMass[ii-1], NuMass[ii-2], ObservedExclusionLimit->GetBinContent(jj,ii), ObservedExclusionLimit->GetBinContent(jj,ii-1));
            cout<< WMass[jj-1] << "   "<<ii<<"  ObsLim="<<ObsLim<<"\n";
            break;
            //             ObsLim = intersection(NuMass[ii-1], NuMass[ii], 1, 1, ObservedExclusionLimit->GetBinContent(ii,jj), ObservedExclusionLimit->GetBinContent(ii+1,jj));
            
            
            //            if (ExpLim) break;
        }
        
        
 
        
        for (int ii =1; ii < 9; ii++){
            
            if (ExpctedExclusionLimit2sigmaPlus->GetBinContent(jj,ii)< 1) continue;
            
            
            ExpLimPlus2 = intersection(NuMass[ii-1], NuMass[ii-2], ExpctedExclusionLimit2sigmaPlus->GetBinContent(jj,ii), ExpctedExclusionLimit2sigmaPlus->GetBinContent(jj,ii-1));
            cout<< WMass[jj-1] << "   "<<ii<<"  ExpLimPlus2="<<ExpLimPlus2<<"\n";
            break;
            
        }
        
        
        for (int ii =1; ii < 9; ii++){
            
            if (ExpctedExclusionLimit2sigmaMinus->GetBinContent(jj,ii)< 1) continue;
            
            
            ExpLimMinus2 = intersection(NuMass[ii-1], NuMass[ii-2], ExpctedExclusionLimit2sigmaMinus->GetBinContent(jj,ii), ExpctedExclusionLimit2sigmaMinus->GetBinContent(jj,ii-1));
            cout<< WMass[jj-1] << "   "<<ii<<"  ExpLimMinus2="<<ExpLimMinus2<<"\n";
            break;
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
//            if (ExpLim && ExpLim < 1500) {
        
//            cout <<WMass[jj] <<" Exp="<<ExpLim<< "    &&&&&&&  ExpLim_low="<<ExpLim_low<<"\n";
        
                
//                if (ExpLim > NuMass[jj-1] &&  ObsLim > NuMass[jj-1]){
                exclusion_expected.push_back(ExpLim);
                exclusion_expectedPlus2.push_back(ExpLimPlus2);
                exclusion_expectedMinus2.push_back(ExpLimMinus2);
                exclusion_observed.push_back(ObsLim);
//                }
            
//        }
    }
    
//    for (int x=0; x<8;x++){
//        cout<<"x==== "<<x << "   "<<exclusion_expected[x]<<"\n";
//    }
    
    
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
    hlimitxsec2->Draw("COLZ ");
//    hlimitxsec2->Draw("textCOLZ");
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
    
    TGraphErrors *greExpPlus2 = new TGraphErrors(exclusion_observed.size()-2);
    greExpPlus2->SetName("Graph");
    greExpPlus2->SetTitle("Graph");
    greExpPlus2->SetFillColor(4);
    greExpPlus2->SetLineColor(5);
    greExpPlus2->SetLineStyle(8);
    greExpPlus2->SetLineWidth(5);
   
    
    TGraphErrors *greExpMinus2 = new TGraphErrors(exclusion_observed.size()-2);
    greExpMinus2->SetName("Graph");
    greExpMinus2->SetTitle("Graph");
    greExpMinus2->SetFillColor(4);
    greExpMinus2->SetLineColor(5);
    greExpMinus2->SetLineStyle(8);
    greExpMinus2->SetLineWidth(5);
   
    
    TGraphErrors *greObs = new TGraphErrors(exclusion_observed.size()-2);
    greObs->SetName("Graph");
    greObs->SetTitle("Graph");
    greObs->SetFillColor(2);
    greObs->SetLineStyle(1);
    greObs->SetLineWidth(4);
    

    for (int kk=0;kk<8;kk++){
        
        
        cout <<"====>"<<kk << "  "<< exclusion_expected[kk] << "  "<< WMass[kk]<<"\n";
        
        greExp->SetPoint(kk, WMass[kk],exclusion_expected[kk] );
        greExp->SetPointError(kk,0,0);
        
        greExpPlus2->SetPoint(kk, WMass[kk],exclusion_expectedPlus2[kk] );
        greExpPlus2->SetPointError(kk,0,0);
        
        greExpMinus2->SetPoint(kk, WMass[kk],exclusion_expectedMinus2[kk] );
        greExpMinus2->SetPointError(kk,0,0);

        
        cout <<"Exp----->"<<kk<< " " <<exclusion_expected[kk]<< " "  <<WMass[kk]<<"\n";
        
        greObs->SetPoint(kk, WMass[kk],exclusion_observed[kk] );
        greObs->SetPointError(kk,0,0);
        
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
    
    
    
    
    
    
    TH1F *Graph_Graph_Graph11Obs = new TH1F("Graph_Graph_Graph11Obs","Graph",1100,1000,3250);
    Graph_Graph_Graph11Obs->SetDirectory(0);
    Graph_Graph_Graph11Obs->SetStats(0);
    
//    Int_t ci;
    ci = TColor::GetColor("#000099");
    Graph_Graph_Graph11Obs->SetLineColor(ci);
    Graph_Graph_Graph11Obs->GetXaxis()->SetNdivisions(505);
    Graph_Graph_Graph11Obs->GetXaxis()->SetLabelFont(42);
    Graph_Graph_Graph11Obs->GetXaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11Obs->GetXaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11Obs->GetXaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11Obs->GetXaxis()->SetTitleFont(42);
    Graph_Graph_Graph11Obs->GetYaxis()->SetNdivisions(505);
    Graph_Graph_Graph11Obs->GetYaxis()->SetLabelFont(42);
    Graph_Graph_Graph11Obs->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11Obs->GetYaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11Obs->GetYaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11Obs->GetYaxis()->SetTitleFont(42);
    Graph_Graph_Graph11Obs->GetZaxis()->SetNdivisions(505);
    Graph_Graph_Graph11Obs->GetZaxis()->SetLabelFont(42);
    Graph_Graph_Graph11Obs->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11Obs->GetZaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11Obs->GetZaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11Obs->GetZaxis()->SetTitleFont(42);
    greObs->SetHistogram(Graph_Graph_Graph11Obs);
    
    greObs->SetMarkerSize(1);
    greObs->SetMarkerStyle(21);
    greObs->Draw("cpsame");
    
    
    
    
    
    TH1F *Graph_Graph_Graph11ExpPlus2 = new TH1F("Graph_Graph_Graph11ExpPlus2","Graph",1100,1000,3250);
    Graph_Graph_Graph11ExpPlus2->SetDirectory(0);
    Graph_Graph_Graph11ExpPlus2->SetStats(0);
    
//    Int_t ci;
    ci = TColor::GetColor("#000599");
    Graph_Graph_Graph11ExpPlus2->SetLineColor(ci);
    Graph_Graph_Graph11ExpPlus2->GetXaxis()->SetNdivisions(505);
    Graph_Graph_Graph11ExpPlus2->GetXaxis()->SetLabelFont(42);
    Graph_Graph_Graph11ExpPlus2->GetXaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11ExpPlus2->GetXaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11ExpPlus2->GetXaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11ExpPlus2->GetXaxis()->SetTitleFont(42);
    Graph_Graph_Graph11ExpPlus2->GetYaxis()->SetNdivisions(505);
    Graph_Graph_Graph11ExpPlus2->GetYaxis()->SetLabelFont(42);
    Graph_Graph_Graph11ExpPlus2->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11ExpPlus2->GetYaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11ExpPlus2->GetYaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11ExpPlus2->GetYaxis()->SetTitleFont(42);
    Graph_Graph_Graph11ExpPlus2->GetZaxis()->SetNdivisions(505);
    Graph_Graph_Graph11ExpPlus2->GetZaxis()->SetLabelFont(42);
    Graph_Graph_Graph11ExpPlus2->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11ExpPlus2->GetZaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11ExpPlus2->GetZaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11ExpPlus2->GetZaxis()->SetTitleFont(42);
    greExpPlus2->SetHistogram(Graph_Graph_Graph11ExpPlus2);
    
    greExpPlus2->SetMarkerSize(0);
    greExpPlus2->SetMarkerStyle(23);
    greExpPlus2->Draw("cpsame");
    
    
    
    
    
    TH1F *Graph_Graph_Graph11ExpMinus2 = new TH1F("Graph_Graph_Graph11ExpMinus2","Graph",1100,1000,3250);
    Graph_Graph_Graph11ExpMinus2->SetDirectory(0);
    Graph_Graph_Graph11ExpMinus2->SetStats(0);
    
    //    Int_t ci;
    ci = TColor::GetColor("#000599");
    Graph_Graph_Graph11ExpMinus2->SetLineColor(ci);
    Graph_Graph_Graph11ExpMinus2->GetXaxis()->SetNdivisions(505);
    Graph_Graph_Graph11ExpMinus2->GetXaxis()->SetLabelFont(42);
    Graph_Graph_Graph11ExpMinus2->GetXaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11ExpMinus2->GetXaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11ExpMinus2->GetXaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11ExpMinus2->GetXaxis()->SetTitleFont(42);
    Graph_Graph_Graph11ExpMinus2->GetYaxis()->SetNdivisions(505);
    Graph_Graph_Graph11ExpMinus2->GetYaxis()->SetLabelFont(42);
    Graph_Graph_Graph11ExpMinus2->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11ExpMinus2->GetYaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11ExpMinus2->GetYaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11ExpMinus2->GetYaxis()->SetTitleFont(42);
    Graph_Graph_Graph11ExpMinus2->GetZaxis()->SetNdivisions(505);
    Graph_Graph_Graph11ExpMinus2->GetZaxis()->SetLabelFont(42);
    Graph_Graph_Graph11ExpMinus2->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph_Graph11ExpMinus2->GetZaxis()->SetLabelSize(0.035);
    Graph_Graph_Graph11ExpMinus2->GetZaxis()->SetTitleSize(0.045);
    Graph_Graph_Graph11ExpMinus2->GetZaxis()->SetTitleFont(42);
    greExpMinus2->SetHistogram(Graph_Graph_Graph11ExpMinus2);
    
    greExpMinus2->SetMarkerSize(0);
    greExpMinus2->SetMarkerStyle(23);
    greExpMinus2->Draw("cpsame");
    
    //
    
 
    
    
    
    
    TLatex* tx = new TLatex(1600,.9101,"CMS");
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
    legendr->AddEntry(greExpPlus2, "2#sigma Expected", "L");
//    legendr->AddEntry(greExpMinus2, "-2#sigma Expected", "L");
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
    can2->SaveAs("lim2D_Final.pdf");
    can2->SaveAs("lim2D_Final.C");
    //     dofile("rhw.json");
    
}
