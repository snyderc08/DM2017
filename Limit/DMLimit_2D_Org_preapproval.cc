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
    hlimitxsec2->SetBinContent(3,2,0.564937); // Bin_2_LQ_1000_DM_350_X_385
    hlimitxsec2->SetBinContent(3,3,0.901368); // Bin_3_LQ_1000_DM_400_X_440
    hlimitxsec2->SetBinContent(3,4,3.074375); // Bin_4_LQ_1000_DM_450_X_495
    hlimitxsec2->SetBinContent(4,1,0.694604); // Bin_5_LQ_1100_DM_300_X_330
    hlimitxsec2->SetBinContent(4,2,0.809051); // Bin_6_LQ_1100_DM_350_X_385
    hlimitxsec2->SetBinContent(4,3,1.000551); // Bin_7_LQ_1100_DM_400_X_440
    hlimitxsec2->SetBinContent(4,4,1.707212); // Bin_8_LQ_1100_DM_450_X_495
    hlimitxsec2->SetBinContent(4,5,6.495857); // Bin_9_LQ_1100_DM_500_X_550
    hlimitxsec2->SetBinContent(5,1,1.084549); // Bin_10_LQ_1200_DM_300_X_330
    hlimitxsec2->SetBinContent(5,2,1.138624); // Bin_11_LQ_1200_DM_350_X_385
    hlimitxsec2->SetBinContent(5,3,1.294434); // Bin_12_LQ_1200_DM_400_X_440
    hlimitxsec2->SetBinContent(5,4,1.703413); // Bin_13_LQ_1200_DM_450_X_495
    hlimitxsec2->SetBinContent(5,5,3.032537); // Bin_14_LQ_1200_DM_500_X_550
    hlimitxsec2->SetBinContent(5,6,14.466584); // Bin_15_LQ_1200_DM_550_X_595
    hlimitxsec2->SetBinContent(6,1,1.682675); // Bin_16_LQ_1300_DM_300_X_330
    hlimitxsec2->SetBinContent(6,2,1.782096); // Bin_17_LQ_1300_DM_350_X_385
    hlimitxsec2->SetBinContent(6,3,1.931963); // Bin_18_LQ_1300_DM_400_X_440
    hlimitxsec2->SetBinContent(6,4,2.280853); // Bin_19_LQ_1300_DM_450_X_495
    hlimitxsec2->SetBinContent(6,5,2.846824); // Bin_20_LQ_1300_DM_500_X_550
    hlimitxsec2->SetBinContent(6,6,5.520961); // Bin_21_LQ_1300_DM_550_X_605
    hlimitxsec2->SetBinContent(6,7,29.468037); // Bin_22_LQ_1300_DM_600_X_660
    hlimitxsec2->SetBinContent(7,1,2.720223); // Bin_23_LQ_1400_DM_300_X_330
    hlimitxsec2->SetBinContent(7,2,2.954053); // Bin_24_LQ_1400_DM_350_X_385
    hlimitxsec2->SetBinContent(7,3,2.850293); // Bin_25_LQ_1400_DM_400_X_440
    hlimitxsec2->SetBinContent(7,4,3.365421); // Bin_26_LQ_1400_DM_450_X_495
    hlimitxsec2->SetBinContent(7,5,3.668137); // Bin_27_LQ_1400_DM_500_X_550
    hlimitxsec2->SetBinContent(7,6,5.104878); // Bin_28_LQ_1400_DM_550_X_605
    hlimitxsec2->SetBinContent(7,7,10.065660); // Bin_29_LQ_1400_DM_600_X_660
    hlimitxsec2->SetBinContent(7,8,61.624760); // Bin_30_LQ_1400_DM_650_X_715
    hlimitxsec2->SetBinContent(8,1,4.571540); // Bin_31_LQ_1500_DM_300_X_330
    hlimitxsec2->SetBinContent(8,2,4.634718); // Bin_32_LQ_1500_DM_350_X_385
    hlimitxsec2->SetBinContent(8,3,4.631145); // Bin_33_LQ_1500_DM_400_X_440
    hlimitxsec2->SetBinContent(8,4,5.039595); // Bin_34_LQ_1500_DM_450_X_495
    hlimitxsec2->SetBinContent(8,5,5.552922); // Bin_35_LQ_1500_DM_500_X_550
    hlimitxsec2->SetBinContent(8,6,6.491073); // Bin_36_LQ_1500_DM_550_X_605
    hlimitxsec2->SetBinContent(8,7,8.810215); // Bin_37_LQ_1500_DM_600_X_660
    hlimitxsec2->SetBinContent(8,8,18.819564); // Bin_38_LQ_1500_DM_650_X_715
    hlimitxsec2->SetBinContent(8,9,140.197805); // Bin_39_LQ_1500_DM_700_X_770
    hlimitxsec2->SetBinContent(1,1,0.241203); // Bin_40_LQ_800_DM_300_X_330
    hlimitxsec2->SetBinContent(1,2,0.610862); // Bin_41_LQ_800_DM_350_X_385
    hlimitxsec2->SetBinContent(2,1,0.304353); // Bin_42_LQ_900_DM_300_X_330
    hlimitxsec2->SetBinContent(2,2,0.486383); // Bin_43_LQ_900_DM_350_X_385
    hlimitxsec2->SetBinContent(2,3,1.425023); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    
    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit->SetBinContent(3,1,0.455768); // Bin_1_LQ_1000_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(3,2,0.564937); // Bin_2_LQ_1000_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(3,3,0.901368); // Bin_3_LQ_1000_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(3,4,3.074375); // Bin_4_LQ_1000_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(4,1,0.694604); // Bin_5_LQ_1100_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(4,2,0.809051); // Bin_6_LQ_1100_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(4,3,1.000551); // Bin_7_LQ_1100_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(4,4,1.707212); // Bin_8_LQ_1100_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(4,5,6.495857); // Bin_9_LQ_1100_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(5,1,1.084549); // Bin_10_LQ_1200_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(5,2,1.138624); // Bin_11_LQ_1200_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(5,3,1.294434); // Bin_12_LQ_1200_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(5,4,1.703413); // Bin_13_LQ_1200_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(5,5,3.032537); // Bin_14_LQ_1200_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(5,6,14.466584); // Bin_15_LQ_1200_DM_550_X_595
    ExpctedExclusionLimit->SetBinContent(6,1,1.682675); // Bin_16_LQ_1300_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(6,2,1.782096); // Bin_17_LQ_1300_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(6,3,1.931963); // Bin_18_LQ_1300_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(6,4,2.280853); // Bin_19_LQ_1300_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(6,5,2.846824); // Bin_20_LQ_1300_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(6,6,5.520961); // Bin_21_LQ_1300_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(6,7,29.468037); // Bin_22_LQ_1300_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(7,1,2.720223); // Bin_23_LQ_1400_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(7,2,2.954053); // Bin_24_LQ_1400_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(7,3,2.850293); // Bin_25_LQ_1400_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(7,4,3.365421); // Bin_26_LQ_1400_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(7,5,3.668137); // Bin_27_LQ_1400_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(7,6,5.104878); // Bin_28_LQ_1400_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(7,7,10.065660); // Bin_29_LQ_1400_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(7,8,61.624760); // Bin_30_LQ_1400_DM_650_X_715
    ExpctedExclusionLimit->SetBinContent(8,1,4.571540); // Bin_31_LQ_1500_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(8,2,4.634718); // Bin_32_LQ_1500_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(8,3,4.631145); // Bin_33_LQ_1500_DM_400_X_440
    ExpctedExclusionLimit->SetBinContent(8,4,5.039595); // Bin_34_LQ_1500_DM_450_X_495
    ExpctedExclusionLimit->SetBinContent(8,5,5.552922); // Bin_35_LQ_1500_DM_500_X_550
    ExpctedExclusionLimit->SetBinContent(8,6,6.491073); // Bin_36_LQ_1500_DM_550_X_605
    ExpctedExclusionLimit->SetBinContent(8,7,8.810215); // Bin_37_LQ_1500_DM_600_X_660
    ExpctedExclusionLimit->SetBinContent(8,8,18.819564); // Bin_38_LQ_1500_DM_650_X_715
    ExpctedExclusionLimit->SetBinContent(8,9,140.197805); // Bin_39_LQ_1500_DM_700_X_770
    ExpctedExclusionLimit->SetBinContent(1,1,0.241203); // Bin_40_LQ_800_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(1,2,0.610862); // Bin_41_LQ_800_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(2,1,0.304353); // Bin_42_LQ_900_DM_300_X_330
    ExpctedExclusionLimit->SetBinContent(2,2,0.486383); // Bin_43_LQ_900_DM_350_X_385
    ExpctedExclusionLimit->SetBinContent(2,3,1.425023); // Bin_44_LQ_900_DM_400_X_440
    
    
    
    
    
    
    
    
    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
    ObservedExclusionLimit->SetBinContent(3,1,0.455122); // Bin_1_LQ_1000_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(3,2,0.563717); // Bin_2_LQ_1000_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(3,3,0.901334); // Bin_3_LQ_1000_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(3,4,3.079050); // Bin_4_LQ_1000_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(4,1,0.693179); // Bin_5_LQ_1100_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(4,2,0.809452); // Bin_6_LQ_1100_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(4,3,1.003621); // Bin_7_LQ_1100_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(4,4,1.705248); // Bin_8_LQ_1100_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(4,5,6.476988); // Bin_9_LQ_1100_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(5,1,1.088472); // Bin_10_LQ_1200_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(5,2,1.138085); // Bin_11_LQ_1200_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(5,3,1.295614); // Bin_12_LQ_1200_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(5,4,1.710284); // Bin_13_LQ_1200_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(5,5,3.025239); // Bin_14_LQ_1200_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(5,6,14.431773); // Bin_15_LQ_1200_DM_550_X_595
    ObservedExclusionLimit->SetBinContent(6,1,1.683858); // Bin_16_LQ_1300_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(6,2,1.783394); // Bin_17_LQ_1300_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(6,3,1.929469); // Bin_18_LQ_1300_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(6,4,2.283249); // Bin_19_LQ_1300_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(6,5,2.841702); // Bin_20_LQ_1300_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(6,6,5.527242); // Bin_21_LQ_1300_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(6,7,29.465344); // Bin_22_LQ_1300_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(7,1,2.724051); // Bin_23_LQ_1400_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(7,2,2.959837); // Bin_24_LQ_1400_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(7,3,2.852007); // Bin_25_LQ_1400_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(7,4,3.371213); // Bin_26_LQ_1400_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(7,5,3.664063); // Bin_27_LQ_1400_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(7,6,5.115353); // Bin_28_LQ_1400_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(7,7,10.092594); // Bin_29_LQ_1400_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(7,8,61.688905); // Bin_30_LQ_1400_DM_650_X_715
    ObservedExclusionLimit->SetBinContent(8,1,4.585766); // Bin_31_LQ_1500_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(8,2,4.618387); // Bin_32_LQ_1500_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(8,3,4.636107); // Bin_33_LQ_1500_DM_400_X_440
    ObservedExclusionLimit->SetBinContent(8,4,5.055634); // Bin_34_LQ_1500_DM_450_X_495
    ObservedExclusionLimit->SetBinContent(8,5,5.534441); // Bin_35_LQ_1500_DM_500_X_550
    ObservedExclusionLimit->SetBinContent(8,6,6.476050); // Bin_36_LQ_1500_DM_550_X_605
    ObservedExclusionLimit->SetBinContent(8,7,8.803995); // Bin_37_LQ_1500_DM_600_X_660
    ObservedExclusionLimit->SetBinContent(8,8,18.804006); // Bin_38_LQ_1500_DM_650_X_715
    ObservedExclusionLimit->SetBinContent(8,9,140.529515); // Bin_39_LQ_1500_DM_700_X_770
    ObservedExclusionLimit->SetBinContent(1,1,0.240868); // Bin_40_LQ_800_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(1,2,0.610170); // Bin_41_LQ_800_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(2,1,0.304091); // Bin_42_LQ_900_DM_300_X_330
    ObservedExclusionLimit->SetBinContent(2,2,0.487558); // Bin_43_LQ_900_DM_350_X_385
    ObservedExclusionLimit->SetBinContent(2,3,1.426267); // Bin_44_LQ_900_DM_400_X_440

    
    
    
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
    can2->SaveAs("lim2D_Final.pdf");
    can2->SaveAs("lim2D_Final.C");
    //     dofile("rhw.json");
    
}
