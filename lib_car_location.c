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
int findAvailable(FILE **fp , location *car,location *car_AVB,char floor[2]);
char *findLocationFromLicense(FILE **fp, location *car, char license[9]);
char *findLicenseFromLocation(FILE **fp, location *car, char location[3]);

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
        //printf("%s\n",token);
        (car + i)->license[8] = '\0';
    }
    fclose(*fp);
}

//------------------------------------------------------------------------------------------
//findAvailable from (**file , *location , floor)
int findAvailable(FILE **fp , location *car,location *car_AVB,char floor[2]){

    read_file_location(fp, car); //call read_file_location

    int isAvailable , slot , space =0;

    //check floor input and return find how many space
    for(int i=0;i<24;i++){
        if(strcmp( floor , car[i].floor)==0){
            if(car[i].status == 0){
                
                strcpy((car_AVB+space)->floor,car[i].floor);
                strcpy((car_AVB+space)->license,car[i].license);
                (car_AVB+space)->slot = car[i].slot;
                (car_AVB+space)->status = car[i].status;
                space++;
            }
        }
    }

    return space;
}



    // Ex of uses     
// int main(void){
//     location car[25];
//     FILE *fp_location;
//     printf("%d",findAvailable(&fp_location, car , car_AVB, "A") );
//     return 0;
// }

//------------------------------------------------------------------------------------------
// findAvailable from (**file , *location , license) make it pointer to get value as character
char *findLocationFromLicense(FILE **fp, location *car, char license[9])
{
    char locat[5];
    read_file_location(fp, car); // call read_file_location

    // check license input and return find location
    for (int i = 0; i < 24; i++)
    {

        // check giving license and license in file
        if (strcmp(license, car[i].license) == 0)
        {
            // locat = car[i].floor[0] + car[i].slot;  ***car[i].floor[0] is char | car[i].slot is int
            snprintf(locat, sizeof(locat), "%c%d", car[i].floor[0], car[i].slot);

            // result is value in address malloc
            char *result = malloc(strlen(locat) + 1);
            strcpy(result, locat);
            return result;
        }
    }
    // notFoundMessage is value in address malloc
    char *notFoundMessage = malloc(strlen("License not found") + 1);
    strcpy(notFoundMessage, "License not found");
    return notFoundMessage;
}

// Ex of uses
// int main(void)
// {
//     location car[25];
//     FILE *fp_location;

//     // return floor and slot of license that input to the function
//     char *result = findLocationFromLicense(&fp_location, car, "00444445");

//     // check return value
//     if (strcmp(result, "License not found") == 0)
//     {
//         printf("License not found\n");
//     }
//     else
//     {
//         printf("Location: %s\n", result);
//     }
//     free(result); // Free the allocated memory

//     return 0;
// }

//------------------------------------------------------------------------------------------
// findAvailable from (**file , *location , location) make it pointer to get value as character
char *findLicenseFromLocation(FILE **fp, location *car, char location[3])
{
    char locat[5];
    read_file_location(fp, car); // call read_file_location

    // check location input and return find location
    for (int i = 0; i < 24; i++)
    {

        // check giving location and location in file
        if ((location[0] == car[i].floor[0]) && (location[1] == (char)('0' + car[i].slot)))
        {
            return car[i].license;
        }
    }
    return "Doesn't Have This Location";
}

// Ex of uses
// int main(void)
// {
//     location car[25];
//     FILE *fp_location;

//     // return license of location that input to the function
//     char *result = findLicenseFromLocation(&fp_location, car, "A1");

//     // check return value
//     if (strcmp(result, "Doesn't Have This Location") == 0)
//     {
//         printf("Doesn't Have This Location\n");
//     }
//     else
//     {
//         printf("License: %s\n", result);
//     }

//     return 0;
// }
//------------------------------------------------------------------------------------------