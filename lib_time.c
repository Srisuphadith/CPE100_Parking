#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

int call_time(char *time_);
void cv_itoc_time(int i_hr, int i_min, int i_sec, char *c_time);

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

int call_time(char *time_)
{
    char s_time[9];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    cv_itoc_time(tm.tm_hour, tm.tm_min, tm.tm_sec, s_time);
    strcmp( time_, s_time);
    // printf("%s\n", s_time);
    //printf("now: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main()
{
    char t[9];
    
    call_time(t);
    printf("%s\n", t);
}