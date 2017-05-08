import os
import ROOT
from ROOT import *


File=TFile("OutFiles_FullSelection/WJetsToLNu_EtaLQtest.root")

Met_Cat= ["_MET500","_MET100", "_MET200", "_MET300", "_MET400"]
MT_Cat = [ "_MT500","_MT100", "_MT200", "_MT300", "_MT400"]

can=TCanvas()
leg=TLegend(0.65, 0.4, 0.92, 0.82, "", "brNDC")

counter=0
_met=0
for met in Met_Cat:
    _met +=1
    _mt=0
    for mt in MT_Cat:
        _mt +=1
        
        if _mt==_met:
            counter +=1
            NormMC="_LQEta"+mt+met
            HistName="MuJet"+NormMC+"_Iso"
            
            Hist=File.Get(HistName)
            
            Hist.SetLineColor(counter)
            leg.AddEntry(Hist,mt+met,"l")
            Hist.Rebin(5)
            if counter < 2:
                
                Hist.DrawNormalized('l')
            else:
                Hist.DrawNormalized('samel')
#            Hist.GetYaxis().SetRangeUser(0,1)


leg.Draw()
can.SaveAs("_checklqEta_"+mt+met+".pdf")