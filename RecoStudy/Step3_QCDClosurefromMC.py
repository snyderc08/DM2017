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
from Step2_JetToMuFR_MC import Make_Mu_FakeRate_MC
from Step2_JetToMuFR_MC import _FIT_Jet_Function
##### Get Jet to Tau FR

gROOT.Reset()
import os




ROOT.gROOT.SetBatch(True)

SubRootDir = 'OutFiles_QCD/'



verbos_ = False
#OS_SS_Ratio=1.06
OS_SS_Ratio=1.00
RB_=1



category = [""]
channelDirectory = ["MuJet"]

############################################################################################################
def _FileReturn(Name, channel,cat,HistoName):

    if not os.path.exists(SubRootDir):
        os.makedirs(SubRootDir)
    myfile = TFile(SubRootDir + Name + '.root')
    print "##### --->>>>>>> File name is ", SubRootDir + Name + '.root'  "   and histo is -->  ", channel+HistoName + cat
    Histo =  myfile.Get(channel+HistoName + cat)
    if not os.path.exists("Extra"):
        os.makedirs("Extra")
    NewFile=TFile("Extra/XXX.root","RECREATE")
    NewFile.WriteObject(Histo,"XXX")
    myfile.Close()
    print "the return is based on the", channel+HistoName + cat
    return NewFile


####################################################
##   Start Making the Datacard Histograms
####################################################
def MakeTheHistogram(channel,NormMC,NormQCD,ShapeQCD):
    print "\n\n\n\n\n\n ****** ------------------------------>     Starting for ",NormMC, "in Channel= ",channel

    TauScaleOut = [ ""]


    myOut = TFile("TotalQCDClosure_"+channel + NormMC+".root" , 'RECREATE') # Name Of the output file


    icat=-1
    for NameCat in category:
        icat =icat +1
        print "starting NameCat and channel and HistoName ", NameCat, channel, NormMC

        tDirectory= myOut.mkdir(channelDirectory[0] + str(NameCat))
        tDirectory.cd()
        


        ################################################
        #  Filling QCD
        ################################################
        print "--------------------------------------------------->     Processing QCD"
        tDirectory.cd()
        
        
        Name="QCD"
        DataSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD)
        DataSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD)
        DataSampleQCDShapeHist=DataSampleQCDShape.Get("XXX")
        DataSampleQCDNormHist=DataSampleQCDNorm.Get("XXX")
        FR_FitMaram=Make_Mu_FakeRate_MC(channel)
        QCDEstimation=0
            
        for bin in xrange(50,1000):
            value=DataSampleQCDNormHist.GetBinContent(bin)
            if value < 0 : value=0
            FR= _FIT_Jet_Function(bin+1.5,FR_FitMaram)
            print "Bin, value , FR= ",bin, value , FR
            if FR> 0.9: FR=0.9
            QCDEstimation += value * FR/(1-FR)
#            QCDEstimation += value * FR

        print "\n##########\n QCDEstimation",    QCDEstimation
        NameOut= "QCD"
        DataSampleQCDShapeHist.Scale(QCDEstimation/DataSampleQCDShapeHist.Integral())  # The shape is from btag-Loose Need get back norm
        RebinedHist= DataSampleQCDShapeHist.Rebin(RB_)
        tDirectory.WriteObject(RebinedHist,NameOut)




        ################################################
        #  Filling Data
        ################################################
        print "--------------------------------------------------->     Processing Data"
        tDirectory.cd()

        Name='QCD'
        NameOut='qcd_obs'

        NormFile= _FileReturn(Name, channel,NameCat, NormMC)
        NormHisto=NormFile.Get("XXX")
        
        RebinedHist= NormHisto.Rebin(RB_)
        tDirectory.WriteObject(RebinedHist,NameOut)




    myOut.Close()










if __name__ == "__main__":

    PlotName= ["_tmass_MuMet","_tmass_JetMet","_tmass_LQMet","_LepEta","_LepPt","_LepIso","_JetPt","_JetEta","_MET","_LQMass","_dPhi_Jet_Met","_dPhi_Mu_Met"]
    for NormMC in PlotName:
        MakeTheHistogram("MuJet",NormMC+"_HighMT"+"_RelaxDPhi"+"_Iso","_CloseJetLepPt"+"_HighMT"+"_RelaxDPhi"+"_AntiIso",NormMC+"_HighMT"+"_RelaxDPhi"+"_Total")

