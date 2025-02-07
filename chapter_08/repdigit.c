/* Counts if a digit repeats in a user entered number(s) */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define NEXT_DIGIT (input%i/(i/10))

int main(int argc, char *argv[])
{
  int digit_count[10] = {0};
  int digit;
  long n;

  printf("Enter a series of numbers: ");

  for( ; ; ){
    scanf("%ld", &n);
    if (n <= 0) break;
    while (n > 0){
      digit = n % 10;
      
      digit_count[digit]++;
     
      n /= 10;
    }
  }
  printf("Digit:        0  1  2  3  4  5  6  7  8  9\n");
  printf("Occurrences:");
  for (int i = 0; i < SIZE; i++){
     printf("  %d", digit_count[i]);
  }
  printf("\n");
  
  return EXIT_SUCCESS;
}
