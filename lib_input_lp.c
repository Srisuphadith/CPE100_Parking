#include<stdio.h>
#include<string.h>
#include"lib_report_readandrewrite.c"
#include"convert_province.c"
#include"lib_time.c"

void display(char d_lp[], char d_pv[], char d_t_in[], char d_t_out[], char d_df_time[], float d_price, char d_cl[]);
void input_lp(FILE **fp, report_info *sheet, int *indexs);

void display(char d_lp[], char d_pv[], char d_t_in[], char d_t_out[], char d_df_time[], float d_price, char d_cl[])
{
    if( d_price == 0 && (strcmp( d_df_time,"-") == 0 ) && (strcmp( d_t_out,"-") == 0))
    {
        printf("lp : %s %s\n", d_lp, d_pv);
        printf("Time_in : %s\n", d_t_in);
        printf("location: %s\n", d_cl);
    }else{
        char df_t[9];
        int df_s;

        printf("lp : %s %s\n", d_lp, d_pv);
        printf("Time_in   : %s\n", d_t_in);
        printf("Time_out  : %s\n", d_t_out);
        df_ctoi_time( d_t_in, d_t_out, &df_s);
        cv_df_stotime( df_s, df_t);
        printf("Time_total: %s\n", df_t);
        printf("location: %s\n", d_cl);
        printf("Price : %.2f bath", d_price);
    }
}

void input_lp(FILE **fp, report_info *sheet, int *indexs)
{
    char n_lp[7];
    char id_pv[3];
    char pv[26];
    char o_t[9];
    char t[9];
    char cl[3];

    printf("license plate : ");
    scanf("%6s%2s", n_lp, id_pv);
    convert_province( atoi(id_pv), pv);

    if(find_lp_report( &*fp, sheet, indexs, n_lp, pv))
    {
        int loc = (find_lp_report( &*fp, sheet, indexs, n_lp, pv)-1);
        // printf("%d\n", loc);
        call_time(t);
        read_old_lp_report( sheet, loc, o_t, cl);
        write_old_lp_report( sheet, loc, t, 1000);
        rewrite_file_report( &*fp, sheet, *indexs);
        display( n_lp, pv, o_t, t, "-", 0, cl); 
    }else{
        call_time(t);
        display( n_lp, pv, t, "-", "-", 0, "b1");
        // printf("%d\n", *indexs);
        *indexs = write_new_lp_report( sheet, *indexs, n_lp, pv, t, "B3", "non-member");
        rewrite_file_report( &*fp, sheet, *indexs);
        // printf("%d\n", *indexs);
    }

}

int main()
{
    FILE *file;
    report_info report[100];
    int index = 0;

    read_file_report( &file, report, &index);
    input_lp( &file, report, &index);

}
