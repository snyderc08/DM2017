./Make.sh CodexAnalyzer_Preselection.cc


cp CodexAnalyzer_Preselection.*   OutFiles_PreSelection/.

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root  ../ROOT80X/WMASS/W*root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root



