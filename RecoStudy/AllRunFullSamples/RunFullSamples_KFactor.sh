./Make.sh CodexAnalyzer_KFactor.cc

cp CodexAnalyzer_KFactor.*   OutFiles_LO/.

./CodexAnalyzer_KFactor.exe  OutFiles_LO/DYJetsToLL_LO.root ../ROOT80X/DYJetsToLL_M-50_HT*.root
./CodexAnalyzer_KFactor.exe  OutFiles_LO/WJetsToLNu_LO.root ../ROOT80X/WJetsToLNu_HT-*.root





#./CodexAnalyzer_KFactor.exe  OutFiles_FXFX/DYJetsToLL_FXFX.root ../ROOT80X/FXFX/DYJetsToLL*FXFX*.root
#./CodexAnalyzer_KFactor.exe  OutFiles_FXFX/WJetsToLNu_FXFX.root ../ROOT80X/FXFX/WJetsToLNu*FXFX*.root

