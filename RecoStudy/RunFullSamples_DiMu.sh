./Make.sh CodexAnalyzer_DiMu.cc





cp CodexAnalyzer_DiMu.*   OutFiles_DiMu/.
./CodexAnalyzer_DiMu.exe  OutFiles_DiMu/WJetsToLNu.root ../ROOT80X/DiMu/WJetsToLNu_HT-*.root

./CodexAnalyzer_DiMu.exe  OutFiles_DiMu/TTJets.root ../ROOT80X/DiMu/TTJets.root

./CodexAnalyzer_DiMu.exe  OutFiles_DiMu/VV.root ../ROOT80X/DiMu/ZZ.root  ../ROOT80X/DiMu/WW.root  ../ROOT80X/DiMu/WZ.root

./CodexAnalyzer_DiMu.exe  OutFiles_DiMu/SingleTop.root ../ROOT80X/DiMu/ST_*.root

./CodexAnalyzer_DiMu.exe  OutFiles_DiMu/Data.root ../ROOT80X/DiMu/SingleMu.root



./CodexAnalyzer_DiMu.exe  OutFiles_DiMu/DYJetsToLL.root ../ROOT80X/DiMu/DYJetsToLL_M-50_HT*.root
