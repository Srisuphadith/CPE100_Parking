#include <stdio.h>
#include <string.h>

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
    for(;fscanf( fp, "%s", tmp) != EOF;)
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
    char input[10];
    printf("Input car number (type 'END' to finish)\n");
    
    while (1) {
        scanf(" %s", input);
        
        if (strcmp("END", input) == 0) 
        {
            break;  
        }

        FILE *fp = fopen("member.csv", "r");
        if (fp == NULL) 
        {
            printf("Error opening file.\n");
            break;
        }

        char data[10];
        int check = 0;

        while (fscanf(fp, "%s", data) != EOF) {
            if (strcmp(input, data) == 0) 
            {
                check = 1;
                printf("This car is already registered.\n");
                printf("Input car number (type 'END' to finish)\n");
            }
        }

        fclose(fp);

        if (check == 0) 
        {
            fp = fopen("member.csv", "a");
            if (fp == NULL) 
            {
                printf("Error opening file.\n");
                return 1;  
            }
            fprintf(fp, "%s\n", input);  
            printf("Input car number (type 'END' to finish)\n");
            fclose(fp);
        }
    }

    return 0;

}

// int main() {
//     registerV();
//     return 0; 
// }

    


    