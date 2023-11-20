#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char mb_st[11];
    int hr_low;
    int pr;
} price_rate_info;

float calculate_price( int sec, char mb[]);

float calculate_price( int sec, char mb[])
{
    FILE *fp = fopen("price_rate.csv","r");
    price_rate_info pr_info[10];

    char tmp[50];
    float num;

    if ( fp == NULL)
    {
        printf("Error opening price_rate.csv");
        return 0;
    }

    fscanf( fp, "%s", tmp);
    for ( int i = 0; fscanf( fp,"%s", tmp) != EOF; i++)
    {
        char *token = strtok( tmp, ",");
        strcpy( pr_info[i].mb_st, token);

        token = strtok( NULL, ",");
        pr_info[i].hr_low = atoi(token);

        token = strtok( NULL, ",");
        pr_info[i].pr = atoi(token);

        int h_s = pr_info[i].hr_low * 3600;
        float pr_s = pr_info[i].pr/3600;
        // printf("%d\n", pr_info[i].pr);
        // printf("%s\n", pr_info[i].mb_st);
        if ( strcmp( mb, pr_info[i].mb_st) == 0 && sec < h_s)
        {
            return sec*pr_s;
        }

    }
    printf("Not found\n");
    return 0;

    fclose(fp);
}
