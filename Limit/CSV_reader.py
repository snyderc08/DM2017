import csv
with open('Felix_Lowercontour_Delta01.csv','rb') as csvfile:
         spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
         for i, row in enumerate(spamreader):
            M= ', '.join(row)
            print i,M.split(',')[1], str(i+M.split(',')[1])