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
    
    printf("\nindex is %d", *indexs);
    fclose(*fp);
}

void input_lp(int *index)
{
    char n_lp[7];
    char id_pv[3];

    printf("license plate : ");
    scanf("%6s%2s", n_lp, id_pv);
}

int main()
{

    FILE *file;

    report_info sheets[100];
    int index;

    read_file_report( &file, sheets, &index);
    input_lp(&index);
}
