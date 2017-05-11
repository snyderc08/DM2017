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
#    print  "----> ", Data.Integral() , Data.GetBinContent(1), Data.GetBinError(1)
#    print  "----> ", W.Integral() , W.GetBinContent(1), W.GetBinError(1)
    print "##########\nW Scale factor for = ", FileName.replace('TotalRootForLimit_PreSelection_MuJet',''), "  is ---> ", WScale, "\t  W purity is", W.Integral(), Data.Integral() , W.Integral()/Data.Integral(),  "\n##########"
    ErrData=Data.GetBinError(1)
    ErrW=W.GetBinError(1)
    TotErr=(Data.GetBinError(1)/Data.GetBinContent(1) + W.GetBinError(1)/W.GetBinContent(1))* WScale
    print "SF= ", WScale, "+- ", TotErr
    ################################################################################################################
    
    return WScale



def SF_TT(Name):
    return returnSF_TT(Name)

#returnSF_W('TotalRootForLimit_PreSelection_MuJet_LQMass_NoMT_HighDPhi_Iso.root',SF_TT())
#returnSF_W('TotalRootForLimit_PreSelection_MuJet_LQMass_LowMT_HighDPhi_Iso.root',SF_TT())
Mass=['_LowMT','_MT100','_MT150','_MT200','_MT250','_MT300']
for mass in Mass:
    NameW='TotalRootForLimit_PreSelection_MuJet_LQMass%s_HighDPhi_Iso.root'%mass
    NameTT='TotalRootForLimit_PreSelection_MuJet_LQMass%s_HighDPhi_ttbarCR_Iso.root'%mass

    returnSF_W(NameW,SF_TT(NameTT))




