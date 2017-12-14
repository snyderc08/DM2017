./Make.sh CodexAnalyzer_Preselection_2Mu1Ele.cc


cp CodexAnalyzer_Preselection_2Mu1Ele.*   OutFiles_DiMuOneEle/.
./CodexAnalyzer_Preselection_2Mu1Ele.exe  OutFiles_DiMuOneEle/WJetsToLNu.root ../ROOT80X/DiMu/WJetsToLNu_HT-*.root

./CodexAnalyzer_Preselection_2Mu1Ele.exe  OutFiles_DiMuOneEle/TTJets.root ../ROOT80X/DiMu/TTJets.root

./CodexAnalyzer_Preselection_2Mu1Ele.exe  OutFiles_DiMuOneEle/VV.root ../ROOT80X/DiMu/ZZ*.root  ../ROOT80X/DiMu/WW*.root  ../ROOT80X/DiMu/WZ*.root

./CodexAnalyzer_Preselection_2Mu1Ele.exe  OutFiles_DiMuOneEle/SingleTop.root ../ROOT80X/DiMu/ST_*.root

./CodexAnalyzer_Preselection_2Mu1Ele.exe  OutFiles_DiMuOneEle/Data.root ../ROOT80X/DiMu/SingleMu.root

./CodexAnalyzer_Preselection_2Mu1Ele.exe  OutFiles_DiMuOneEle/DYJetsToLL.root ../ROOT80X/DiMu/DYJetsToLL_M-50_HT*.root



