#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define HI 100

/********************************************
 * Sums a multidimensional array using array*
 * arithmatec instead of subscripting       *
 ********************************************/
void sum_array(int *p, int n, int *s);

/*******************************************
 * Fills an array with random nums up to HI*
 *******************************************/
void random_nums(int (*p)[N], int n);

int main(int argc, char *argv[]) {
  int a[N][N], sum = 0;

  srand((unsigned) time(NULL));

  random_nums(&a[0], N);

  sum_array(&a[0][0], N, &sum);

  printf("The sum is: %d\n", sum);

  return EXIT_SUCCESS;
}

void sum_array(int *p, int n, int *sum) {
  int *end = p + n * n;

  do {
    *sum += *p;
  } while (++p < end);
}

void random_nums(int (*p)[N], int n){
  int (*end)[N] = &p[N];

  do 
  {
    int i = 0;
    do 
    {
      *(p[0] + i) = rand() % HI;
    } 
    while (++i < N);
  } 
  while (++p < end);

}
