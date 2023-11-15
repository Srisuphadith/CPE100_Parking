#include<stdio.h>
#include<string.h>
#include"lib_report_readandrewrite.c"
#include"convert_province.c"

void input_lp(FILE **fp, report_info *sheet, int *indexs)
{
    char n_lp[7];
    char id_pv[3];
    char pv[26];

    printf("license plate : ");
    scanf("%6s%2s", n_lp, id_pv);
    convert_province( atoi(id_pv), pv);
    if(find_lp_report( &*fp, sheet, indexs, n_lp, pv))
    {
        printf("found lp");
    }else{
        printf("not found lp");
    }

}

int main()
{
    FILE *file;
    report_info report[100];
    int index;

    read_file_report( &file, report, &index);
    input_lp( &file, report, &index);

}
