import os
import ROOT
from ROOT import *

def MakeCompare(r1,hist1,r2,hist2,name,RB_,XTit,name2):

    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    
    file1=TFile(r1,"open")
    file2=TFile(r2,"open")

#    Histo1=file1.Get(cat1+'/'+hist1)
    Histo1=file1.Get(hist1)
    Histo1.SetLineColor(2)
    Histo1.SetLineWidth(2)
    Histo1.Rebin(RB_)
    Histo1.Scale(1/Histo1.Integral())
    
#    Histo2=file2.Get(cat2+'/'+hist2)
    Histo2=file2.Get(hist2)
    print 'fileis',r1, '  histo is', hist2
    Histo2.SetLineColor(3)
    Histo2.SetLineWidth(2)
    Histo2.Rebin(RB_)
    Histo2.Scale(1/Histo2.Integral())
    
    
#    Histo3=file.Get(Cat+'/'+hist3)
#    Histo3.SetLineColor(4)
#    Histo3.SetLineWidth(2)
#
    Can=TCanvas("canvas","",0,0,600,600)
    Can.SetLogy()

    Histo1.SetTitle('')
    Histo1.GetXaxis().SetTitle(XTit)
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
    Histo1.Draw()
    Histo2.Draw('same')
#    Histo3.Draw('same')
#
    leg=TLegend(.6,.8,.9,.9, "", "brNDC")
    leg.SetLineWidth(1)
    leg.SetLineStyle(0)
    leg.SetFillStyle(0)
#    leg.SetBorderSize(0)
    leg.SetTextFont(62)
    leg.AddEntry(Histo1,'Mu channel','l')
    leg.AddEntry(Histo2,'electron channel','l')
#    leg.AddEntry(Histo3,hist3.replace("_CMS_scale",""),'l')
    leg.Draw()
    
    Can.SaveAs('_compare_%s%s.pdf'%(name,name2))


F1='OutFiles_PreSelection/Data.root'
F2='OutFiles_PreSelection_SampleLQ1/Data.root'


#F1='OutFiles_Excess_LQMore1100/Data.root'
#F2='Data_LQ1100.root'



process=[
         ['Jet_LepEta_MT500_HighDPhi_Iso',10,'Lepton #eta'],
         ['Jet_JetEta_MT500_HighDPhi_Iso',10,'Jet #eta'],
         ['Jet_LQMass_MT500_HighDPhi_Iso',10,'M_{LQ} GeV'],
         ['Jet_MET_MT500_HighDPhi_Iso',10,'MET GeV'],
         ['Jet_JetPt_MT500_HighDPhi_Iso',50,'Jet pT GeV'],
         ['Jet_LepPt_MT500_HighDPhi_Iso',50,'lepton pT GeV'],
         ['Jet_dEta_Mu_Jet_MT500_HighDPhi_Iso',50,'#Delta#eta lep,jet']
         ]


for i in range(0,len(process)):
#    MakeCompare(F1,'Mu'+process[i][0],F2,'Ele'+process[i][0].replace('_HighMT','_MT500'),process[i][0],process[i][1],process[i][2])
    MakeCompare(F1,'Mu'+process[i][0],F2,'Ele'+process[i][0],process[i][0],process[i][1],process[i][2],'_MTHigh')
    MakeCompare(F1,'Mu'+process[i][0].replace('_MT500','_HighMT'),F2,'Ele'+process[i][0].replace('_MT500','_HighMT'),process[i][0],process[i][1],process[i][2],'_MT500')


