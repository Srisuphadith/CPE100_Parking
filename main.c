#include <stdio.h>
//------------------------------------------------------------------------------------------
typedef struct // define location datatype
{
    char floor[2];
    int slot, status;
    char license[7];
} location;

void write_to_file_location(FILE **fp, char floor[], int slot, int status, char license[]);
void read_file_location(FILE **fp, location *car);

//------------------------------------------------------------------------------------------
int main()
{
    // char buff[25][200]; // A(1-8),B(9-16),C(17,24)

    location car[24]; 
    FILE *fp_location;

    read_file_location(&fp_location, car);
    write_to_file_location(&fp_location, "A", 2, 1, "007916");
    fclose(fp_location);
    printf("%d\n",car[0].slot);
    printf("%d\n",car[1].slot);
    return 0;
}
//------------------------------------------------------------------------------------------

void write_to_file_location(FILE **fp, char floor[], int slot, int status, char license[]) //,int pos[], char floor[], char slot[], char status[], char license[]
{
    char buff[200];
    int index;
    int pos[25];
    rewind(*fp);
    for (int i = 0; i < 25; i++) // find file pointer of line
    {
        pos[i] = ftell(*fp);
        fscanf(*fp, "%s", buff);
    }
    if (floor[0] == 'A') // change file pointer to floor and slot
    {
        index = 0 + slot;
    }
    else if (floor[0] == 'B')
    {
        index = 8 + slot;
    }
    else if (floor[0] == 'C')
    {
        index = 16 + slot;
    }
    fseek(*fp, pos[index] + 6, 0);          // change file pointer in floor and slot to state and license
    fprintf(*fp, "%d,%s", status, license); // write state and license
    fseek(*fp, pos[index], 0);              // debug
    fscanf(*fp, "%s", buff);                // debug
    printf("--%s--\n", buff);               // debug
}
//------------------------------------------------------------------------------------------
void read_file_location(FILE **fp, location *car)
{
    *fp = fopen("car_location.csv", "r+");
    (car+0)->slot = 10;
    (car+1)->slot = 20;
    
}