#####  This script is to make the nice plot (in pdf/png) for the Ersatz study of the W+Jet background shape and normalization validation.

#!/usr/bin/env python
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


BinningLQ = array.array("d",[0,50,100,150,200,250,300,350,400,450,500,550,600,650,700,800,900,1000,1200,1400,2000])
BinningM = array.array("d",[60,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,110,120])


from Step5_TT_W_ScaleFactor import *




RB_=40
def add_lumi():
    lowX=0.69
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.06)
    lumi.SetTextFont (   42 )
    lumi.AddText("35.9 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.21
    lowY=0.70
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.08)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.21
    lowY=0.63
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.06)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend():
        output = ROOT.TLegend(0.65, 0.4, 0.92, 0.82, "", "brNDC")
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        output.SetFillStyle(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output


def MakePlot(FileName,categoriy,HistName,Xaxis,Info,RB_,channel,yMin,isLOG,scale,MTLegend,Binning):
    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)

    c=ROOT.TCanvas("canvas","",0,0,600,600)
    c.cd()

    file=ROOT.TFile(FileName,"r")

    adapt=ROOT.gROOT.GetColor(12)
    new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1


    Data_=file.Get(categoriy).Get("data_obs")
    Data= Data_.Rebin(len(Binning)-1,"",Binning)
    
#    QCD=file.Get(categoriy).Get("QCD")
#    QCD.Rebin(RB_)


    W_=file.Get(categoriy).Get("W")
    W= W_.Rebin(len(Binning)-1,"",Binning)
#    W.Rebin(RB_)
#    if ttbarCR=="" :  W.Scale(SF_W_SingleLep())
#    if ttbarCR=="_ttbarCRSingleLep" :  W.Scale(SF_W_SingleLep())
#    if ttbarCR=="_ttbarCRDiLep" :  W.Scale(SF_W_DiLep())
    W.Scale(1)
    

    TT_=file.Get(categoriy).Get("TT")
    TT= TT_.Rebin(len(Binning)-1,"",Binning)
#    TT.Rebin(RB_)
#    TT.Scale(1)
    TT.Scale(SF_TT_SingleLep())
#    if ttbarCR=="_ttbarCRSingleLep" :  TT.Scale(SF_TT_SingleLep())
#    if ttbarCR=="_ttbarCRDiLep" :  TT.Scale(SF_TT_DiLep())

    SingleT_=file.Get(categoriy).Get("SingleTop")
    SingleT= SingleT_.Rebin(len(Binning)-1,"",Binning)
#    SingleT.Rebin(RB_)

    VV_=file.Get(categoriy).Get("VV")
    VV= VV_.Rebin(len(Binning)-1,"",Binning)
#    VV.Rebin(RB_)


    DYS_=file.Get(categoriy).Get("ZTT")
    DYS= DYS_.Rebin(len(Binning)-1,"",Binning)
#    DYS.Rebin(RB_)

    Data.GetXaxis().SetTitle("")
    Data.GetXaxis().SetTitleSize(0)
    Data.GetXaxis().SetNdivisions(505)
    Data.GetYaxis().SetLabelFont(42)
    Data.GetYaxis().SetLabelOffset(0.01)
    Data.GetYaxis().SetLabelSize(0.06)
    Data.GetYaxis().SetTitleSize(0.075)
    Data.GetYaxis().SetTitleOffset(1.04)
    Data.SetTitle("")
    Data.GetYaxis().SetTitle("Events")


#    Signal=file.Get(categoriy).Get("Codex_1200")
#    Signal.Scale(1.50E-03*.5)
#    Signal.Rebin(RB_)
#    Signal.SetLineStyle(11)
#    Signal.SetLineWidth(3)
#    Signal.SetLineColor(4)
#    Signal.SetMarkerColor(4)


#    QCD.SetFillColor(ROOT.TColor.GetColor(408, 106, 154))
    W.SetFillColor(ROOT.TColor.GetColor(200, 2, 285))
    TT.SetFillColor(ROOT.TColor.GetColor(208, 376, 124))
    SingleT.SetFillColor(ROOT.TColor.GetColor(150, 132, 232))
    VV.SetFillColor(ROOT.TColor.GetColor(200, 282, 232))
    DYS.SetFillColor(ROOT.TColor.GetColor(108, 226, 354))
    
    
    
#    ######  Add OverFlow Bin
#    if not FileName.find("_tmass_MuMet") > 0:
#        QCD.SetBinContent(QCD.GetNbinsX(),QCD.GetBinContent(QCD.GetNbinsX()+1)+QCD.GetBinContent(QCD.GetNbinsX()))
#        W.SetBinContent(W.GetNbinsX(),W.GetBinContent(W.GetNbinsX()+1)+W.GetBinContent(W.GetNbinsX()))
#        TT.SetBinContent(TT.GetNbinsX(),TT.GetBinContent(TT.GetNbinsX()+1)+TT.GetBinContent(TT.GetNbinsX()))
#        SingleT.SetBinContent(SingleT.GetNbinsX(),SingleT.GetBinContent(SingleT.GetNbinsX()+1)+SingleT.GetBinContent(SingleT.GetNbinsX()))
#        VV.SetBinContent(VV.GetNbinsX(),VV.GetBinContent(VV.GetNbinsX()+1)+VV.GetBinContent(VV.GetNbinsX()))
#        DYS.SetBinContent(DYS.GetNbinsX(),DYS.GetBinContent(DYS.GetNbinsX()+1)+DYS.GetBinContent(DYS.GetNbinsX()))
#        Data.SetBinContent(Data.GetNbinsX(),Data.GetBinContent(Data.GetNbinsX()+1)+Data.GetBinContent(Data.GetNbinsX()))







    Data.SetMarkerStyle(20)
    Data.SetMarkerSize(1)
#    QCD.SetLineColor(ROOT.kBlack)
    W.SetLineColor(ROOT.kBlack)
    TT.SetLineColor(ROOT.kBlack)
    DYS.SetLineColor(ROOT.kBlack)
    VV.SetLineColor(ROOT.kBlack)
    SingleT.SetLineColor(ROOT.kBlack)
    Data.SetLineColor(ROOT.kBlack)
    Data.SetLineWidth(2)
    
#    #Making the plot blind
#    if FileName.find("LQMass") > 0 :
#        print "##################################\n", FileName
#        for i in range(Data.GetNbinsX()):
#            if i > 15 : Data.SetBinContent(i+1,0)
#
#    if FileName.find("MET") > 0 :
#        print "##################################\n", FileName
#        for i in range(Data.GetNbinsX()):
#            if i > 9 : Data.SetBinContent(i+1,0)
#
#    if FileName.find("tmass_MuMet") > 0 :
#        print "##################################\n", FileName
#        for i in range(Data.GetNbinsX()):
#                if i > 9 : Data.SetBinContent(i+1,0)




    stack=ROOT.THStack("stack","stack")
#    stack.Add(QCD)
    stack.Add(W)
    stack.Add(VV)
    stack.Add(SingleT)
    stack.Add(TT)
    stack.Add(DYS)
    
    errorBand=DYS.Clone()
#    errorBand.Add(QCD)
    errorBand.Add(TT)
    errorBand.Add(VV)
    errorBand.Add(SingleT)
    
    errorBand.Add(W)
    
    errorBand.SetMarkerSize(0)
    errorBand.SetFillColor(16)
    errorBand.SetFillStyle(3001)
    errorBand.SetLineWidth(1)

    pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
    if isLOG: pad1.SetLogy()
    pad1.Draw()
    pad1.cd()
    pad1.SetFillColor(0)
    pad1.SetBorderMode(0)
    pad1.SetBorderSize(10)
    pad1.SetTickx(1)
    pad1.SetTicky(1)
    pad1.SetLeftMargin(0.18)
    pad1.SetRightMargin(0.05)
    pad1.SetTopMargin(0.122)
    pad1.SetBottomMargin(0.026)
    pad1.SetFrameFillStyle(0)
    pad1.SetFrameLineStyle(0)
    pad1.SetFrameLineWidth(3)
    pad1.SetFrameBorderMode(0)
    pad1.SetFrameBorderSize(10)

    Data.GetXaxis().SetLabelSize(0)
    if isLOG: Data.SetMaximum(Data.GetMaximum()*10000)
    else:  Data.SetMaximum(Data.GetMaximum()*3)
    Data.SetMinimum(yMin)
    Data.Draw("e")
    stack.Draw("histsame")
    errorBand.Draw("e2same")
    Data.Draw("esame")
#    Signal.Draw("histsame")

    legende=make_legend()
    legende.AddEntry(Data,"Observed","elp")
#    legende.AddEntry(Signal,"Codex_1200","l")
    legende.AddEntry(DYS,"DY #rightarrowll ","f")
    legende.AddEntry(TT,"t#bar{t}+jets","f")
    legende.AddEntry(SingleT,"SingleTop","f")
    
    legende.AddEntry(VV,"Diboson","f")
    legende.AddEntry(W,"W","f")
#    legende.AddEntry(QCD,"QCD multijet","f")
    legende.AddEntry(errorBand,"Uncertainty","f")

    legende.Draw()

    l1=add_lumi()
    l1.Draw("same")
    l2=add_CMS()
    l2.Draw("same")
    l3=add_Preliminary()
    l3.Draw("same")

    pad1.RedrawAxis()

    categ  = ROOT.TPaveText(0.22, 0.5+0.013, 0.43, 0.50+0.155, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.05 )
    categ.SetTextColor(    1 )
    categ.SetTextFont (   41 )
    #       if i==1 or i==3: 
    categ.AddText(scale.replace("TotalRoot_DiMu_","").replace("MuJet",""))
    categ.AddText(MTLegend.replace("_",""))
    #       else :
    #        categ.AddText("SS")
    categ.Draw()

    c.cd()
    pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
    pad2.SetTopMargin(0.05);
    pad2.SetBottomMargin(0.35);
    pad2.SetLeftMargin(0.18);
    pad2.SetRightMargin(0.05);
    pad2.SetTickx(1)
    pad2.SetTicky(1)
    pad2.SetFrameLineWidth(3)
    pad2.SetGridx()
    pad2.SetGridy()
    pad2.Draw()
    pad2.cd()
    
    h1=errorBand.Clone()
    h1.SetMaximum(1.8)
    h1.SetMinimum(0.2)
    h1.SetMarkerStyle(20)

    h3=Data.Clone()
    
    h3.Sumw2()
    h1.Sumw2()
    
    
    h1.SetStats(0)
    h3.SetStats(0)
    h1.SetTitle("")
    
    h1.Divide(errorBand)
    #######  set the bin errors to zero befive divinig data to that
    errorBandZeroErr=errorBand.Clone()
    for ibin in range(errorBandZeroErr.GetXaxis().GetNbins()):
        errorBandZeroErr.SetBinError(ibin+1,0)
    #######
    h3.Divide(errorBandZeroErr)


    h1.GetXaxis().SetTitle(Xaxis)
    h1.GetXaxis().SetLabelSize(0.08)
    h1.GetYaxis().SetLabelSize(0.08)
    h1.GetYaxis().SetTitle("Obs./Exp.")
    h1.GetXaxis().SetNdivisions(505)
    h1.GetYaxis().SetNdivisions(5)
    h1.GetXaxis().SetTitleSize(0.15)
    h1.GetYaxis().SetTitleSize(0.15)
    h1.GetYaxis().SetTitleOffset(0.56)
    h1.GetXaxis().SetTitleOffset(1.04)
    h1.GetXaxis().SetLabelSize(0.11)
    h1.GetYaxis().SetLabelSize(0.11)
    h1.GetXaxis().SetTitleFont(42)
    h1.GetYaxis().SetTitleFont(42)
    
    h1.Draw("e2")
    h3.Draw("E0psame")

    c.cd()
    pad1.Draw()

    ROOT.gPad.RedrawAxis()

    c.Modified()
    c.SaveAs("_plot_DiMu"+scale+FileName.replace('TotalRootForLimit_PreSelection_DiMu_MuJet','').replace('.root','')+str(isLOG)+".pdf")








FileNamesInfo=[
#               ["_tmass_JetMet","M_{T}(jet,MET) (GeV)","",5,1],
#               ["_tmass_LQMet","M_{T}(LQ,MET)  (GeV)","",5,1],
#               ["_LepPt","lepton p_{T} (GeV)","",5,1],
#               ["_LepEta","lepton #eta ","",5,10],
#               ["_JetPt","jet p_{T} (GeV)","",5,1],
#               ["_JetEta","jet #eta ","",5,10],
##               ["_nVtx","# of vertex","",1,10],
##               ["_nVtx_NoPU","# of vertex before PU reweighting","",1,10],
#               ["_MET","MET  (GeV)","",5,1],
               ["_LQMass","M_{LQ}   (GeV)","",10,.1,BinningLQ],
               ["_WMass","M_{#mu^{+}#mu^{-}} shifted to W Mass   (GeV)","",10,.1,BinningM],
               ["_ZMass","M_{#mu^{+}#mu^{-}}   (GeV)","",10,.1,BinningM],
#               ["_tmass_MuMet","M_{T}(#mu,MET) (GeV)","",5,1],
#               ["_dPhi_Jet_Met","#Delta#phi (jet,MET)","",5,1],
#               ["_dPhi_Mu_Jet","#Delta#phi (#mu,jet)","",5,1],
#               ["_dPhi_Mu_Met","#Delta#phi (#mu,MET)","",5,1],
#               ["_dPhi_Mu_Jet","#Delta#phi (#mu,jet)","",5,1],
##               ["_LQEta","#eta_{LQ}","",10,10],
#               ["_NumJet","Jet multiplicity","",1,1],
#               ["_NumBJet","BJet multiplicity","",1,1],
               ]


Isolation=["_Iso"]
MT=["_NoMT","_HighMT","_MT150","_MT200"]
JPT=[ "_HighDPhi"]

logStat=[0]
#logStat=[1]

Scales=["TotalRoot_DiMu_ScaledWZMuJet","TotalRoot_DiMu_NoZScaleMuJet","TotalRoot_DiMu_RealDiMuMuJet"]

for i in range(0,len(FileNamesInfo)):
    
    NormMC=FileNamesInfo[i][0]
    axisName=FileNamesInfo[i][1]
    nothing=FileNamesInfo[i][2]
    Bin=FileNamesInfo[i][3]
    yMin=FileNamesInfo[i][4]
    Binning=FileNamesInfo[i][5]
    
    for iso in Isolation:
        for mt in MT:
            for jpt in JPT:
                for isLOG in logStat:
                    for scale in Scales:
            
                        FileName=scale+NormMC+mt+jpt+iso+".root"
                        Info=NormMC+mt+jpt+iso
                        print "---->", FileName
                        MakePlot(FileName,"MuJet","",axisName,Info,Bin,"",yMin,isLOG,scale,mt,Binning)


