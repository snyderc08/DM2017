import os
import ROOT
from ROOT import *

def PlotMaker(InputRoot,process,Name,RB_):

    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    Can=TCanvas("canvas","",0,0,600,600)
    
    file=TFile(InputRoot,"open")
    Histo1=file.Get(process)
    
    
#    print InputRoot,process, Histo1.Integral()
    Histo1.SetLineColor(9)
    Histo1.SetLineWidth(3)
    Histo1.Rebin(RB_)
    Histo1.Draw()
#    Histo2=file.Get(Cat+'/'+hist2)
#    Histo2.SetLineColor(3)
#    Histo2.SetLineWidth(2)
#    Histo3=file.Get(Cat+'/'+hist3)
#    Histo3.SetLineColor(4)
#    Histo3.SetLineWidth(2)
#

#
    Histo1.SetTitle('')
    Histo1.GetXaxis().SetTitle('M_{LQ} [GeV]')
    Histo1.GetXaxis().SetLabelSize(0.04)
    Histo1.GetXaxis().SetNdivisions(505)
    Histo1.GetXaxis().SetTitleSize(0.05)
    Histo1.GetXaxis().SetTitleOffset(0.9)
    Histo1.GetXaxis().SetLabelSize(0.04)
    Histo1.GetXaxis().SetTitleFont(42)
    Histo1.GetYaxis().SetTitle("Events")
#
#
#
#    
#    
#    Histo1.Draw()
#    Histo2.Draw('same')
#    Histo3.Draw('same')
#
    leg=TLegend(.7,.8,.9,.9, "", "brNDC")
    leg.SetLineWidth(1)
    leg.SetLineStyle(0)
    leg.SetFillStyle(0)
#    leg.SetBorderSize(0)
    leg.SetTextFont(62)
    leg.AddEntry(Histo1,Name,'l')
    leg.Draw()
#
    Can.SaveAs('DiBoson_'+Name+str(RB_)+'_.pdf')



PlotMaker('testVV.root','MuJet_LQMass_MT500_HighDPhi_Iso','VV',10)
PlotMaker('testVV.root','MuJet_LQMass_MT500_HighDPhi_Iso','VV',5)

PlotMaker('testWW.root','MuJet_LQMass_MT500_HighDPhi_Iso','WW',10)
PlotMaker('testWW.root','MuJet_LQMass_MT500_HighDPhi_Iso','WW',5)

PlotMaker('testWZ.root','MuJet_LQMass_MT500_HighDPhi_Iso','WZ',10)
PlotMaker('testWZ.root','MuJet_LQMass_MT500_HighDPhi_Iso','WZ',5)

PlotMaker('testZZ.root','MuJet_LQMass_MT500_HighDPhi_Iso','ZZ',10)
PlotMaker('testZZ.root','MuJet_LQMass_MT500_HighDPhi_Iso','ZZ',5)
