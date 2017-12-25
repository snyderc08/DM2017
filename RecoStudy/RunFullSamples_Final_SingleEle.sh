./Make.sh CodexAnalyzer_FinalSelection_SingleEle.cc



cp CodexAnalyzer_FinalSelection_SingleEle*   OutFiles_FinalSelection_SampleLQ1/.
./CodexAnalyzer_FinalSelection_SingleEle.exe  OutFiles_FinalSelection_SampleLQ1/DYJetsToLL.root ../ROOT80X/SampleLQ1/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_FinalSelection_SingleEle.exe  OutFiles_FinalSelection_SampleLQ1/WJetsToLNu.root ../ROOT80X/SampleLQ1/WJets*.root ../ROOT80X/SampleLQ1/W*root

./CodexAnalyzer_FinalSelection_SingleEle.exe  OutFiles_FinalSelection_SampleLQ1/TTJets.root ../ROOT80X/SampleLQ1/TTJets.root

./CodexAnalyzer_FinalSelection_SingleEle.exe  OutFiles_FinalSelection_SampleLQ1/VV.root ../ROOT80X/SampleLQ1/ZZ*.root  ../ROOT80X/SampleLQ1/WW*.root  ../ROOT80X/SampleLQ1/WZ*.root

./CodexAnalyzer_FinalSelection_SingleEle.exe  OutFiles_FinalSelection_SampleLQ1/SingleTop.root ../ROOT80X/SampleLQ1/ST_*.root

./CodexAnalyzer_FinalSelection_SingleEle.exe  OutFiles_FinalSelection_SampleLQ1/Data.root ../ROOT80X/SampleLQ1/SingleEle.root




