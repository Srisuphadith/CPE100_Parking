#include <stdio.h>
#include <stdbool.h>

void swap (int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void selectionSort(int data[], int n)
{
  int i, j, minPos;
  for (i=0;i<n-1;i++)
    {
      minPos = i;
      for (j=i+1;j<n;j++)
        {
          if (data[j] < data[minPos])
          {
            minPos = j;
          }
        }
        swap(&data[minPos], &data[i]);
    }
}

void convertPosition(int row, int car_lot[], int *car_park_posU, int *car_park_posD) {
  
  for (int i=0; i<row; i++) {
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
    } else {
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
};

void printMiddle_N_floor(char floor) {
  for (int i=0; i<19; i++) {
    printf("-");
  }
  printf("|");
  for (int i=0; i<4; i++) {
    printf(" ");
  }
  printf("%c", floor);                // <--- Floor
};

void showGraphic(char cars[][3], int row) {

  char floor;
  int car_lot[8];
  int car_park_posU[5];
  int car_park_posD[5];
  int count=0, count_u=0, count_d=0;
  bool isPark = false;
  
  sscanf(&cars[0][0], "%s", &floor);
  for (int i = 0; i < row; i++) {
    for (int j=0l; j<2; j++) {
      sscanf(&cars[i][j], "%d", &car_lot[i]);
      } 
    }

  selectionSort(car_lot, row);
  
  convertPosition(row, car_lot, car_park_posU, car_park_posD);

  //                    ----------Upper Lot----------
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
    } else {
      for (int j=0; j<row; j++) {
        if (count == car_park_posU[j]) {
          printf("*");
          isPark = true;
          break;
        }
      }
      if (isPark) {
        isPark = false;
      } else {
        printf(" ");
      }
    }
  }
  printf("\n");
  count = 0;
  isPark = false;

  //                      ----------Middle Gap----------

  printMiddle_N_floor(floor);
  printf("\n");
  
  //                      ----------Lower Lot----------
  for (int i=1;i<=20;i++) {
    count++;
    if (i%5==0) {
      printf("|");
    } else {
      for (int j=0; j<row; j++) {
        if (count == car_park_posD[j]) {
          printf("*");
          isPark = true;
          break;
        }
      }
      if (isPark) {
        isPark = false;
      } else {
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
};

// int main(void) {
//   char cars[][3] = {"A1", "A7", "A4"};

//   int row = sizeof(cars)/sizeof(cars[0]);
//   showGraphic(cars, row);
  

//   return 0;
// }