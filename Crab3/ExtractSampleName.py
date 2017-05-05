import os


def print_Signal(File):
    inputfile=open(File,'r')
    for line in inputfile.readlines():
        
        if (line[0] == "#"): continue
        if (line[0] == "\n"): continue
        if (line[0] != "/"): continue

        splitLine=line.split()
        sampleName_tmp1=line.replace("/","",1).partition("/")[0]
        sampleName_tmp2=sampleName_tmp1.replace("_TuneCUETP8M1_13TeV-madgraph","")
        sampleName=sampleName_tmp2.replace("_Codex","")
        newLine=line.replace("\n","")
        
        
        print 'config.General.requestName = "%s"'%sampleName
        print 'config.Data.inputDataset = "%s"'%newLine
        print 'submit(config)'
        print "\n"



def print_Data(File):
    inputfile=open(File,'r')
    for line in inputfile.readlines():
        
        if (line[0] == "#"): continue
        if (line[0] == "\n"): continue
        if (line[0] != "/"): continue
        
        splitLine=line.split()
        sampleName_tmp1=line.replace("/","",2).partition("/")[0]
        sampleName=sampleName_tmp1.replace("Run","_Run")
        newLine=line.replace("\n","")
        
        
        print 'config.General.requestName = "%s"'%sampleName
        print 'config.Data.inputDataset = "%s"'%newLine
        print 'submit(config)'
        print "\n"


def print_BG(File):
    inputfile=open(File,'r')
    for line in inputfile.readlines():
        
        if (line[0] == "#"): continue
        if (line[0] == "\n"): continue
        if (line[0] != "/"): continue
        
        splitLine=line.split()
        sampleName_tmp1=line.replace("/","",2).partition("/")[0]
        sampleName=sampleName_tmp1.replace("RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6","").replace("_13TeV-madgraphMLM-pythia8","").replace("_13TeV-pythia8","").replace("_TuneCUETP8M1","").replace("-powheg-pythia8_TuneCUETP8M1","").replace("_13TeV-amcatnloFXFX-pythia8","_FXFX")
        newLine=line.replace("\n","")
        
        
        print 'config.General.requestName = "%s"'%sampleName
        print 'config.Data.inputDataset = "%s"'%newLine
        print 'submit(config)'
        print "\n"








#print_Signal('2017SignalSamples.txt')
#print_Data('2017DataSamples.txt')
#print_BG('2017BGSamples_Total.txt')
#print_BG('2017BGSamples_FXFX.txt')
print_Signal('2017PrivateSamples.txt')


