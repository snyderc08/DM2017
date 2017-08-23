import ROOT
from ROOT import *


def _Make_Histo(file,histo,Name):
    
    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    c=ROOT.TCanvas("canvas","",0,0,600,600)
    c.cd()
    
    
    file1=TFile(file,'R')
    Histo1=file1.Get(histo)
    Histo1.SetLineColor(4)
    Histo1.SetLineWidth(2)
    Histo1.SetMarkerColor(4)
    Histo1.SetMarkerStyle(20)
    Histo1.GetXaxis().SetTitle('M_{#muj}  [GeV]')
    Histo1.GetYaxis().SetTitle('Events')
    Histo1.GetXaxis().SetTitleSize(0.04)
    Histo1.GetYaxis().SetTitleSize(0.04)
#    Histo1.GetXaxis().SetRangeUser(0,1900)
    Histo1.SetTitle("")


    c.SetLogy()
#    c.Draw()
#    c.cd()
    c.SetFillColor(0)
    c.SetBorderMode(0)
    c.SetBorderSize(10)
    c.SetTickx(1)
    c.SetTicky(1)
#    c.SetLeftMargin(0.18)
#    c.SetRightMargin(0.05)
#    c.SetTopMargin(0.122)
#    c.SetBottomMargin(0.026)
    c.SetFrameFillStyle(0)
    c.SetFrameLineStyle(0)
    c.SetFrameLineWidth(3)
    c.SetFrameBorderMode(0)
    c.SetFrameBorderSize(10)
    
    
    
    
    
    
    Histo1.Draw()
    
    if Name=='Codex_':
        Name='LQ_1200'

    categ  = ROOT.TPaveText(0.6, 0.7+0.013, 0.8, 0.8+0.1, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.05 )
    categ.SetTextColor(    1 )
    categ.AddText(Name)
    categ.Draw()



    c.SaveAs('_Single_Samle_%s.pdf'%Name)







Sample=['W','TT','SingleTop','VV','ZTT','Codex_']
for Sam in Sample:
    _Make_Histo('postfit_shapes.root','Codex__mj_1_13TeV_prefit/%s'%Sam,Sam)




