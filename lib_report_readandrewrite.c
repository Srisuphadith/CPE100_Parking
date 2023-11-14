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

int read_file_report(FILE **fp, report_info *sheet);

int read_file_report(FILE **fp, report_info *sheet)
{

    *fp = fopen("report_sheet.csv","r+");

    int index;
    float num;
    char tmp[200];

    fscanf( *fp, "%s", tmp);
    printf("%s", tmp);

    for (int i = 0; fscanf( *fp, "%s", tmp) != EOF; i++)
    {

        char *token = strtok( tmp, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->lp, token);

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->pv, token);

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->t_in, token);

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->t_out, token);

        token = strtok( NULL, ",");
        num = atoi(token);
        printf( "\n token %.2f", token);
        (sheet + i)->price = num;

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->cl, token);
        
        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->mb, token);
        (sheet + i)->mb[10] = '\0';

        printf( "\n license_plate %d : %s"  , i, (sheet + i)->lp);
        printf( "\n province      %d : %s"  , i, (sheet + i)->pv);
        printf( "\n time_in       %d : %s"  , i, (sheet + i)->t_in);
        printf( "\n time_out      %d : %s"  , i, (sheet + i)->t_out);
        printf( "\n price         %d : %.2f", i, (sheet + i)->price);
        printf( "\n car_location  %d : %s"  , i, (sheet + i)->cl);
        printf( "\n member        %d : %s"  , i, (sheet + i)->mb);
    }
        
    fclose(*fp);
}

int main()
{

    FILE *file;

    report_info sheets[100];

    read_file_report( &file, sheets);
}
