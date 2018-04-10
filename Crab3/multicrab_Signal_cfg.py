from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.workArea = 'MC_Signal'
config.section_('JobType')
config.JobType.psetName = 'run_mc_80X.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['ggtree_mc.root']
config.JobType.inputFiles = ['Summer16_23Sep2016AllV4_DATA.db','Summer16_23Sep2016V4_MC.db']
config.section_('Data')
config.Data.unitsPerJob = 1
#config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.outLFNDirBase = '/store/user/abdollah/Moriond17/Signal/'
config.Data.allowNonValidInputDataset = True
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T3_US_FNALLPC'



if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand
    from CRABClient.ClientExceptions import ClientException
    from httplib import HTTPException

    # We want to put all the CRAB project directories from the tasks we submit here into one common directory.
    # That's why we need to set this parameter (here or above in the configuration file, it does not matter, we will not overwrite it).
    config.General.workArea = 'MC_Signal'

    def submit(config):
        try:
            crabCommand('submit', config = config)
        except HTTPException as hte:
            print "Failed submitting task: %s" % (hte.headers)
        except ClientException as cle:
            print "Failed submitting task: %s" % (cle)

    #############################################################################################
    ## From now on that's what users should modify: this is the a-la-CRAB2 configuration part. ##
    #############################################################################################

    config.General.requestName = "DarkMatter_LQ800_DM_300_X_330"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ800_DM_300_X_330_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)
    
    
    config.General.requestName = "DarkMatter_LQ900_DM_350_X_385"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ900_DM_350_X_385_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)
    


    config.General.requestName = "DarkMatter_LQ1000_DM_400_X_440"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1000_DM_400_X_440_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)



    config.General.requestName = "DarkMatter_LQ1100_DM_450_X_495"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1100_DM_450_X_495_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)



    config.General.requestName = "DarkMatter_LQ1200_DM_500_X_550"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1200_DM_500_X_550_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)



    config.General.requestName = "DarkMatter_LQ1300_DM_550_X_605"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1300_DM_550_X_605_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1400_DM_600_X_660"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1400_DM_600_X_660_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)



    config.General.requestName = "DarkMatter_LQ1500_DM_650_X_715"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1500_DM_650_X_715_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)







hadd DIR/WWTo2L2Nu_powheg.root   crab_WWTo2L2Nu_powheg*root
hadd DIR/WWTo4Q_powheg.root   crab_WWTo4Q_powheg*root
hadd DIR/WWToLNuQQ_powheg.root   crab_WWToLNuQQ_powheg*root
hadd DIR/WZTo1L3Nu_amcatnloFXFX.root   crab_WZTo1L3Nu_amcatnloFXFX*root
hadd DIR/WZTo2L2Q_amcatnloFXFX.root   crab_WZTo2L2Q_amcatnloFXFX*root
hadd DIR/WZTo2Q2Nu_amcatnloFXFX.root   crab_WZTo2Q2Nu_amcatnloFXFX*root
hadd DIR/WZTo3LNu_powheg.root   crab_WZTo3LNu_powheg*root
hadd DIR/WZToLNu2Q_powheg.root   crab_WZToLNu2Q_powheg*root
hadd DIR/ZZTo2L2Nu_powheg.root   crab_ZZTo2L2Nu_powheg*root
hadd DIR/ZZTo2L2Q_powheg.root   crab_ZZTo2L2Q_powheg*root
hadd DIR/ZZTo2Q2Nu_powheg.root   crab_ZZTo2Q2Nu_powheg*root
hadd DIR/ZZTo4L_powheg.root   crab_ZZTo4L_powheg*root
hadd DIR/ZZTo4Q_amcatnloFXFX.root   crab_ZZTo4Q_amcatnloFXFX*root


hadd  DIR/DYJetsToLL_M-50_HT-100to200.root  crab_DYJetsToLL_M-50_HT-100to200*.root
hadd  DIR/DYJetsToLL_M-50_HT-1200to2500.root  crab_DYJetsToLL_M-50_HT-1200to2500*.root
hadd  DIR/DYJetsToLL_M-50_HT-200to400.root  crab_DYJetsToLL_M-50_HT-200to400*.root
hadd  DIR/DYJetsToLL_M-50_HT-2500toInf.root  crab_DYJetsToLL_M-50_HT-2500toInf*.root
hadd  DIR/DYJetsToLL_M-50_HT-400to600.root  crab_DYJetsToLL_M-50_HT-400to600*.root
hadd  DIR/DYJetsToLL_M-50_HT-600to800.root  crab_DYJetsToLL_M-50_HT-600to800*.root
hadd  DIR/DYJetsToLL_M-50_HT-70to100.root  crab_DYJetsToLL_M-50_HT-70to100*.root
hadd  DIR/DYJetsToLL_M-50_HT-800to1200.root  crab_DYJetsToLL_M-50_HT-800to1200*.root

hadd  DIR/ST_t-channel_antitop.root  crab_ST_t-channel_antitop_4f_inclusiveDecays*.root
hadd  DIR/ST_t-channel_top.root  crab_ST_t-channel_top_4f_inclusiveDecays*.root
hadd  DIR/ST_tW_antitop_5f.root  crab_ST_tW_antitop_5f_inclusiveDecays*.root
hadd  DIR/ST_tW_top_5f.root  crab_ST_tW_top_5f_inclusiveDecays*.root
hadd  DIR/ST_s_channel.root  crab_ST_s-channel_4f_leptonDecays_13TeV*root
hadd  DIR/TTJets.root  crab_TT*.root

hadd  DIR/WJetsToLNu_HT-100to200.root  crab_WJetsToLNu_HT-100To200*.root
hadd  DIR/WJetsToLNu_HT-1200to2500.root  crab_WJetsToLNu_HT-1200To2500*.root
hadd  DIR/WJetsToLNu_HT-200to400.root  crab_WJetsToLNu_HT-200To400*.root
hadd  DIR/WJetsToLNu_HT-2500toInf.root  crab_WJetsToLNu_HT-2500ToInf*.root
hadd  DIR/WJetsToLNu_HT-400to600.root  crab_WJetsToLNu_HT-400To600*.root
hadd  DIR/WJetsToLNu_HT-600to800.root  crab_WJetsToLNu_HT-600To800*.root
hadd  DIR/WJetsToLNu_HT-70to100.root  crab_WJetsToLNu_HT-70To100*.root
hadd  DIR/WJetsToLNu_HT-800to1200.root  crab_WJetsToLNu_HT-800To1200*.root
hadd  DIR/WJetsToLNu.root  crab_WJetsToLNu-*.root  crab_WJetsToLNu_ext2-v10000*.root

hadd  DIR/QCD.root  crab_QCD_*.root

hadd DIR/WToMuNu_M-1000.root   *WToMuNu_M-1000_TuneCUETP8M1_13TeV-pythia8*root
hadd DIR/WToMuNu_M-100.root   *WToMuNu_M-100_TuneCUETP8M1_13TeV-pythia8*root
hadd DIR/WToMuNu_M-2000.root   *WToMuNu_M-2000_TuneCUETP8M1_13TeV-pythia8*root
hadd DIR/WToMuNu_M-200.root   *WToMuNu_M-200_TuneCUETP8M1_13TeV-pythia8*root
hadd DIR/WToMuNu_M-3000.root   *WToMuNu_M-3000_TuneCUETP8M1_13TeV-pythia8*root
hadd DIR/WToMuNu_M-500.root   *WToMuNu_M-500_TuneCUETP8M1_13TeV-pythia8*root




