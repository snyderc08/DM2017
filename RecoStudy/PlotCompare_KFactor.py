import os
import ROOT
from ROOT import *
import array

rb_=array.array("d",[0,50,100,150,200,250,300,375,450,525,600,700,1000])


def _Fit_Line(x,p):
    return p[0]+p[1]*x[0]

def Get_Boson_KFactor(x,p):
    return p[0]+p[1]*x


def MakeCompare(root1,hist1,name1, root2,hist2, name2,root3, hist3,name3,Name,Sample):
    
    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    c=ROOT.TCanvas("canvas","",0,0,600,600)
    c.cd()
    
    
    file1=TFile(root1,"open")
    print "---->,", file1.GetName()
    Histo1_=file1.Get(hist1)
    Histo1=Histo1_.Rebin(len(rb_)-1,"",rb_)
    Histo1.SetLineColor(2)
    Histo1.SetLineWidth(2)
    Histo1.SetMaximum(Histo1.GetMaximum()*200)
    Histo1.SetMarkerColor(2)
    Histo1.SetMarkerStyle(20)
    
    file2=TFile(root2,"open")
    Histo2_=file2.Get(hist2)
    Histo2=Histo2_.Rebin(len(rb_)-1,"",rb_)
    Histo2.SetLineColor(3)
    Histo2.SetLineWidth(3)
    Histo2.SetMarkerColor(3)
    Histo2.SetMarkerStyle(29)
    
    file3=TFile(root3,"open")
    Histo3_=file3.Get(hist3)
    Histo3=Histo3_.Rebin(len(rb_)-1,"",rb_)
    Histo3.SetLineColor(4)
    Histo3.SetLineWidth(4)
    Histo3.SetMarkerColor(4)
    Histo3.SetMarkerStyle(24)
    

#    Histo1.SetTitle('')
    Histo1.GetXaxis().SetTitle('boson p_{T} (GeV)')
#    Histo1.GetXaxis().SetLabelSize(0.04)
#    Histo1.GetXaxis().SetNdivisions(505)
#    Histo1.GetXaxis().SetTitleSize(0.05)
#    Histo1.GetXaxis().SetTitleOffset(0.9)
#    Histo1.GetXaxis().SetLabelSize(0.04)
#    Histo1.GetXaxis().SetTitleFont(42)
#    Histo1.GetYaxis().SetTitle("Events")
#    Histo1.GetXaxis().SetRangeUser(50,1000)

    Histo1.GetXaxis().SetTitle("")
    Histo1.GetXaxis().SetTitleSize(0)
    Histo1.GetXaxis().SetLabelSize(0)
    Histo1.GetXaxis().SetNdivisions(505)
    Histo1.GetYaxis().SetLabelFont(42)
    Histo1.GetYaxis().SetLabelOffset(0.01)
    Histo1.GetYaxis().SetLabelSize(0.06)
    Histo1.GetYaxis().SetTitleSize(0.075)
    Histo1.GetYaxis().SetTitleOffset(1.04)
    Histo1.SetTitle("")
#    Histo1.Setlabel("")
    Histo1.GetYaxis().SetTitle("Events")
    Histo1.GetXaxis().SetRangeUser(50,1000)    




    pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
    pad1.SetLogy()
    pad1.Draw()
    pad1.cd()
    pad1.SetFillColor(0)
    pad1.SetBorderMode(0)
    pad1.SetBorderSize(10)
    pad1.SetTickx(1)
    pad1.SetTicky(1)
    pad1.SetLeftMargin(0.18)
    pad1.SetRightMargin(0.05)
    pad1.SetTopMargin(0.122)
    pad1.SetBottomMargin(0.026)
    pad1.SetFrameFillStyle(0)
    pad1.SetFrameLineStyle(0)
    pad1.SetFrameLineWidth(3)
    pad1.SetFrameBorderMode(0)
    pad1.SetFrameBorderSize(10)
    
    
    
    
    
    
    Histo1.Draw()
    Histo2.Draw('same')
    Histo3.Draw('same')
    
    
    categ  = ROOT.TPaveText(0.63, 0.4+0.013, 0.89, 0.5+0.1, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.08 )
    categ.SetTextColor(    1 )
    #    categ.SetTextFont (   41 )
    #       if i==1 or i==3:
    categ.AddText(Sample)
    categ.Draw()
    
    
    

    leg=ROOT.TLegend(0.2, 0.6, 0.95, 0.82, "", "brNDC")
    leg.SetLineWidth(1)
    leg.SetLineStyle(0)
    leg.SetFillStyle(0)
    leg.SetTextSize(0.035)
#    leg.SetBorderSize(0)
    leg.SetTextFont(62)
    leg.AddEntry(Histo1,name1,'lp')
    leg.AddEntry(Histo3,name3,'lp')
    leg.AddEntry(Histo2,name2,'lp')
    leg.Draw()
    
    pad1.RedrawAxis()
    
    c.cd()
    pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
    pad2.SetTopMargin(0.05);
    pad2.SetBottomMargin(0.35);
    pad2.SetLeftMargin(0.18);
    pad2.SetRightMargin(0.05);
    pad2.SetTickx(1)
    pad2.SetTicky(1)
    pad2.SetFrameLineWidth(3)
    pad2.SetGridx()
    pad2.SetGridy()
    pad2.Draw()
    pad2.cd()
    
    
    
    
    h1=Histo1.Clone()
    h1.SetMaximum(2)
    h1.SetMinimum(0)
    h1.SetMarkerStyle(20)
    h1.SetMarkerColor(2)
    h1.GetXaxis().SetTitle('boson p_{T} (GeV)')
    
    h5=Histo3.Clone()
    h5.SetMaximum(2)
    h5.SetMinimum(0)
    h5.SetMarkerStyle(24)
    h5.SetMarkerColor(4)
    
    
    h2=Histo2.Clone()
#    h3=Histo3.Clone()

    
    
    
    h1.Sumw2()
    h2.Sumw2()
    h5.Sumw2()

    h1.SetStats(0)
    h2.SetStats(0)
    h5.SetStats(0)
    h1.SetTitle("")
    
    h1.Divide(h2)
    h5.Divide(h2)
    
    
    h1.GetXaxis().SetTitle("")
    h1.GetXaxis().SetLabelSize(0.08)
    h1.GetYaxis().SetLabelSize(0.08)
    h1.GetYaxis().SetTitle("NLO/LO")
    h1.GetXaxis().SetNdivisions(505)
    h1.GetYaxis().SetNdivisions(5)
    h1.GetXaxis().SetTitleSize(0.15)
    h1.GetYaxis().SetTitleSize(0.15)
    h1.GetYaxis().SetTitleOffset(0.56)
    h1.GetXaxis().SetTitleOffset(1.04)
    h1.GetXaxis().SetLabelSize(0.11)
    h1.GetYaxis().SetLabelSize(0.11)
    h1.GetXaxis().SetTitleFont(42)
    h1.GetYaxis().SetTitleFont(42)
    h1.GetXaxis().SetTitle('boson p_{T} (GeV)')
    
    
    
    
    nPar = 2
    ##### The ratio plot for mono-LQ
    h1.Draw("ep2")
    theFit1=TF1("theFit", _Fit_Line, 0, 1000,nPar)
    h1.Fit("theFit","R0")
    theFit1.SetLineColor(2)
    FitParameter_monoLQ=theFit1.GetParameters()
    theFit1.Draw("SAME")
    
    
    ##### The ratio plot for mono-jet
    h5.Draw("ep2same")
    theFit5=TF1("theFit", _Fit_Line, 150, 1000,nPar)
    h5.Fit("theFit","R0")
    theFit5.SetLineColor(4)
    FitParameter_monoJet=theFit5.GetParameters()
    theFit5.Draw("SAME")

    c.cd()
    pad1.Draw()
    
    ROOT.gPad.RedrawAxis()
    
    c.Modified()
    
    
    
    c.SaveAs('kfactor%s.pdf'%Name)
    outF=TFile('../interface/kfactor_lq%s.root'%Name,'RECREATE')
    outHist=TH1F('KFcator','',2,0,2)
#    outHist.SetBinContent(1,FitParameter_monoLQ[0])
#    outHist.SetBinContent(2,FitParameter_monoLQ[1])
    outHist.SetBinContent(1,FitParameter_monoJet[0])
    outHist.SetBinContent(2,FitParameter_monoJet[1])
    outHist.Write()
    outF.Write()
    outF.Close()

#    return FitParameter_monoLQ
    return FitParameter_monoJet


location='OutFiles_LO/'


plotInput=[
[location+'WJetsToLNu_FXFX.root','_WBosonPt_KFactor_OnlyEWK','NLO(amc@NLO)+ NLO-EWK'],
[location+'WJetsToLNu_LO.root','_WBosonPt','LO(Madgraph)'],
[location+'WJetsToLNu_LO.root','_WBosonPt_KFactor','LO(Madgraph)+ NLO-QCD(from MonoJet)+ NLO-EWK'],
]

list=[]
for i in range(0,3):
    for j in range(0,3):
        list.append(plotInput[i][j])

def get_Factor_W():
    MakeCompare(list[0],list[1],list[2],list[3],list[4],list[5],list[6],list[7],list[8],'_W','W+Jet')




plotInput2=[
           [location+'DYJetsToLL_FXFX.root','_ZBosonPt_KFactor_OnlyEWK','NLO(amc@NLO)+ NLO-EWK'],
           [location+'DYJetsToLL_LO.root','_ZBosonPt','LO(Madgraph)'],
           [location+'DYJetsToLL_LO.root','_ZBosonPt_KFactor','LO(Madgraph)+ NLO-QCD(from MonoJet)+ NLO-EWK'],
           ]

list2=[]
for i in range(0,3):
    for j in range(0,3):
        list2.append(plotInput2[i][j])


def get_Factor_Z():
    MakeCompare(list2[0],list2[1],list2[2],list2[3],list2[4],list2[5],list2[6],list2[7],list2[8],'_Z','Z+Jet')



get_Factor_W()
get_Factor_Z()


