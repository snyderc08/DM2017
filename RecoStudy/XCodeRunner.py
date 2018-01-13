import os

import argparse
import logging
import os
import shutil
import subprocess
import sys
import re
import subprocess

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

preName='NewOutFiles_'
dirName='%s%s'%(preName,args.codex)


SingleMuLoc='/Users/abdollah1/GIT_abdollah110/DM2017/ROOT80X/SampleLQ2/'


if not os.path.exists(dirName):
    os.makedirs(dirName)

#os.system("cp CodexAnalyzer_%s.cc %s/."%(args.codex,dirName))
#os.system("./Make.sh CodexAnalyzer_%s.cc"%args.codex)



Input=[
['DYJetsToLL.root','DYJetsToLL_M-50_HT*.root'],
['WJetsToLNu.root','WJetsToLNu*.root','WTo*root'],
['TTJets.root','TTJets.root'],
['VV.root','ZZ*.root','WZ*.root','WW*.root'],
['SingleTop.root','ST_*.root'],
['Data.root','SingleMu.root']
]



outF=open('out%s.txt'%dirName,'w')


outF.write("\n ./Make.sh %s.cc"%args.codex)
outF.write("\n cp %s.cc %s/."%(args.codex,dirName))
outF.write("\n cp out%s.txt %s/."%(dirName,dirName))


for sam in range(0,len(Input)):
    
    
    

    if len(Input[sam])==2: outF.write("\n./%s.exe   %s/%s      %s%s "%(args.codex,dirName,Input[sam][0],SingleMuLoc, Input[sam][1] ))
    
    if len(Input[sam])==3: outF.write("\n./%s.exe   %s/%s    %s%s %s%s"%(args.codex,dirName,Input[sam][0],SingleMuLoc, Input[sam][1], SingleMuLoc,Input[sam][2] ))

    if len(Input[sam])==4: outF.write("\n./%s.exe   %s/%s  %s%s %s%s %s%s"%(args.codex,dirName,Input[sam][0],SingleMuLoc, Input[sam][1], SingleMuLoc,Input[sam][2], SingleMuLoc,Input[sam][3] ))


outF.close()

print "Run the following line\n"
print "source out%s.txt"%dirName
                
#
#
#os.system("cp out%s.txt %s/."%(dirName,dirName))
##myscope = {}
##execfile('Step1_JetToMuFR_Data.py')
#subprocess.check_call('./CodexAnalyzer_Preselection.exe   NewOutFiles_Preselection/Data.root      /Users/abdollah1/GIT_abdollah110/DM2017/ROOT80X/SampleLQ2/SingleMu.root')
##exec(open("outNewOutFiles_Preselection.txt").read(), globals())
#
