import os
import ROOT
from ROOT import *

def MakeCompare(root1,hist1, root2,hist2, root3, hist3,Name):
    
    print  "====>", root1,hist1, root2,hist2, root3, hist3

    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    
    file1=TFile(root1,"open")
    print "---->,", file1.GetName()
    Histo1=file1.Get(hist1)
    Histo1.Rebin(5)
    Histo1.SetLineColor(2)
    Histo1.SetLineWidth(2)
    Histo1.SetMaximum(Histo1.GetMaximum()*2)
    
    file2=TFile(root2,"open")
    Histo2=file2.Get(hist2)
    Histo2.Rebin(5)
    Histo2.SetLineColor(3)
    Histo2.SetLineWidth(3)
    
    file3=TFile(root3,"open")
    Histo3=file3.Get(hist3)
    Histo3.Rebin(5)
    Histo3.SetLineColor(4)
    Histo3.SetLineWidth(4)
    

    Can=TCanvas("canvas","",0,0,600,600)
#    Can.SetLogy()

    Histo1.SetTitle('')
    Histo1.GetXaxis().SetTitle('boson p_{T} (GeV)')
    Histo1.GetXaxis().SetLabelSize(0.04)
    Histo1.GetXaxis().SetNdivisions(505)
    Histo1.GetXaxis().SetTitleSize(0.05)
    Histo1.GetXaxis().SetTitleOffset(0.9)
    Histo1.GetXaxis().SetLabelSize(0.04)
    Histo1.GetXaxis().SetTitleFont(42)
    Histo1.GetYaxis().SetTitle("Events")
    Histo1.GetXaxis().SetRangeUser(0,1000)
    


    
    
    Histo1.Draw()
    Histo2.Draw('same')
    Histo3.Draw('same')

    leg=TLegend(.5,.3,.9,.5, "", "brNDC")
    leg.SetLineWidth(1)
    leg.SetLineStyle(0)
    leg.SetFillStyle(0)
#    leg.SetBorderSize(0)
    leg.SetTextFont(62)
    leg.AddEntry(Histo1,hist1.replace("_CMS_scale",""),'l')
    leg.AddEntry(Histo2,hist2.replace("_CMS_scale",""),'l')
    leg.AddEntry(Histo3,hist3.replace("_CMS_scale",""),'l')
    leg.Draw()
    
    Can.SaveAs('kfactor%s.pdf'%Name)


location='OutFiles_LO/'
MakeCompare(location+'DYJetsToLL_FXFX.root','MuJet_ZBosonPt_HighMT_HighDPhi_Iso',location+'DYJetsToLL_LO.root','MuJet_ZBosonPt_HighMT_HighDPhi_Iso',location+'DYJetsToLL_LO.root','MuJet_ZBosonPt_KFactor_HighMT_HighDPhi_Iso','HighMT_Z')
MakeCompare(location+'DYJetsToLL_FXFX.root','MuJet_ZBosonPt_NoMT_HighDPhi_Iso',location+'DYJetsToLL_LO.root','MuJet_ZBosonPt_NoMT_HighDPhi_Iso',location+'DYJetsToLL_LO.root','MuJet_ZBosonPt_KFactor_NoMT_HighDPhi_Iso','NoMT_Z')



MakeCompare(location+'WJetsToLNu_FXFX.root','MuJet_WBosonPt_HighMT_HighDPhi_Iso',location+'WJetsToLNu_LO.root','MuJet_WBosonPt_HighMT_HighDPhi_Iso',location+'WJetsToLNu_LO.root','MuJet_WBosonPt_KFactor_HighMT_HighDPhi_Iso','HighMT_W')
MakeCompare(location+'WJetsToLNu_FXFX.root','MuJet_WBosonPt_NoMT_HighDPhi_Iso',location+'WJetsToLNu_LO.root','MuJet_WBosonPt_NoMT_HighDPhi_Iso',location+'WJetsToLNu_LO.root','MuJet_WBosonPt_KFactor_NoMT_HighDPhi_Iso','NoMT_W')


