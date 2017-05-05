from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.workArea = 'MC_PrivateSignal'
config.section_('JobType')
config.JobType.psetName = 'run_mc_80X.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['ggtree_mc.root']
config.JobType.inputFiles = ['Summer16_23Sep2016AllV4_DATA.db','Summer16_23Sep2016V4_MC.db']
config.section_('Data')
config.Data.unitsPerJob = 1
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.outLFNDirBase = '/store/user/abdollah/Moriond17/SignalPrivate/'
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
    config.General.workArea = 'MC_PrivateSignal'

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



    config.General.requestName = "DM_1000_DM_350_X_385"
    config.Data.inputDataset = "/DM_Codex_1000_DM_350_X_385/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1000_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_1000_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1100_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_1100_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1000_DM_450_X_495"
    config.Data.inputDataset = "/DM_Codex_1000_DM_450_X_495/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1100_DM_400_X_440"
    config.Data.inputDataset = "/DM_Codex_1100_DM_400_X_440/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1100_DM_350_X_385"
    config.Data.inputDataset = "/DM_Codex_1100_DM_350_X_385/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1200_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_1200_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1100_DM_500_X_550"
    config.Data.inputDataset = "/DM_Codex_1100_DM_500_X_550/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1200_DM_400_X_440"
    config.Data.inputDataset = "/DM_Codex_1200_DM_400_X_440/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1200_DM_350_X_385"
    config.Data.inputDataset = "/DM_Codex_1200_DM_350_X_385/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1200_DM_550_X_595"
    config.Data.inputDataset = "/DM_Codex_1200_DM_550_X_595/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1200_DM_450_X_495"
    config.Data.inputDataset = "/DM_Codex_1200_DM_450_X_495/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1300_DM_350_X_385"
    config.Data.inputDataset = "/DM_Codex_1300_DM_350_X_385/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1300_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_1300_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1300_DM_450_X_495"
    config.Data.inputDataset = "/DM_Codex_1300_DM_450_X_495/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1300_DM_400_X_440"
    config.Data.inputDataset = "/DM_Codex_1300_DM_400_X_440/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1300_DM_600_X_660"
    config.Data.inputDataset = "/DM_Codex_1300_DM_600_X_660/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1300_DM_500_X_550"
    config.Data.inputDataset = "/DM_Codex_1300_DM_500_X_550/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1400_DM_350_X_385"
    config.Data.inputDataset = "/DM_Codex_1400_DM_350_X_385/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1400_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_1400_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1400_DM_450_X_495"
    config.Data.inputDataset = "/DM_Codex_1400_DM_450_X_495/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1400_DM_400_X_440"
    config.Data.inputDataset = "/DM_Codex_1400_DM_400_X_440/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1400_DM_550_X_605"
    config.Data.inputDataset = "/DM_Codex_1400_DM_550_X_605/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1400_DM_500_X_550"
    config.Data.inputDataset = "/DM_Codex_1400_DM_500_X_550/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_1500_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1400_DM_650_X_715"
    config.Data.inputDataset = "/DM_Codex_1400_DM_650_X_715/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_400_X_440"
    config.Data.inputDataset = "/DM_Codex_1500_DM_400_X_440/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_350_X_385"
    config.Data.inputDataset = "/DM_Codex_1500_DM_350_X_385/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_500_X_550"
    config.Data.inputDataset = "/DM_Codex_1500_DM_500_X_550/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_450_X_495"
    config.Data.inputDataset = "/DM_Codex_1500_DM_450_X_495/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_600_X_660"
    config.Data.inputDataset = "/DM_Codex_1500_DM_600_X_660/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_550_X_605"
    config.Data.inputDataset = "/DM_Codex_1500_DM_550_X_605/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_700_X_770"
    config.Data.inputDataset = "/DM_Codex_1500_DM_700_X_770/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_1500_DM_650_X_715"
    config.Data.inputDataset = "/DM_Codex_1500_DM_650_X_715/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_800_DM_350_X_385"
    config.Data.inputDataset = "/DM_Codex_800_DM_350_X_385/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_800_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_800_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_900_DM_400_X_440"
    config.Data.inputDataset = "/DM_Codex_900_DM_400_X_440/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)


    config.General.requestName = "DM_900_DM_300_X_330"
    config.Data.inputDataset = "/DM_Codex_900_DM_300_X_330/mnaseri-MiniAODv2-b59cb78551aff289588aa5c69db4a3a1/USER"
    submit(config)






