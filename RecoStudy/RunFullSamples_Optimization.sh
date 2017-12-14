./Make.sh CodexAnalyzer_Optimization.cc


cp CodexAnalyzer_Optimization.*  OutFiles_Optimization/.

./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/DYJetsToLL.root ../ROOT80X/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/WJetsToLNu.root ../ROOT80X/WJetsToLNu_HT-*.root

./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/TTJets.root ../ROOT80X/TTJets.root

./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/VV.root ../ROOT80X/ZZ.root  ../ROOT80X/WW.root  ../ROOT80X/WZ.root

./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/SingleTop.root ../ROOT80X/ST_*.root

./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Data.root ../ROOT80X/SingleMu.root


./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_800.root ../ROOT80X/PrivateSample/Codex_LQ800_DM_300_X_330.root
./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_900.root ../ROOT80X/PrivateSample/Codex_LQ900_DM_350_X_385.root
./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_1000.root ../ROOT80X/PrivateSample/Codex_LQ1000_DM_400_X_440.root
./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_1100.root ../ROOT80X/PrivateSample/Codex_LQ1100_DM_450_X_495.root
./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root
./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_1300.root ../ROOT80X/PrivateSample/Codex_LQ1300_DM_550_X_605.root
./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_1400.root ../ROOT80X/PrivateSample/Codex_LQ1400_DM_600_X_660.root
./CodexAnalyzer_Optimization.exe  OutFiles_Optimization/Codex_1500.root ../ROOT80X/PrivateSample/Codex_LQ1500_DM_650_X_715.root




