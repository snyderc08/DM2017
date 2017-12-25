import os

import argparse
import logging
import os
import shutil
import subprocess
import sys
import re

parser = argparse.ArgumentParser(description='Process some integers.')

#parser.add_argument('integers', metavar='N', type=int, nargs='+',
#                    help='an integer for the accumulator')
#parser.add_argument('--sum', dest='accumulate', action='store_const',
#                    const=sum, default=max,
#                    help='sum the integers (default: find the max)')

parser.add_argument('SingleMuon', action='store_true',default='SingleMuon',
                    help="Which dataset")
parser.add_argument('-i','--in',dest='codex', default='CodexAnalyzer_Preselection',
                    help="Provide a code name")

args = parser.parse_args()
print args.codex

if not os.path.exists('OutFiles_%s'%args.codex):
    os.makedirs('OutFiles_%s'%args.codex)

os.system("cp %s.cc OutFiles_%s/."%(args.codex,args.codex))



Input=[
['DYJetsToLL.root','DYJetsToLL_M-50_HT*.root'],
['WJetsToLNu.root','WJetsToLNu*.root','WTo*root'],
['TTJets.root','TTJets.root'],
['VV.root','ZZ*.root','WZ*.root','WW*.root'],
['SingleTop.root','ST_*.root'],
['Data.root','SingleMu.root']
]




./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/DYJetsToLL.root ../ROOT80X/SampleLQ2/DYJetsToLL_M-50_HT*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/WJetsToLNu.root ../ROOT80X/SampleLQ2/WJetsToLNu*.root  ../ROOT80X/WMASS/W*root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/TTJets.root ../ROOT80X/SampleLQ2/TTJets.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/VV.root ../ROOT80X/SampleLQ2/ZZ*.root  ../ROOT80X/SampleLQ2/WW*.root  ../ROOT80X/SampleLQ2/WZ*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/SingleTop.root ../ROOT80X/SampleLQ2/ST_*.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/Data.root ../ROOT80X/SampleLQ2/SingleMu.root

./CodexAnalyzer_Preselection.exe  OutFiles_PreSelection/Codex_1200.root ../ROOT80X/PrivateSample/Codex_LQ1200_DM_500_X_550.root






#
#cp CodexAnalyzer_Preselection.*   OutFiles_PreSelection/.





