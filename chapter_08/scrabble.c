// Calculate the scrabble score of the entered word using arrays

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char in;
  short score;
  int score_chart[26] = {1, 3, 3, 2, 1, 
                         4, 2, 4, 1, 8, 
                         5, 1, 3, 1, 1, 
                         3, 10, 1, 1, 1, 
                         1, 4, 4, 4, 8, 10};

  printf("Enter a word: ");

  while ((in = getchar()) != '\n') {
    if ((char) 97 <= in && in <= (char) 122)
      in = toupper(in);
    if ((char) 65 <= in && in <= (char) 90){
      score += score_chart[in - 65];
    } 
  }

  printf("Scrabble value: %d\n", score);
  return EXIT_SUCCESS;
}

