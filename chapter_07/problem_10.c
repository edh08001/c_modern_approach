/* This program counts the number of vowels in a sentence */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  char in;
  int vowels = 0;

  printf("Enter a sentence: ");

  while((in = getchar()) != '\n'){
    in = toupper(in);
    switch(in){
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U': vowels++;
      /* fallthrough */
      break;
    }
  }
  
  printf("There are %d vowels.\n", vowels);

  return 0;
}

