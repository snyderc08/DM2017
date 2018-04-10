./Make.sh CodexAnalyzer_Preselection_Jet50.cc


cp CodexAnalyzer_Preselection_Jet50.* OutFiles_Jet50_200/.

./CodexAnalyzer_Preselection_Jet50.exe  OutFiles_Jet50_200/DYJetsToLL.root ../ROOT80X/lqsamples2_jetPt50_MT300/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection_Jet50.exe  OutFiles_Jet50_200/WJetsToLNu.root ../ROOT80X/lqsamples2_jetPt50_MT300/WJets*.root   ../ROOT80X/lqsamples2_jetPt50_MT300/WTo*

./CodexAnalyzer_Preselection_Jet50.exe  OutFiles_Jet50_200/TTJets.root ../ROOT80X/lqsamples2_jetPt50_MT300/TTJets.root

./CodexAnalyzer_Preselection_Jet50.exe  OutFiles_Jet50_200/VV.root ../ROOT80X/lqsamples2_jetPt50_MT300/ZZ*.root  ../ROOT80X/lqsamples2_jetPt50_MT300/WW*.root  ../ROOT80X/lqsamples2_jetPt50_MT300/WZ*.root

./CodexAnalyzer_Preselection_Jet50.exe  OutFiles_Jet50_200/SingleTop.root ../ROOT80X/lqsamples2_jetPt50_MT300/ST_*.root

./CodexAnalyzer_Preselection_Jet50.exe  OutFiles_Jet50_200/Data.root ../ROOT80X/lqsamples2_jetPt50_MT300/SingleMu.root

./CodexAnalyzer_Preselection_Jet50.exe  OutFiles_Jet50_200/Codex_1200.root  ../ROOT80X/lqsamples2_jetPt50_MT300/LQ1200_DM500_X550_Jet50_MT300.root





