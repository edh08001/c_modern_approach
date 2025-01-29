// Calculate the scrabble score of the entered word

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define WORD_SIZE 20

/*****************************************************************
* Reads a user inputted string and converts it to an array of    *
* chars. Ignores any chars in strings longer than WORD_SIZE and  *
* appends the nul character at the end of the string             *
******************************************************************/
int read_string(char input[], int n);

/*****************************************************************
* Scans the input and returns an integer value representing the  *
* scrabble score of that particular word. The word must be a nul *
* terminated string otherwise infinite loop                      *
******************************************************************/
int get_score(const char input[], int n);

int main(int argc, char *argv[])
{
  char in;
  short score;
  char word[WORD_SIZE + 1];

  printf("Enter a word: ");
  read_string(word, WORD_SIZE);

  score = get_score(word, WORD_SIZE);

  printf("Scrabble value: %d\n", score);
  return EXIT_SUCCESS;
}

int get_score(const char input[], int n)
{
  int score = 0;
  char c;

  for (;;){
    if ((char) 97 <= *input && *input <= (char) 122)
      c = toupper(*input++);
    if ((char) 65 <= c && c <= (char) 90){
      /* Could also use if/else utilizing multiple > comparisons but find this more readable */
      switch(c) {
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
      if (*input == '\0')
        break;
    } 
  }
  return score;
}

int read_string(char input[], int n)
{
  int in, i = 0, day;
  while((in = getchar()) != '\n'){
    if (i < n) {
      input[i++] = in;
    }
  }
  input[i] = '\0';
  return i;
}

