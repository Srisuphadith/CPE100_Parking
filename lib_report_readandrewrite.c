#include<stdio.h>
#include<string.h>
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

void read_file_report(FILE **fp, report_info *sheet, int *indexs);
int find_lp_report(FILE **fp, report_info *sheet, int *indexs1, char lp[]);

void read_file_report(FILE **fp, report_info *sheet, int *indexs)
{

    *fp = fopen("report_sheet.csv","r+");

    float num;
    char tmp[200];

    fscanf( *fp, "%s", tmp);

    for (int i = 0; fscanf( *fp, "%s", tmp) != EOF; i++, *indexs = i)
    {

        char *token = strtok( tmp, ",");
        strcpy( (sheet + i)->lp, token);

        token = strtok( NULL, ",");
        strcpy( (sheet + i)->pv, token);

        token = strtok( NULL, ",");
        strcpy( (sheet + i)->t_in, token);

        token = strtok( NULL, ",");
        strcpy( (sheet + i)->t_out, token);

        token = strtok( NULL, ",");
        num = atoi(token);
        (sheet + i)->price = num;

        token = strtok( NULL, ",");
        strcpy( (sheet + i)->cl, token);
        
        token = strtok( NULL, ",");
        strcpy( (sheet + i)->mb, token);
        (sheet + i)->mb[11] = '\0';

    }
    
    fclose(*fp);
}



int find_lp_report(FILE **fp, report_info *sheet, int *indexs1, char lp[], char pv[])
{
    printf("%d\n", *indexs1);
    for(int i = 0;i <= *indexs1 ;i++)
    {
        printf("%d\n", i);
        printf("%s\n", (sheet + i)->lp);
        if((strcmp(lp,(sheet + i)->lp) == 0) && (strcmp(pv,(sheet + i)->pv) == 0))
        {
            printf("found lp");
            return 1;
        }
    }
    printf("not found lp");
    return 0;
}