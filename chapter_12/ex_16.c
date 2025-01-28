#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define D 7 
#define H 24
#define HI 100
#define FREEZING 32

/**********************************************
 * Randomizes the row values between 0 and HI *
 **********************************************/ 
void random_temps(int a[D][H], int n);

/*******************************************
 * Prints each day's highest temp          *
 *******************************************/ 
void print_highs(int a[D][H], int n);

/*******************************************
 * Finds the largest number in an array    *
 *******************************************/ 
void find_largest(int a[], int n, int *largest);

int main(int argc, char *argv[])
{
  int a[D][H] = {0};

  srand((unsigned) time(NULL));

  random_temps(a, H);

  print_highs(a, H);

  return EXIT_SUCCESS;
}

void print_highs(int a[D][H], int n)
{
  int (*p)[H] = &a[0];

  do 
  {
    int max = 0;
    find_largest(p[0], H, &max);
    printf("%d\n", max);
  } 
  while(++p < &a[D]);
}

void random_temps(int a[D][H], int n){
  
  int (*p)[H] = &a[0];

  do 
  {
    int i = 0;
    do 
    {
      *(p[0] + i) = rand() % HI;
    } 
    while (++i < H);
  } 
  while (++p < &a[D]);

}

void find_largest(int a[], int n, int *largest)
{
  int i = 0;

  while (i++ < n){
    if (*a++ > *largest) *largest = *(a-1);
  }
}

