#include <stdio.h>
#include "lib_car_location.c"
int main() // A(1-8),B(9-16),C(17,24)
{
    location car[25];
    FILE *fp_location;
<<<<<<< Updated upstream
    read_file_location(&fp_location, car);
    //write_to_file_location(&fp_location, "A", 5, 1, "00791600");
=======
    //read_file_location(&fp_location, car);
    write_to_file_location(&fp_location, "A", 5, 0, "AB791600");
>>>>>>> Stashed changes

    return 0;
}