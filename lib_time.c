#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

int call_time(char *time_);
void cv_itoc_time(int i_hr, int i_min, int i_sec, char *c_time);
void cv_df_stotime(int t_sec, char *time);
void df_ctoi_time(char *c_time1, char *c_time2, int *df_sec);

void cv_itoc_time(int i_hr, int i_min, int i_sec, char *c_time)
{
    char c_hr[3], c_min[3], c_sec[3];
    itoa( i_hr, c_hr, 10);
    itoa( i_min, c_min, 10);
    itoa( i_sec, c_sec, 10);
    strcat( c_time, c_hr);
    strcat( c_time, ":");
    strcat( c_time, c_min);
    strcat( c_time, ":");
    strcat( c_time, c_sec);
}

void cv_df_stotime(int t_sec, char *time)
{
    
}

void df_ctoi_time(char *c_time1, char *c_time2, int *df_sec)
{
    int df = 0;
    char *token = strtok( c_time2, ":");
        df += (atoi(token)*3600);
    token = strtok( NULL, ":");
        df += atoi(token)*60;
    token = strtok( NULL, ":");
        df += atoi(token);
    token = strtok( c_time1, ":");
        df -= atoi(token)*3600;
    token = strtok( NULL, ":");
        df -= atoi(token)*60;
    token = strtok( NULL, ":");
        df -= atoi(token);
        printf("%d\n", df);
    *df_sec = df;
}   

int call_time(char *time_)
{
    char s_time[9];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    cv_itoc_time(tm.tm_hour, tm.tm_min, tm.tm_sec, s_time);
    strcpy( time_, s_time);
    // printf("%s\n", time_);
    //printf("now: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main()
{
    char t[9];
    char t2[9] = "2:40:00";
    int dfsec;

    call_time(t);
    printf("%s\n", t);
    df_ctoi_time( t, t2, &dfsec);
    printf("%d", dfsec);
}