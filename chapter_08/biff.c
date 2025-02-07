/* This program takes a message and converts to 1337 speak */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ENTHUSIASM_LEVEL 10

int main(int argc, char *argv[])
{
  char message[100], in;
  int index = 0;

  // Swap letters for numbers
  printf("Enter message: ");
  while((in = getchar()) != '\n'){
    in = toupper(in);
    switch(in){
      case 'A': in = '4';
      break;
      case 'B': in = '8';
      break;
      case 'E': in = '3';
      break;
      case 'I': in = '1';
      break;
      case 'O': in = '0';
      break;
      case 'S': in = '5';
      break;
    }
    message[index] = in;
    index++;
  }

  // Add Enthusiasm (!!!!)
  for (int i = 0; i < ENTHUSIASM_LEVEL; i++){
    message[index + i] = '!';
  }
 
  printf("In B1FF-speak: ");
  for(int i = 0; i < index + ENTHUSIASM_LEVEL; i++){
    printf("%c", message[i]);
  }

  printf("\n");

  return EXIT_SUCCESS;
}
