#!/bin/bash
echo "I'm here!"

CLUSTER=$1
PROCESS=$2
RUNPATH=$3
OUTPATH=$4

echo "input parameters: cluster, process, run path, out path, sample name" $1 $2 $3 $4

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc530
eval `scramv1 project CMSSW CMSSW_8_0_11`
mv InputSamples.txt CMSSW_8_0_11/src/
mv Skimmer* CMSSW_8_0_11/src/
mv Makefile CMSSW_8_0_11/src/

cd CMSSW_8_0_11/src
eval `scramv1 runtime -sh`

echo "CMSSW: "$CMSSW_BASE

echo $PWD

SplitingNumber=10
DataSetArray=($(cat InputSamples.txt)) # array of the input datadets
echo ${DataSetArray[$PROCESS / $SplitingNumber]}
DataSetName=${DataSetArray[$PROCESS / $SplitingNumber]}
rootNumber=$(($PROCESS % $SplitingNumber))

########### compile the Skimmer
make

ls


########### loop over all root file in a dataset directory
#xrdfs root://cmseos.fnal.gov ls "/eos/uscms/store/user/abdollah/Moriond17/"$DataSetName | grep $rootNumber.root | while read FullDataSetName
xrdfs root://cmseos.fnal.gov ls "/eos/uscms/store/user/snyderc3/DM_Electron/"$DataSetName | grep $rootNumber.root | while read FullDataSetName

############  Here is where the Skimmer is running     ############
do
 file=`echo $FullDataSetName`
 #ShortName=${file##*Moriond17}  # This removes all the string before Moriond17 (including Moriond17)
 ShortName=${file##*DM_Electron} 
 echo "Here is the short Name   ------>" $ShortName
 ./Skimmer  $ShortName
done
############  Here is where the Skimmer ends          ############


IFS="/"
set $DataSetName
OutName=$4$6$rootNumber".root"  # this makes the 4th and 6th pieces of the
echo $OutName
hadd -f $OutName "skimed_"*.root


##########  remove the unneccesat files
rm skim*root  Skimmer.cc  Skimmer.h  Makefile  InputSamples.txt
echo "Done execution ..."

echo "Transferring"

xrdcp $OutName root://cmseos.fnal.gov//store/user/snyderc3/$OutName

echo "Transferred" $OutName
