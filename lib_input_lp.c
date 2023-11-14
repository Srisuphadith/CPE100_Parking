#include<stdio.h>
#include<string.h>
#include"lib_report_readandrewrite.c"
#include"convert_province.c"

void input_lp(int *count)
{
    char n_lp[7];
    char id_pv[3];
    char pv[26];

    printf("license plate : ");
    scanf("%6s%2s", n_lp, id_pv);
    printf("%s\n", n_lp);
    printf("%s\n", id_pv);
    // convert_province( id_pv, pv);
    // printf("%s\n", pv);
}

int main()
{
    FILE *file;
    report_info report[100];
    int index;

    read_file_report( &file, report, &index);
    input_lp( &index);

}
