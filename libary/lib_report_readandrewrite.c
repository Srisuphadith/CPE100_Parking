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

void read_file_report( FILE **fp, report_info *sheet, int *indexs);
void rewrite_file_report( FILE **fp, report_info *sheet, int indexs);
int write_new_lp_report( report_info *sheet, int index2,char n_lp[], char n_pv[], char n_t_in[], char n_cl[], char mb_s[]);
void write_old_lp_report( report_info *sheet, int loc, char n_t_out[], float price);
void read_old_lp_report( report_info *sheet, int loc, char *o_t_in, char *o_cl, char* o_mbstat);
int find_lp_report( FILE **fp, report_info *sheet, int *indexs1, char lp[], char pv[]);

void read_file_report( FILE **fp, report_info *sheet, int *indexs)
{

    *fp = fopen("report_sheet.csv","r+"); // read file report

    float num;
    char tmp[200];

    fscanf( *fp, "%s", tmp);  //clear first row

    //loop to read a file and input a data into a report_info report[100]
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

void rewrite_file_report( FILE **fp, report_info *sheet, int indexs)
{
    *fp = fopen("report_sheet.csv","w");

    char o_lp[14] = "license_plate";
    char o_pv[9] = "province";
    char o_ti[8] = "time_in";
    char o_to[9] = "time_out";
    char o_p[6] = "price";
    char o_cl[13] = "car_location";
    char o_mb[7] = "member";
    // write a first row
    fprintf( *fp, "%s,%s,%s,%s,%s,%s,%s\n", o_lp, o_pv, o_ti, o_to, o_p, o_cl, o_mb);
    for(int i = 0; i < indexs; i++){
    
        fprintf( *fp, "%s,%s,%s,%s,%.2f,%s,%s\n"
        , (sheet + i)->lp
        , (sheet + i)->pv
        , (sheet + i)->t_in
        , (sheet + i)->t_out
        , (sheet + i)->price
        , (sheet + i)->cl
        , (sheet + i)->mb);

    }

    fclose(*fp);
}

int write_new_lp_report( report_info *sheet, int index2,char n_lp[], char n_pv[], char n_t_in[], char n_cl[], char mb_s[])
{

    int i = index2 ;

    strcpy( (sheet + i)->lp, n_lp);
    strcpy( (sheet + i)->pv, n_pv);
    strcpy( (sheet + i)->t_in, n_t_in);
    strcpy( (sheet + i)->t_out, "-");
    (sheet + i)->price = 0;
    strcpy( (sheet + i)->cl, n_cl);
    strcpy( (sheet + i)->mb, mb_s);

    i += 1;
    return i;
}

void write_old_lp_report( report_info *sheet, int loc, char n_t_out[], float price)
{
    int i = loc;

    strcpy( (sheet + i)->lp, (sheet + i)->lp);
    strcpy( (sheet + i)->pv, (sheet + i)->pv);
    strcpy( (sheet + i)->t_in, (sheet + i)->t_in);
    strcpy( (sheet + i)->t_out, n_t_out);
    (sheet + i)->price = price;
    strcpy( (sheet + i)->cl, (sheet + i)->cl);
    strcpy( (sheet + i)->mb, (sheet + i)->mb);
    
}

void read_old_lp_report( report_info *sheet, int loc, char *o_t_in, char *o_cl, char* o_mbstat)
{
    int i = loc;

    strcpy( o_t_in, (sheet + i)->t_in);
    strcpy( o_cl, (sheet + i)->cl);
    strcpy( o_mbstat, (sheet + i)->mb);
}

int find_lp_report(FILE **fp, report_info *sheet, int *indexs1, char lp[], char pv[])
{
    // printf("%d\n", *indexs1);
    for(int i = *indexs1;i >= 0 ;i--)
    {
        if(strcmp(lp,(sheet + i)->lp) == 0 && strcmp(pv,(sheet + i)->pv) == 0 && strcmp( (sheet + i)->t_out, "-") == 0) 
        {
            return i+1;
        }
    }
    return 0;
}