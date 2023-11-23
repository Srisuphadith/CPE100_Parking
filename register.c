#include <stdio.h>
#include <string.h>
#include "convert_province.c"

void read_member();
void check_member(char lp[], char* stat_member);
int registerV();

void read_member(){
    int i=0;
    FILE *fp = fopen("member.csv", "r");
    if (fp == NULL) 
    {
        printf("Error opening file.\n");
    }
    char data_member[10];
    while (fscanf(fp, "%s", data_member) != EOF) {
        printf("%s\n", data_member);
    }
    fclose(fp);
}

void check_member(char lp[],char* stat_member)
{
    FILE *fp = fopen( "member.csv", "r");

    if( fp == NULL)
    {
        printf("Error opening member_file");
        return;
    }

    char tmp[11];
    while(fscanf( fp, "%s", tmp) != EOF)
    {
        if ( strcmp( lp, tmp) == 0)
        {
            strcpy( stat_member, "member");
            return;
        }
    }
    strcpy( stat_member, "non-member");

    fclose(fp);
    return;
}

int registerV() {
    printf("Register System\n");
    
    while (1) {
        char full_licens_plate[20];
        printf("License plate (type 'END' to stop entry) : ");
        scanf(" %s", full_licens_plate);
        char n_lp[7];
        char id_pv[3];
        char pv[26];
        
        //check a format of license plate-----------
        if (strlen(full_licens_plate)==8){
            sscanf(full_licens_plate, "%6s%2s", n_lp, id_pv);
        }
        else{
            if (strcmp("END", full_licens_plate) == 0) 
            {
                break;  
            }
            printf("License plate's format is invalid\n");
            break;
        }
        if (convert_province( atoi(id_pv), pv) == 0 )
        {
            printf("This id : %s not found as the province\n",id_pv);
            break;
        }
        //-----------------------------------------------

        FILE *fp = fopen("member.csv", "r");
        if (fp == NULL) 
        {
            printf("Error opening file.\n");
            break;
        }

        char data[9];
        int check = 0;

        while (fscanf(fp, "%s", data) != EOF) {
            if (strcmp(full_licens_plate, data) == 0) 
            {
                check = 1;
                printf("This car is already registered.\n");
            }
        }

        fclose(fp);

        if (check == 0) 
        {
            fp = fopen("member.csv", "a");
            if (fp == NULL) 
            {
                printf("Error opening file.\n");
                break; 
            }
            fprintf(fp, "%s\n", full_licens_plate);
            fclose(fp);
            printf("Registered\n");
        }
    }

    return 0;

}

// int main() {
//     registerV();
//     return 0; 
// }

    


    