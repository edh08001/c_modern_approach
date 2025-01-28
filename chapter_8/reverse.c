/* Reverses a series of numbers entered by the user */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc, char *argv[])
{
  int a[SIZE] = {0};

  printf("Enter %d numbers: ", SIZE);
  for (int i = 0; i < SIZE; i++){
    scanf("%d", &a[i]);
  }

  printf("In reverse order: ");
  for (int i = 0; i < SIZE; i++){
    printf("%d ", a[9 - i]);
  }

  printf("\n");
  return EXIT_SUCCESS;
}
