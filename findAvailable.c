#include <stdio.h>
#include <string.h>
#include "carLocation.c"

//findAvailable from (**file , *location , floor)
int findAvailable(FILE **fp , location *car ,char floor[2]){

    read_file_location(&fp, car); //call read_file_location

    int isAvailable , slot , i= 0 , space =0;

    //check floor input and find how many space
    while(i < 24){
        
        if(strcmp( floor , car[i].floor)==0){
            if(car[i].status == 0){
                space++;
            }
        }
        i++;
    }

    return space;
}

    // Ex of uses     
    // location car[25];
    // FILE *fp_location;
    // printf("%d",findAvailable(&fp_location, car , "A") );


