import os
import json
from pprint import pprint
import ROOT
from ROOT import *

#mass = [
#        
#        '1000_MNu-250',
#        '1000_MNu-500',
#        '1000_MNu-750',
#        '1500_MNu-1000',
#        '1500_MNu-1250',
#        '1500_MNu-250',
#        '1500_MNu-500',
#        '1500_MNu-750',
#        '2000_MNu-1000',
#        '2000_MNu-1250',
#        '2000_MNu-1500',
#        '2000_MNu-1750',
#        '2000_MNu-500',
#        '2000_MNu-750',
#        '2500_MNu-1000',
#        '2500_MNu-1250',
#        '2500_MNu-1500',
#        '2500_MNu-1750',
#        '2500_MNu-2000',
#        '2500_MNu-2250',
#        '2500_MNu-500',
#        '2500_MNu-750',
#        '3000_MNu-1000',
#        '3000_MNu-1250',
#        '3000_MNu-1500',
#        '3000_MNu-1750',
#        '3000_MNu-2000',
#        '3000_MNu-2250',
#        '3000_MNu-2500',
#        '3000_MNu-2750',
#        '3000_MNu-750',
#        '3500_MNu-1000',
#        '3500_MNu-1250',
#        '3500_MNu-1500',
#        '3500_MNu-1750',
#        '3500_MNu-2000',
#        '3500_MNu-2250',
#        '3500_MNu-2500',
#        '3500_MNu-2750',
#        '3500_MNu-3000',
#        '3500_MNu-3250',
#        '3500_MNu-750',
#        '4000_MNu-1000',
#        '4000_MNu-1250',
#        '4000_MNu-1500',
#        '4000_MNu-1750',
#        '4000_MNu-2000',
#        '4000_MNu-2250',
#        '4000_MNu-2500',
#        '4000_MNu-2750',
#        '4000_MNu-3000',
#        '4000_MNu-3250',
#        '4000_MNu-3500',
#        '4000_MNu-3750'
#        ]
#
#
#
#def XS(sample):
#    if sample[0:8]=="1000_MNu" : return 1.692E0
#    elif sample[0:8]=="1500_MNu": return 2.9E-1
#    elif sample[0:8]=="2000_MNu": return 6.563E-02
#    elif sample[0:8]=="2500_MNu": return 1.92E-02
#    elif sample[0:8]=="3000_MNu": return 6.030E-03
#    elif sample[0:8]=="3500_MNu": return 0.00209
#    elif sample[0:8]=="4000_MNu" : return 0.000801
#    else: return 0
#
#
#def Nu_M_Array(sample):
#    if sample[5:13]=="MNu-1000": return 1
#    elif sample[5:13]=="MNu-1250": return 2
#    elif sample[5:13]=="MNu-1500": return 3
#    elif sample[5:13]=="MNu-1750": return 4
#    elif sample[5:13]=="MNu-2000": return 5
#    elif sample[5:13]=="MNu-2250" : return 6
#    elif sample[5:13]=="MNu-2500": return 7
#    elif sample[5:13]=="MNu-2750": return 8
#    elif sample[5:13]=="MNu-3000": return 9
#    elif sample[5:13]=="MNu-3250": return 10
#    elif sample[5:13]=="MNu-3500": return 11
#    elif sample[5:13]=="MNu-3750": return 12
#    else: return 0
#
#
#def W_M_Array(sample):
#    if sample[0:8]=="1500_MNu": return 1
#    elif sample[0:8]=="2000_MNu": return 2
#    elif sample[0:8]=="2500_MNu": return 3
#    elif sample[0:8]=="3000_MNu": return 4
#    elif sample[0:8]=="3500_MNu": return 5
#    elif sample[0:8]=="4000_MNu" : return 6
#    else: return 0
#




Met_Cat= ["_MET200", "_MET250","_MET300", "_MET350","_MET400"]
MT_Cat = ["_MT0", "_MT50","_MT100"]


OutFile=TFile("file.root","RECREATE")
Hist2D=TH2F("2d","2d",5,0,5,3,0,3)
Mass=['1000.0','1400.0','1800.0']

for mass in Mass:
    i=0
    for met in Met_Cat:
        i+=1
        j=0
        for mt in MT_Cat:
            j+=1
            with open('outputCodex/Codex%s%s/limits_LIMITS.json'%(mt,met)) as data_file:
                data = json.load(data_file)
                print i,j,data[mass]["exp0"]
                Hist2D.SetBinContent(i,j,data[mass]["exp0"]*1000)
    OutFile.WriteObject(Hist2D,mass)
OutFile.Close()



##pprint(data)
#
#    for ch in range(0,54):
#        if  W_M_Array(mass[ch]) and Nu_M_Array(mass[ch]):   print "hlimitxsec2->SetBinContent(",W_M_Array(mass[ch]),",",Nu_M_Array(mass[ch]),",", data[str(ch+1)]["exp0"]*1000 ,"); //",mass[ch]
##        print  ch+1, mass[ch], data[str(ch+1)]["exp0"]/XS(mass[ch])
##        print "hlimitxsec2->SetBinContent(",W_M_Array(mass[ch]),",",Nu_M_Array(mass[ch]),",", data[str(ch+1)]["exp0"]/XS(mass[ch]) ,"); //",mass[ch]
#
#
#    print "\n\n\n\n\n\n\n"
#    for ch in range(0,54):
#        if  W_M_Array(mass[ch]) and Nu_M_Array(mass[ch]):   print "ExpctedExclusionLimit->SetBinContent(",W_M_Array(mass[ch]),",",Nu_M_Array(mass[ch]),",", data[str(ch+1)]["exp0"]/XS(mass[ch]) ,"); //",mass[ch]
#
#    print "\n\n\n\n\n\n\n"
#    for ch in range(0,54):
#        if  W_M_Array(mass[ch]) and Nu_M_Array(mass[ch]):   print "ObservedExclusionLimit->SetBinContent(",W_M_Array(mass[ch]),",",Nu_M_Array(mass[ch]),",", data[str(ch+1)]["obs"]/XS(mass[ch]) ,"); //",mass[ch]
#
#
#

