#! /usr/bin/python

# To change this template, choose Tools | Templates
# and open the template in the editor.
#http://root.cern.ch/viewvc/trunk/tutorials/pyroot/hsimple.py?revision=20881&view=markup
__author__ = "abdollahmohammadi"
__date__ = "$Feb 23, 2013 10:39:33 PM$"

import math
import ROOT
from ROOT import Double
from ROOT import TCanvas
from ROOT import TFile
from ROOT import TH1F
from ROOT import TH2F
from ROOT import TNtuple
from ROOT import TProfile
from ROOT import gBenchmark
from ROOT import gROOT
from ROOT import gRandom
from ROOT import gSystem
from ctypes import *
import ROOT as r
import array

##### Get Jet to Tau FR
from Step1_JetToMuFR_Data import Make_Mu_FakeRate
from Step1_JetToMuFR_Data import *
##### Get Jet to Tau FR

gROOT.Reset()
import os


ROOT.gROOT.SetBatch(True)
#ROOT.gROOT.ProcessLine('.x rootlogon.C')
#SubRootDir = 'OutFiles_PreSelection/'
#SubRootDir = 'OutFiles_PreSelection_BeforeFreeze/'
#SubRootDir = 'OutFiles_PreSelection_100to150/'  # changed October 23rd
#SubRootDir = 'OutFiles_PreSelection_OldKFactor/'
#SubRootDir = 'OutFiles_PreSelection_dPhiOverLapWithJetOnly/'
#SubRootDir = 'OutFiles_PreSelection_OnlydPhiLeadJet/'


verbos_ = True
RB_=1
includeSignal= True

#signal = ['LQ_']
#signalName = ['LQ_']
##mass = [200,250, 300, 350, 400, 450, 500, 550,  600, 650, 700, 750, 800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500]
##TOTMASS = [200,250, 300, 350, 400, 450, 500, 550,  600, 650, 700, 750, 800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500]
#mass = [1000,1100]
#TOTMASS = [1000,1100]
#lenghtSig = len(signal) * len(mass) +1
category = [""]

############################################################################################################
def _FileReturn(Name, channel,cat,HistoName,SubRootDir):

    if not os.path.exists(SubRootDir):
        os.makedirs(SubRootDir)
    myfile = TFile(SubRootDir + Name + '.root')
    if verbos_: print "##### --->>>>>>> File name is ", SubRootDir + Name + '.root'  "   and histo is -->  ", channel+HistoName + cat
    Histo =  myfile.Get(channel+HistoName + cat)
    if not os.path.exists("Extra"):
        os.makedirs("Extra")
    NewFile=TFile("Extra/HISTO.root","RECREATE")
    NewFile.WriteObject(Histo,"HISTO")
    myfile.Close()
    return NewFile


####################################################
##   Start Making the Datacard Histograms
####################################################
def MakeTheHistogram(channel,NormMC,NormQCD,ShapeQCD,NormTTbar,SubRootDir1,SubRootDir2,legend,Norm):
    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
#    OutFile = TFile("TotalRootForLimit_PreSelection_"+channel + NormMC+".root" , 'RECREATE') # Name Of the output file

#    for NameCat in category:
#    print "\nstarting NameCat and channel and HistoName ", NameCat, channel, NormMC

#        tDirectory= OutFile.mkdir(channel + str(NameCat))
#        tDirectory.cd()


        ################################################
        #  Filling W
        ################################################
    print "--------------------------------------------------->     Processing W"
#    tDirectory.cd()

    Name="WJetsToLNu_ALlStitch"

    NormFile1= _FileReturn(Name, channel,"", NormMC,SubRootDir1)
    NormHisto1=NormFile1.Get("HISTO")

    Name="WJetsToLNu_HTONLY"
    NormFile2= _FileReturn(Name, channel,"", NormMC,SubRootDir2)
    NormHisto2=NormFile2.Get("HISTO")

    can=ROOT.TCanvas("canvas","",0,0,600,600)
        
#    if not NormHisto:
#        raise Exception('Not valid %s'%NameOut)
#    else:
    RebinedHist1= NormHisto1.Rebin(10)
    RebinedHist1.SetLineColor(2)
    RebinedHist1.SetLineWidth(3)
    RebinedHist1.SetMaximum(RebinedHist1.GetMaximum()*2)
    RebinedHist1.GetXaxis().SetTitle(Norm)
    RebinedHist1.SetTitle("")
    RebinedHist1.Draw()
    
    
    RebinedHist2= NormHisto2.Rebin(10)
    RebinedHist2.SetLineColor(4)
    RebinedHist2.Draw('same')
    
    categ  = ROOT.TPaveText(0.18, 0.5+0.013, 0.43, 0.70+0.155, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.04 )
    categ.SetTextColor(    1 )
    #    categ.SetTextFont (   41 )
#       if i==1 or i==3:
#    categ.AddText(MTLegend)
#    categ.AddText(ttbarCR)
#    categ.AddText(NormMC.replace('_HighDPhi_Iso',''))
    if legend=='_HighMT': categ.AddText("M_{T}(#mu,j) > 100 GeV")
    if legend=='_MT500': categ.AddText("M_{T}(#mu,j) > 500 GeV")
    #    categ.AddText(MTLegend)
    #       else :
    #        categ.AddText("SS")
    categ.Draw()
    
    
    legende=ROOT.TLegend(0.35, 0.78, 0.82, 0.88, "", "brNDC")
    legende.AddEntry(RebinedHist1,"Stitching All W samples","l")
    legende.AddEntry(RebinedHist2,"Only HTBinned","l")
    
    legende.Draw()
    
    
    can.SaveAs(Name+channel+NormMC+'.pdf')







SubRootDir1 = 'OutFiles_PreSelection/'
SubRootDir2 = 'OutFiles_PreSelection/'



if __name__ == "__main__":
    
    PlotName=["_tmass_MuMet","_tmass_LQMet","_LepEta","_LepPt","_JetPt","_JetEta","_MET","_LQMass","_dPhi_Jet_Met","_dPhi_Mu_Jet","_dPhi_Mu_Met","_NumJet","_NumBJet"]
#    PlotName=["_LQMass"]



#    Isolation=["_Iso", "_AntiIso","_Total"]
    Isolation=["_Iso"]
    
    
#    MT= ["_NoMT","_HighMT","_MT50To150","_MT150to200","_MT200to250","_MT250to300","_MT300to350","_MT200","_MT300","_MT400","_MT500"]
#    MT= ["_NoMT","_HighMT","_MT50To150","_MT400","_MT500"]
    MT= ["_HighMT","_MT500"]

    JPT=[ "_HighDPhi"]

    region= [""]

    for Norm in PlotName:
        for iso in Isolation:
            for mt in MT:
                for jpt in JPT:
                    for reg in region:
                    
                        channel='MuJet'
                        
                        NormMC=Norm+mt+jpt+reg+iso
#                            NormQCD="_CloseJetLepPt"+mt+jpt+reg+"_AntiIso"
                        NormQCD="_LepPt"+mt+jpt+reg+"_AntiIso"
                        ShapeQCD=Norm+mt+jpt+reg+"_AntiIso"
                        NormTTbar=Norm+"_NoTopRW"+mt+jpt+reg+iso
                        
                        MakeTheHistogram(channel,NormMC,NormQCD,ShapeQCD,NormTTbar,SubRootDir1,SubRootDir2,mt,Norm)
