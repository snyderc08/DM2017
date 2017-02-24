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
from ROOT import TF1
from ROOT import TPaveText
from ROOT import TMath
from ctypes import *
import ROOT as r
import array

gROOT.Reset()
import os




ROOT.gROOT.SetBatch(True)
SubRootDir = 'OutFiles_QCD/'
#SubRootDir = 'OutFiles_PreSelectionQCD/'


verbos_ = False



def add_lumi():
    lowX=0.69
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.03)
    lumi.SetTextFont (   42 )
    lumi.AddText("(13 TeV)")
    return lumi

def add_CMS():
    lowX=0.11
    lowY=0.75
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.05)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

lowX=0.11
lowY=0.68
def add_Preliminary():
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.05)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Simulation")
    return lumi

def make_legend():
    output = ROOT.TLegend(0.44,lowY+0.06, 0.88, lowY+0.21, "", "brNDC")
    output.SetLineWidth(0)
    output.SetLineStyle(0)
    output.SetFillStyle(0)
    output.SetBorderSize(0)
    output.SetTextFont(62)
    output.SetTextSize(.045)
    return output

############################################################################################################
def _FileReturn(Name, channel,HistoName):
    if not os.path.exists(SubRootDir):
        os.makedirs(SubRootDir)
    myfile = TFile(SubRootDir + Name + '.root')
    Histo =  myfile.Get(channel+HistoName)
    print "0--------->>>>>>  ",SubRootDir,Name, channel+HistoName
    if not os.path.exists("Extra"):
        os.makedirs("Extra")
    NewFile=TFile("Extra/XXX.root","RECREATE")
    NewFile.WriteObject(Histo,"XXX")
    myfile.Close()
    return NewFile


####################################################
##   Start Making the Datacard Histograms
####################################################
def MakeTheHistogram(channel,NormQCD,ShapeQCD,Binning,doBinning):
        return _FileReturn("QCD", channel, ShapeQCD)
#        ShapeHist=ShapeFile.Get("XXX")
#        if doBinning:    RebinedHist= ShapeHist.Rebin(len(Binning)-1,"",Binning)
#        return RebinedHist

#############################################################################################################
##   Fit Functions
#############################################################################################################
def _FIT_Jet(x, p):
    Land = p[2] * TMath.Landau(x[0], p[3], p[4])
#    Pol0 = p[0]+p[1]*x[0]
    Pol0 = p[0]
    return Land + Pol0
#    return Land
def _FIT_Jet_Function(x, p):
    Land = p[2] * TMath.Landau(x, p[3], p[4])
#    Pol0 = p[0]+p[1]*x
    Pol0 = p[0]
    return Land + Pol0
#    return Land



def _FIT_Lepton( x,  par) :
    return par[0] / (par[0]+ par[1]*math.exp(par[2] * x[0]))
def _FIT_Lepton_Function( x,  par) :
    return par[0] / (par[0]+ par[1]*math.exp(par[2] * x))



FR_vs_LeptonPT=0
if FR_vs_LeptonPT:
    ObjectPT="_LepPt"
    BinningFake = array.array("d",[0,20,30,40,50,60,70,80,90,100,120,150,200,300])
else:
    ObjectPT="_CloseJetLepPt"
#    BinningFake = array.array("d",[0,50,70,90,110,140,170,200,240,280,320,360,400])
    BinningFake = array.array("d",[0,30,40,50,75,90,110,130,150,200,250,300,400,500])

#############################################################################################################
##   Calculating the Fake Rate ---> "Linear Fit, 2 parameters"
#############################################################################################################
Binning = array.array("d",[0,30,50,60,70,85,100,115,130,150,200,250,300,400,500])
def Make_Mu_FakeRate_MC(channelName):
    
    
    
    
    HistoFakeNum=ObjectPT+"_LowMT_RelaxDPhi_Iso"
    HistoFakeDeNum=ObjectPT+"_LowMT_RelaxDPhi_Total"



    
    ShapeNum=MakeTheHistogram(channelName,HistoFakeNum,HistoFakeNum,BinningFake,1)
    HistoNumX=ShapeNum.Get("XXX")
    HistoNum= HistoNumX.Rebin(len(Binning)-1,"",Binning)
    
    ShapeDeNum=MakeTheHistogram(channelName,HistoFakeDeNum,HistoFakeDeNum,BinningFake,1)
    HistoDeNumX=ShapeDeNum.Get("XXX")
    HistoDeNum= HistoDeNumX.Rebin(len(Binning)-1,"",Binning)
    
    print "\n---------------------------------------------------------------------------\n"
    print "overal FR = ", HistoNum.Integral()/ HistoDeNum.Integral(), "\n"
    print "---------------------------------------------------------------------------\n\n"
    HistoNum.Divide(HistoDeNum)
    
    
    
    canv = TCanvas("canv", "histograms", 600, 600)
    #    HistoNum.SetMinimum(0.5)
    #    HistoNum.GetXaxis().SetRangeUser(0,400)
    canv.SetLogy()
#    canv.SetGridx()
    canv.SetGridy()
    HistoNum.SetTitle("")
    if FR_vs_LeptonPT: HistoNum.GetXaxis().SetTitle("#mu p_{T} [GeV]")
    else: HistoNum.GetXaxis().SetTitle("Jet p_{T} [GeV]")
    HistoNum.GetYaxis().SetTitle("#mu Fake Rate  (Tight Iso / Loose Iso)")
    HistoNum.GetYaxis().SetTitleOffset(1.3)
    HistoNum.GetYaxis().SetRangeUser(0.05,2)
    HistoNum.SetStats(0)
    HistoNum.SetMarkerStyle(20)
    
    
    #    ######  Fit parameters for fake rate v.s. Jet Pt
    
    #####  Fit parameters for fake rate v.s. muon Pt
    # number of parameters in the fit
    if FR_vs_LeptonPT:
        nPar = 3
        theFit=TF1("theFit", _FIT_Lepton, 80, 500,nPar)
        theFit.SetParameter(0, .2)
        theFit.SetParLimits(0, 0.1, 0.4)
        theFit.SetParameter(1, 4)
        theFit.SetParameter(2, -.30)
    
    else:
        nPar = 5
        theFit=TF1("theFit",_FIT_Jet,55,500,nPar)
#        theFit.SetParLimits(0,    0,     0.5);
##        theFit.SetParameter(0, 0.03)
##        theFit.SetParameter(1, 0)
#        theFit.SetParameter(2, 0.6)
#        theFit.SetParameter(3, -0.6)
##        theFit.SetParameter(4, 196.6)
#Loose
#        theFit.SetParLimits(0,    0,     0.5);
#        theFit.SetParameter(0, 0.03)
#        theFit.SetParameter(1, 0)
        theFit.SetParameter(2, 0.6)
#        theFit.SetParameter(3, -0.6)
#        theFit.SetParameter(4, 96.6)

    
    
    HistoNum.Fit("theFit", "R0")
    HistoNum.Draw("E1")
    theFit.SetLineWidth(3)
    theFit.SetLineColor(3)
    FitParam=theFit.GetParameters()
    theFit.Draw("SAME")

    legende=make_legend()
    legende.AddEntry(HistoNum,"Jet#rightarrow#mu fake rate","lp")
    legende.AddEntry(theFit,"Fit (Landau+Pol0)","l")
    
    legende.Draw()
    
    l1=add_lumi()
    l1.Draw("same")
    l2=add_CMS()
    l2.Draw("same")
    l3=add_Preliminary()
    l3.Draw("same")


    categ  = ROOT.TPaveText(0.51, 0.45+0.013, 0.93, 0.60+0.155, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.04 )
    categ.SetTextColor(    1 )
    categ.SetTextFont (   41 )
    categ.AddText(channelName+" channel")
#    categ.Draw()


    canv.SaveAs("muFakeRate"+channelName+"_MC.pdf")
    canv.SaveAs("muFakeRate"+channelName+"_MC.root")
    
    
    if FR_vs_LeptonPT:
        return FitParam[0],FitParam[1],FitParam[2]
    else:
        return FitParam[0],FitParam[1],FitParam[2],FitParam[3],FitParam[4]


##########################################    ##########################################    ##########################################
##########################################    ##########################################    ##########################################
##########################################    ##########################################    ##########################################

if __name__ == "__main__":
    FR_FitMaram=Make_Mu_FakeRate_MC("MuJet")
#    FR_FitMaram=Make_Tau_FakeRate("EleTau")



