./Make.sh CodexAnalyzer_Preselection.cc


cp CodexAnalyzer_Preselection.* OutFiles_Excess_Jet50MT300/.

./CodexAnalyzer_Preselection.exe  OutFiles_Excess_Jet50MT300/DYJetsToLL.root ../ROOT80X/lqsamples2_jetPt50_MT300/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection.exe  OutFiles_Excess_Jet50MT300/WJetsToLNu.root ../ROOT80X/lqsamples2_jetPt50_MT300/WJets*.root   ../ROOT80X/lqsamples2_jetPt50_MT300/WTo*

./CodexAnalyzer_Preselection.exe  OutFiles_Excess_Jet50MT300/TTJets.root ../ROOT80X/lqsamples2_jetPt50_MT300/TTJets.root

./CodexAnalyzer_Preselection.exe  OutFiles_Excess_Jet50MT300/VV.root ../ROOT80X/lqsamples2_jetPt50_MT300/ZZ*.root  ../ROOT80X/lqsamples2_jetPt50_MT300/WW*.root  ../ROOT80X/lqsamples2_jetPt50_MT300/WZ*.root

./CodexAnalyzer_Preselection.exe  OutFiles_Excess_Jet50MT300/SingleTop.root ../ROOT80X/lqsamples2_jetPt50_MT300/ST_*.root

./CodexAnalyzer_Preselection.exe  OutFiles_Excess_Jet50MT300/Data.root ../ROOT80X/lqsamples2_jetPt50_MT300/SingleMu.root

./CodexAnalyzer_Preselection.exe  OutFiles_Excess_Jet50MT300/Codex_1200.root  ../ROOT80X/lqsamples2_jetPt50_MT300/LQ1200_DM500_X550_Jet50_MT300.root





