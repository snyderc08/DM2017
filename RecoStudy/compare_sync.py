import os
import ROOT
from ROOT import *


def make_legend():
    output = ROOT.TLegend(0.25, 0.6, 0.52, 0.82, "", "brNDC")
    output.SetLineWidth(0)
    output.SetLineStyle(0)
    output.SetFillStyle(0)
    output.SetBorderSize(0)
    output.SetTextFont(62)
    return output



C=TCanvas()
ROOT.gStyle.SetFrameLineWidth(3)
ROOT.gStyle.SetLineWidth(3)
ROOT.gStyle.SetOptStat(0)

F_Abdollah=TFile("test.root","OPEN")
H_Abdollah=F_Abdollah.Get("_LQMass")
H_Abdollah.Rebin(2)
H_Abdollah.SetMarkerSize(1)
H_Abdollah.SetMarkerColor(9)
H_Abdollah.SetMarkerStyle(20)
H_Abdollah.GetXaxis().SetRangeUser(0,2000)
H_Abdollah.GetXaxis().SetTitle("M_{LQ} (GeV)")
H_Abdollah.Draw('p')



F_Atanu=TFile("LQ_Mass_TH1F.root","OPEN")
H_Atanu=F_Atanu.Get("mass_noveto_LQ__1")
H_Atanu.Rebin(20)
H_Atanu.SetMarkerSize(1)
H_Atanu.SetMarkerStyle(30)
H_Atanu.SetMarkerColor(2)

H_Atanu.Draw('samep')



legende=make_legend()
legende.AddEntry(H_Abdollah,"Abdollah","p")
legende.AddEntry(H_Atanu,"Atanu","p")
legende.Draw()

C.SaveAs('t.pdf')