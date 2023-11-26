#include<stdio.h>
#include<string.h>
#include"lib_report_readandrewrite.c"
#include"lib_time.c"
#include"lib_price.c"
#include"register.c"
#include "lib_car_location.c"

void display(char d_lp[], char d_pv[], char d_t_in[], char d_t_out[], char d_df_time[], float d_price, char d_cl[], char d_mbstat[]);
int input_lp(FILE **fp, report_info *sheet, int *indexs, float time_speed);

int input_lp(FILE **fp, report_info *sheet, int *indexs, float time_speed)
{
    char n_lp[7];
    char id_pv[3];
    char pv[26];
    char o_t[9];
    char t[9];
    char cl[3];
    float pr;
    char df_t[9];
    int df_s;
    char mb_stat[11];
    char buff[20];

    printf("license plate : ");
    scanf("%s", buff);
    
    if (strlen(buff)==8){
        sscanf(buff, "%6s%2s", n_lp, id_pv);
    }
    else{
        printf("License plate's format is invalid\n");
        return 0;
    }
    if ( strcmp(n_lp,"admin0")==0 && strcmp(id_pv,"00") == 0 ){
        return -1;
    }
    if (convert_province( atoi(id_pv), pv) == 0 )
    {
        printf("This id : %s not found as the province\n",id_pv);
        return 0;
    }
    
    location car[25];
    FILE *fp_location;
    if(find_lp_report( &*fp, sheet, indexs, n_lp, pv))
    {
        //car_out
        int loc = (find_lp_report( &*fp, sheet, indexs, n_lp, pv)-1);
        // printf("%d\n", loc);
        call_time(t);
        read_old_lp_report( sheet, loc, o_t, cl, mb_stat);
        df_ctoi_time( o_t, t, &df_s);
        df_s *= time_speed;
        cv_df_stotime( df_s, df_t);
        pr = calculate_price( df_s, mb_stat);
        read_file_location(&fp_location, car);
        int slot;
        sscanf(cl+1," %d",&slot);
        write_to_file_location(&fp_location, &cl[0], slot , 0, "00000000");
        write_old_lp_report( sheet, loc, t, pr);
        rewrite_file_report( &*fp, sheet, *indexs);
        display( n_lp, pv, o_t, t, df_t, pr, cl, mb_stat); 
    }
    else{
        call_time(t);
        read_file_location(&fp_location, car);
        int car_lot = get_car_lot(&fp_location, car);
        if(car_lot == -1){
            return 0;
        }
        write_to_file_location(&fp_location, car[car_lot].floor, car[car_lot].slot, 1, buff);
        strcpy(cl,car[car_lot].floor);
        sprintf(cl + strlen(cl), "%d", car[car_lot].slot);
        check_member( buff, mb_stat);
        display( n_lp, pv, t, "-", "-", 0, cl, mb_stat);
        // printf("%d\n", *indexs);
        *indexs = write_new_lp_report( sheet, *indexs, n_lp, pv, t, cl, mb_stat);
        rewrite_file_report( &*fp, sheet, *indexs);
        // printf("%d\n", *indexs);
    }

}

void display(char d_lp[], char d_pv[], char d_t_in[], char d_t_out[], char d_df_time[], float d_price, char d_cl[], char d_mbstat[])
{
    printf("\n");
    if( d_price == 0 && (strcmp( d_df_time,"-") == 0 ) && (strcmp( d_t_out,"-") == 0))
    {
        printf("LP. : %s %s\n", d_lp, d_pv);
        printf("Time in : %s\n", d_t_in);
        printf("Location : %s\n", d_cl);
        printf("%s\n",d_mbstat);
    }else{
        
        printf("LP. : %s %s\n", d_lp, d_pv);
        printf("Time in   : %s\n", d_t_in);
        printf("Time out  : %s\n", d_t_out);
        printf("Time total: %s\n", d_df_time);
        printf("Location : %s\n", d_cl);
        printf("%s\n",d_mbstat);
        printf("Price : %.2f bath\n", d_price);
    }
    printf("\n");
}



// int main()
// {
//     FILE *file;
//     report_info report[100];
//     int index = 0;

//     read_file_report( &file, report, &index);
//     input_lp( &file, report, &index);

// }
