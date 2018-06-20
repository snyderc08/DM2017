import os
import ROOT
from ROOT import *

def MakeCompare(rootfile1,histo1,rootfile2,histo2,name,XAxis):

    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    
    file1=TFile(rootfile1,"open")
    Histo1=file1.Get(histo1)
    Histo1.Rebin(5)
#    print rootfile1,histo1, Histo1.Integral()


    file2=TFile(rootfile2,"open")
    Histo2=file2.Get(histo2)
    Histo2.Rebin(5)
#    print rootfile2,histo2, Histo2.Integral()



    print " %s %s 2016 norm= %f  v.s. 2017 norm= %f  and ratio ====>       %f \n\n"%(rootfile1.replace('NewOutFiles_QCDEstim_Data_bjetPt20/','') , histo1, Histo1.Integral(), Histo2.Integral(), Histo2.Integral()/Histo1.Integral())

    Histo1.SetLineColor(2)
    Histo1.SetLineWidth(3)
#    Histo2=file.Get(Cat+'/'+hist2)
    Histo2.SetLineColor(3)
    Histo2.SetLineWidth(3)
#    Histo3=file.Get(Cat+'/'+hist3)
#    Histo3.SetLineColor(4)
#    Histo3.SetLineWidth(2)
#
    Can=TCanvas("canvas","",0,0,600,600)
#
    Histo1.SetTitle('')
    Histo1.GetXaxis().SetTitle(XAxis)
    Histo1.GetXaxis().SetLabelSize(0.04)
    Histo1.GetXaxis().SetNdivisions(505)
    Histo1.GetXaxis().SetTitleSize(0.05)
    Histo1.GetXaxis().SetTitleOffset(0.9)
    Histo1.GetXaxis().SetLabelSize(0.04)
    Histo1.GetXaxis().SetTitleFont(42)
    Histo1.GetXaxis().SetRangeUser(0,1000)
#
#
#
#    
#    
    Histo2.Draw()
    Histo1.Draw('same')
#    Histo3.Draw('same')
#
    leg=TLegend(.3,.7,.9,.9, "", "brNDC")
    leg.SetLineWidth(1)
    leg.SetLineStyle(0)
    leg.SetFillStyle(0)
#    leg.SetBorderSize(0)
    leg.SetTextFont(62)
    leg.AddEntry(Histo1,'HT_Binned + Mass_binned W samples','l')
    leg.AddEntry(Histo2,'NJet_Binned + Mass_binned W samples','l')
#    leg.AddEntry(Histo3,hist3.replace("_CMS_scale",""),'l')
    leg.Draw()
    
    
    
    categ  = ROOT.TPaveText(0.55, 0.5+0.013, 0.77, 0.70+0.155, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.04 )
    categ.SetTextColor(    1 )
    categ.SetTextFont (   41 )
    categ.AddText(name)
    categ.Draw()
    
    Can.SaveAs('_qcdCompare_%s_%s.pdf'%(rootfile1.replace('NewOutFiles_QCDEstim_Data_bjetPt20/',''),histo1))




#rootfile=['data_obs','TT','W','SingleTop','VV','ZTT','Codex_1200','QCD']
#histo='NewROOTdePhiOnlyJet/TotalRootForLimit_PreSelection_MuJet_LQMass_HighMT_HighDPhi_AntiIso.root'


Loc1='NewOutFiles_QCDEstim_Data_bjetPt20/'
Loc2='../../DM2018/RecoStudy/NewOutFiles_QCDEstim_Data_RemoveTopPtRW/'
ListOfProcess=[
               'DYJetsToLL.root',
               'WJetsToLNu.root',
               'VV.root',
               'TTJets.root',
               'SingleTop.root',
               'Data.root',

]

ListOfHisto=[
'MuJet_LepPt_HighMT_LowDPhi_TotEta_Iso',
'MuJet_LepPt_HighMT_LowDPhi_TotEta_Total',
             ]



for pro in ListOfProcess:
    for histo in ListOfHisto:
        MakeCompare(Loc1+pro,histo,Loc2+pro,histo,'MT > 100 GeV','M_{LQ}  (GeV)')

#
#rootfile1='NewOutFiles_Preselection_addMetPhiRemoveBug/WJetsToLNu.root'
#rootfile2='NewOutFiles_Preselection_addMetPhiRemoveBug/WJetsToLNu_NJetBinSamples.root'
#
#
#
#histo1='MuJet_LQMass_HighMT_HighDPhi_Iso'
#histo2='MuJet_LQMass_HighMT_HighDPhi_Iso'
#
#
#
#MakeCompare(rootfile1,histo1,rootfile2,histo1,'MT > 100 GeV','M_{LQ}  (GeV)')
#
#histo1='MuJet_LQMass_NoMT_HighDPhi_Iso'
#MakeCompare(rootfile1,histo1,rootfile2,histo1,'MT > 0 GeV','M_{LQ}  (GeV)')
#
#histo1='MuJet_LQMass_MT500_HighDPhi_Iso'
#MakeCompare(rootfile1,histo1,rootfile2,histo1,'MT > 500 GeV','M_{LQ}  (GeV)')
#
#histo1='MuJet_tmass_MuMet_NoMT_HighDPhi_Iso'
#MakeCompare(rootfile1,histo1,rootfile2,histo1,'MT > 0 GeV','m_{T}(#mu,MET)  (GeV)')
#
#
#
#
#
#
##
##histo1='MuJet_LQMass_MT400_HighDPhi_Iso'
##histo2='MuJet_LQMass_MT400_HighDPhi_Iso'
##MakeCompare(rootfile1,histo1,rootfile2,histo2,'MT > 400 GeV')
#
#
