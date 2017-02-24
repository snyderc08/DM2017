#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "TTree.h"
#include "TFile.h"
#include "TF1.h"
#include "TSystem.h"
#include "TMath.h" //M_PI is in TMath
#include "TRandom3.h"
#include <TLorentzVector.h>
using namespace std;









float LandauFunc(float x){
    
    //return Landau(float x, Double_t mpv = 0, Double_t sigma = 1, Bool_t norm = kFALSE)
    
    float Land= 9.794 * TMath::Landau(x, 210, 137);
    if (x > 200)  Land= 9.794 * TMath::Landau(200, 210, 137);
    
    return Land;
    
}
//-----------------------------------------------------------------------------
//https://twiki.cern.ch/twiki/bin/view/CMS/BTagCalibration

//operatingPoint (loose = 0, medium = 1, tight = 2, disriminator reshaping = 3)
//measurementType (e.g. "ttbar", or "comb" for combination)
//sysType ("up", "central", "down", but arbitrary strings possible, like "up_generator" or "up_jec")
//jetFlavor (B = 0, C = 1, UDSG = 2)
//etaMin, etaMax
//ptMin, ptMax
//discrMin, discrMax (only for disriminator reshaping)
//(formula is the scale factor itself)
//
//-----------------------------------------------------------------------------
//0	 mujets	 central	0	-2.4	2.4	30	670	0	1	 "0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x)))"
//
//0	 mujets	 down	0	-2.4	2.4	30	50	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))-0.025967003777623177"
//0	 mujets	 down	0	-2.4	2.4	50	70	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))-0.024922125041484833"
//0	 mujets	 down	0	-2.4	2.4	70	100	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))-0.022432966157793999"
//0	 mujets	 down	0	-2.4	2.4	100	140	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))-0.027810061350464821"
//0	 mujets	 down	0	-2.4	2.4	140	200	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))-0.045993752777576447"
//0	 mujets	 down	0	-2.4	2.4	200	300	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))-0.060691386461257935"
//0	 mujets	 down	0	-2.4	2.4	300	670	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))-0.096668705344200134"
//
//0	 mujets	 up	0	-2.4	2.4	30	50	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))+0.025967003777623177"
//0	 mujets	 up	0	-2.4	2.4	50	70	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))+0.024922125041484833"
//0	 mujets	 up	0	-2.4	2.4	70	100	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))+0.022432966157793999"
//0	 mujets	 up	0	-2.4	2.4	100	140	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))+0.027810061350464821"
//0	 mujets	 up	0	-2.4	2.4	140	200	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))+0.045993752777576447"
//0	 mujets	 up	0	-2.4	2.4	200	300	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))+0.060691386461257935"
//0	 mujets	 up	0	-2.4	2.4	300	670	0	1	 "(0.953039*((1.+(0.00582506*x))/(1.+(0.00603666*x))))+0.096668705344200134"

//-----------------------------------------------------------------------------
//0	 comb	 central	0	-2.4	2.4	30	670	0	1	 "0.747498*((1.+(0.473236*x))/(1.+(0.375778*x)))"

//0	 comb	 down	0	-2.4	2.4	30	50	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))-0.018585335463285446"
//0	 comb	 down	0	-2.4	2.4	50	70	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))-0.018662562593817711"
//0	 comb	 down	0	-2.4	2.4	70	100	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))-0.018709532916545868"
//0	 comb	 down	0	-2.4	2.4	100	140	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))-0.027433760464191437"
//0	 comb	 down	0	-2.4	2.4	140	200	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))-0.045776486396789551"
//0	 comb	 down	0	-2.4	2.4	200	300	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))-0.060772690922021866"
//0	 comb	 down	0	-2.4	2.4	300	670	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))-0.098300635814666748"

//0	 comb	 up	0	-2.4	2.4	30	50	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.018585335463285446"
//0	 comb	 up	0	-2.4	2.4	50	70	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.018662562593817711"
//0	 comb	 up	0	-2.4	2.4	70	100	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.018709532916545868"
//0	 comb	 up	0	-2.4	2.4	100	140	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.027433760464191437"
//0	 comb	 up	0	-2.4	2.4	140	200	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.045776486396789551"
//0	 comb	 up	0	-2.4	2.4	200	300	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.060772690922021866"
//0	 comb	 up	0	-2.4	2.4	300	670	0	1	 "(0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.098300635814666748"
//-----------------------------------------------------------------------------
//0	 incl	 central	2	0	2.4	20	1000	0	1	 "1.00317+0.000204778*x+7.49098e-07*x*x+-9.52146e-10*x*x*x"
//0	 incl	 down       2	0	2.4	20	1000	0	1	 "0.897474+0.000130807*x+8.17188e-07*x*x+-9.52657e-10*x*x*x"
//0	 incl	 up         2	0	2.4	20	1000	0	1	 "1.10884+0.000279575*x+6.77543e-07*x*x+-9.4973e-10*x*x*x"
//-----------------------------------------------------------------------------






//0	 comb	 central	1	-2.4	2.4	30	670	0	1	 "0.931535+(1.40704e-05*x)"  //These two are the same for b and c but uncertaities are different
//0	 comb	 central	0	-2.4	2.4	30	670	0	1	 "0.931535+(1.40704e-05*x)"

//0	 comb	 down	1	-2.4	2.4	30	50	0	1	 "0.931535+((1.40704e-05*x)-0.01710829883813858)"
//0	 comb	 down	1	-2.4	2.4	50	70	0	1	 "0.931535+((1.40704e-05*x)-0.020177565515041351)"
//0	 comb	 down	1	-2.4	2.4	70	100	0	1	 "0.931535+((1.40704e-05*x)-0.019350524991750717)"
//0	 comb	 down	1	-2.4	2.4	100	140	0	1	 "0.931535+((1.40704e-05*x)-0.027258865535259247)"
//0	 comb	 down	1	-2.4	2.4	140	200	0	1	 "0.931535+((1.40704e-05*x)-0.027310512959957123)"
//0	 comb	 down	1	-2.4	2.4	200	300	0	1	 "0.931535+((1.40704e-05*x)-0.039027795195579529)"
//0	 comb	 down	1	-2.4	2.4	300	670	0	1	 "0.931535+((1.40704e-05*x)-0.089093379676342122)"

//0	 comb	 down	0	-2.4	2.4	30	50	0	1	 "0.931535+((1.40704e-05*x)-0.0085541494190692902)"
//0	 comb	 down	0	-2.4	2.4	50	70	0	1	 "0.931535+((1.40704e-05*x)-0.010088782757520676)"
//0	 comb	 down	0	-2.4	2.4	70	100	0	1	 "0.931535+((1.40704e-05*x)-0.0096752624958753586)"
//0	 comb	 down	0	-2.4	2.4	100	140	0	1	 "0.931535+((1.40704e-05*x)-0.013629432767629623)"
//0	 comb	 down	0	-2.4	2.4	140	200	0	1	 "0.931535+((1.40704e-05*x)-0.013655256479978561)"
//0	 comb	 down	0	-2.4	2.4	200	300	0	1	 "0.931535+((1.40704e-05*x)-0.019513897597789764)"
//0	 comb	 down	0	-2.4	2.4	300	670	0	1	 "0.931535+((1.40704e-05*x)-0.044546689838171005)"

//0	 comb	 up	1	-2.4	2.4	30	50	0	1	 "(0.931535+(1.40704e-05*x))+0.01710829883813858"
//0	 comb	 up	1	-2.4	2.4	50	70	0	1	 "(0.931535+(1.40704e-05*x))+0.020177565515041351"
//0	 comb	 up	1	-2.4	2.4	70	100	0	1	 "(0.931535+(1.40704e-05*x))+0.019350524991750717"
//0	 comb	 up	1	-2.4	2.4	100	140	0	1	 "(0.931535+(1.40704e-05*x))+0.027258865535259247"
//0	 comb	 up	1	-2.4	2.4	140	200	0	1	 "(0.931535+(1.40704e-05*x))+0.027310512959957123"
//0	 comb	 up	1	-2.4	2.4	200	300	0	1	 "(0.931535+(1.40704e-05*x))+0.039027795195579529"
//0	 comb	 up	1	-2.4	2.4	300	670	0	1	 "(0.931535+(1.40704e-05*x))+0.089093379676342122"

//0	 comb	 up	0	-2.4	2.4	30	50	0	1	 "(0.931535+(1.40704e-05*x))+0.0085541494190692902"
//0	 comb	 up	0	-2.4	2.4	50	70	0	1	 "(0.931535+(1.40704e-05*x))+0.010088782757520676"
//0	 comb	 up	0	-2.4	2.4	70	100	0	1	 "(0.931535+(1.40704e-05*x))+0.0096752624958753586"
//0	 comb	 up	0	-2.4	2.4	100	140	0	1	 "(0.931535+(1.40704e-05*x))+0.013629432767629623"
//0	 comb	 up	0	-2.4	2.4	140	200	0	1	 "(0.931535+(1.40704e-05*x))+0.013655256479978561"
//0	 comb	 up	0	-2.4	2.4	200	300	0	1	 "(0.931535+(1.40704e-05*x))+0.019513897597789764"
//0	 comb	 up	0	-2.4	2.4	300	670	0	1	 "(0.931535+(1.40704e-05*x))+0.044546689838171005"








//0	 mujets	 central	0	-2.4	2.4	30	670	0	1	 "0.956768*((1.+(0.107522*x))/(1.+(0.110892*x)))"


//0	 incl	 central	2	0	2.4	20	1000	0	1	 "1.05636+0.000920353*x+-7.85916e-07*x*x+1.92221e-11*x*x*x"
//0	 incl	 down	2	0	2.4	20	1000	0	1	 "(1.05636+0.000920353*x+-7.85916e-07*x*x+1.92221e-11*x*x*x)*(1-(0.0539991+-6.29073e-06*x+-3.39895e-09*x*x))"
//0	 incl	 up	2	0	2.4	20	1000	0	1	 "(1.05636+0.000920353*x+-7.85916e-07*x*x+1.92221e-11*x*x*x)*(1+(0.0539991+-6.29073e-06*x+-3.39895e-09*x*x))"




//The name of the measurements is
//
//"incl" for light jets,
//"mujets" (from QCD methods only) or “comb” (combination of QCD and ttbar methods) for b and c jets for what concerns the pT/eta

//operatingPoint (loose = 0, medium = 1, tight = 2, disriminator reshaping = 3)
//measurementType (e.g. "ttbar", or "comb" for combination)
//sysType ("up", "central", "down", but arbitrary strings possible, like "up_generator" or "up_jec")
//jetFlavor (B = 0, C = 1, UDSG = 2)
//etaMin, etaMax
//ptMin, ptMax
//discrMin, discrMax (only for disriminator reshaping)
//(formula is the scale factor itself)

// Aplly Btag Scale Factor ----------------------------------------------------------------

float GetBJetSF(float x, float jetEta, float jetHadFlvr){
    
    //    cout<< "--->Btag    pt= "<<x<<  "   jetHadFlvr" <<jetHadFlvr<< "  SF="<<1.05636+0.000920353*x+-7.85916e-07*x*x+1.92221e-11*x*x*x <<"   "<< 0.931535+(1.40704e-05*x) <<"\n";
    
    if (jetHadFlvr ==0 )
        return 1.05636+0.000920353*x+-7.85916e-07*x*x+1.92221e-11*x*x*x ;
    //        return  1.00317+0.000204778*x+7.49098e-07*x*x+-9.52146e-10*x*x*x;
    else if (jetHadFlvr ==4 || jetHadFlvr ==5 )
        return 0.931535+(1.40704e-05*x);
    //        return 0.747498*((1.+(0.473236*x))/(1.+(0.375778*x)));
    else
        return 1;
}



float GetBJetSFUp (float x, float jetEta, float jetHadFlvr){
    
    if (jetHadFlvr ==0 )
        return (1.05636+0.000920353*x+-7.85916e-07*x*x+1.92221e-11*x*x*x)*(1+(0.0539991+-6.29073e-06*x+-3.39895e-09*x*x)) ;
    //        return  1.10884+0.000279575*x+6.77543e-07*x*x+-9.4973e-10*x*x*x;
    
    else if (jetHadFlvr ==4  ){
        
        
        
        
        
        if (x >= 	30	 && x <50)  return   (0.931535+(1.40704e-05*x))+0.020177565515041351;
        if (x >= 	50	 && x <70)  return   (0.747498*((1.+(0.473236*x))/(1.+(0.375778*x))))+0.018662562593817711;
        if (x >= 	70	 && x <100)  return   (0.931535+(1.40704e-05*x))+0.019350524991750717;
        if (x >= 	100	 && x <140)  return   (0.931535+(1.40704e-05*x))+0.027258865535259247;
        if (x >= 	140 && x <	200)  return   (0.931535+(1.40704e-05*x))+0.027310512959957123;
        if (x >= 	200 && x <	300)  return   (0.931535+(1.40704e-05*x))+0.039027795195579529;
        if (x >= 	300	 && x <670)  return   (0.931535+(1.40704e-05*x))+0.089093379676342122;
        else return   (0.931535+(1.40704e-05*x))+0.089093379676342122 * 2;
    }
    
    
    else if (jetHadFlvr ==5 ){
        
        
        
        
        if (x >= 	30	 && x <50)  return   (0.931535+(1.40704e-05*x))+0.0085541494190692902;
        if (x >= 	50	 && x <70)  return   (0.931535+(1.40704e-05*x))+0.010088782757520676;
        if (x >= 	70	 && x <100)  return   (0.931535+(1.40704e-05*x))+0.0096752624958753586;
        if (x >= 	100	 && x <140)  return   (0.931535+(1.40704e-05*x))+0.013629432767629623;
        if (x >= 	140 && x <	200)  return   (0.931535+(1.40704e-05*x))+0.013655256479978561;
        if (x >= 	200 && x <	300)  return   (0.931535+(1.40704e-05*x))+0.019513897597789764;
        if (x >= 	300	 && x <670)  return   (0.931535+(1.40704e-05*x))+0.044546689838171005;
        else return   (0.931535+(1.40704e-05*x))+0.044546689838171005 * 2;
    }
    else
        
        return 1;
}


float GetBJetSFDown (float x, float jetEta, float jetHadFlvr){
    
    if (jetHadFlvr ==0 )
        return (1.05636+0.000920353*x+-7.85916e-07*x*x+1.92221e-11*x*x*x)*(1-(0.0539991+-6.29073e-06*x+-3.39895e-09*x*x))       ;
    //        return  0.897474+0.000130807*x+8.17188e-07*x*x+-9.52657e-10*x*x*x;
    
    else if (jetHadFlvr ==4 ){
        
        
        
        
        if (x >= 	30	 && x <50)  return   0.931535+((1.40704e-05*x)-0.01710829883813858);
        if (x >= 	50	 && x <70)  return   0.931535+((1.40704e-05*x)-0.020177565515041351);
        if (x >= 	70	 && x <100)  return   0.931535+((1.40704e-05*x)-0.019350524991750717);
        if (x >= 	100	 && x <140)  return   0.931535+((1.40704e-05*x)-0.027258865535259247);
        if (x >= 	140 && x <	200)  return   0.931535+((1.40704e-05*x)-0.027310512959957123);
        if (x >= 	200 && x <	300)  return   0.931535+((1.40704e-05*x)-0.039027795195579529);
        if (x >= 	300	 && x <670)  return   0.931535+((1.40704e-05*x)-0.089093379676342122);
        else return 0.931535+((1.40704e-05*x)-0.089093379676342122)*2;
        
    }
    else if (jetHadFlvr ==5 ){
        
        
        
        if (x >= 	30	 && x <50)  return   0.931535+((1.40704e-05*x)-0.0085541494190692902);
        if (x >= 	50	 && x <70)  return   0.931535+((1.40704e-05*x)-0.010088782757520676);
        if (x >= 	70	 && x <100)  return   0.931535+((1.40704e-05*x)-0.0096752624958753586);
        if (x >= 	100	 && x <140)  return   0.931535+((1.40704e-05*x)-0.013629432767629623);
        if (x >= 	140 && x <	200)  return   0.931535+((1.40704e-05*x)-0.013655256479978561);
        if (x >= 	200 && x <	300)  return   0.931535+((1.40704e-05*x)-0.019513897597789764);
        if (x >= 	300	 && x <670)  return   0.931535+((1.40704e-05*x)-0.044546689838171005);
        else return 0.931535+((1.40704e-05*x)-0.044546689838171005) *2;
        
    }
    
    
    else
        
        return 1;
}


//-----------------------------------------------------------------------------

//  Apply W scale factor

float WShapeUnc(string InputROOT, float CLoseJetTauPt){
    
    
    //    if  (InputROOT.find("WJets"))
    //        return  LandauFunc(CLoseJetTauPt) ;
    //    else
    //        return 1;
    
    return 1;
}



//  Apply W k-factor scale factor


float Get_W_Z_BosonKFactor(float WBosonPt, TH1F* WLO, TH1F* WNLO){
    float LO=0;
    float NLO=0;
    float kfactor=1;
    for (int ibin =1; ibin < WLO->GetNbinsX()+1;ibin++){
    
        if ( WBosonPt > WLO->GetBinCenter(ibin) - WLO->GetBinWidth(ibin)/2   && WBosonPt < WLO->GetBinCenter(ibin) + WLO->GetBinWidth(ibin)/2 ){
            LO=WLO->GetBinContent(ibin);
            NLO=WNLO->GetBinContent(ibin);
            kfactor=NLO/LO;
            break;
        }
    }
    
    if ( WBosonPt < WLO->GetBinCenter(1) - WLO->GetBinWidth(1)/2){
            LO=WLO->GetBinContent(1);
            NLO=WNLO->GetBinContent(1);
            kfactor=NLO/LO;
        }
    if ( WBosonPt > WLO->GetBinCenter(WLO->GetNbinsX()) + WLO->GetBinWidth(WLO->GetNbinsX())/2){
            LO=WLO->GetBinContent(WLO->GetNbinsX());
            NLO=WNLO->GetBinContent(WLO->GetNbinsX());
            kfactor=NLO/LO;
        }
    
//    cout << " WBosonPt = " << WBosonPt << "   & kfactor=" << kfactor<<"\n";
    return kfactor;
    
    
}



//-----------------------------------------------------------------------------
// AM: recipe for top quark Pt reweighting taken from https://twiki.cern.ch/twiki/bin/viewauth/CMS/TopPtReweighting

float compTopPtWeight(float topPt) {
    const float a =  0.148 ;
    const float b =  -0.00129;
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



////******************** ETau/MuTau turn-on *****************************
//
//double correctionHighPtTail_Data(myobject const& a) {
//    //Additional corrections for high pT taus in muTau & eTau (Arun, Mar14)
//    TF1 *TriggerWeightBarrel = new TF1("AddTriggerWeightMuTauBarrel", "1 - 9.01280e-04*(x - 140) + 4.81592e-07*(x - 140)*(x-140)", 0., 800.);
//    TF1 *TriggerWeightEndcaps = new TF1("AddTriggerWeightMuTauEndcaps", "1 - 1.81148e-03*(x - 60) + 5.44335e-07*(x - 60)*(x-60)", 0., 800.);
//
//    //    Double_t DataValBarrel_pt = 0.3 + 0.7 * TriggerWeightBarrel->Eval(a.pt);
//    //    Double_t DataValBarrel_800 = 0.3 + 0.7 * TriggerWeightBarrel->Eval(800.);
//    //
//    //    Double_t DataValEndcaps_pt = 0.3 + 0.7 * TriggerWeightEndcaps->Eval(a.pt);
//    //    Double_t DataValEndcaps_400 = 0.3 + 0.7 * TriggerWeightEndcaps->Eval(400.);
//    float ratioABCD= 0.62457;
//    float OneMinratioABCD= 1- ratioABCD;
//    if (a.pt > 140 && a.pt < 800 && fabs(a.eta) < 1.5) return (OneMinratioABCD + ratioABCD * TriggerWeightBarrel->Eval(a.pt));
//    else if (a.pt >= 800 && fabs(a.eta) <= 1.5) return (OneMinratioABCD + ratioABCD * TriggerWeightBarrel->Eval(800.));
//    else if (a.pt > 60 && a.pt < 400 && fabs(a.eta) > 1.5) return (OneMinratioABCD + ratioABCD * TriggerWeightEndcaps->Eval(a.pt));
//    else if (a.pt >= 400 && fabs(a.eta) >= 1.5) return (OneMinratioABCD + ratioABCD * TriggerWeightEndcaps->Eval(400.));
//        //    if (a.pt < 800 && fabs(a.eta) < 1.5) return (0.3 + 0.7 * TriggerWeightBarrel->Eval(a.pt));
//        //    else if (a.pt >= 800 && fabs(a.eta) <= 1.5) return (0.3 + 0.7 * TriggerWeightBarrel->Eval(800.));
//        //    else if (a.pt < 400 && fabs(a.eta) > 1.5) return (0.3 + 0.7 * TriggerWeightEndcaps->Eval(a.pt));
//        //    else if (a.pt >= 400 && fabs(a.eta) >= 1.5) return (0.3 + 0.7 * TriggerWeightEndcaps->Eval(400.));
//    else return 1;
//}
//
//double correctionHighPtTail_MC(myobject const& a) {
//    //Additional corrections for high pT taus in muTau & eTau (Arun, Mar14)
//    TF1 *TriggerWeightBarrel = new TF1("AddTriggerWeightMuTauBarrel", "1 - 9.01280e-04*(x - 140) + 4.81592e-07*(x - 140)*(x-140)", 0., 800.);
//    TF1 *TriggerWeightEndcaps = new TF1("AddTriggerWeightMuTauEndcaps", "1 - 1.81148e-03*(x - 60) + 5.44335e-07*(x - 60)*(x-60)", 0., 800.);
//
//    //    Double_t MCValBarrel_pt = TriggerWeightBarrel->Eval(a.pt);
//    //    Double_t MCValBarrel_800 = TriggerWeightBarrel->Eval(800.);
//    //
//    //    Double_t MCValEndcaps_pt = TriggerWeightEndcaps->Eval(a.pt);
//    //    Double_t MCValEndcaps_400 = TriggerWeightEndcaps->Eval(400.);
//
//
//    if (a.pt > 140 && a.pt < 800 && fabs(a.eta) < 1.5) return TriggerWeightBarrel->Eval(a.pt);
//    else if (a.pt >= 800 && fabs(a.eta) <= 1.5) return TriggerWeightBarrel->Eval(800.);
//    else if (a.pt > 60 && a.pt < 400 && fabs(a.eta) > 1.5) return TriggerWeightEndcaps->Eval(a.pt);
//    else if (a.pt >= 400 && fabs(a.eta) >= 1.5) return TriggerWeightEndcaps->Eval(400.);
//    else return 1;
//
//}
//
////double efficiency(double m, double m0, double sigma, double alpha, double n, double norm) {
////    const double sqrtPiOver2 = 1.2533141373;
////    const double sqrt2 = 1.4142135624;
////    double sig = fabs((double) sigma);
////    double t = (m - m0) / sig;
////    if (alpha < 0)
////        t = -t;
////    double absAlpha = fabs(alpha / sig);
////    double a = TMath::Power(n / absAlpha, n) * exp(-0.5 * absAlpha * absAlpha);
////    double b = absAlpha - n / absAlpha;
////    double ApproxErf;
////    double arg = absAlpha / sqrt2;
////    if (arg > 5.) ApproxErf = 1;
////    else if (arg < -5.) ApproxErf = -1;
////    else ApproxErf = TMath::Erf(arg);
////    double leftArea = (1 + ApproxErf) * sqrtPiOver2;
////    double rightArea = (a * 1 / TMath::Power(absAlpha - b, n - 1)) / (n - 1);
////    double area = leftArea + rightArea;
////    if (t <= absAlpha) {
////        arg = t / sqrt2;
////        if (arg > 5.) ApproxErf = 1;
////        else if (arg < -5.) ApproxErf = -1;
////        else ApproxErf = TMath::Erf(arg);
////        return norm * (1 + ApproxErf) * sqrtPiOver2 / area;
////    } else {
////        return norm * (leftArea + a * (1 / TMath::Power(t - b, n - 1) -
////                1 / TMath::Power(absAlpha - b, n - 1)) / (1 - n)) / area;
////    }
////
////}
//
//double efficiency(double m, double m0, double sigma, double alpha, double n, double norm) {
//    const double sqrtPiOver2 = 1.2533141373;
//    const double sqrt2 = 1.4142135624;
//    double sig = fabs((double) sigma);
//    double t = (m - m0) / sig;
//    if (alpha < 0)
//        t = -t;
//    double absAlpha = fabs(alpha / sig);
//    double a = TMath::Power(n / absAlpha, n) * exp(-0.5 * absAlpha * absAlpha);
//    double b = absAlpha - n / absAlpha;
//    double ApproxErf;
//    double arg = absAlpha / sqrt2;
//    if (arg > 5.) ApproxErf = 1;
//    else if (arg < -5.) ApproxErf = -1;
//    else ApproxErf = TMath::Erf(arg);
//    double leftArea = (1 + ApproxErf) * sqrtPiOver2;
//    double rightArea = (a * 1 / TMath::Power(absAlpha - b, n - 1)) / (n - 1);
//    double area = leftArea + rightArea;
//    if (t <= absAlpha) {
//        arg = t / sqrt2;
//        if (arg > 5.) ApproxErf = 1;
//        else if (arg < -5.) ApproxErf = -1;
//        else ApproxErf = TMath::Erf(arg);
//        return norm * (1 + ApproxErf) * sqrtPiOver2 / area;
//    } else {
//        return norm * (leftArea + a * (1 / TMath::Power(t - b, n - 1) -
//                1 / TMath::Power(absAlpha - b, n - 1)) / (1 - n)) / area;
//    }
//}
//
//
////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//// *** 2011 *** //
////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//
//float Cor74X_ID_Iso_Mu_2011(myobject const& a) {
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) < 1.5) return 0.9895;
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) >= 1.5) return 1.0303;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) < 1.5) return 1.0168;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) >= 1.5) return 1.0247;
//    if (a.pt > 20 && fabs(a.eta) < 1.5) return 1.0061;
//    if (a.pt > 20 && fabs(a.eta) >= 1.5) return 1.0144;
//    return 1.0;
//}
//
//float Cor74X_ID_Iso_Ele_2011(myobject const& a) {
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) < 1.479) return 1.0396;
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) >= 1.479) return 0.9758;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) < 1.479) return 0.9622;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) >= 1.479) return 1.1483;
//    if (a.pt >= 20 && fabs(a.eta) < 1.479) return 0.9849;
//    if (a.pt >= 20 && fabs(a.eta) >= 1.479) return 1.0117;
//    return 1.0;
//}
//
////*****************************************************
////***************** ETau channel **********************
////*****************************************************
//
//float Cor74X_IDIso_ETau_Ele_2012(myobject const& a) {
//    if (a.pt >= 24 && a.pt < 30 && fabs(a.eta) < 1.479) return 0.8999 * 0.9417;
//    else if (a.pt >= 24 && a.pt < 30 && fabs(a.eta) > 1.479) return 0.7945 * 0.9471;
//    else if (a.pt >= 30 && fabs(a.eta) < 1.479) return 0.9486 * 0.9804;
//    else if (a.pt >= 30 && fabs(a.eta) > 1.479) return 0.8866 * 0.9900;
//    else return 1.0;
//}
//
//float Cor74X_ID_ETau_Ele_2012(myobject const& a) {
//    if (a.pt >= 24 && a.pt < 30 && fabs(a.eta) < 1.479) return 0.8999;
//    else if (a.pt >= 24 && a.pt < 30 && fabs(a.eta) > 1.479) return 0.7945;
//    else if (a.pt >= 30 && fabs(a.eta) < 1.479) return 0.9486;
//    else if (a.pt >= 30 && fabs(a.eta) > 1.479) return 0.8866;
//    else return 1.0;
//}
//
//float Cor74X_Iso_ETau_Ele_2012(myobject const& a) {
//    if (a.pt >= 24 && a.pt < 30 && fabs(a.eta) < 1.479) return 0.9417;
//    else if (a.pt >= 24 && a.pt < 30 && fabs(a.eta) > 1.479) return 0.9471;
//    else if (a.pt >= 30 && fabs(a.eta) < 1.479) return 0.9804;
//    else if (a.pt >= 30 && fabs(a.eta) > 1.479) return 0.9900;
//    else return 1.0;
//}
////   Trigger   *****************************************************
//
//float Eff_ETauTrg_Ele_MC_2012(myobject const& a) {
//    if (fabs(a.eta) < 1.479) return efficiency(a.pt, 21.7243, 0.619015, 0.739301, 1.34903, 1.02594);
//    else return efficiency(a.pt, 22.1217, 1.34054, 1.8885, 1.01855, 4.7241);
//}
//
//float Eff_ETauTrg_Ele_Data_2012(myobject const& a) {
//    if (fabs(a.eta) < 1.479) return efficiency(a.pt, 22.9704, 1.0258, 1.26889, 1.31024, 1.06409);
//    else return efficiency(a.pt, 21.9816, 1.40993, 0.978597, 2.33144, 0.937552);
//}
//
////float Eff_ETauTrg_Tau_MC_2012(myobject const& a) {
////    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 18.525766, 0.275904, 0.126185, 4.957594, 0.915910);
////    else return efficiency(a.pt, 18.552006, 0.632002, 0.426891, 133.934952, 0.866543);
////}
////
////float Eff_ETauTrg_Tau_Data_2012(myobject const& a) {
////    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 18.538229, 0.651562, 0.324869, 13.099048, 0.902365);
////    else return efficiency(a.pt, 18.756548, 0.230732, 0.142859, 3.358497, 0.851919);
////}
//// ABCD
//
//float Eff_ETauTrg_Tau_Data_2012(myobject const& a) {
//    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 1.83211e+01, -1.89051e+00, 3.71081e+00, 1.06628e+00, 1.28559e+00); //data barrel
//    else return efficiency(a.pt, 1.80812e+01, 1.39482e+00, 1.14305e+00, 1.08989e+01, 8.97087e-01); //data end cap
//}
//// MC ABCD
//
//float Eff_ETauTrg_Tau_MC_2012(myobject const& a) {
//    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 1.83709e+01, 1.37806e-01, 1.64478e-01, 1.44798e+00, 9.92673e-01); //MC barrel
//    else return efficiency(a.pt, 1.83074e+01, 1.43406e+00, 1.40743e+00, 1.41501e+02, 9.19457e-01); //MC end cap
//}
//
////*****************************************************
////***************** MuTau channel *********************
////*****************************************************
//
//float Cor74X_IDIso_MuTau_Muon_2012(myobject const& a) {
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 0.8) return 0.9818 * 0.9494;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 1.2) return 0.9829 * 0.9835;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 2.1) return 0.9869 * 0.9923;
//    if (a.pt >= 30 && fabs(a.eta) < 0.8) return 0.9852 * 0.9883;
//    if (a.pt >= 30 && fabs(a.eta) < 1.2) return 0.9852 * 0.9937;
//    if (a.pt >= 30 && fabs(a.eta) < 2.1) return 0.9884 * 0.9996;
//    return 1.0;
//}
//
//float Cor74X_ID_MuTau_Muon_2012(myobject const& a) {
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 0.8) return 0.9818;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 1.2) return 0.9829;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 2.1) return 0.9869;
//    if (a.pt >= 30 && fabs(a.eta) < 0.8) return 0.9852;
//    if (a.pt >= 30 && fabs(a.eta) < 1.2) return 0.9852;
//    if (a.pt >= 30 && fabs(a.eta) < 2.1) return 0.9884;
//    return 1.0;
//}
//
//float Cor74X_Iso_MuTau_Muon_2012(myobject const& a) {
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 0.8) return 0.9494;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 1.2) return 0.9835;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) < 2.1) return 0.9923;
//    if (a.pt >= 30 && fabs(a.eta) < 0.8) return 0.9883;
//    if (a.pt >= 30 && fabs(a.eta) < 1.2) return 0.9937;
//    if (a.pt >= 30 && fabs(a.eta) < 2.1) return 0.9996;
//    return 1.0;
//}
////   Trigger   *****************************************************
//
//float Eff_MuTauTrg_Mu_Data_2012(myobject const& a) {
//    if (a.eta < -1.2) return efficiency(a.pt, 15.9977, 0.0000764004, 6.4951e-8, 1.57403, 0.865325);
//    else if (a.eta < -0.8) return efficiency(a.pt, 17.3974, 0.804001, 1.47145, 1.24295, 0.928198);
//    else if (a.eta < 0) return efficiency(a.pt, 16.4307, 0.226312, 0.265553, 1.55756, 0.974462);
//    else if (a.eta < 0.8) return efficiency(a.pt, 17.313, 0.662731, 1.3412, 1.05778, 1.26624);
//    else if (a.eta < 1.2) return efficiency(a.pt, 16.9966, 0.550532, 0.807863, 1.55402, 0.885134);
//    else if (a.eta > 1.2) return efficiency(a.pt, 15.9962, 0.000106195, 4.95058e-8, 1.9991, 0.851294);
//    else return 1;
//}
//
//float Eff_MuTauTrg_Mu_MC_2012(myobject const& a) {
//    if (a.eta < -1.2) return efficiency(a.pt, 16.0051, 2.45144e-5, 4.3335e-9, 1.66134, 0.87045);
//    else if (a.eta < -0.8) return efficiency(a.pt, 17.3135, 0.747646, 1.21803, 1.40611, 0.934983);
//    else if (a.eta < 0) return efficiency(a.pt, 15.9556, 0.0236127, 0.00589832, 1.75409, 0.981338);
//    else if (a.eta < 0.8) return efficiency(a.pt, 15.9289, 0.0271317, 0.00448573, 1.92101, 0.978625);
//    else if (a.eta < 1.2) return efficiency(a.pt, 16.5678, 0.328333, 0.354533, 1.67085, 0.916992);
//    else if (a.eta > 1.2) return efficiency(a.pt, 15.997, 7.90069e-5, 4.40039e-8, 1.66272, 0.884502);
//    else return 1;
//}
//
////float Eff_MuTauTrg_Tau_MC_2012(myobject const& a) {
////    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 18.537441, 1.385790, 3.102076, 1.002486, 6.275127);
////    else return efficiency(a.pt, 18.393366, 1.526254, 2.021678, 124.741631, 0.893280);
////}
////
////float Eff_MuTauTrg_Tau_Data_2012(myobject const& a) {
////    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 18.604910, 0.276042, 0.137039, 2.698437, 0.94721);
////    else return efficiency(a.pt, 18.701715, 0.216523, 0.148111, 2.245081, 0.895320);
////}
//
//
//// ABCD      antiEMed
//
//float Eff_MuTauTrg_Tau_Data_2012(myobject const& a) {
//    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 1.83211e+01, -1.89051e+00, 3.71081e+00, 1.06628e+00, 1.28559e+00); //data barrel
//    else return efficiency(a.pt, 1.80812e+01, 1.39482e+00, 1.14305e+00, 1.08989e+01, 8.97087e-01); //data endcap
//}
//
//// MC ABCD   antiEMed
//
//float Eff_MuTauTrg_Tau_MC_2012(myobject const& a) {
//    if (fabs(a.eta) < 1.5) return efficiency(a.pt, 1.83709e+01, 1.37806e-01, 1.64478e-01, 1.44798e+00, 9.92673e-01); //MC barrel
//    else return efficiency(a.pt, 1.83074e+01, 1.43406e+00, 1.40743e+00, 1.41501e+02, 9.19457e-01); //MC endcap
//}
//
////*****************************************************
////****************** EMu channel **********************
////*****************************************************
//
//float Cor74X_IDIso_EMu_Mu_2012(myobject const& a) {
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) < 0.8) return 0.9771;
//    if (a.pt >= 10 && a.pt < 15 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9746;
//    if (a.pt >= 10 && a.pt < 15 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9644;
//    if (a.pt >= 10 && a.pt < 15 && 1.6 <= fabs(a.eta)) return 0.9891;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) < 0.8) return 0.9548;
//    if (a.pt >= 15 && a.pt < 20 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9701;
//    if (a.pt >= 15 && a.pt < 20 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9766;
//    if (a.pt >= 15 && a.pt < 20 && 1.6 <= fabs(a.eta)) return 0.9892;
//    if (a.pt >= 20 && a.pt < 25 && fabs(a.eta) < 0.8) return 0.9648;
//    if (a.pt >= 20 && a.pt < 25 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9836;
//    if (a.pt >= 20 && a.pt < 25 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9820;
//    if (a.pt >= 20 && a.pt < 25 && 1.6 <= fabs(a.eta)) return 0.9909;
//    if (a.pt >= 25 && a.pt < 30 && fabs(a.eta) < 0.8) return 0.9676;
//    if (a.pt >= 25 && a.pt < 30 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9817;
//    if (a.pt >= 25 && a.pt < 30 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9886;
//    if (a.pt >= 25 && a.pt < 30 && 1.6 <= fabs(a.eta)) return 0.9883;
//    if (a.pt >= 30 && a.pt < 35 && fabs(a.eta) < 0.8) return 0.9730;
//    if (a.pt >= 30 && a.pt < 35 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9833;
//    if (a.pt >= 30 && a.pt < 35 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9910;
//    if (a.pt >= 30 && a.pt < 35 && 1.6 <= fabs(a.eta)) return 0.9900;
//    if (a.pt >= 35 && fabs(a.eta) < 0.8) return 0.9826;
//    if (a.pt >= 35 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9841;
//    if (a.pt >= 35 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9900;
//    if (a.pt >= 35 && 1.6 <= fabs(a.eta)) return 0.9886;
//    return 1.0;
//}
//
//float Cor74X_IDIso_EMu_Ele_2012(myobject const& a) {
//    if (a.pt > 10.0 && a.pt <= 15.0 && fabs(a.eta) >= 0.0 && fabs(a.eta) < 0.8) return 0.7654;
//    if (a.pt > 10.0 && a.pt <= 15.0 && fabs(a.eta) >= 0.8 && fabs(a.eta) < 1.5) return 0.7693;
//    if (a.pt > 10.0 && a.pt <= 15.0 && fabs(a.eta) >= 1.5) return 0.5719;
//    if (a.pt > 15.0 && a.pt <= 20.0 && fabs(a.eta) >= 0.0 && fabs(a.eta) < 0.8) return 0.8394;
//    if (a.pt > 15.0 && a.pt <= 20.0 && fabs(a.eta) >= 0.8 && fabs(a.eta) < 1.5) return 0.8457;
//    if (a.pt > 15.0 && a.pt <= 20.0 && fabs(a.eta) >= 1.5) return 0.7024;
//    if (a.pt > 20.0 && a.pt <= 25.0 && fabs(a.eta) >= 0.0 && fabs(a.eta) < 0.8) return 0.8772;
//    if (a.pt > 20.0 && a.pt <= 25.0 && fabs(a.eta) >= 0.8 && fabs(a.eta) < 1.5) return 0.8530;
//    if (a.pt > 20.0 && a.pt <= 25.0 && fabs(a.eta) >= 1.5) return 0.7631;
//    if (a.pt > 25.0 && a.pt <= 30.0 && fabs(a.eta) >= 0.0 && fabs(a.eta) < 0.8) return 0.9006;
//    if (a.pt > 25.0 && a.pt <= 30.0 && fabs(a.eta) >= 0.8 && fabs(a.eta) < 1.5) return 0.8874;
//    if (a.pt > 25.0 && a.pt <= 30.0 && fabs(a.eta) >= 1.5) return 0.8092;
//    if (a.pt > 30.0 && a.pt <= 35.0 && fabs(a.eta) >= 0.0 && fabs(a.eta) < 0.8) return 0.9261;
//    if (a.pt > 30.0 && a.pt <= 35.0 && fabs(a.eta) >= 0.8 && fabs(a.eta) < 1.5) return 0.9199;
//    if (a.pt > 30.0 && a.pt <= 35.0 && fabs(a.eta) >= 1.5) return 0.8469;
//    if (a.pt > 35.0 && fabs(a.eta) >= 0.0 && fabs(a.eta) < 0.8) return 0.9514;
//    if (a.pt > 35.0 && fabs(a.eta) >= 0.8 && fabs(a.eta) < 1.5) return 0.9445;
//    if (a.pt > 35.0 && fabs(a.eta) >= 1.5) return 0.9078;
//    return 1.0;
//}
//
//float Corr_EMuTrg_Mu_2011(myobject const& a) {
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) <= 1.5) return 1.01;
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) > 1.5) return 1.03;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) <= 1.5) return 0.99;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) > 1.5) return 1.07;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) <= 1.5) return 0.99;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) > 1.5) return 1.04;
//    if (a.pt > 30 && fabs(a.eta) <= 1.5) return 0.992;
//    if (a.pt > 30 && fabs(a.eta) > 1.5) return 1.06;
//    return 1;
//}
//
//float Corr_EMuTrg_Ele_2011(myobject const& a) {
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) <= 1.479) return 0.98;
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) > 1.479) return 0.97;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) <= 1.479) return 1.00;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) > 1.479) return 1.05;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) <= 1.479) return 1.001;
//    if (a.pt >= 20 && a.pt < 30 && fabs(a.eta) > 1.479) return 1.00;
//    if (a.pt > 30 && fabs(a.eta) <= 1.479) return 1.003;
//    if (a.pt > 30 && fabs(a.eta) > 1.479) return 1.008;
//    return 1;
//}
//
//float Corr_EMuTrg_MuLeg_2012(myobject const& a) {
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) < 0.8) return 0.9829;
//    if (a.pt >= 10 && a.pt < 15 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9745;
//    if (a.pt >= 10 && a.pt < 15 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9943;
//    if (a.pt >= 10 && a.pt < 15 && 1.6 <= fabs(a.eta)) return 0.9158;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) < 0.8) return 0.9850;
//    if (a.pt >= 15 && a.pt < 20 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9852;
//    if (a.pt >= 15 && a.pt < 20 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9743;
//    if (a.pt >= 15 && a.pt < 20 && 1.6 <= fabs(a.eta)) return 0.9333;
//    if (a.pt >= 20 && a.pt < 25 && fabs(a.eta) < 0.8) return 0.9951;
//    if (a.pt >= 20 && a.pt < 25 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9610;
//    if (a.pt >= 20 && a.pt < 25 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9716;
//    if (a.pt >= 20 && a.pt < 25 && 1.6 <= fabs(a.eta)) return 0.9459;
//    if (a.pt >= 25 && a.pt < 30 && fabs(a.eta) < 0.8) return 0.9869;
//    if (a.pt >= 25 && a.pt < 30 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9779;
//    if (a.pt >= 25 && a.pt < 30 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9665;
//    if (a.pt >= 25 && a.pt < 30 && 1.6 <= fabs(a.eta)) return 0.9501;
//    if (a.pt >= 30 && a.pt < 35 && fabs(a.eta) < 0.8) return 0.9959;
//    if (a.pt >= 30 && a.pt < 35 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9881;
//    if (a.pt >= 30 && a.pt < 35 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9932;
//    if (a.pt >= 30 && a.pt < 35 && 1.6 <= fabs(a.eta)) return 0.9391;
//    if (a.pt >= 35 && fabs(a.eta) < 0.8) return 0.9986;
//    if (a.pt >= 35 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.2) return 0.9540;
//    if (a.pt >= 35 && 1.2 <= fabs(a.eta) && fabs(a.eta) < 1.6) return 0.9549;
//    if (a.pt >= 35 && 1.6 <= fabs(a.eta)) return 0.9386;
//    return 1.0;
//}
//
//float Corr_EMuTrg_EleLeg_2012(myobject const& a) {
//    if (a.pt >= 10 && a.pt < 15 && fabs(a.eta) >= 0 && fabs(a.eta) < 0.8) return 0.9548;
//    if (a.pt >= 10 && a.pt < 15 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.5) return 0.9015;
//    if (a.pt >= 10 && a.pt < 15 && 1.5 <= fabs(a.eta)) return 0.9017;
//    if (a.pt >= 15 && a.pt < 20 && fabs(a.eta) >= 0 && fabs(a.eta) < 0.8) return 0.9830;
//    if (a.pt >= 15 && a.pt < 20 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.5) return 0.9672;
//    if (a.pt >= 15 && a.pt < 20 && 1.5 <= fabs(a.eta)) return 0.9463;
//    if (a.pt >= 20 && a.pt < 25 && fabs(a.eta) >= 0 && fabs(a.eta) < 0.8) return 0.9707;
//    if (a.pt >= 20 && a.pt < 25 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.5) return 0.9731;
//    if (a.pt >= 20 && a.pt < 25 && fabs(a.eta) >= 1.5) return 0.9691;
//    if (a.pt >= 25 && a.pt < 30 && fabs(a.eta) >= 0 && fabs(a.eta) < 0.8) return 0.9768;
//    if (a.pt >= 25 && a.pt < 30 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.5) return 0.9870;
//    if (a.pt >= 25 && a.pt < 30 && fabs(a.eta) >= 1.5) return 0.9727;
//    if (a.pt >= 30 && a.pt < 35 && fabs(a.eta) >= 0 && fabs(a.eta) < 0.8) return 1.0047;
//    if (a.pt >= 30 && a.pt < 35 && 0.8 <= fabs(a.eta) && fabs(a.eta) < 1.5) return 0.9891;
//    if (a.pt >= 30 && a.pt < 35 && fabs(a.eta) >= 1.5) return 0.9858;
//    if (a.pt > 35 && fabs(a.eta) >= 0.0 && fabs(a.eta) < 0.8) return 1.0063;
//    if (a.pt > 35 && fabs(a.eta) >= 0.8 && fabs(a.eta) < 1.5) return 1.0047;
//    if (a.pt > 35 && fabs(a.eta) >= 1.5) return 1.0015;
//    return 1;
//}
//
////*****************************************************
////***************** TauTau channel ********************
////*****************************************************
//
//double eff2012IsoParkedTau19fb_Simone(double pt, double eta) {
//    return ( 0.826969 * 0.5 * (TMath::Erf((pt - 42.2274) / 2. / 0.783258 / sqrt(pt)) + 1.)); // only one eta bin
//}
//
//double eff2012IsoParkedTau19fbMC_Simone(double pt, double eta) {
//    double data_plateau = 0.826969;
//    if (pt < 140.)
//        return ( 0.813769 * 0.5 * (TMath::Erf((pt - 39.9322) / 2. / 0.819354 / sqrt(pt)) + 1.)); // only one eta bin
//    else if (pt > 400) return data_plateau / 2.03467;
//    else if (pt > 300) return data_plateau / 1.31593;
//    else if (pt > 250) return data_plateau / 1.25698;
//    else if (pt > 200) return data_plateau / 1.18941;
//    else if (pt > 180) return data_plateau / 1.17448;
//    else if (pt > 160) return data_plateau / 1.0964;
//    else return data_plateau / 1.09279;
//}
//
//double eff2012IsoTau19fb_Simone(double pt, double eta) {
//    // for real Taus mT<20
//    if (fabs(eta) < 1.4) {
//        return ( 808.411 * (0.764166 * 0.5 * (TMath::Erf((pt - 33.2236) / 2. / 0.97289 / sqrt(pt)) + 1.)) // 2012A by Bastian not split in eta
//                + 4428.0 * (0.75721 * 0.5 * (TMath::Erf((pt - 39.0836) / 2. / 1.07753 / sqrt(pt)) + 1.)) // 2012B
//                + 6892.158 * (0.791464 * 0.5 * (TMath::Erf((pt - 38.4932) / 2. / 1.01232 / sqrt(pt)) + 1.)) // 2012C measured in v2 only
//                + 7274. * (0.779446 * 0.5 * (TMath::Erf((pt - 38.4603) / 2. / 1.01071 / sqrt(pt)) + 1.))) // 2012D measured in one go
//                / (808.411 + 4428.0 + 6892.158 + 7274.);
//        //                if(a.pt >= 17 && a.pt < 20 && fabs(a.eta) < 0.8) return;
//    } else {
//        return ( 808.411 * (0.764166 * 0.5 * (TMath::Erf((pt - 33.2236) / 2. / 0.97289 / sqrt(pt)) + 1.)) // 2012A by Bastian not split in eta
//                + 4428.0 * (0.693788 * 0.5 * (TMath::Erf((pt - 37.7719) / 2. / 1.09202 / sqrt(pt)) + 1.)) // 2012B
//                + 6892.158 * (0.698909 * 0.5 * (TMath::Erf((pt - 36.5533) / 2. / 1.05743 / sqrt(pt)) + 1.)) // 2012C measured in v2 only
//                + 7274. * (0.703532 * 0.5 * (TMath::Erf((pt - 38.8609) / 2. / 1.05514 / sqrt(pt)) + 1.))) // 2012D measured in one go
//                / (808.411 + 4428.0 + 6892.158 + 7274.);
//    }
//}
//
//double eff2012IsoTau19fbMC_Simone(double pt, double eta) {
//    if (fabs(eta) < 1.4) {
//        return ( 0.807425 * 0.5 * (TMath::Erf((pt - 35.2214) / 2. / 1.04214 / sqrt(pt)) + 1.));
//    } else {
//        return ( 0.713068 * 0.5 * (TMath::Erf((pt - 33.4584) / 2. / 0.994692 / sqrt(pt)) + 1.));
//    }
//}
//
//double eff2012Jet19fb(double pt, double eta) {
//    return (fabs(eta) <= 2.1)*
//            ((808.411 * (0.99212 * 0.5 * (TMath::Erf((pt - 31.3706) / 2. / 1.22821 / sqrt(pt)) + 1.))
//            + 4428.0 * (0.99059 * 0.5 * (TMath::Erf((pt - 32.1104) / 2. / 1.23292 / sqrt(pt)) + 1.))
//            + 1783.003 * (0.988256 * 0.5 * (TMath::Erf((pt - 31.3103) / 2. / 1.18766 / sqrt(pt)) + 1.))
//            + 5109.155 * (0.988578 * 0.5 * (TMath::Erf((pt - 31.6391) / 2. / 1.22826 / sqrt(pt)) + 1.))
//            + 4131. * (0.989049 * 0.5 * (TMath::Erf((pt - 31.9836) / 2. / 1.23871 / sqrt(pt)) + 1.))
//            + 3143. * (0.988047 * 0.5 * (TMath::Erf((pt - 31.6975) / 2. / 1.25372 / sqrt(pt)) + 1.)))
//            / (808.411 + 4428.0 + 1783.003 + 5109.155 + 4131 + 3143))+
//            (fabs(eta) > 2.1)*
//            ((808.411 * (0.969591 * 0.5 * (TMath::Erf((pt - 36.8179) / 2. / 0.904254 / sqrt(pt)) + 1.))
//            + 4428.0 * (0.975932 * 0.5 * (TMath::Erf((pt - 37.2121) / 2. / 0.961693 / sqrt(pt)) + 1.))
//            + 1783.003 * (0.990305 * 0.5 * (TMath::Erf((pt - 36.3096) / 2. / 0.979524 / sqrt(pt)) + 1.))
//            + 5109.155 * (0.971612 * 0.5 * (TMath::Erf((pt - 36.2294) / 2. / 0.871726 / sqrt(pt)) + 1.))
//            + 4131. * (0.977958 * 0.5 * (TMath::Erf((pt - 37.131) / 2. / 0.987523 / sqrt(pt)) + 1.))
//            + 3143. * (0.968457 * 0.5 * (TMath::Erf((pt - 36.3159) / 2. / 0.895031 / sqrt(pt)) + 1.)))
//            / (808.411 + 4428.0 + 1783.003 + 5109.155 + 4131 + 3143));
//}
//
////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
////&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//
//float getCorrTriggerLep(std::string channel, std::string type, myobject const& a) {
//
////    if (type == "mc12" || type == "embedmc12") {
//    if (type == "mc12" || type == "embedmc12") {
//
//        if (channel == "eltau") {
//            return (Eff_ETauTrg_Ele_Data_2012(a) / Eff_ETauTrg_Ele_MC_2012(a));
//        }
//        if (channel == "mutau") {
//            return (Eff_MuTauTrg_Mu_Data_2012(a) / Eff_MuTauTrg_Mu_MC_2012(a));
//        }
//    } else if (type == "data11" || type == "data12")
//        return 1;
//    return 1.0;
//
//}
//
//float getCorrTriggerTau(std::string channel, std::string type, myobject const& b) {
//
//    if (type == "mc12" || type == "embedmc12") {
//        if (channel == "eltau") {
//            return ((Eff_ETauTrg_Tau_Data_2012(b) / Eff_ETauTrg_Tau_MC_2012(b)))*(correctionHighPtTail_Data(b) / correctionHighPtTail_MC(b));
//        }
//        if (channel == "mutau") {
//            return ((Eff_MuTauTrg_Tau_Data_2012(b) / Eff_MuTauTrg_Tau_MC_2012(b)))*(correctionHighPtTail_Data(b) / correctionHighPtTail_MC(b));
//        }
//
//    } else
//        return 1;
//    return 1.0;
//}
//
//
//float getCorrIDIsoLep(std::string channel, std::string type, myobject const& a) {
//
//    if (type == "mc12" || type == "embedmc12"|| type == "embeddata12") {
//
//        if (channel == "eltau") {
//            return Cor74X_IDIso_ETau_Ele_2012(a);
//        }
//        if (channel == "mutau") {
//            return Cor74X_IDIso_MuTau_Muon_2012(a);
//        }
//    } else if (type == "data11" || type == "data12")
//        return 1;
//    return 1.0;
//
//}
//
//float getCorrTriggerLepTau(std::string channel, std::string type, myobject const& a, myobject const& b) {
//
//    return getCorrTriggerLep(channel, type, a) * getCorrTriggerTau(channel, type, b);
//}
//float getCorrIDLep(std::string channel, std::string type, myobject const& a) {
//
//    if (type == "mc12" || type == "embedmc12"|| type == "embeddata12") {
//
//        if (channel == "eltau") {
//            return Cor74X_ID_ETau_Ele_2012(a);
//        }
//        if (channel == "mutau") {
//            return Cor74X_ID_MuTau_Muon_2012(a);
//        }
//    } else if (type == "data11" || type == "data12")
//        return 1;
//    return 1.0;
//
//}
//
//float getCorrIsoLep(std::string channel, std::string type, myobject const& a) {
//
//    if (type == "mc12" || type == "embedmc12" || type == "embeddata12") {
//
//        if (channel == "eltau") {
//            return Cor74X_Iso_ETau_Ele_2012(a);
//        }
//        if (channel == "mutau") {
//            return Cor74X_Iso_MuTau_Muon_2012(a);
//        }
//    } else if (type == "data11" || type == "data12")
//        return 1;
//    return 1.0;
//
//}


int ptBIN=0;
int etaBIN=0;





//x min    x avg    x max     ratio    -err / +err
//------   ------   ------     -----  ------/------
//-2.400   -2.231   -2.100     98.79  - 0.27/+ 0.27
//-2.100   -1.828   -1.600     99.39  - 0.05/+ 0.04
//-1.600   -1.346   -1.100     99.70  - 0.03/+ 0.03
//-1.100   -0.843   -0.600     99.54  - 0.02/+ 0.02
//-0.600   -0.298    0.000     99.37  - 0.02/+ 0.02
//0.000    0.299    0.600     99.59  - 0.01/+ 0.01
//0.600    0.843    1.100     99.76  - 0.02/+ 0.02
//1.100    1.348    1.600     99.61  - 0.03/+ 0.03
//1.600    1.828    2.100     99.30  - 0.04/+ 0.04
//2.100    2.234    2.400     98.19  - 0.22/+ 0.21
/////////////////////////////////////////////////////
//  Muon TRK Correction 80X
////////////////////////////////////////////////////////////
float Cor80X_TRK_Mu(float eta ) {
    
    if (eta >= -2.4 && eta < -2.1 ) return 0.9879;
    else if (eta >= -2.1 && eta < -1.6 ) return 0.9939;
    else if (eta >= -1.6 && eta < -1.1) return 0.9970;
    else if (eta >= -1.1 && eta < -0.6) return 0.9954;
    else if (eta >= -0.6 && eta < 0 ) return 0.9937;
    else if (eta >= 0 && eta < 0.6 ) return 0.9959;
    else if (eta >= 0.6 && eta < 1.1 ) return 0.9976;
    else if (eta >= 1.1 && eta < 1.6 ) return 0.9961;
    else if (eta >= 1.6 && eta < 2.1 ) return 0.9930;
    else if (eta >= 2.1 && eta < 2.4 ) return 0.9819;
    else return 1;
    
    
    
}

/////////////////////////////////////////////////////
//  Muon Id Correction 74X
////////////////////////////////////////////////////////////
float Cor80X_ID_Mu(float pt, float eta , TH2F * HistoId) {
    
    if (pt >= 20 && pt < 25 ) ptBIN=1;
    if (pt >= 25 && pt < 30 ) ptBIN=2;
    if (pt >= 30 && pt < 40 ) ptBIN=3;
    if (pt >= 40 && pt < 50 ) ptBIN=4;
    if (pt >= 50 && pt < 60 ) ptBIN=5;
    if (pt >= 60 && pt < 100) ptBIN=6;
    if (pt >= 100 ) ptBIN=7;
    
    if (fabs(eta) <= 0.9) etaBIN=1;
    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
    if (2.1 <= fabs(eta) && fabs(eta) < 2.4) etaBIN=4;
    
    
    //    cout<< "--->Muon Id    pt= "<<pt<<  "   eta" <<eta<< "  SF="<<HistoId->GetBinContent(ptBIN,etaBIN)<<"\n";
    return HistoId->GetBinContent(ptBIN,etaBIN);
}

//float Cor74X_ID_Mu(float pt, float eta , TH2F * HistoId) {
//
//    if (pt >= 20 && pt < 25 ) ptBIN=1;
//    if (pt >= 25 && pt < 30 ) ptBIN=2;
//    if (pt >= 30 && pt < 40 ) ptBIN=3;
//    if (pt >= 40 && pt < 50 ) ptBIN=4;
//    if (pt >= 50 && pt < 60 ) ptBIN=5;
//    if (pt >= 60 && pt < 120000) ptBIN=6;
//
//    if (fabs(eta) <= 0.9) etaBIN=1;
//    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
//    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
//    if (2.1 <= fabs(eta) && fabs(eta) < 2.4) etaBIN=4;
//
//    return HistoId->GetBinContent(ptBIN,etaBIN);
//}
////////////////////////////////////////////////////////////
//  Muon Iso Correction 74X
////////////////////////////////////////////////////////////
//float Cor74X_Iso_Mu(float pt,float eta, TH2F* HistoIso){
//
//    if (pt >= 20 && pt < 25 ) ptBIN=1;
//    if (pt >= 25 && pt < 30 ) ptBIN=2;
//    if (pt >= 30 && pt < 40 ) ptBIN=3;
//    if (pt >= 40 && pt < 50 ) ptBIN=4;
//    if (pt >= 50 && pt < 60 ) ptBIN=5;
//    if (pt >= 60 && pt < 120000) ptBIN=6;
//
//    if (fabs(eta) <= 0.9) etaBIN=1;
//    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
//    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
//    if (2.1 <= fabs(eta) && fabs(eta) < 2.4) etaBIN=4;
//
//    return HistoIso->GetBinContent(ptBIN,etaBIN);;
//}

float Cor80X_Iso_Mu(float pt,float eta, TH2F* HistoIso){
    
    if (pt >= 20 && pt < 25 ) ptBIN=1;
    if (pt >= 25 && pt < 30 ) ptBIN=2;
    if (pt >= 30 && pt < 40 ) ptBIN=3;
    if (pt >= 40 && pt < 50 ) ptBIN=4;
    if (pt >= 50 && pt < 60 ) ptBIN=5;
    if (pt >= 60 && pt < 100) ptBIN=6;
    if (pt >= 100 ) ptBIN=7;
    
    if (fabs(eta) <= 0.9) etaBIN=1;
    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
    if (2.1 <= fabs(eta) && fabs(eta) < 2.4) etaBIN=4;
    
    //    cout<< "--->Muon Iso    pt= "<<pt<<  "   eta" <<eta<< "  SF="<<HistoIso->GetBinContent(ptBIN,etaBIN)<<"\n";
    return HistoIso->GetBinContent(ptBIN,etaBIN);
}

///////////////////////////////////////////////
//  Muon Trigger Correction 74X
////////////////////////////////////////////////////////////
float Cor80X_Trigger_Mu(float pt,float eta, TH2F* HistoTrg ){
    
    if (pt >= 45 && pt < 50 ) ptBIN=1;
    if (pt >= 50 && pt < 60 ) ptBIN=2;
    if (pt >= 60 && pt < 120) ptBIN=3;
    if (pt >= 120 && pt < 200) ptBIN=4;
    if (pt >= 200) ptBIN=5;
    
    if (fabs(eta) <= 0.9) etaBIN=1;
    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
    
    //    cout<< "--->Trigger    pt= "<<pt<<  "   eta" <<eta<< "  SF="<<HistoTrg->GetBinContent(ptBIN,etaBIN)<<"\n";
    return HistoTrg->GetBinContent(ptBIN,etaBIN);
    
}

////////////////////////////////////////////////////////////
vector<float> _getMuTrgWeight(float pt,float eta){
    
    
    //barrel
    //    1  p0           9.17305e-01   4.63004e-03   1.83763e-04  -1.39161e-04
    //    2  p1          -5.00202e-05   4.91184e-05   1.20000e-05  -1.31193e-02
    //Transition
    //    1  p0           9.17394e-01   1.01338e-02   1.29242e-04   5.58450e-05
    //    2  p1          -3.42661e-04   1.08333e-04   1.20000e-05   5.22137e-03
    //EndCap
    //    1  p0           9.36539e-01   8.43010e-03   1.20902e-04  -1.10272e-04
    //    2  p1          -1.11611e-03   9.05589e-05   1.20000e-05  -1.02555e-02
    
    
    vector<float> FitPar;
    FitPar.clear();
    
    
    if (fabs(eta) <= 0.9) etaBIN=1;
    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
    
    if (etaBIN==1){
        FitPar.push_back(9.17305e-01);
        FitPar.push_back(-5.00202e-05);
    }
    else if (etaBIN==2){
        FitPar.push_back(9.17394e-01);
        FitPar.push_back(-3.42661e-04);
    }
    else if (etaBIN==3){
        FitPar.push_back(9.36539e-01);
        FitPar.push_back(-1.11611e-03);
    }
    else {
        FitPar.push_back(9.36539e-01);
        FitPar.push_back(-1.11611e-03);
    }
    
    return FitPar;
}

    //New
//    EXT PARAMETER                                   STEP         FIRST
//    NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE
//    1  p0           9.22073e-01   3.72714e-03   1.86850e-04  -1.54306e-04
//    2  p1          -1.02098e-04   3.88883e-05   1.20000e-05  -1.47852e-02
//
//    EXT PARAMETER                                   STEP         FIRST
//    NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE
//    1  p0           9.23993e-01   8.03439e-03   1.85149e-04  -2.18784e-04
//    2  p1          -4.14952e-04   8.46039e-05   1.20000e-05  -2.07779e-02
//
//    
//    NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE
//    1  p0           9.50527e-01   6.90139e-03   1.83512e-04   1.05129e-04
//    2  p1          -1.26964e-03   7.33305e-05   1.20000e-05   9.89566e-03

    
//    vector<float> FitPar;
//    FitPar.clear();
//    
//    
//    if (fabs(eta) <= 0.9) etaBIN=1;
//    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
//    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
//    
//    if (etaBIN==1){
//        FitPar.push_back(9.22073e-01);
//        FitPar.push_back(-1.02098e-04);
//    }
//    else if (etaBIN==2){
//        FitPar.push_back(9.23993e-01);
//        FitPar.push_back(-4.14952e-04);
//    }
//    else if (etaBIN==3){
//        FitPar.push_back(9.50527e-01);
//        FitPar.push_back(-1.26964e-03);
//    }
//    else {
//        FitPar.push_back(9.50527e-01);
//        FitPar.push_back(-1.26964e-03);
//    }
//    
//    return FitPar;
//}


////////////////////////////////////////////////////////////


float Cor80X_Trigger_Mu_FIT(float pt,float eta, TH2F* HistoTrg ){
    
    if (pt >= 45 && pt < 50 ) ptBIN=1;
    if (pt >= 50 && pt < 60 ) ptBIN=2;
    if (pt >= 60 && pt < 120) ptBIN=3;
    if (pt >= 120 && pt < 200) ptBIN=4;
    if (pt >= 200) ptBIN=5;
    
    if (fabs(eta) <= 0.9) etaBIN=1;
    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
    
    
    float Weight= HistoTrg->GetBinContent(ptBIN,etaBIN);

    
    
    if (pt > 60){
//        cout<<" pt and eta= "<<pt << "  "<<fabs(eta)<<" "<< Weight<<"\t";
        vector<float>   Weight_vec=_getMuTrgWeight(pt,eta);
        Weight=Weight_vec[0] + Weight_vec[1]*pt;
//        cout<< Weight<<"\n";
    }
    
    return Weight;
    
}

//float Cor74X_Trigger_Mu(float pt,float eta, TH2F* HistoTrg ){
    //
    //    if (pt >= 45 && pt < 50 ) ptBIN=1;
    //    if (pt >= 50 && pt < 60 ) ptBIN=2;
    //    if (pt >= 60 && pt < 120000) ptBIN=3;
    //
    //    if (fabs(eta) <= 0.9) etaBIN=1;
    //    if (0.9 <= fabs(eta) && fabs(eta) < 1.2) etaBIN=2;
    //    if (1.2 <= fabs(eta) && fabs(eta) < 2.1) etaBIN=3;
    //
    //    //    cout<< "pt= "<<pt<<  "   eta" <<eta<< "  SF="<<HistoTrg->GetBinContent(ptBIN,etaBIN)<<"\n";
    //    return HistoTrg->GetBinContent(ptBIN,etaBIN);
    //
    //
    //}
    //////////////////////////////////////////////////////////////
    //  Electron Id/Iso Correction 74X  from HTT group
    ////////////////////////////////////////////////////////////
    
    
    //float Cor74X_IDIso_Ele(float pt, float eta,  TH2F * HistoEleSF0p5, TH2F * HistoEleSF5 ){
    float Cor80X_IDIso_Ele(float pt, float eta,  TH2F * HistoEleSF){
        
        if (pt >= 10 && pt < 20 ) ptBIN=1;
        if (pt >= 20 && pt < 30 ) ptBIN=2;
        if (pt >= 30 && pt < 40) ptBIN=3;
        if (pt >= 40 && pt < 50) ptBIN=4;
        if (pt >= 50 ) ptBIN=5;
        
        if (eta >= -2.5 && eta < -2 ) etaBIN=1;
        if (eta >= -2 && eta < -1.566 ) etaBIN=2;
        if (eta >= -1.566 && eta < -1.444) etaBIN=3;
        if (eta >= -1.444 && eta < -0.800) etaBIN=4;
        if (eta >= -0.800 && eta < 0 ) etaBIN=5;
        if (eta >= 0 && eta < 0.800 ) etaBIN=6;
        if (eta >= 0.800 && eta < 1.444 ) etaBIN=7;
        if (eta >= 1.444 && eta < 1.566 ) etaBIN=8;
        if (eta >= 1.566 && eta < 2 ) etaBIN=9;
        if (eta >= 2 && eta < 2.5 ) etaBIN=10;
        
        //    float SF_0p5= HistoEleSF0p5->GetBinContent(etaBIN, ptBIN);
        //    float SF_5= HistoEleSF5->GetBinContent(etaBIN, ptBIN);
        //    float FinalSF= 0.05 * SF_0p5  + 0.95 * SF_5;   //approximation of 10/fb data
        
        //    cout << pt << "  " << eta << " "<<SF_0p5<<"  "<<SF_5 << "  "<< FinalSF <<"\n";
        //    cout<< "--->Electron    pt= "<<pt<<  "   eta" <<eta<< "  SF="<<HistoEleSF->GetBinContent(etaBIN, ptBIN)<<"\n";
        return HistoEleSF->GetBinContent(etaBIN, ptBIN);
        
        
        
        
    }
    float Cor80X_Trg_Ele(float pt, float eta){
        
        
        
        if (pt >= 50 && pt < 55){
            if (eta >= -2.5 && eta < -2 ) return   .729;
            if (eta >= -2 && eta < -1.566 ) return   .752;
            if (eta >= -1.566 && eta < -1.444) return   .684;
            if (eta >= -1.444 && eta < -0.800) return   .81;
            if (eta >= -0.800 && eta < 0 ) return  .833 ;
            if (eta >= 0 && eta < 0.800 ) return   .827;
            if (eta >= 0.800 && eta < 1.444 ) return   .825;
            if (eta >= 1.444 && eta < 1.566 ) return   .627;
            if (eta >= 1.566 && eta < 2 ) return   .755;
            if (eta >= 2 && eta < 2.5 ) return   .746;
        }
        else if (pt >= 55 && pt < 70){
            if (eta >= -2.5 && eta < -2 ) return  .812 ;
            if (eta >= -2 && eta < -1.566 ) return   .814;
            if (eta >= -1.566 && eta < -1.444) return  .781 ;
            if (eta >= -1.444 && eta < -0.800) return   .802;
            if (eta >= -0.800 && eta < 0 ) return   .869;
            if (eta >= 0 && eta < 0.800 ) return   .862;
            if (eta >= 0.800 && eta < 1.444 ) return   .879;
            if (eta >= 1.444 && eta < 1.566 ) return   .642;
            if (eta >= 1.566 && eta < 2 ) return   .843;
            if (eta >= 2 && eta < 2.5 ) return   .845;
        }
        else if (pt >= 70 && pt < 100){
            if (eta >= -2.5 && eta < -2 ) return   .788;
            if (eta >= -2 && eta < -1.566 ) return   .809;
            if (eta >= -1.566 && eta < -1.444) return   .833;
            if (eta >= -1.444 && eta < -0.800) return   .888;
            if (eta >= -0.800 && eta < 0 ) return   .883;
            if (eta >= 0 && eta < 0.800 ) return  .882 ;
            if (eta >= 0.800 && eta < 1.444 ) return   .884;
            if (eta >= 1.444 && eta < 1.566 ) return  .808 ;
            if (eta >= 1.566 && eta < 2 ) return   .833;
            if (eta >= 2 && eta < 2.5 ) return   .853;
        }
        else if (pt >= 100 && pt < 120){
            if (eta >= -2.5 && eta < -2 ) return  .919 ;
            if (eta >= -2 && eta < -1.566 ) return  .871 ;
            if (eta >= -1.566 && eta < -1.444) return   .894;
            if (eta >= -1.444 && eta < -0.800) return   .908;
            if (eta >= -0.800 && eta < 0 ) return  .902 ;
            if (eta >= 0 && eta < 0.800 ) return  .924 ;
            if (eta >= 0.800 && eta < 1.444 ) return  .927 ;
            if (eta >= 1.444 && eta < 1.566 ) return  .728 ;
            if (eta >= 1.566 && eta < 2 ) return  .87 ;
            if (eta >= 2 && eta < 2.5 ) return  .867 ;
        }
        else if (pt >= 120 && pt < 180){
            if (eta >= -2.5 && eta < -2 ) return  .955 ;
            if (eta >= -2 && eta < -1.566 ) return   .986;
            if (eta >= -1.566 && eta < -1.444) return  .887 ;
            if (eta >= -1.444 && eta < -0.800) return  .924 ;
            if (eta >= -0.800 && eta < 0 ) return  .941 ;
            if (eta >= 0 && eta < 0.800 ) return   .934;
            if (eta >= 0.800 && eta < 1.444 ) return  .956 ;
            if (eta >= 1.444 && eta < 1.566 ) return  .81 ;
            if (eta >= 1.566 && eta < 2 ) return  .977 ;
            if (eta >= 2 && eta < 2.5 ) return  .948 ;
        }
        else if (pt >= 180 && pt < 250){
            if (eta >= -2.5 && eta < -2 ) return  1 ;
            if (eta >= -2 && eta < -1.566 ) return  .984 ;
            if (eta >= -1.566 && eta < -1.444) return  .918 ;
            if (eta >= -1.444 && eta < -0.800) return  .934 ;
            if (eta >= -0.800 && eta < 0 ) return   .981;
            if (eta >= 0 && eta < 0.800 ) return   .937;
            if (eta >= 0.800 && eta < 1.444 ) return  .931 ;
            if (eta >= 1.444 && eta < 1.566 ) return   .939;
            if (eta >= 1.566 && eta < 2 ) return   .968;
            if (eta >= 2 && eta < 2.5 ) return  .954 ;
        }
        else if (pt >= 250 ){
            if (eta >= -2.5 && eta < -2 ) return  1 ;
            if (eta >= -2 && eta < -1.566 ) return  1 ;
            if (eta >= -1.566 && eta < -1.444) return 1  ;
            if (eta >= -1.444 && eta < -0.800) return  .927 ;
            if (eta >= -0.800 && eta < 0 ) return  .953 ;
            if (eta >= 0 && eta < 0.800 ) return   .959;
            if (eta >= 0.800 && eta < 1.444 ) return  .972 ;
            if (eta >= 1.444 && eta < 1.566 ) return  1 ;
            if (eta >= 1.566 && eta < 2 ) return  1 ;
            if (eta >= 2 && eta < 2.5 ) return   1;
        }
        return 1;
        
    }
    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    
    float getCorrFactorMuon74X(bool isData, float pt, float eta, TH2F * HistoId, TH2F * HistoIso,TH2F * HistoTrg) {
        
        if (isData)
            return 1;
        else{
            
            //        cout << Cor74X_ID_Mu(pt,eta,HistoId) << "  "<< Cor74X_Iso_Mu(pt,eta,HistoIso) << "  "<< Cor74X_Trigger_Mu(pt,eta,HistoTrg) << "\n";
            //        return (Cor74X_ID_Mu(pt,eta,HistoId) * Cor74X_Iso_Mu(pt,eta,HistoIso) * Cor74X_Trigger_Mu(pt,eta,HistoTrg) );
            //        return (Cor74X_ID_Mu(pt,eta,HistoId) * Cor74X_Iso_Mu(pt,eta,HistoIso) * Cor74X_Trigger_Mu(pt,eta,HistoTrg) * Cor74X_TRK_Mu(eta)); //TMP for 80X
//            return (Cor80X_ID_Mu(pt,eta,HistoId) * Cor80X_Iso_Mu(pt,eta,HistoIso) * Cor80X_Trigger_Mu(pt,eta,HistoTrg) * Cor80X_TRK_Mu(eta)); //TMP for 80X
            
   
//            return (Cor80X_ID_Mu(pt,eta,HistoId) * Cor80X_Iso_Mu(pt,eta,HistoIso) * Cor80X_Trigger_Mu(pt,eta,HistoTrg) * Cor80X_Trigger_Mu_FIT(pt,eta,HistoTrg));
            
//            return (Cor80X_ID_Mu(pt,eta,HistoId) * Cor80X_Iso_Mu(pt,eta,HistoIso) * Cor80X_TRK_Mu(eta) * Cor80X_Trigger_Mu_FIT(pt,eta,HistoTrg));
            return (Cor80X_ID_Mu(pt,eta,HistoId) * Cor80X_Iso_Mu(pt,eta,HistoIso) * Cor80X_TRK_Mu(eta) * Cor80X_Trigger_Mu(pt,eta,HistoTrg));
        }
        
    }
    
    float getCorrFactorElectron74X(bool isData, float pt, float eta,    TH2F * HistoEleSF ){
        if (isData)
            return 1;
        else
            return Cor80X_IDIso_Ele(pt,eta,HistoEleSF)*Cor80X_Trg_Ele(pt,eta);
    }
    
    float getCorrFactorElectron74X_IDOnly(bool isData, float pt, float eta,    TH2F * HistoEleSF ){
        if (isData)
            return 1;
        else
            return Cor80X_IDIso_Ele(pt,eta,HistoEleSF);
    }
    
    
    
    
    
