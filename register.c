#include <stdio.h>
#include <string.h>

int registerV() {
    char input[10];
    printf("Input car number (type 'END' to finish)\n");
    
    while (1) {
        scanf("%s", input);
        
        if (strcmp("END", input) == 0) 
        {
            break;  
        }

        FILE *fp = fopen("register.csv", "r");
        if (fp == NULL) 
        {
            printf("Error opening file.\n");
            return 1;  
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
            fp = fopen("register.csv", "a");
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

int main() {
    registerV();
    return 0; 
}

    


    