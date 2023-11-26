#include <stdio.h>
#include <string.h>
#include "convert_province.c"

void read_member();
void check_member(char lp[], char* stat_member);
int registerV();

void read_member(){
    int i=0;  // Initialize a counter variable i
    FILE *fp = fopen("member.csv", "r");  // Open the file "member.csv" in read mode
    if (fp == NULL)   // Check if the file was opened successfully
    {
        printf("Error opening file.\n");
    }
    char data_member[10];    // Declare an array to store data from the file 
    while (fscanf(fp, "%s", data_member) != EOF) { // Read data from the file until the end of the file is reached
        printf("%s\n", data_member);    // Print the data read from the file
    }
    fclose(fp); // Close the file after reading
}

void check_member(char lp[],char* stat_member)
{
    FILE *fp = fopen( "member.csv", "r");// Open the "member.csv" file for reading

    if( fp == NULL)// Check if the file opening is successful
    {
        printf("Error opening member_file");
        return;
    }

    char tmp[11];// Temporary variable to store license plates read from the file
    while(fscanf( fp, "%s", tmp) != EOF)// Read license plates from the file until the end of the file (EOF) is reached
    {
        if ( strcmp( lp, tmp) == 0)// Compare the given license plate (lp) with the one read from the file (tmp)
        {
            strcpy( stat_member, "member");// If a match is found, set the status to "member" and return from the function
            return;
        }
    }
    strcpy( stat_member, "non-member");// If the loop completes without finding a match, set the status to "non-member"

    fclose(fp);// Close the file before returning
    return;
}

int registerV() {
    printf("Register System\n");// Print a welcome message
    
    while (1) {// Infinite loop for continuous user input
        char full_licens_plate[20];
        printf("License plate (type 'END' to stop entry) : ");// Prompt the user to enter the license plate
        scanf(" %s", full_licens_plate);
        char n_lp[7];
        char id_pv[3];
        char pv[26];
        
        //check a format of license plate-----------
        if (strlen(full_licens_plate)==8){
            sscanf(full_licens_plate, "%6s%2s", n_lp, id_pv);// Extract the license plate components
        }
        else{
            if (strcmp("END", full_licens_plate) == 0)// If the format is invalid, check if the user entered 'END' to stop entry 
            {
                break;// Exit the loop if 'END' is entered  
            }
            printf("License plate's format is invalid\n");
            break;// Exit the loop for any other invalid format
        }
        if (convert_province( atoi(id_pv), pv) == 0 )// Check if the province ID is valid using the convert_province function
        {
            printf("This id : %s not found as the province\n",id_pv);
            break;// Exit the loop if the province ID is not found
        }
        //-----------------------------------------------

        FILE *fp = fopen("member.csv", "r");// Open the "member.csv" file for reading
        if (fp == NULL) 
        {
            printf("Error opening file.\n");
            break;// Exit the loop if the file cannot be opened
        }

        char data[9];
        int check = 0;

        while (fscanf(fp, "%s", data) != EOF) {// Check if the vehicle is already registered
            if (strcmp(full_licens_plate, data) == 0) 
            {
                check = 1;
                printf("This car is already registered.\n");
            }
        }

        fclose(fp);// Close the file

        if (check == 0)  // If the vehicle is not already registered, add it to the "member.csv" file
        {
            fp = fopen("member.csv", "a");
            if (fp == NULL) 
            {
                printf("Error opening file.\n");
                break; // Exit the loop if the file cannot be opened for writing
            }
            fprintf(fp, "%s\n", full_licens_plate);
            fclose(fp);
            printf("Registered\n");
        }
    }

    return 0;// Return 0 to indicate successful completion

}


    


    
