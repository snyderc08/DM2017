./Make.sh CodexAnalyzer_QCDEstim_Data.cc

./CodexAnalyzer_QCDEstim_Data.exe  OutFiles_QCD/DYJetsToLL.root ../Skim/DIR_MET80/DYJetsToLL*.root
./CodexAnalyzer_QCDEstim_Data.exe  OutFiles_QCD/TTJets.root ../Skim/DIR_MET80/TTJets.root
./CodexAnalyzer_QCDEstim_Data.exe  OutFiles_QCD/WJetsToLNu.root ../Skim/DIR_MET80/WJetsToLNu*.root
./CodexAnalyzer_QCDEstim_Data.exe  OutFiles_QCD/VV.root ../Skim/DIR_MET80/ZZ.root  ../Skim/DIR_MET80/WW.root  ../Skim/DIR_MET80/WZ.root
./CodexAnalyzer_QCDEstim_Data.exe  OutFiles_QCD/SingleTop.root ../Skim/DIR_MET80/ST_*.root

./CodexAnalyzer_QCDEstim_Data.exe  OutFiles_QCD/Data.root ../Skim/DIR_MET80/SingleMu.root


