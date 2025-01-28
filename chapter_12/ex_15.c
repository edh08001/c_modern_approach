#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define D 7 
#define H 24
#define HI 100
#define LO 0
#define FREEZING 32

/**********************************************
 * Randomizes the row values between HI and LO*
 **********************************************/ 
void random_temps(int a[D][H], int n);

/*******************************************
 * Prints one row's worth of temps         *
 *******************************************/ 
void print_row(int a[D][H], int n, int r);

int main(int argc, char *argv[])
{
  int a[D][H] = {0};

  srand((unsigned) time(NULL));

  random_temps(a, H);

  print_row(a, H, 2);

  for (int i = 0; i < D; i++){
    for (int j = 0; j < H; j++){
      printf("%d ", a[i][j]);
      if (j == 23) printf("\n");
    }
  }
  return EXIT_SUCCESS;
}

void print_row(int a[D][H], int n, int r)
{
  int (*p)[H] = &(a + r)[0], i = 0;

  do {
    printf("%d ", *(p[0] + i));
  } while (++i < H);
  printf("\n");
}

void random_temps(int a[D][H], int n){
  
  int (*p)[H] = &a[0];

  do {
    int i = 0;
    do {
      *(p[0] + i) = rand() % HI;
    } while (++i < H);
  } while (++p < &a[D]);

}

