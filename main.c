
#include "print_summary.c"
#include "lib_input_lp.c"
#include "graphic.c"

int main() // A(1-8),B(9-16),C(17,24)
{
    //pass --> password
    char verify_pass[20];
    char base_pass[20] = "0"; 
    int options=0;
    float time_speed=1.00;

    //Create a variable to store data from the input license plate function.
    FILE *file;
    report_info report[100];
    int index = 0;

    //Create a variable to store data from the car location function.
    location car[25];
    location car_AVB[25];
    FILE *fp_location;
    
    system("cls");
    printf("To accelerate the testing process, speed up the time \nbetween the car entering the park and its exit.\n");
    printf("Enter time speed (Ex : 1.25) :");
    scanf(" %f", &time_speed);
    while (options != -1) {
        system("cls");
        read_file_report(&file, report, &index);
        //read file report_sheet to collect a data of report and amount of car in report_sheet.
        while (input_lp(&file, report, &index, time_speed) != -1) {}
        //input_lp() == -1 mean user enter "admin000".
        system("cls");
        
        printf("Please, Verify your Identity\n");
        printf("----------------------------\n");
        //when user enter "admin000" , user need to enter a valid password.
        do {
            printf("Enter Password: ");
            scanf(" %s", verify_pass);
        } while (strcmp(verify_pass, base_pass) != 0);
        
        //when user enter a vaild password ,program will go next to admin console.
        printf("Verify Success\n");
        do {
            printf("\nWelcome to Administrator Console.\n");
            printf("--------------------------------\n");
            printf("1 : Summary Overall Information.\n");
            printf("2 : Available Parking Space.\n");
            printf("3 : Register Menu.\n");
            printf("4 : Register Member.\n");
            printf("5 : Show Graphic.\n");
            printf("6 : Find Location From License\n");
            printf("7 : Find License From Location\n");
            printf("0 : Back\n");
            printf("-1 : Quit the Programs\n");
            //admin enter an options to continue.
            printf("Enter a number of Options to continue: ");
            scanf(" %d", &options);

            system("cls");

            //call function depend on options that admin enter.
            switch (options) {
                case -1:
                    break;
                case 0:
                    break;
                case 1:
                //call print data function to pritnt out all of data.
                    printf("Summary Overall Information.\n\n");
                    print_data("report_sheet.csv");
                    break;
                case 2:
                //call findAvailable function to pritnt out Avaible Parking Space.
                    printf("Avaible Parking Space --> %d\n", findAvailable(&fp_location, car, car_AVB));
                    break;
                case 3:
                //call registerV function to Register Member.
                    printf("Register Member.\n\n");
                    registerV(NULL);
                    break;
                case 4:
                //call registerV function to pritnt out all of member.
                    printf("Member:\n");
                    read_member(NULL);
                    break;
                case 5:
                //call showGraphic function to pritnt out simulation of car in that floor.
                    printf("Simulation.\n\n");
                    showGraphic(NULL);
                    break;
                case 6:
                //call findLocationFromLicense function to pritnt out Location of that License plate.
                    char *result_locate = findLocationFromLicense(&fp_location, car);
                    if (strcmp(result_locate, "License not found") == 0)
                    {
                        printf("License not found\n");
                    }
                    else
                    {
                        printf("Location: %s\n", result_locate);
                    }
                    free(result_locate);
                    break;
                case 7:
                //call findLicenseFromLocation function to pritnt out License plate of that Location.
                    char *result_lisense = findLicenseFromLocation(&fp_location, car);
                    if (strcmp(result_lisense, "Doesn't Have This Location") == 0)
                    {
                        printf("Doesn't Have a car in This Location\n");
                    }
                    else
                    {
                        printf("License: %s\n", result_lisense);
                    }
                    break;
                default:
                //print error if user enter a invalid number options.
                    printf("Invalid option, please try again.\n");
            }
        //if options == 0 break the loop and go back to input license plate console.
        } while (options != 0 && options != -1);
    }
    return 0;
}


    // location car[25];
    // location car_AVB[25];
    // FILE *fp_location;
    // read_file_location(&fp_location, car);
    // write_to_file_location(&fp_location, "A", 5, 1, "00791600");
    // printf("%d",findAvailable(&fp_location , car,car_AVB,"A"));

//feen
    // int id_province;
    // char name_province[25] = "";
    // printf("Enter id of province : ");
    // scanf(" %d", &id_province);
    // convert_province(id_province,name_province); //convert_province(int *const , char *const)
    // printf("%s\n", name_province);
    // print_data("report_sheet.csv"); //print_data(File name);
//phu
    // showGraphic(NULL);

//nut
    // registerV();
    // read_member();
    
