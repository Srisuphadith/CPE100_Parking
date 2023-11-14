#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct 
{
    char license_plate[7];
    char province[26];
    char time_in[9];
    char time_out[9];
    float price;
    char car_location[3];
    char member[11];
} report_sheet_info ;

report_sheet_info sheets[100];

void read_file_location(FILE *file, report_sheet_info *sheet);

int main()
{
    
    report_sheet_info *sheet = sheets;

    FILE *file;

    file = fopen("report_sheet.csv", "r+");

    char new_license_plate[7] = "AB1500";
    char new_province[26] = "sakaeo";
    char new_time_in[9] = "10:40:10";
    char new_time_out[9] = "11:40:11";
    float new_price = 1000.00;
    char new_car_location[3] = "b3";
    char new_member[10] = "non-member";
    char buff[200];
    int index;
    int pos[25];

    for (int i = 0; fscanf(file, "%s", buff) != EOF; i++ ,index = i) // find file pointer of line
    {
        pos[i] = ftell(file);
        printf("%s\n", buff);
        if(strstr(buff,new_license_plate))
        {
            break;
        }
    }
    printf("%d",index);
    fseek(file, pos[index] + 2, 0); 
    printf("\n %p", pos[index]);         // change file pointer in floor and slot to state and license
    fprintf(file, "%s,%s,%s,%s,%s,%.2f,%s,%s"
    , new_license_plate
    , new_province
    , new_time_in
    , new_time_out
    , new_price
    , new_car_location
    , new_member); // write state and license
    fseek(file, pos[index], 0);              // debug
    fscanf(file, "%s", buff);                // debug
    printf("--%s--\n", buff);               // debug
    fclose(file);
    // read_file_location( &file, sheets);
}

void read_file_location(FILE *file, report_sheet_info *sheet)
{

    file = fopen("report_sheet.csv", "r+");

    char tmp[200];
    float num;

    fscanf( file, "%s", tmp);
    //printf( "%s", tmp);

    for (int i = 0; fscanf( file, "%s", tmp) != EOF; i++)
    {

        //printf("%s",tmp);
        char *token = strtok( tmp, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->license_plate, token);

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->province, token);

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->time_in, token);

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->time_out, token);

        token = strtok( NULL, ",");
        num = atoi(token);
        printf( "\n token %.2f", token);
        (sheet + i)->price = num;

        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->car_location, token);
        
        token = strtok( NULL, ",");
        printf( "\n token %s", token);
        strcpy( (sheet + i)->member, token);
        (sheet + i)->member[10] = '\0';

        printf( "\n license_plate %d : %s"  , i, (sheet + i)->license_plate);
        printf( "\n province      %d : %s"  , i, (sheet + i)->province);
        printf( "\n time_in       %d : %s"  , i, (sheet + i)->time_in);
        printf( "\n time_out      %d : %s"  , i, (sheet + i)->time_out);
        printf( "\n price         %d : %.2f", i, (sheet + i)->price);
        printf( "\n car_location  %d : %s"  , i, (sheet + i)->car_location);
        printf( "\n member        %d : %s"  , i, (sheet + i)->member);
    }
        
    fclose(file);
}
