#include <stdio.h>
#include <string.h>

//--province info datatype--//
typedef struct
    {
        int num;
        char name[25];
    } province_info;
//-----------------------//

int convert_province(int id , char *name);

int convert_province(int id , char *name){
    FILE *dataset_provinces;
    province_info province[80];
    int i=0; 
    dataset_provinces = fopen("province_id.csv","r");
    //if cannot open file print out an error.
    if (dataset_provinces == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    //read all of data in file province_id.csv by the row.
    while (fscanf(dataset_provinces,"%d , %s", &province[i].num, province[i].name) != EOF){
        //compare an input id and id that read from file.
        //if same number copy a name of a province that read in a same row with number and return -1.
        if(id == province[i].num){
            strcpy(name,province[i].name);
            return -1;
        }
        i++;
    }
    //but if read all of data in file but number do not match let return 0.
    return 0; 
    fclose(dataset_provinces);
}
//------------------end----------------------//

//--- this function show how to use convert_province function ---//
// void inout_province(){
//     int id_province;
//     char name_province[25] = "";
//     printf("Enter id of province : ");
//     scanf(" %d", &id_province);
//     convert_province(id_province,name_province); //convert_province(int *const , char *const)
//     printf("%s", name_province);
// }
