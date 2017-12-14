./Make.sh CodexAnalyzer_Excess.cc



cp CodexAnalyzer_Excess.*    OutFiles_Excess_MTGreat1400/.
./CodexAnalyzer_Excess.exe  OutFiles_Excess_MTGreat1400/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Excess.exe  OutFiles_Excess_MTGreat1400/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu_HT-*.root

./CodexAnalyzer_Excess.exe  OutFiles_Excess_MTGreat1400/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Excess.exe  OutFiles_Excess_MTGreat1400/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Excess.exe  OutFiles_Excess_MTGreat1400/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Excess.exe  OutFiles_Excess_MTGreat1400/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Excess.exe  OutFiles_Excess_MTGreat1400/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root



