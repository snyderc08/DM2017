./Make.sh CodexAnalyzer_Preselection_SingleEle.cc



cp CodexAnalyzer_Preselection_SingleEle*   OutFiles_PreSelection_SampleLQ1/.
./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1/DYJetsToLL.root ../ROOT80X/SampleLQ1/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1/WJetsToLNu.root ../ROOT80X/SampleLQ1/WJetsToLNu_HT-*.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1/TTJets.root ../ROOT80X/SampleLQ1/TTJets.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1/VV.root ../ROOT80X/SampleLQ1/ZZ*.root  ../ROOT80X/SampleLQ1/WW*.root  ../ROOT80X/SampleLQ1/WZ*.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1/SingleTop.root ../ROOT80X/SampleLQ1/ST_*.root

./CodexAnalyzer_Preselection_SingleEle.exe  OutFiles_PreSelection_SampleLQ1/Data.root ../ROOT80X/SampleLQ1/SingleEle.root




