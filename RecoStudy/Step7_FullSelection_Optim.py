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
from Step1_JetToMuFR_Data import _FIT_Jet_Function
#from Step5_TT_W_ScaleFactor import SF_W
from Step5_TT_W_ScaleFactor import SF_TT
##### Get Jet to Tau FR

gROOT.Reset()
import os


ROOT.gROOT.SetBatch(True)
SubRootDir = 'OutFiles_FullSelection/'
verbos_ = False
JetScale = ["JetESDown", "", "JetESUp"]
#JetResol = ["JetERDown", "", "JetERUp"]
JetResol = [""]
METScale = ["METUESDown", "", "METUESUp","METJESDown","METJESUp"]
SystematicTopPtReWeight = ["TopPtRWUp","TopPtRWDown"]
FinalName = ["_mj"]

############################################################################################################
def _FileReturn(Name, channel,cat,HistoName,PostFixJet,PostFixJetRes,PostFixMET):

    if not os.path.exists(SubRootDir):
        os.makedirs(SubRootDir)
    myfile = TFile(SubRootDir + Name + '.root')
    if verbos_: print "##### --->>>>>>> File name is ", SubRootDir + Name + '.root'  "   and histo is -->  ", channel+HistoName + cat+PostFixJet+PostFixJetRes+PostFixMET
    Histo =  myfile.Get(channel+HistoName + cat+PostFixJet+PostFixJetRes+PostFixMET)
    if not os.path.exists("Extra"):
        os.makedirs("Extra")
    NewFile=TFile("Extra/XXX.root","RECREATE")
    NewFile.WriteObject(Histo,"XXX")
    myfile.Close()
    return NewFile


####################################################
##   Start Making the Datacard Histograms
####################################################
def MakeTheHistogram(channel,NormMC,NormQCD,ShapeQCD,chl,Binning,NormMCTT):
    
    
    signal = ['Codex_']
    signalName = ['Codex_']
    mass = [
    '800',
    '900',
    '1000',
    '1100',
    '1200',
    '1300',
    '1400',
    '1500'
    ]


#    TOTMASS = ['800','900','1000','1100','1200','1300','1400','1500']
    category = [""]

    

    JetScaleOut = ["_CMS_scale_jes"+"Down", "", "_CMS_scale_jes"+"Up"]
#    JetResolOut = ["_CMS_scale_jer"+"Down", "", "_CMS_scale_jer"+"Up"]
    JetResolOut = [""]
    METScaleOut = ["_CMS_scale_met_UES"+"Down", "", "_CMS_scale_met_UES"+"Up","_CMS_scale_met_JES"+"Down", "_CMS_scale_met_JES"+"Up"]
    Signal_Unc_TopPTRW = ["_CMS_top_pt_Reweighting"+"Up","_CMS_top_pt_Reweighting"+"Down"]

    myOut = TFile(FinalName[chl]+NormMC+".root" , 'RECREATE') # Name Of the output file


    for NameCat in category:
        print "starting NameCat=%s and channel=%s and HistoName=%s "%(NameCat, channel, NormMC)

        tDirectory= myOut.mkdir(channel + str(NameCat))
        tDirectory.cd()
        for jscale in range(len(JetScale)):
            for jres in range(len(JetResol)):
                for mscale in range(len(METScale)):
                
                    if jscale != 1 and mscale!=1 : continue
                    if jscale != 1 and jres!=0 : continue
                    if jres != 0 and mscale!=1 : continue
                    ################################################
                    #   Filling Signal
                    ################################################
                    for sig in range(len(signal)):
                        for m in range(len(mass)):
                            print "===>", str(mass[m])

                            print "--------------------------------------------------->     Processing  Signal ", signal[sig]+str(mass[m])
                            tDirectory.cd()

                            Name= str(signal[sig])+str(mass[m])
                            NameOut= str(signalName[sig]) +str(mass[m])+str(JetScaleOut[jscale])+str(JetResolOut[jres])+str(METScaleOut[mscale])

                                    
                            NormFile= _FileReturn(Name, channel,NameCat, NormMC, JetScale[jscale] , JetResol[jres] , METScale[mscale])
                            NormHisto=NormFile.Get("XXX")
                    
                            NormHisto.Scale(0.001)
                            RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                            tDirectory.WriteObject(RebinedHist,NameOut)


                    ################################################
                    #  Filling SingleTop
                    ################################################
                    print "--------------------------------------------------->     Processing SingleTop"
                    tDirectory.cd()
                
                    Name= "SingleTop"
                    NameOut= "SingleTop"+str(JetScaleOut[jscale])+str(JetResolOut[jres])+str(METScaleOut[mscale])
                    
                    NormFile= _FileReturn(Name, channel,NameCat, NormMC, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                    NormHisto=NormFile.Get("XXX")
                    
                    RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                    tDirectory.WriteObject(RebinedHist,NameOut)
                    

                    ################################################
                    #  Filling VV
                    ################################################
                    print "--------------------------------------------------->     Processing VV"
                    tDirectory.cd()
                
                    Name= "VV"
                    NameOut= "VV"+str(JetScaleOut[jscale])+str(JetResolOut[jres])+str(METScaleOut[mscale])
                    
                    NormFile= _FileReturn(Name, channel,NameCat, NormMC, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                    NormHisto=NormFile.Get("XXX")
                    
                    RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                    tDirectory.WriteObject(RebinedHist,NameOut)
                    



                    ################################################
                    #  Filling TOP
                    ################################################
                    print "--------------------------------------------------->     Processing TOP"
                    tDirectory.cd()

                    Name= "TTJets"
                    NameOut= "TT"+str(JetScaleOut[jscale])+str(JetResolOut[jres])+str(METScaleOut[mscale])

                    
                    print NormMCTT
                    NormFile= _FileReturn(Name, channel,NameCat, NormMCTT, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                    NormHisto=NormFile.Get("XXX")
                    
                    NormFileShape= _FileReturn(Name, channel,NameCat, NormMC, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                    NormHistoShape=NormFileShape.Get("XXX")
                    
                    
                    
                    
                    NormHistoShape.Scale(NormHisto.Integral()*1.0/NormHistoShape.Integral())
                    NormHistoShape.Scale(1)
                    RebinedHist= NormHistoShape.Rebin(len(Binning)-1,"",Binning)
                    tDirectory.WriteObject(RebinedHist,NameOut)
                    ###############  Systematics on Shape and Norm for  To PT Reweighting ####
                    if jscale==1 and mscale==1 and jres==0:
                        for systTopRW in range(len(SystematicTopPtReWeight)):
                            tDirectory.cd()

                            HistogramNorm = NormMCTT
                            HistogramShape = NormMC.replace("_LQMass","_LQMass"+SystematicTopPtReWeight[systTopRW])
                            
                            NameOut= "TT"+str(Signal_Unc_TopPTRW[systTopRW])

                            NormFile= _FileReturn(Name, channel,NameCat, HistogramNorm, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                            NormHisto=NormFile.Get("XXX")
                            
                            NormFileShape= _FileReturn(Name, channel,NameCat, HistogramShape, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                            NormHistoShape=NormFileShape.Get("XXX")

                            NormHistoShape.Scale(NormHisto.Integral()*1.0/NormHistoShape.Integral())
                            NormHistoShape.Scale(1)
                            RebinedHist= NormHistoShape.Rebin(len(Binning)-1,"",Binning)
                            tDirectory.WriteObject(RebinedHist,NameOut)
                                
        
                    ################################################
                    #  Filling ZTT
                    ################################################
                    print "--------------------------------------------------->     Processing ZTT"
                    tDirectory.cd()

                    Name= "DYJetsToLL"
                    NameOut= "ZTT"+str(JetScaleOut[jscale])+str(JetResolOut[jres])+str(METScaleOut[mscale])
                    
                    NormFile= _FileReturn(Name, channel,NameCat, NormMC, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                    NormHisto=NormFile.Get("XXX")
                    
                    RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                    tDirectory.WriteObject(RebinedHist,NameOut)

                    ################################################
                    #  Filling W
                    ################################################
                    print "--------------------------------------------------->     Processing W"
                    tDirectory.cd()

                    Name="WJetsToLNu"
                    NameOut= "W"+str(JetScaleOut[jscale])+str(JetResolOut[jres])+str(METScaleOut[mscale])

                    NormFileWNoCor= _FileReturn(Name, channel,NameCat, NormMC.replace("","") +"", JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                    NormHistoWNoCor=NormFileWNoCor.Get("XXX")
                    WNoCorNormaliztaion=NormHistoWNoCor.Integral()
                    
                
                    NormFile= _FileReturn(Name, channel,NameCat, NormMC, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                    NormHisto=NormFile.Get("XXX")
                    
                    NormHisto.Scale(WNoCorNormaliztaion/NormHisto.Integral())
                    NormHisto.Scale(1)
                    RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                    tDirectory.WriteObject(RebinedHist,NameOut)



                    ################################################
                    #  Filling QCD
                    ################################################
                    if jscale==1 and mscale==1 and jres==0:
                        print "--------------------------------------------------->     Processing QCD"
                        tDirectory.cd()
                        
                        Name= "SingleTop"
                        SingleTSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        SingleTSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        
                        Name= "VV"
                        VVSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        VVSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )

                        Name= "TTJets"
                        TTSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        TTSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )

                        Name= "DYJetsToLL"
                        ZTTSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        ZTTSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )

                        Name= "WJetsToLNu"
                        WSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        WSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                                    
                        Name="Data"
                        DataSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        DataSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, JetScale[jscale] , JetResol[jres] , METScale[mscale] )



                        SingleTSampleQCDShapeHist=SingleTSampleQCDShape.Get("XXX")
                        VVSampleQCDShapeHist=VVSampleQCDShape.Get("XXX")
                        TTSampleQCDShapeHist=TTSampleQCDShape.Get("XXX")
                        ZTTSampleQCDShapeHist=ZTTSampleQCDShape.Get("XXX")
                        WSampleQCDShapeHist=WSampleQCDShape.Get("XXX")
                        DataSampleQCDShapeHist=DataSampleQCDShape.Get("XXX")

                        print "\n---->   ##########\nlooseQCDShape before=",    DataSampleQCDShapeHist.Integral()
                        
                        if (SingleTSampleQCDShapeHist) : DataSampleQCDShapeHist.Add(SingleTSampleQCDShapeHist, -1)
                        if (VVSampleQCDShapeHist): DataSampleQCDShapeHist.Add(VVSampleQCDShapeHist, -1)
                        DataSampleQCDShapeHist.Add(TTSampleQCDShapeHist, -1)
                        DataSampleQCDShapeHist.Add(ZTTSampleQCDShapeHist, -1)
                        DataSampleQCDShapeHist.Add(WSampleQCDShapeHist, -1)
                        print "\n---->   ##########\nlooseQCDShaoe after=",    DataSampleQCDShapeHist.Integral()


                        SingleTSampleQCDNormHist=SingleTSampleQCDNorm.Get("XXX")
                        VVSampleQCDNormHist=VVSampleQCDNorm.Get("XXX")
                        TTSampleQCDNormHist=TTSampleQCDNorm.Get("XXX")
                        ZTTSampleQCDNormHist=ZTTSampleQCDNorm.Get("XXX")
                        WSampleQCDNormHist=WSampleQCDNorm.Get("XXX")
                        DataSampleQCDNormHist=DataSampleQCDNorm.Get("XXX")
                        

                        if (SingleTSampleQCDNormHist) : DataSampleQCDNormHist.Add(SingleTSampleQCDNormHist, -1)
                        if (VVSampleQCDNormHist): DataSampleQCDNormHist.Add(VVSampleQCDNormHist, -1)
                        DataSampleQCDNormHist.Add(TTSampleQCDNormHist, -1)
                        DataSampleQCDNormHist.Add(ZTTSampleQCDNormHist, -1)
                        DataSampleQCDNormHist.Add(WSampleQCDNormHist, -1)
                        
                        print "\n##########\nlooseQCDNORM after=",    DataSampleQCDNormHist.Integral()
                        FR_FitMaram=Make_Mu_FakeRate(channel)
                        QCDEstimation=0
                        for bin in xrange(50,1000):
                            value=DataSampleQCDNormHist.GetBinContent(bin)
                            if value < 0 : value=0
                            FR= _FIT_Jet_Function(bin+1.5,FR_FitMaram)
                            if FR> 0.9: FR=0.9
                            QCDEstimation += value * FR/(1-FR)
                        print "\n##########\n QCDEstimation",    QCDEstimation

                        NameOut= "QCD"+str(JetScaleOut[jscale])+str(JetResolOut[jres])+str(METScaleOut[mscale])
                        DataSampleQCDShapeHist.Scale(QCDEstimation/DataSampleQCDShapeHist.Integral())  # The shape is from btag-Loose Need get back norm
                        RebinedHist= DataSampleQCDShapeHist.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)

                    ################################################
                    #  Filling Data
                    ################################################
                    if jscale==1 and mscale==1 and jres==0:
                        print "--------------------------------------------------->     Processing Data"
                        tDirectory.cd()

                        Name='Data'
                        NameOut='data_obs'

                        NormFile= _FileReturn(Name, channel,NameCat, NormMC, JetScale[jscale] , JetResol[jres] , METScale[mscale] )
                        NormHisto=NormFile.Get("XXX")
                    
                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)




    myOut.Close()

if __name__ == "__main__":

    Binning = array.array("d",[0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000])


    Met_Cat= ["_MET100","_MET200", "_MET300","_MET400", "_MET500", "_MET600"]
    MT_Cat = ["_MT100", "_MT200","_MT300","_MT400", "_MT500", "_MT600"]

#    Met_Cat= [ "_MET250"]
#    MT_Cat = ["_MT250"]

    for met in Met_Cat:
        for mt in MT_Cat:


            NormMC="_LQMass"+mt+met
            NormMCTT="_LQMass_NoTopRW"+mt+met
            MakeTheHistogram("MuJet",NormMC+"_Iso","_CloseJetLepPt"+mt+met+"_AntiIso",NormMC+"_AntiIso",0,Binning,NormMCTT+"_Iso")
