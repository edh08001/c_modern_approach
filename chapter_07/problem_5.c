// Calculate the scrabble score of the entered word

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char in;
  short score;

  printf("Enter a word: ");

  while ((in = getchar()) != '\n') {
    if ((char) 97 <= in && in <= (char) 122)
      in = toupper(in);
    if ((char) 65 <= in && in <= (char) 90){
      /* Could also use if/else utilizing multiple > comparisons but find this more readable */
      switch(in) {
        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'O':
        case 'R':
        case 'S':
        case 'T':
        case 'U': score += 1;
        break;
        case 'D':
        case 'G': score += 2;
        break;
        case 'B':
        case 'C':
        case 'M':
        case 'P': score += 3;
        break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y': score += 4;
        break;
        case 'K': score += 5;
        break;
        case 'J':
        case 'X': score += 8;
        break;
        case 'Q':
        case 'Z': score += 10;
        break;
      }
    } 
  }
  printf("Scrabble value: %d\n", score);
  return EXIT_SUCCESS;
}
