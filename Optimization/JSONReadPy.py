import os
import json
from pprint import pprint


MassXS=[
[800,300,2.73E-02],
[900,350,1.23E-02],
[1000,400,5.86E-03],
[1100,450,2.91E-03],
[1200,500,1.50E-03],
[1300,550,7.95E-04],
[1400,600,4.33E-04],
[1500,650,2.40E-04],
]


with open('limits_LIMITS.json') as data_file:
    data = json.load(data_file)

    for bin, M in enumerate(MassXS,1):
        print 'hlimitxsec2->SetBinContent(%d,%d,%f); // LQ_%d_DM_%d'%(bin,bin,data[str(M[0])]["exp0"],M[0], M[1])


    print "\n\n\n\n\n\n\n"

    for bin, M in enumerate(MassXS,1):
        print 'ExpctedExclusionLimit->SetBinContent(%d,%d,%f); // LQ_%d_DM_%d'%(bin,bin,data[str(M[0])]["exp0"]/(M[2]*1000.),M[0], M[1])


    print "\n\n\n\n\n\n\n"
#    bin=1
    for bin,M in enumerate(MassXS,1):
        print 'ObservedExclusionLimit->SetBinContent(%d,%d,%f); // LQ_%d_DM_%d'%(bin,bin,data[str(M[0])]["obs"]/(M[2]*1000.),M[0], M[1])
#        bin +=1

#pprint(data)

#
#    for ch in TOTMASS:
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



