#include "lib_car_location.c"
#include "print_summary.c"
#include "lib_input_lp.c"
#include "graphic.c"
#include "register.c"
int main() // A(1-8),B(9-16),C(17,24)
{
    //pass --> password
    char verify_pass[20];
    char base_pass[20] = "0"; 
    int options;
    FILE *file;
    report_info report[100];
    int index = 0;
    while (1) {
        system("cls");
        read_file_report(&file, report, &index);
        while (input_lp(&file, report, &index) != -1) {}
        
        system("cls");
        printf("Please, Verify your Identity\n");
        printf("----------------------------\n");
        
        do {
            printf("Enter Password: ");
            scanf(" %s", verify_pass);
        } while (strcmp(verify_pass, base_pass) != 0);
        
        printf("Verify Success\n");

        do {
            printf("\nWelcome to Administrator Console.\n");
            printf("--------------------------------\n");
            printf("1 : Summary Overall Information.\n");
            printf("2 : Available Parking Space.\n");
            printf("3 : Register Menu.\n");
            printf("4 : Register Member.\n");
            printf("5 : Show Graphic.\n");
            printf("0 : Back\n");
            printf("Enter a number of Options: ");
            scanf(" %d", &options);
            printf("\n");
            system("cls");

            switch (options) {
                case 0:
                    break;
                case 1:
                    printf("Summary Overall Information.\n\n");
                    print_data("report_sheet.csv");
                    break;
                case 2:
                    location car[25];
                    location car_AVB[25];
                    FILE *fp_location;
                    printf("Avaible Parking Space --> %d\n", findAvailable(&fp_location, car, car_AVB, "A"));
                    break;
                case 3:
                    printf("Registor Member.\n\n");
                    registerV(NULL);
                    break;
                case 4:
                    printf("Member:\n");
                    read_member(NULL);
                    break;
                case 5:
                    printf("Simulation.\n\n");
                    showGraphic(NULL);
                    break;
                default:
                    printf("Invalid option, please try again.\n");
            }
        } while (options != 0);
    }
    return 0;

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
    
}