#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    char lp[7]; //license_plate
    char pv[26];//province
    char t_in[9];//time_in
    char t_out[9];//time_out
    float price;//price
    char cl[3];//car location
    char mb[11];//member
} report_info ;

int read_file_report(FILE **fp, report_info *sheet);

int read_file_report(FILE **fp, report_info *sheet)
{

    *fp = fopen("report_sheet.csv","r+");

    int index;
    float num;
    char tmp[200];

    fscanf( *fp, "%s", tmp);
    printf("%s", tmp);
}

