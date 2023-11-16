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
    for ( int i = 0; fscanf( fp,"%s,%d,%d", pr_info[i].mb_st, &pr_info[i].hr_low, &pr_info[i].pr) != EOF; i++)
    {

        int h_s = pr_info[i].hr_low * 3600;
        float pr_s = pr_info[i].pr/3600;
        printf("%s %s %d %d\n", mb, pr_info[i].mb_st, sec ,h_s);
        if ( strcmp( mb, pr_info[i].mb_st) == 0 && sec < h_s)
        {
            return sec*pr_s;
        }

    }
    printf("not found");
    return 0;

    fclose(fp);
}
