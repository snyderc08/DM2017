#!/usr/bin/env python
import ROOT
import re
from array import array

RB_=10
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
    lumi.AddText("13 TeV")
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

def add_Preliminary():
    lowX=0.11
    lowY=0.68
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
    output = ROOT.TLegend(0.4, 0.65, 0.88, 0.88, "", "brNDC")
    output.SetLineWidth(0)
    output.SetLineStyle(0)
    output.SetFillStyle(0)
    output.SetBorderSize(0)
    output.SetTextFont(62)
    output.SetTextSize(.04)
    return output


def MakePlot(FileName,categoriy,HistName,Xaxis,Info,RB_,channel):
    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    c=ROOT.TCanvas("canvas","",0,0,600,600)
#    c.cd()

    file=ROOT.TFile(FileName,"r")
    
#    adapt=ROOT.gROOT.GetColor(12)
#    new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
    #    trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)
    
    #    categories=["MuTau_DiJet","MuTau_JetBJet"]
    #    ncat=
    
    print "--->  ", FileName,categoriy,HistName
    Data=file.Get(categoriy).Get("qcd_obs")
    Data.Rebin(RB_)
    QCD=file.Get(categoriy).Get("QCD")
    QCD.Rebin(RB_)
    
    
    Data.GetXaxis().SetTitle("")
    QCD.SetFillColor(ROOT.TColor.GetColor(408, 106, 154))
    
    
    
    
    ######  Add OverFlow Bin
    QCD.SetBinContent(QCD.GetNbinsX(),QCD.GetBinContent(QCD.GetNbinsX()+1)+QCD.GetBinContent(QCD.GetNbinsX()))
    
    Data.SetBinContent(Data.GetNbinsX(),Data.GetBinContent(Data.GetNbinsX()+1)+Data.GetBinContent(Data.GetNbinsX()))
    
    Data.SetMarkerStyle(24)
    Data.SetMarkerSize(1.5)
    Data.SetMarkerColor(2)
    QCD.SetMarkerStyle(20)
    QCD.SetMarkerSize(1.5)
    QCD.SetMarkerColor(9)



    Data.GetXaxis().SetTitle("")
#    Data.GetXaxis().SetTitleSize(0)
    Data.GetXaxis().SetNdivisions(505)
    Data.GetYaxis().SetLabelFont(42)
    Data.GetYaxis().SetLabelOffset(0.01)
    Data.GetYaxis().SetLabelSize(0.03)
    Data.GetYaxis().SetTitleSize(0.04)
    Data.GetYaxis().SetTitleOffset(1.29904)
    Data.SetTitle("")
    Data.GetYaxis().SetTitle("Events / GeV")
    Data.GetXaxis().SetTitle(Xaxis)
    Data.SetMaximum(Data.GetMaximum()*2.5)
    Data.SetMinimum(0)
    Data.Draw("e")
    QCD.Draw("esame")
#    stack.Draw("esame")
#    errorBand.Draw("e2same")
#    Data.Draw("esame")

    legende=make_legend()
    legende.AddEntry(Data,"QCD ","p")
    legende.AddEntry(QCD,"QCD estim. using FR","p")
#    legende.AddEntry(errorBand,"Uncertainty","f")

    legende.Draw()
    
    l1=add_lumi()
    l1.Draw("same")
    l2=add_CMS()
    l2.Draw("same")
    l3=add_Preliminary()
    l3.Draw("same")
    
#    pad1.RedrawAxis()

    categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.43, 0.70+0.155, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.03 )
    categ.SetTextColor(    1 )
    categ.SetTextFont (   41 )
    #       if i==1 or i==3:
    categ.AddText(channel)
    #       else :
    #        categ.AddText("SS")
#    categ.Draw()


    c.SaveAs("_ValidationPlotQCD"+HistName+"_"+categoriy+"_MC.pdf")
#       c.SaveAs("mvis"+categoriy+".png")


#channelDirectory = ["MuTau", "EleTau"]
channelDirectory = ["MuJet"]
#Category = ["_DiJet","_JetBJet"]
#Category = ["_NoBJet"]
Category = [""]






FileNamesInfo=[
                              ["_tmass_MuMet","M_{T}(#mu,MET) (GeV)","",5],
                              ["_tmass_JetMet","M_{T}(jet,MET) (GeV)","",5],
                              ["_tmass_LQMet","M_{T}(LQ,MET) (GeV)","",5],
                              ["_LepEta","#mu #eta ","",5],
                              ["_LepPt","#mu p_{T} (GeV)","",1],
                              ["_JetPt","jet p_{T} (GeV)","",5],
                              ["_JetEta","jet #eta ","",5],
                              ["_LQMass","M_{LQ} (GeV)","",5],
                              ["_dPhi_Jet_Met","d#phi (Jet,Met)","",5],
                              ["_MET","MET  (GeV)","",5],
                              ["_dPhi_Mu_Met","d#phi (#mu,Met)","",5],
               
               
               ]



for ch in channelDirectory:
    for cat in Category:
        for i in range(0,len(FileNamesInfo)):
            
            FileName="TotalQCDClosure_"+ch+FileNamesInfo[i][0]+"_HighMT_RelaxDPhi_Iso.root"
            MakePlot(FileName,ch+cat,FileNamesInfo[i][0],FileNamesInfo[i][1],FileNamesInfo[i][2],FileNamesInfo[i][3],ch+cat)




