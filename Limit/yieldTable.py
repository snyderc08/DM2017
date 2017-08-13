#########
# /uscms_data/d3/abdollah/Analysis/Limit/CMSSW_7_4_7/src/CombineHarvester/CombineTools/bin/outputCodex_May11_NewSignificance_WithBtagVeto/Codex_MT500_MET100
#########

import CombineHarvester.CombineTools.ch as ch
# import CombineHarvester.CombineTools.pdgRounding as pdgRounding
import ROOT

import math



ROOT.PyConfig.IgnoreCommandLineOptions = True
ROOT.gROOT.SetBatch(ROOT.kTRUE)

ROOT.gSystem.Load('libHiggsAnalysisCombinedLimit')


### WORKSPACE PATH  [CHANGE BOTH WORKSPACE AND MLFIT ROOT FILE AT THE SAME TIME]
### ======= CONSTRAINED =========
# fin = ROOT.TFile('output/CONSTRAINED-svfit/cmb/wsp.root')
# fin = ROOT.TFile('output/CONSTRAINED-mvis/cmb/wsp.root')

### ======= UNCONSTRAINED =========
# fin = ROOT.TFile('output/LIMITS-svfit/cmb/wsp.root')
fin = ROOT.TFile('ws.root')

wsp = fin.Get('w')

cmb = ch.CombineHarvester()
cmb.SetFlag("workspaces-use-clone", True)
ch.ParseCombineWorkspace(cmb, wsp, 'ModelConfig', 'data_obs', False)

### MLFIT ROOT FILE PATH [CHANGE BOTH WORKSPACE AND MLFIT ROOT FILE AT THE SAME TIME]
### ======= CONSTRAINED =========
# mlf = ROOT.TFile('output/CONSTRAINED-svfit/cmb/mlfit.Test.root')
# mlf = ROOT.TFile('output/CONSTRAINED-mvis/cmb/mlfit.Test.root')

### ======= UNCONSTRAINED =========
# mlf = ROOT.TFile('output/LIMITS-svfit/cmb/mlfit.Test.root')
mlf = ROOT.TFile('mlfit.root')




rfr = mlf.Get('fit_s')


def AddSystQuad(a,b):
    a2 = math.pow(a, 2.) 
    b2 = math.pow(b, 2.)
    x  = a2 + b2 
    quad =  math.sqrt(x)
    return quad




def PrintTables(cmb, uargs):
    c_et = cmb.cp().bin(['Codex__mj_1_13TeV'])
#    c_mt = cmb.cp().bin(['Codex__mj_1_13TeV'])
#    c_em = cmb.cp().bin(['em_inclusive'])
#    c_tt = cmb.cp().bin(['tt_inclusive'])
#    c_mm = cmb.cp().bin(['mm_inclusive'])



#    print  c_et.cp().PrintAll()

    print r"""

\begin{tabular}{|l|r@{$ \,\,\pm\,\, $}l|}
\hline
Process & \multicolumn{2}{c|}{Normalization}  \\
\hline
\hline"""
    
    print r' W+jets                                           & $%.1f$ & $%.1f$  \\' % (
                                                                                         
        c_et.cp().process(['W']).GetRate(), c_et.cp().process(['W']).GetUncertainty(*uargs)),"\n",
        
        
        
        
        
        
    print r'QCD multijet                                        & $%.1f$ & $%.1f$  \\' % (
                                                                                          
        c_et.cp().process(['QCD']).GetRate(), c_et.cp().process(['QCD']).GetUncertainty(*uargs)),"\n",
        
        
        
        
        

    print r'TT                              & $%.1f$ & $%.1f$  \\' % (
         c_et.cp().process(['TT']).GetRate(), c_et.cp().process(['TT']).GetUncertainty(*uargs)),"\n",
         
         
         
         
    
    print r'Electroweak                             & $%.1f$ & $%.1f$  \\' % (
        c_et.cp().process(['SingleTop','ZTT','VV']).GetRate(), c_et.cp().process(['SingleTop','ZTT','VV']).GetUncertainty(*uargs)),"\n",
        
        
        
    
    print r'LQ 1200 GeV                                         & $%.1f$ & $%.1f$  \\' % (
        c_et.cp().process(['Codex_']).GetRate(), c_et.cp().process(['Codex_']).GetUncertainty(*uargs)),"\n",
        
        
        

    print r'\hline'
    
    
    
    print r'Total expected background                        & $%.1f$ & $%.1f$  \\ ' % (
        c_et.cp().backgrounds().GetRate(), c_et.cp().backgrounds().GetUncertainty(*uargs)),"\n",
        
        

    print r'\hline'

    print r'\hline'
    
    print r'Observed data                                    & \multicolumn{2}{c|}{$%g$} \\' % (
                                                                                                
        c_et.cp().GetObservedRate()),"\n",
    print r"""\hline
\end{tabular}"""




print 'Pre-fit tables:'
PrintTables(cmb, tuple())

cmb.UpdateParameters(rfr)

print 'Post-fit tables:\n\n'
PrintTables(cmb, (rfr, 500))
