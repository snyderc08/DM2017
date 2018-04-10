./Make.sh CodexAnalyzer_Preselection_EtaMu2p0.cc


cp CodexAnalyzer_Preselection_EtaMu2p0.*   OutFiles_PreSelection_MuEta2p0/.

./CodexAnalyzer_Preselection_EtaMu2p0.exe  OutFiles_PreSelection_MuEta2p0/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection_EtaMu2p0.exe  OutFiles_PreSelection_MuEta2p0/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root  ../ROOT80X/WMASS/W*root

./CodexAnalyzer_Preselection_EtaMu2p0.exe  OutFiles_PreSelection_MuEta2p0/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Preselection_EtaMu2p0.exe  OutFiles_PreSelection_MuEta2p0/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Preselection_EtaMu2p0.exe  OutFiles_PreSelection_MuEta2p0/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Preselection_EtaMu2p0.exe  OutFiles_PreSelection_MuEta2p0/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Preselection_EtaMu2p0.exe  OutFiles_PreSelection_MuEta2p0/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root



