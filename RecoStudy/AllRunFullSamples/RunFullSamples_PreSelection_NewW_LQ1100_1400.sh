./Make.sh CodexAnalyzer_Preselection.cc


cp CodexAnalyzer_Preselection.*   OutFiles_PreSelection_NewW_LQ1100_1400/.

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection_NewW_LQ1100_1400/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection_NewW_LQ1100_1400/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root  ../ROOT80X/WMASS/W*root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection_NewW_LQ1100_1400/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection_NewW_LQ1100_1400/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection_NewW_LQ1100_1400/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection_NewW_LQ1100_1400/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection_NewW_LQ1100_1400/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root



