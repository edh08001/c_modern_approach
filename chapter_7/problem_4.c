/* Convert a typed phone number with letters to the corresponding */
/* number value. Takes upper or lower case letters                */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char in;
  char number[15];
  int index = 0;

  printf("Enter phone number: ");

  while ((in = getchar()) != '\n') {
    if ((char) 97 <= in && in <= (char) 122)
      in = toupper(in);
    if ((char) 65 <= in && in <= (char) 90){
      /* Could also use if/else utilizing multiple > comparisons but find this more readable */
      switch(in) {
        case 'A':
        case 'B':
        case 'C': number[index] = '2';
        break;
        case 'D':
        case 'E':
        case 'F': number[index] = '3'; 
        break;
        case 'G':
        case 'H':
        case 'I': number[index] = '4';
        break;
        case 'J':
        case 'K':
        case 'L': number[index] = '5';
        break;
        case 'M':
        case 'N':
        case 'O': number[index] = '6';
        break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S': number[index] = '7';
        break;
        case 'T':
        case 'U':
        case 'V': number[index] = '8';
        break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z': number[index] = '9';
        break;
      }
    } else {
      number[index] = in;
    }
    index++;
  }

  printf("In numeric Form: ");
  for(int i = 0; i < 15; i++){
    printf("%c", number[i]);
  }

  printf("\n");
  return EXIT_SUCCESS;
}
