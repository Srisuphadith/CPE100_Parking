#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int car_lot[8];
int car_park_posU[5];
int car_park_posD[5];

void convertPosition(int n_of_carPark, int *car_lot, int *car_park_posU, int *car_park_posD);
void printMiddle_N_floor(char floor[2]);
void read_file_location_graph(location *location);
void showGraphic();

void convertPosition(int n_of_carPark, int *car_lot, int *car_park_posU, int *car_park_posD) {
  
  for (int i=0; i<n_of_carPark; i++) {
   if (car_lot[i] < 5) {
      if (car_lot[i] == 1) {
        car_park_posU[i] = 2;
      }
      if (car_lot[i] == 2) {
        car_park_posU[i] = 7;
      }
      if (car_lot[i] == 3) {
        car_park_posU[i] = 12;
      }
      if (car_lot[i] == 4) {
        car_park_posU[i] = 17;
      }
    } 
    else {
      // printf("Hello World");
      if (car_lot[i] == 5) {
        car_park_posD[i] = 2;
      }
      if (car_lot[i] == 6) {
        car_park_posD[i] = 7;
      }
      if (car_lot[i] == 7) {
        car_park_posD[i] = 12;
      }
      if (car_lot[i] == 8) {
        car_park_posD[i] = 17;
      }
     
    }
  }
}

void printMiddle_N_floor(char floor[2]) {
  for (int i=0; i<19; i++) {
    printf("-");
  }
  printf("|");
  for (int i=0; i<4; i++) {
    printf(" ");
  }
  printf("%s", floor);  // <--- Floor
};

void read_file_location_graph(location *location)
{
  int i=0;
  FILE *carlocate_data;
  carlocate_data = fopen("car_location.csv","r");
  if (carlocate_data == NULL) {
        printf("Error opening file\n");
    }

  fscanf(carlocate_data,"%s",(location+i)->license);
  while (fscanf(carlocate_data,"%1s,%1d,%1d,%s",(location+i)->floor,
  &(location+i)->slot,
  &(location+i)->status,
  (location+i)->license) != EOF)
  {
    // debug ------------------------------------------------
    // printf("Floor %d -->%s\n",i,(location+i)->floor);
    // printf("Slot %d -->%d\n",i,(location+i)->slot);
    // printf("Status %d -->%d\n",i,(location+i)->status);
    // printf("\n");
    // debug ------------------------------------------------
    i++;
  }
  fclose(carlocate_data);
}

void showGraphic() {
  char floor[2];
  int count=0;
  int n_of_carPark = 0;
  
  bool isPark = false;
  location location[25];
  read_file_location_graph(location);
  
  printf("Enter floor:");
  scanf(" %s", floor);

  for (int i=0; i<24; i++)
  {
    if ((strcmp((location+i)->floor, floor) == 0) && ((location+i)->status == 1)) 
    {
        car_lot[n_of_carPark] = (location+i)->slot;
        n_of_carPark++;

      }
    }

  // printf("numberofcar_park -->%d\n", n_of_carPark); //debug

  // ----------ทิ้ง----------
  // sscanf(&cars[0][0], "%s", &floor);
  // for (int i = 0; i < row; i++) {
  //   for (int j=0; j<2; j++) {
  //     sscanf(&cars[i][j], "%d", &car_lot[i]);
  //     printf("%d\n",cars[i][j]);
  //     printf("-->%d\n",car_lot[i]);
  //   } 
  // }
  // -------------------------
  
  convertPosition(n_of_carPark, car_lot, car_park_posU, car_park_posD);

  //---------------------------------debug-------------
  // for (int i=0; i<8; i++) {
  //   printf("car_lot-->%d\n",car_lot[i]);
  // }
  // for (int i=0; i<4; i++) {
  //   printf("car_posup-->%d\n",car_park_posU[i]);
  // }

  // for (int i=0; i<4; i++) {
  //   printf("car_posdown-->%d\n",car_park_posD[i]);
  // }
  //----------------------------------------------------

  //----------Upper Lot----------
  printf(" ");
  for (int i=0; i<4; i++) {
    printf("%d", i+1);              // <--- Lable number 1-4
    for (int j=0; j<4; j++) {
      printf(" ");
    }
  }
  
  printf("\n");
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      printf("_");
    }
    printf(" ");
  }
  printf("\n");
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      printf(" ");
    }
    printf("|");
  }
  
  printf("\n");
  
  for (int i=1;i<=20;i++) {
    count++;
    if (i%5==0) {
      printf("|");
    } 
    else {
      for (int j=0; j<n_of_carPark; j++) {
        if (count == car_park_posU[j]) {
          printf("*");
          isPark = true;
          break;
        }
      }
      if (isPark) {
        isPark = false;
      } 
      else {
        printf(" ");
      } 
    }
  }
  printf("\n");
  count = 0;
  isPark = false;

  //----------Middle Gap----------

  printMiddle_N_floor(floor);
  printf("\n");
  
  //----------Lower Lot----------
  for (int i=1;i<=20;i++) {
    count++;
    if (i%5==0) {
      printf("|");
    } 
    else {
      for (int j=0; j<n_of_carPark; j++) {
        if (count == car_park_posD[j]) {
          printf("*");
          isPark = true;
          break;
        }
      }
      if (isPark) {
        isPark = false;
      } 
      else {
        printf(" ");
      }
    }
  }
  
  
  printf("\n");

  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      printf("_");
    }
    printf("|");
  }
  
  printf("\n\n");
  printf(" ");
  for (int i=0; i<4; i++) {
    printf("%d", i+5);              // <--- Lable number 5-8
    for (int j=0; j<4; j++) {
      printf(" ");
    }
  }
  printf("\n");
}