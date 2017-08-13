import ROOT
from ROOT import *
import array


Binning = array.array("d",[0,2000])

def ShowYield(File,categoriy,sig,channel,XS):
    file=TFile(File,'r')
    
    
    Data=file.Get(categoriy+"/"+"data_obs")
    Data_r=Data.Rebin(len(Binning)-1,"",Binning)
    data_yield= round(Data_r.GetBinContent(1),1)
    
    QCD=file.Get(categoriy+"/"+"QCD")
    Norm_QCD=0;
    Error_QCD=0;
    for i in range(QCD.GetXaxis().GetNbins()):
        Norm_QCD +=QCD.GetBinContent(i+1)
        Error_QCD +=pow(QCD.GetBinError(i+1),1)
    QCD_r=QCD.Rebin(len(Binning)-1,"",Binning)
    qcd_yield= round(QCD_r.GetBinContent(1),1)
    qcd_error= round(QCD_r.GetBinError(1),1)

    TT=file.Get(categoriy+"/"+"TT")
    Norm_TT=0;
    Error_TT=0;
    for i in range(TT.GetXaxis().GetNbins()):
        Norm_TT +=TT.GetBinContent(i+1)
        Error_TT +=pow(TT.GetBinError(i+1),1)
    TT_r=TT.Rebin(len(Binning)-1,"",Binning)
    tt_yield= round(TT_r.GetBinContent(1),1)
    tt_error= round(TT_r.GetBinError(1),1)



    SingleT=file.Get(categoriy+"/"+"SingleTop")
    Norm_SingleT=0;
    Error_SingleT=0;
    for i in range(SingleT.GetXaxis().GetNbins()):
        Norm_SingleT +=SingleT.GetBinContent(i+1)
        Error_SingleT +=pow(SingleT.GetBinError(i+1),1)
    SingleT_r=SingleT.Rebin(len(Binning)-1,"",Binning)
    singlet_yield= round(SingleT_r.GetBinContent(1),1)
    singlet_error= round(SingleT_r.GetBinError(1),1)

    
    
    W=file.Get(categoriy+"/"+"W")
    VV=file.Get(categoriy+"/"+"VV")
    W.Add(VV)
    DYS=file.Get(categoriy+"/"+"ZTT")
    W.Add(DYS)
    Norm_W=0;
    Error_W=0;
    for i in range(W.GetXaxis().GetNbins()):
        Norm_W +=W.GetBinContent(i+1)
        Error_W +=pow(W.GetBinError(i+1),1)
    W_r=W.Rebin(len(Binning)-1,"",Binning)
    w_yield= round(W_r.GetBinContent(1),1)
    w_error= round(W_r.GetBinError(1),1)

    TotBKG=file.Get(categoriy+"/"+"TotalBkg")
    TotBKG_r=TotBKG.Rebin(len(Binning)-1,"",Binning)
    totbkg_yield= round(TotBKG_r.GetBinContent(1),1)
    totbkg_error= round(TotBKG_r.GetBinError(1),1)
    Norm_Tot= Norm_W+Norm_TT+Norm_QCD+Norm_SingleT
    Error_Tot= pow ( pow( Error_W, 2)+pow(Error_TT , 2)+pow(Error_QCD , 2)+pow(Error_SingleT , 2),0.5  )

    Signal=file.Get(categoriy+"/"+sig)
    Signal.Scale(XS)
    Norm_Sig=0;
    Error_Sig=0;
    for i in range(Signal.GetXaxis().GetNbins()):
        Norm_Sig +=Signal.GetBinContent(i+1)
        Error_Sig +=pow(Signal.GetBinError(i+1),1)
    Signal_r=Signal.Rebin(len(Binning)-1,"",Binning)
    signal_yield= round(Signal_r.GetBinContent(1),1)
    signal_error= round(Signal_r.GetBinError(1),1)



#    print '%s & %d $\pm$ %d & %d $\pm$ %d   & %d $\pm$ %d  & %d $\pm$ %d  & %d $\pm$ %d &  %d $\pm$ %d & %d'%(channel,Norm_TT,Error_TT,Norm_W,Error_W,Norm_SingleT,Error_SingleT,Norm_QCD,Error_QCD,  Norm_Tot,Error_Tot,  Norm_Sig,Error_Sig,  data_yield)

    print '%s & %d $\pm$ %d & %d $\pm$ %d & %d $\pm$ %d & %d $\pm$ %d & %d $\pm$ %d & %.1f $\pm$ %.1f & %d \\'%(channel,tt_yield,tt_error,singlet_yield,singlet_error,w_yield,w_error,qcd_yield,qcd_error,  totbkg_yield,totbkg_error,  signal_yield,signal_error,  data_yield)



#
#
#
#    
#    for pro in process:
#        hist=Inputfile.Get(categoriy+"/"+dir+'/'+pro)
#        if hist:
#            
#            RebinedHist= hist.Rebin(len(Binning)-1,"",Binning)
#            print  dir, pro,  round(RebinedHist.GetBinContent(1),1),round(RebinedHist.GetBinError(1),1)
#



ShowYield('postfit_shapes.root','Codex__mj_1_13TeV_prefit','Codex_','\mu jet',6.030E-03)
#ShowYield('rootPaper/final_rw_et_3000.root','RHW__et_1_13TeV_postfit','RHW_','\etau',6.030E-03)
#ShowYield('rootPaper/final_lq_mt_900.root','lq_mt_1_13TeV_postfit','LQ_','\mutau',1.23E-02)
#ShowYield('rootPaper/final_lq_et_900.root','lq_et_1_13TeV_postfit','LQ_','\etau',1.23E-02)

