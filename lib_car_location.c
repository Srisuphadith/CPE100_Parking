#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//------------------------------------------------------------------------------------------
typedef struct // define location datatype
{
    char floor[2];
    int slot, status;
    char license[9];
} location;

void write_to_file_location(FILE **fp, char floor[], int slot, int status, char license[]);
void read_file_location(FILE **fp, location *car);
int read_file_and_print();
//------------------------------------------------------------------------------------------
int read_file_and_print()
{
    // char buff[25][200]; // A(1-8),B(9-16),C(17,24)

    location car[25];
    FILE *fp_location;

    read_file_location(&fp_location, car);
    // write_to_file_location(&fp_location, "A", 5, 1, "00791600");
    fclose(fp_location);

    // printf("%d\n",car[0].slot);
    // printf("%d\n",car[1].slot);
    for(int cc =0;cc<24;cc++){
        printf("%s %d %d %s\n",car[cc].floor,car[cc].slot,car[cc].status,car[cc].license);
    }
    
    return 0;
    
}
//------------------------------------------------------------------------------------------
void write_to_file_location(FILE **fp, char floor[], int slot, int status, char license[]) //,int pos[], char floor[], char slot[], char status[], char license[]
{
    char buff[200];
    int index;
    int pos[25];
    *fp = fopen("car_location.csv", "r+");
    for (int i = 0; i < 25; i++) // find file pointer of line
    {
        pos[i] = ftell(*fp);
        fscanf(*fp, "%s", buff);
    }
    if (floor[0] == 'A') // change file pointer to floor and slot
    {
        index = 0 + slot;
    }
    else if (floor[0] == 'B')
    {
        index = 8 + slot;
    }
    else if (floor[0] == 'C')
    {
        index = 16 + slot;
    }
    fseek(*fp, pos[index] + 6, 0);          // change file pointer in floor and slot to state and license
    fprintf(*fp, "%d,%s", status, license); // write state and license
    fseek(*fp, pos[index], 0);              // debug
    fscanf(*fp, "%s", buff);                // debug
    // printf("--%s--\n", buff);               // debug
     fclose(*fp);
}
//------------------------------------------------------------------------------------------
void read_file_location(FILE **fp, location *car)
{
    char tmp[200];
    int num;
    *fp = fopen("car_location.csv", "r+");

    fscanf(*fp, "%s", tmp);
    for (int i = 0; i < 24; i++) // find file pointer of line
    {
        fscanf(*fp, "%s", tmp);
        
        char *token = strtok(tmp, ",");
        strcpy((car + i)->floor, token); //save floor 

        token = strtok(NULL, ",");
        num = atoi(token);
        (car + i)->slot = num; //save slot

        token = strtok(NULL, ",");
        num = atoi(token);
        (car + i)->status = num;//save status

        token = strtok(NULL, ",");
        strcpy((car + i)->license, token);//save license
        (car + i)->license[8] = '\0';
    }
    fclose(*fp);
}