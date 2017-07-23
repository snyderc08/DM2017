import csv
with open('Felix_Uppercontour_Delta01.csv','rb') as csvfile:
         spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
         for row in spamreader:
            M= ', '.join(row)
            print M.split(',')[1]