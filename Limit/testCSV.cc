#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;



void testCSV()
{
    

    

    char buffer[1024] ;
    char *record,*line,*rec1,*rec2,*subtoken, *savedEndd1;
    
    FILE *fstream = fopen("Felix_Lowercontour_Delta01.csv","r");
    if(fstream == NULL)
    {
        printf("\n file opening failed ");
        return -1 ;
    }
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
        
        record = strtok(line,";");
        subtoken = strtok_r(record, ",",&savedEndd1);
    
            printf("record : %s *** %s",subtoken,  savedEndd1) ;    //here you can put the record into the array as per your requirement.
            cout<< "==>  "<<atof(record)*2;
            cout<< "  "<<atof(savedEndd1)*2<<"\n";
    }

}

