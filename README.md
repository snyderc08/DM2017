# DM2017
Git repository for searchf or Dark Matter in 2017

Crab3 files belong in cd CMSSW_8_0_26_patch1 and follow the directions for set up here:

https://github.com/cmkuo/ggAnalysis 

The Crab is the first step in the analysis and generates the n-tuples for data and MC. These can be large so they are stored in your eos space. The extra files there that aren't in Abdollah's should be in the environment once it is set up but if not they are here. 

Once those are done you have to skim. I put my skimming files in the folder called Skim3 just because one of the files refers to the name of the folder it is in and I was trying to make it work. Condor had issues so had to modify it from working in nobackup to working in the eos. These new files in Skim3 should account for that. 

To start the skimming process you need to open up 
Skimmer.cc (the .cc code where the skimming is defined here)
Skimmer.h (header file)
Makefile (used to compile Skimmer.cc)
Submit_batch.jdl  (where condor parameters are defined. Note: you need to change the location of the runPath!!)
Submit_run2.sh   (instruct condor how to run the jobs)
InputSamples.txt  (where the list of all samples are stored. More info at  snagSample.py)

I have different Skimmer.cc's, InputSamples.txt's, Submit_batch.jdl's and Submit_run2.sh's depending on if I am skimming data, mc or signal. The reason is because data is in my eos, MC is in Abdollah's eos, and the signal samples are in Orgho's eos. If you want to skim the first step is to modify the Skimmer.cc. If I am doing data I copy everything in Skimmer_Data_mine.cc into Skimmer.cc. Check to make sure the cuts are what you want. In my case I have a pfmet cut, electron cut and a jet cut but you might want two electron cuts or something else I just have it called data because it has the location of my data files in the code. Similarly if you want to do MC or signal you copy the realating file into the Skimmer.cc and modify it such that the cuts are what you want. 

Once the Skimmer.cc is saved type make into the terminal to create Skimmer.h

The next step is to modify Submit_batch.jdl, Submit_run2.sh and InputSamples.txt in similar manner as done for the Skimmer.cc. You do not need to type make because Makefile is only for the skimmer. 

Now you are ready to submit by typing into terminal 

condor_submit Submit_batch.jdl

You can check on jobs by typing:

condor_q





