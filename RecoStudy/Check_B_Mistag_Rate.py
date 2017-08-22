##### This code is used to measure the btag mistage rate uncertainties. One needs to run the CodexAnalyzer_FinalSelection.cc file first and the output will be stores in OutFiles_FullSelection directories. Then run this code simply and get the percentage for b-mistage rate. I found it to be less than 1% for all processes
#######

import ROOT
from ROOT  import *



def CompareMistag(inputFile):
    file=TFile(inputFile)

    Nominal=file.Get('MuJet_LQMass_MT500_MET100_Iso')
    Up=file.Get('MuJet_LQMass_BtagUp_MT500_MET100_Iso')
    Down=file.Get('MuJet_LQMass_BtagDown_MT500_MET100_Iso')

    Int_Nom=Nominal.Integral()
    Int_Up=Up.Integral()
    Int_Down=Down.Integral()

    print "For File: %s nominal=%f Up=%f  Down=%f  Unc=%f  percent \n"%(inputFile, Int_Nom,Int_Up,Int_Down, max(abs(Int_Up-Int_Nom)/Int_Nom, abs(Int_Down-Int_Nom)/Int_Nom )*100)




Samples=[
'DYJetsToLL.root',
'WJetsToLNu.root',
'TTJets.root',
'VV.root',
'SingleTop.root',
'Codex_1.root',
'Codex_20.root',
'Codex_40.root'
         ]


for S in Samples:
    CompareMistag('OutFiles_FullSelection/%s'%S)