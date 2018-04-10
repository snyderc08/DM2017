import ROOT
from ROOT import *

rootfiles=[
"NewOutFiles_Preselection_CheckJetOverLap/",
"NewOutFiles_Preselection_CheckNOJetOverLap/"
]

sample=[
"Codex_1200.root",
"DYJetsToLL.root",
"Data.root",
"SingleTop.root",
"TTJets.root",
"VV.root",
"WJetsToLNu.root"
 ]

for j in rootfiles:
    for i in sample:
        file=TFile(j+i)
        hist=file.Get('MuJet_LQMass_MT500_HighDPhi_Iso')
        print j, i, hist.Integral()