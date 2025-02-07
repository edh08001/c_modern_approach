/* This program takes a First Last name and outputs Last, First Initial */

#include <stdio.h>

int main(int argc, char *argv[])
{
  char in, first_initial, last_initial;

  printf("Enter a name: ");
  scanf(" %c", &first_initial);
  
  while(getchar() != ' ')
    ; /* Skip to end of first name */ 

  scanf(" %c", &last_initial);

  printf("%c", last_initial);

  while((in = getchar()) != '\n'){
    if(in == ' ') break;
    printf("%c", in);
  }

  printf(", %c.\n", first_initial);

  return 0;
}

