#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int print_data(char *name_sheet);

int print_data(char *name_sheet){
    typedef struct
    {
        char license[9],name_province[25],
        time_in[9],time_out[9],car_location[3],member[11],price[6];
    }data_info;
    FILE *datasheet;
    data_info data[90];
    datasheet = fopen(name_sheet,"r");
    int i = 0;
    // if can not open file print out error.
    if (datasheet == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    fscanf(datasheet,"%s",data[i].license); //make a first row dissappear.
    //print out a header.
    printf("| License Plate | Province                 | Time In  | Time Out |  Price   | Car Location | Member     |\n");
    printf("|---------------|--------------------------|----------|----------|----------|--------------|------------|\n");
    
    //print out a data in report sheet.csv by a row.
    while (fscanf(datasheet, " %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %10s",
                   data[i].license, data[i].name_province,
                   data[i].time_in, data[i].time_out,
                   data[i].price, data[i].car_location, data[i].member) != EOF)
    {
        printf("| %-13s | %-24s | %-8s | %-8s | %-8s | %-12s | %-10s |\n",
               data[i].license, data[i].name_province,
               data[i].time_in, data[i].time_out,
               data[i].price, data[i].car_location, data[i].member);
        i++;
    }

    fclose(datasheet);
}
//--- this function show how to use print_data function ---//
// void input_output(){
//     print_data("report_sheet.csv"); //print_data(File name);
// }

// int main(){
//     input_output();
// }