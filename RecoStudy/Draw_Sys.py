import os
import ROOT
from ROOT import *

OutF=TFile('outsys_2.root','RECREATE')
outHist=TH1F('MeanSys','',200,0,2)

File=TFile('test_lq800.root','R')
for isys in range(0,99):
    Hist=File.Get('___Sys_%s'%str(isys))
    mean=Hist.GetMean()
    print mean
    OutF.cd()
    outHist.Fill(mean)

outHist.Write()
OutF.Write()
OutF.Close()
