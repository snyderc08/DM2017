./Make.sh CodexAnalyzer_BTagEff.cc

cp CodexAnalyzer_BTagEff*  OutFiles_BTagSF/.
./CodexAnalyzer_BTagEff.exe  OutFiles_BTagSF/DYJetsToLL.root ../ROOT80X/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_BTagEff.exe  OutFiles_BTagSF/WJetsToLNu.root ../ROOT80X/WJetsToLNu_HT-*.root

./CodexAnalyzer_BTagEff.exe  OutFiles_BTagSF/TTJets.root ../ROOT80X/TTJets.root

./CodexAnalyzer_BTagEff.exe  OutFiles_BTagSF/VV.root ../ROOT80X/ZZ.root  ../ROOT80X/WW.root  ../ROOT80X/WZ.root

./CodexAnalyzer_BTagEff.exe  OutFiles_BTagSF/SingleTop.root ../ROOT80X/ST_*.root

./CodexAnalyzer_BTagEff.exe  OutFiles_BTagSF/Data.root ../ROOT80X/SingleMu.root



