#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib_car_location.c"

// findAvailable from (**file , *location , license) make it pointer to get value as character
char *findLocationFromLicense(FILE **fp, location *car, char license[9])
{
    char locat[5];
    int n = 0;
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