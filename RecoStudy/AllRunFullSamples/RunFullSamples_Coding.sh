#!/bin/sh

./Make.sh   CodexAnalyzer_Excess_Total.cc

mkdir OutFile_Excess_Total

cp CodexAnalyzer_Excess_Total.*  OutFile_Excess_Total/.

./CodexAnalyzer_Excess_Total.exe  OutFile_Excess_Total/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Excess_Total.exe  OutFile_Excess_Total/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root

./CodexAnalyzer_Excess_Total.exe  OutFile_Excess_Total/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Excess_Total.exe  OutFile_Excess_Total/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Excess_Total.exe  OutFile_Excess_Total/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Excess_Total.exe  OutFile_Excess_Total/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Excess_Total.exe  OutFile_Excess_Total/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root




./Make.sh   CodexAnalyzer_Excess_LQMore1100.cc

mkdir OutFile_Excess_LQMore1100

cp CodexAnalyzer_Excess_LQMore1100.*  OutFile_Excess_LQMore1100/.

./CodexAnalyzer_Excess_LQMore1100.exe  OutFile_Excess_LQMore1100/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Excess_LQMore1100.exe  OutFile_Excess_LQMore1100/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root

./CodexAnalyzer_Excess_LQMore1100.exe  OutFile_Excess_LQMore1100/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Excess_LQMore1100.exe  OutFile_Excess_LQMore1100/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Excess_LQMore1100.exe  OutFile_Excess_LQMore1100/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Excess_LQMore1100.exe  OutFile_Excess_LQMore1100/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Excess_LQMore1100.exe  OutFile_Excess_LQMore1100/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root






./Make.sh   CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.cc

mkdir OutFile_Excess_LQ1100_1400_Jet_100_200

cp CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.*  OutFile_Excess_LQ1100_1400_Jet_100_200/.

./CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.exe  OutFile_Excess_LQ1100_1400_Jet_100_200/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.exe  OutFile_Excess_LQ1100_1400_Jet_100_200/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root

./CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.exe  OutFile_Excess_LQ1100_1400_Jet_100_200/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.exe  OutFile_Excess_LQ1100_1400_Jet_100_200/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.exe  OutFile_Excess_LQ1100_1400_Jet_100_200/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.exe  OutFile_Excess_LQ1100_1400_Jet_100_200/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Excess_LQ1100_1400_Jet_100_200.exe  OutFile_Excess_LQ1100_1400_Jet_100_200/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root







./Make.sh   CodexAnalyzer_Excess_LQ1100_1400.cc

mkdir OutFile_Excess_LQ1100_1400

cp CodexAnalyzer_Excess_LQ1100_1400.*  OutFile_Excess_LQ1100_1400/.

./CodexAnalyzer_Excess_LQ1100_1400.exe  OutFile_Excess_LQ1100_1400/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Excess_LQ1100_1400.exe  OutFile_Excess_LQ1100_1400/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root

./CodexAnalyzer_Excess_LQ1100_1400.exe  OutFile_Excess_LQ1100_1400/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Excess_LQ1100_1400.exe  OutFile_Excess_LQ1100_1400/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Excess_LQ1100_1400.exe  OutFile_Excess_LQ1100_1400/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Excess_LQ1100_1400.exe  OutFile_Excess_LQ1100_1400/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Excess_LQ1100_1400.exe  OutFile_Excess_LQ1100_1400/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root





