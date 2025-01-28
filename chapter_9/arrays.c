#include <stdio.h>
#include <stdlib.h>

#define N 10

int get_largest(int a[], int size);
double get_average(int a[], int size);
int get_positive_count(int a[], int size);

int main(int argc, char *argv[])
{
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, -9, 10};

  printf("Largest value is: %d\n", get_largest(a, N));
  printf("Average value is: %g\n", get_average(a, N));
  printf("Count of positive values is: %d\n", get_positive_count(a, N));

  return EXIT_SUCCESS;
}

int get_largest(int a[], int size){
  int i, max = 0; 

  for(i = 0; i < size; i++){
    if(a[i] > max) max = a[i];
  }

  return max;
}

double get_average(int a[], int size){
  int i, total = 0; 

  for(i = 0; i < size; i++){
    total += a[i];
  }

  return (double) total / size;
}

int get_positive_count(int a[], int size){
  int i, count = 0; 

  for(i = 0; i < size; i++){
    if (a[i] > 0) count++;
  }

  return count;
}
