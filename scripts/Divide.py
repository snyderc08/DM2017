import os
import ROOT
from ROOT import *

KFactor= TFile("kfactors.root");
WLO= KFactor.Get("WJets_LO/inv_pt");
WNLO=  KFactor.Get("EWKcorr/W");


can=TCanvas("can","",600,600)
WNLO.Divide(WLO)
WNLO.Draw()
WNLO.SetTitle("")
WNLO.SetStats(0)
WNLO.GetXaxis().SetTitle("generated W boson p_{T}")
WNLO.GetYaxis().SetTitle("K-factor")
#WNLO.GetXaxis().SetTitleSize(0)
#WNLO.GetXaxis().SetNdivisions(505)
WNLO.GetYaxis().SetLabelFont(42)
#WNLO.GetYaxis().SetLabelOffset(0.01)
WNLO.GetYaxis().SetLabelSize(0.03)
WNLO.GetYaxis().SetTitleSize(0.045)
WNLO.GetXaxis().SetLabelSize(0.03)
WNLO.GetXaxis().SetTitleSize(0.045)

#WNLO.GetYaxis().SetTitleOffset(.74)
#WNLO.GetXaxis().SetTitleOffset(.74)
WNLO.SetTitle("")

line=TLine(150,1.21,1250,1.21)
line.SetLineColor(2)
line.SetLineWidth(2)
line.Draw()

output = ROOT.TLegend(0.4, 0.77, 0.92, 0.85, "", "brNDC")
output.SetLineWidth(0)
output.SetLineStyle(0)
output.SetFillStyle(0)
output.SetBorderSize(0)
output.SetTextFont(62)
output.AddEntry(WNLO,"Boson pt-dependent K-factor","lpe")
output.AddEntry(line,"Flat K-factor","l")
output.Draw()


can.SaveAs("div.pdf")