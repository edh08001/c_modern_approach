/* This program takes a First Last name and outputs Last, First Initial */

#include <stdio.h>

#define NAME_LENGTH 20

int main(int argc, char *argv[])
{
  char in, first_initial;
  char last_name[NAME_LENGTH];
  int index = 1;

  for (int i = 0; i < NAME_LENGTH; i++)
    last_name[i] = ' ';
  printf("Enter a name: ");
  scanf(" %c", &first_initial);
  
  while(getchar() != ' ')
    ; /* Skip to end of first name */ 

  scanf(" %c", &last_name[0]);
  
  while((in = getchar()) != '\n'){
    last_name[index] = in;
    index++;
    if(in == ' ') break;
  }

  for(int i = 0; i < NAME_LENGTH; i++){
    if (last_name[i] != ' ')
      printf("%c", last_name[i]);
  }
  printf(", %c.\n", first_initial);
  
  return 0;
}

