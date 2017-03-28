#!/usr/bin/env python
import ROOT
import re
from array import array

def returnSF_TT(FileName):
    
    
    file=ROOT.TFile(FileName,"r")
    categoriy='MuJet'
    Data=file.Get(categoriy).Get("data_obs")
    QCD=file.Get(categoriy).Get("QCD")
    W=file.Get(categoriy).Get("W")
    TT=file.Get(categoriy).Get("TT")
    SingleT=file.Get(categoriy).Get("SingleTop")
    VV=file.Get(categoriy).Get("VV")
    DYS=file.Get(categoriy).Get("ZTT")


    ################################################################################################################
    #   Here we compute the TT scale factor
    #   (Data - allBkg)/TT
    TTScale=(Data.Integral() - SingleT.Integral() - DYS.Integral() - VV.Integral()- W.Integral() - QCD.Integral()) / TT.Integral()
    print "##########\nTT Scale factor for = ", FileName.replace('TotalRootForLimit_PreSelection_MuJet',''), "  is ---> ", TTScale, "\n##########"
    ################################################################################################################

    return TTScale


def returnSF_W(FileName,TTSF):
    
    
    file=ROOT.TFile(FileName,"r")
    categoriy='MuJet'
    Data=file.Get(categoriy).Get("data_obs")
    QCD=file.Get(categoriy).Get("QCD")
    W=file.Get(categoriy).Get("W")
    TT=file.Get(categoriy).Get("TT")
    TT.Scale(TTSF)
    SingleT=file.Get(categoriy).Get("SingleTop")
    VV=file.Get(categoriy).Get("VV")
    DYS=file.Get(categoriy).Get("ZTT")
    
    ################################################################################################################
    #   Here we compute the W scale factor
    #   (Data - allBkg)/W
    WScale=(Data.Integral() - SingleT.Integral() - DYS.Integral() - VV.Integral()- TT.Integral() - QCD.Integral()) / W.Integral()
    print "##########\nTT Scale factor for = ", FileName.replace('TotalRootForLimit_PreSelection_MuJet',''), "  is ---> ", WScale, "\n##########"
    ################################################################################################################
    
    return WScale



def SF_TT():
    return returnSF_TT('TotalRootForLimit_PreSelection_MuJet_LQMass_HighMT_HighDPhi_TotEta_ttbarCR_Iso.root')


def SF_W():
    return returnSF_W('TotalRootForLimit_PreSelection_MuJet_LQMass_HighMT_HighDPhi_Endcap_Iso.root',SF_TT())


SF_TT()
SF_W()

