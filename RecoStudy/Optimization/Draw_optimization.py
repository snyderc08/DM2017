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


def MakePlot(FileName,HistName,Info):
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
    
#    print "--->  ", FileName,categoriy,HistName
    Data=file.Get(mass)
    
    
    Data.GetXaxis().SetTitle("")
    




    Data.GetXaxis().SetTitle("")
#    Data.GetXaxis().SetTitleSize(0)
    Data.GetXaxis().SetNdivisions(505)
    Data.GetYaxis().SetLabelFont(42)
    Data.GetYaxis().SetLabelOffset(0.01)
    Data.GetYaxis().SetLabelSize(0.03)
    Data.GetYaxis().SetTitleSize(0.04)
    Data.GetYaxis().SetTitleOffset(1.29904)
    Data.SetTitle("")
    Data.GetZaxis().SetTitle("r-value")
#    Data.GetXaxis().SetTitle(Xaxis)
#    Data.SetMaximum(Data.GetMaximum()*2.5)




    Data.GetXaxis().SetBinLabel(1,'MET > 200 GeV')
    Data.GetXaxis().SetBinLabel(2,'MET > 250 GeV')
    Data.GetXaxis().SetBinLabel(3,'MET > 300 GeV')
    Data.GetXaxis().SetBinLabel(4,'MET > 350 GeV')
    Data.GetXaxis().SetBinLabel(5,'MET > 400 GeV')

    Data.GetYaxis().RotateTitle(0)
    Data.GetYaxis().SetBinLabel(1,'MT>0')
    Data.GetYaxis().SetBinLabel(2,'MT>50')
    Data.GetYaxis().SetBinLabel(3,'MT>100')
    
    
    
    Data.GetZaxis().SetNdivisions(505);
    Data.GetZaxis().SetLabelFont(42);
    Data.GetZaxis().SetLabelOffset(0.007);
    Data.GetZaxis().SetLabelSize(0.035);
    Data.GetZaxis().SetTitleSize(0.045);
    Data.GetZaxis().SetTitleFont(42);
#    Data.GetZaxis().SetRangeUser(2, 43);
    Data.Draw("COLZ");
    #    Data.SetMinimum(0)
    Data.Draw("COLZ")
#    stack.Draw("esame")
#    errorBand.Draw("e2same")
#    Data.Draw("esame")

#    legende=make_legend()
#    legende.AddEntry(Data,"QCD ","p")
#    legende.AddEntry(QCD,"QCD estim. using FR","p")
##    legende.AddEntry(errorBand,"Uncertainty","f")
#
#    legende.Draw()
#    
#    l1=add_lumi()
#    l1.Draw("same")
#    l2=add_CMS()
#    l2.Draw("same")
#    l3=add_Preliminary()
#    l3.Draw("same")

#    pad1.RedrawAxis()

#    categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.43, 0.70+0.155, "NDC")
#    categ.SetBorderSize(   0 )
#    categ.SetFillStyle(    0 )
#    categ.SetTextAlign(   12 )
#    categ.SetTextSize ( 0.03 )
#    categ.SetTextColor(    1 )
#    categ.SetTextFont (   41 )
#    #       if i==1 or i==3:
#    categ.AddText(channel)
#    #       else :
#    #        categ.AddText("SS")
##    categ.Draw()
#

    c.SaveAs("_opt_%s.pdf"%mass)
#       c.SaveAs("mvis"+categoriy+".png")


#channelDirectory = ["MuTau", "EleTau"]
channelDirectory = ["MuJet"]
#Category = ["_DiJet","_JetBJet"]
#Category = ["_NoBJet"]
Category = [""]







Mass=['1000.0','1400.0','1800.0']

for mass in Mass:
     FileName='file.root'
     MakePlot(FileName,mass,'')




