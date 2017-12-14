./Make.sh CodexAnalyzer_DiEle.cc





cp CodexAnalyzer_DiEle.* OutFiles_DiEle/.
./CodexAnalyzer_DiEle.exe  OutFiles_DiEle/WJetsToLNu.root ../ROOT80X/DiEle/WJetsToLNu_HT-*.root

./CodexAnalyzer_DiEle.exe  OutFiles_DiEle/TTJets.root ../ROOT80X/DiEle/TTJets.root

./CodexAnalyzer_DiEle.exe  OutFiles_DiEle/VV.root ../ROOT80X/DiEle/ZZ_pythia.root  ../ROOT80X/DiEle/WW_pythia.root  ../ROOT80X/DiEle/WZ_pythia.root

./CodexAnalyzer_DiEle.exe  OutFiles_DiEle/SingleTop.root ../ROOT80X/DiEle/ST_*.root

./CodexAnalyzer_DiEle.exe  OutFiles_DiEle/Data.root ../ROOT80X/DiEle/Data.root



./CodexAnalyzer_DiEle.exe  OutFiles_DiEle/DYJetsToLL.root ../ROOT80X/DiEle/DYJetsToLL_M-50_HT*.root

