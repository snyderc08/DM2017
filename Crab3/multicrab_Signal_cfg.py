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
config.Data.outLFNDirBase = '/store/user/abdollah/Moriond17/MC/'
config.Data.allowNonValidInputDataset = True
config.section_('User')
config.User.voGroup = 'becms'
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



    config.General.requestName = "DarkMatter_LQ1000_DM_400_X_420"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1000_DM_400_X_420_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1000_DM_400_X_440"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1000_DM_400_X_440_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1000_DM_400_X_460"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1000_DM_400_X_460_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1100_DM_450_X_475"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1100_DM_450_X_475_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1100_DM_450_X_495"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1100_DM_450_X_495_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1100_DM_450_X_520"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1100_DM_450_X_520_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1200_DM_500_X_525"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1200_DM_500_X_525_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1200_DM_500_X_550"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1200_DM_500_X_550_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1200_DM_500_X_575"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1200_DM_500_X_575_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1200_DM_600_X_600"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1200_DM_600_X_600_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1300_DM_550_X_580"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1300_DM_550_X_580_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1300_DM_550_X_605"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1300_DM_550_X_605_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1300_DM_550_X_635"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1300_DM_550_X_635_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1300_DM_600_X_600"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1300_DM_600_X_600_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1400_DM_600_X_600"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1400_DM_600_X_600_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1400_DM_600_X_630"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1400_DM_600_X_630_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1400_DM_600_X_660"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1400_DM_600_X_660_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1400_DM_600_X_690"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1400_DM_600_X_690_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1500_DM_600_X_600"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1500_DM_600_X_600_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1500_DM_650_X_685"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1500_DM_650_X_685_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1500_DM_650_X_715"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1500_DM_650_X_715_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1500_DM_650_X_750"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1500_DM_650_X_750_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1600_DM_600_X_600"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1600_DM_600_X_600_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1600_DM_700_X_735"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1600_DM_700_X_735_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1600_DM_700_X_770"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1600_DM_700_X_770_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1600_DM_700_X_805"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1600_DM_700_X_805_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1700_DM_600_X_600"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1700_DM_600_X_600_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1700_DM_750_X_790"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1700_DM_750_X_790_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1700_DM_750_X_825"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1700_DM_750_X_825_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1700_DM_750_X_865"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1700_DM_750_X_865_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1800_DM_600_X_600"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1800_DM_600_X_600_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1800_DM_800_X_840"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1800_DM_800_X_840_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1800_DM_800_X_880"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1800_DM_800_X_880_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1800_DM_800_X_920"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1800_DM_800_X_920_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1900_DM_850_X_895"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1900_DM_850_X_895_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1900_DM_850_X_935"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1900_DM_850_X_935_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ1900_DM_850_X_975"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ1900_DM_850_X_975_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ2000_DM_900_X_990"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ2000_DM_900_X_990_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ800_DM_300_X_330"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ800_DM_300_X_330_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)


    config.General.requestName = "DarkMatter_LQ900_DM_350_X_385"
    config.Data.inputDataset = "/DarkMatter_Codex_LQ900_DM_350_X_385_TuneCUETP8M1_13TeV-madgraph/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM"
    submit(config)
    



