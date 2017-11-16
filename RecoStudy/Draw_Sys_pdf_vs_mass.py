import os
import ROOT
from ROOT import *
import math

#OutF=TFile('Out1200.root','RECREATE')
#outHistSys=TH1F('MeanSys','',20,0,2)
#
#File=TFile('test1200.root','R')
#sum=0
#for isys in range(0,100):
#    HistSys=File.Get('___Sys_%s'%str(isys))
#    mean=HistSys.GetMean()
#    print mean
#    OutF.cd()
#    sum +=(mean*mean)
#    outHistSys.Fill(mean)
#
#outHistSys.Write()
#OutF.Write()
#OutF.Close()
#print "sum=",sum
#



def add_CMS():
    lowX=0.15
    lowY=0.70
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.06)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi



def add_Preliminary():
    lowX=0.15
    lowY=0.63
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.04)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Simulation")
    return lumi


def make_legend():
    output = ROOT.TLegend(0.5, 0.75, 0.85, 0.85, "", "brNDC")
#    output.SetLineWidth(0)
    output.SetLineStyle(0)
    output.SetFillStyle(0)
#    output.SetBorderSize(0)
    output.SetTextFont(62)
    return output




filePDF_vs_Mass=TFile('pdf_vs_mass.root','RECREATE')
histo_pdf_vs_mass_high=TH1F('pdf_vs_mass_high','',10,0,10)
histo_pdf_vs_mass_low=TH1F('pdf_vs_mass_low','',10,0,10)
histo_scale_vs_mass_high=TH1F('scale_vs_mass_high','',10,0,10)
histo_scale_vs_mass_low=TH1F('scale_vs_mass_low','',10,0,10)





InputRootFiles=[
            ['OutFiles_SignalPDF/Codex_LQ800_DM_300_X_330.root','800',1],
            ['OutFiles_SignalPDF/Codex_LQ900_DM_350_X_385.root','900',2],
            ['OutFiles_SignalPDF/Codex_LQ1000_DM_400_X_440.root','1000',3],
            ['OutFiles_SignalPDF/Codex_LQ1100_DM_450_X_495.root','1100',4],
            ['OutFiles_SignalPDF/Codex_LQ1200_DM_500_X_550.root','1200',5],
            ['OutFiles_SignalPDF/Codex_LQ1300_DM_550_X_605.root','1300',6],
            ['OutFiles_SignalPDF/Codex_LQ1400_DM_600_X_660.root','1400',7],
            ['OutFiles_SignalPDF/Codex_LQ1500_DM_650_X_715.root','1500',8]
            ]




for inFile in InputRootFiles:

    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)
    
    







    File=TFile(inFile[0],'R')


    sumP=0
    numP=0
    
    sumN=0
    numN=0
    for isys in range(0,100):
        HisMean=File.Get('MuJet_LQMass_MT500_MET100_Iso')
        HistSys=File.Get('MuJet_LQMass_PDF%s_MT500_MET100_Iso'%str(isys))
        HistSys_Denum=File.Get('___SysPDFDenumerator_%s'%str(isys))
        HistSys_Denum0=File.Get('___SysPDFDenumerator_1')

            
        meanCental=HisMean.Integral()
        meanSys=HistSys.Integral()/(HistSys_Denum.Integral()*1.0/HistSys_Denum0.Integral())


            
        if meanSys > meanCental:
            sumP +=pow( (meanSys-meanCental)  ,2)
            numP +=1
        
        if meanSys < meanCental:
            sumN +=pow( (meanCental-meanSys)  ,2)
            numN +=1




    print '========>',inFile[2] , 'numP ', numP,   'sumP= ', sumP,  ' Final Number plus is=', math.sqrt( 1./(numP -1) * sumP  ),  '  unc= ', math.sqrt( 1./(numP -1) * sumP  )/ meanCental

    BinValuPlus=math.sqrt( 1./(numP -1) * sumP  )/ meanCental
    histo_pdf_vs_mass_high.SetBinContent(inFile[2],1+BinValuPlus)
    histo_pdf_vs_mass_high.GetXaxis().SetBinLabel(inFile[2],inFile[1])


    print  '========>', inFile[2],  'numN ', numN,   'sumN= ', sumN,  ' Final Number minus is=', math.sqrt( 1./(numN -1) * sumN  ),  '  unc= ', math.sqrt( 1./(numN -1) * sumN  )/ meanCental

    BinValuMinus=math.sqrt( 1./(numN -1) * sumN  )/ meanCental
    histo_pdf_vs_mass_low.SetBinContent(inFile[2],1-BinValuMinus)
    





##########################################################################################
# Scale Uncertainty
##########################################################################################
    Minimum=0
    Maximum=100
        
    for isys in range(1,9):
            
        if isys==5 or isys==7: continue  # these 2 are non-physical related to the (2,0.5) or (0.5,2)
        
        HistCentral=File.Get('MuJet_LQMass_MT500_MET100_Iso')
        HistSys=File.Get('MuJet_LQMass_Scale%s_MT500_MET100_Iso'%str(isys))
        HistSys_Denum=File.Get('___SysScaleDenumerator_%s'%str(isys))
        HistSys_Denum0=File.Get('___SysScaleDenumerator_0')
        
        #        HistCentral.Rebin(10)
        #        HistSys.Rebin(10)
        
        
        
        #        meanCental=HistCentral.Integral()
        #        meanSys=HistSys.Integral()
        meanCental=HistCentral.Integral()
        meanSys=HistSys.Integral()/(HistSys_Denum.Integral()*1.0/HistSys_Denum0.Integral())
        
        
        if meanSys/meanCental > Minimum:
            largestDeviationUp=meanSys/meanCental
            Minimum=largestDeviationUp
        
        
        if meanSys/meanCental < Maximum:
            largestDeviationDown=meanSys/meanCental
            Maximum=largestDeviationDown



    print inFile[2], largestDeviationUp, largestDeviationDown
    
    histo_scale_vs_mass_high.SetBinContent(inFile[2],largestDeviationUp )
    histo_scale_vs_mass_low.SetBinContent(inFile[2],largestDeviationDown )






#####################################################################################

filePDF_vs_Mass.cd()

histo_pdf_vs_mass_high.Write()
histo_pdf_vs_mass_low.Write()
histo_scale_vs_mass_high.Write()
histo_scale_vs_mass_low.Write()



c=ROOT.TCanvas("canvas","",0,0,600,600)
c.cd()
c.SetGridy()




#pad1 = ROOT.TPad("pad1","pad1",0,0,1,1)
##pad1.SetLogy()
#pad1.Draw()
#pad1.cd()
#pad1.SetFillColor(0)
#pad1.SetBorderMode(0)
#pad1.SetBorderSize(10)
#pad1.SetTickx(1)
#pad1.SetTicky(1)
#pad1.SetLeftMargin(0.18)
#pad1.SetRightMargin(0.05)
#pad1.SetTopMargin(0.122)
#pad1.SetBottomMargin(0.026)
#pad1.SetFrameFillStyle(0)
#pad1.SetFrameLineStyle(0)
#pad1.SetFrameLineWidth(3)
#pad1.SetFrameBorderMode(0)
#pad1.SetFrameBorderSize(10)


#    histo_pdf_vs_mass_high=File.Get('MuJet_LQMass_MT500_MET100_Iso')

histo_pdf_vs_mass_high.Draw('pL')
histo_pdf_vs_mass_low.Draw('pLsame')
histo_scale_vs_mass_high.Draw('pLsame')
histo_scale_vs_mass_low.Draw('pLsame')
#histo_pdf_vs_mass_high.Draw('AXIS')

histo_pdf_vs_mass_high.GetXaxis().SetRangeUser(0,8)
histo_pdf_vs_mass_high.GetYaxis().SetRangeUser(0.8,1.2)
histo_pdf_vs_mass_high.GetXaxis().SetTitle("M_{LQ} [GeV]")
histo_pdf_vs_mass_high.GetXaxis().SetNdivisions(505)
histo_pdf_vs_mass_high.GetYaxis().SetLabelFont(42)
histo_pdf_vs_mass_high.GetYaxis().SetLabelOffset(0.01)
histo_pdf_vs_mass_high.GetYaxis().SetLabelSize(0.03)
histo_pdf_vs_mass_high.GetYaxis().SetTitleSize(0.04)
histo_pdf_vs_mass_high.GetYaxis().SetTitleOffset(1.2)
histo_pdf_vs_mass_high.SetTitle("")
histo_pdf_vs_mass_high.GetYaxis().SetTitle("PDF/QCD scale Uncertainty")
histo_pdf_vs_mass_high.SetLineColor(38)
histo_pdf_vs_mass_high.SetLineWidth(3)
histo_pdf_vs_mass_high.SetMarkerColor(38)
histo_pdf_vs_mass_high.SetMarkerStyle(20)




histo_pdf_vs_mass_low.SetLineColor(38)
histo_pdf_vs_mass_low.SetLineWidth(3)
histo_pdf_vs_mass_low.SetMarkerColor(38)
histo_pdf_vs_mass_low.SetMarkerStyle(20)


histo_scale_vs_mass_high.SetLineColor(8)
histo_scale_vs_mass_high.SetLineWidth(3)
histo_scale_vs_mass_high.SetMarkerColor(8)
histo_scale_vs_mass_high.SetMarkerStyle(21)



histo_scale_vs_mass_low.SetLineColor(8)
histo_scale_vs_mass_low.SetLineWidth(3)
histo_scale_vs_mass_low.SetMarkerColor(8)
histo_scale_vs_mass_low.SetMarkerStyle(21)



legende=make_legend()
legende.AddEntry(histo_pdf_vs_mass_low,"PDF uncertainty","lp")
legende.AddEntry(histo_scale_vs_mass_high,"QCD scale uncertainty","lp")
legende.Draw()



#categ  = ROOT.TPaveText(0.2, 0.3+0.013, 0.39, 0.4+0.1, "NDC")
#categ.SetBorderSize(   0 )
#categ.SetFillStyle(    0 )
#categ.SetTextAlign(   12 )
#categ.SetTextSize ( 0.05 )
#categ.SetTextColor(    1 )
#categ.AddText('PDF')
#categ.Draw()


l2=add_CMS()
l2.Draw("same")
l3=add_Preliminary()
l3.Draw("same")


c.RedrawAxis('same')



c.SaveAs('PDF_Uncertaint_vs_Mass.pdf')
#
#    c.cd()
#    pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
#    pad2.SetTopMargin(0.05);
#    pad2.SetBottomMargin(0.3);
#    pad2.SetLeftMargin(0.18);
#    pad2.SetRightMargin(0.05);
#    #pad2.SetTickx(1)
#    #pad2.SetTicky(1)
#    pad2.SetFrameLineWidth(3)
#    pad2.SetGridx()
#    pad2.SetGridy()
#    pad2.Draw()
#    pad2.cd()








filePDF_vs_Mass.Close()




