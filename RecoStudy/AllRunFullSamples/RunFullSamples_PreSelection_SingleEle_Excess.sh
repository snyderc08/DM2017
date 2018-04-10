./Make.sh CodexAnalyzer_Preselection_SingleEle.cc



cp CodexAnalyzer_Preselection_SingleEle*   OutFiles_PreSelection_SampleLQ1_Excess/.
./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1_Excess/DYJetsToLL.root ../ROOT80X/SampleLQ1/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1_Excess/WJetsToLNu.root ../ROOT80X/SampleLQ1/WJets*.root ../ROOT80X/WMASS_ENu/W*root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1_Excess/TTJets.root ../ROOT80X/SampleLQ1/TTJets.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1_Excess/VV.root ../ROOT80X/SampleLQ1/ZZ*.root  ../ROOT80X/SampleLQ1/WW*.root  ../ROOT80X/SampleLQ1/WZ*.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1_Excess/SingleTop.root ../ROOT80X/SampleLQ1/ST_*.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1_Excess/Data.root ../ROOT80X/SampleLQ1/SingleEle.root




