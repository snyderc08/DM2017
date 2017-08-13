import os
import ROOT
from ROOT import *

def MakeCompare(InputRoot,process):

    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    
    file=TFile(InputRoot,"open")
    Histo1=file.Get('MuJet/'+process)
    print InputRoot,process, Histo1.Integral()
#    Histo1.SetLineColor(2)
#    Histo1.SetLineWidth(2)
#    Histo2=file.Get(Cat+'/'+hist2)
#    Histo2.SetLineColor(3)
#    Histo2.SetLineWidth(2)
#    Histo3=file.Get(Cat+'/'+hist3)
#    Histo3.SetLineColor(4)
#    Histo3.SetLineWidth(2)
#
#    Can=TCanvas("canvas","",0,0,600,600)
#
#    Histo1.SetTitle('')
#    Histo1.GetXaxis().SetTitle('M_{LQ}')
#    Histo1.GetXaxis().SetLabelSize(0.04)
#    Histo1.GetXaxis().SetNdivisions(505)
#    Histo1.GetXaxis().SetTitleSize(0.05)
#    Histo1.GetXaxis().SetTitleOffset(0.9)
#    Histo1.GetXaxis().SetLabelSize(0.04)
#    Histo1.GetXaxis().SetTitleFont(42)
#    Histo1.GetYaxis().SetTitle("Events")
#    
#
#
#    
#    
#    Histo1.Draw()
#    Histo2.Draw('same')
#    Histo3.Draw('same')
#
#    leg=TLegend(.5,.3,.9,.5, "", "brNDC")
#    leg.SetLineWidth(1)
#    leg.SetLineStyle(0)
#    leg.SetFillStyle(0)
##    leg.SetBorderSize(0)
#    leg.SetTextFont(62)
#    leg.AddEntry(Histo2,hist2.replace("_CMS_scale",""),'l')
#    leg.AddEntry(Histo1,hist1.replace("_CMS_scale",""),'l')
#    leg.AddEntry(Histo3,hist3.replace("_CMS_scale",""),'l')
#    leg.Draw()
#    
#    Can.SaveAs('_Unc'+Name+'.pdf')




process=['data_obs','TT','W','SingleTop','VV','ZTT','Codex_1200','QCD']
UncUp='NewROOTdePhiOnlyJet/TotalRootForLimit_PreSelection_MuJet_LQMass_HighMT_HighDPhi_AntiIso.root'
UncDown='NewROOTdePhiBothJetMu/TotalRootForLimit_PreSelection_MuJet_LQMass_HighMT_HighDPhi_AntiIso.root'


for pro in process:
        MakeCompare(UncUp,pro)
        MakeCompare(UncDown,pro)

