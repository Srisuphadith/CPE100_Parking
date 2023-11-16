#include<stdio.h>
#include"lib_input_lp.c"

int main()
{
    FILE *file;
    report_info report[100];
    int index = 0;

    read_file_report( &file, report, &index);
    input_lp( &file, report, &index);

}