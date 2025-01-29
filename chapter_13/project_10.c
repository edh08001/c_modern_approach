/* This program takes a First Last name and outputs Last, First Initial */

#include <stdio.h>
#define N 20

int main(int argc, char *argv[])
{
  char in, first_initial, last_initial;
  char first[N+1], last[N+1], full[N*2 + 1];

  printf("Enter a name: ");
  scanf("%s", first);
  scanf("%s", last);

  printf("%s, %c.\n", last, first[0]);  

  return 0;
}

