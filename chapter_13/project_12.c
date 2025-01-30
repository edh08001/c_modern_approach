/* This program reverses the words in a sentence */
#include <stdio.h>
#include <stdlib.h>

#define WORD_LEN 15
#define WORD_COUNT 20

/********************************************************
 * Gathers user input and stores each word in an array. *
 * Each word will be nul terminated to be treated as a  *
 * string.                                              *
 ********************************************************/
int parse_words(char words[][WORD_LEN + 1], char *p, int num_words, int word_size);

int main(int argc, char *argv[])
{
  char p = '.', words[WORD_COUNT][WORD_LEN + 1];
  int wc;

  wc = parse_words(words, &p, WORD_COUNT, WORD_LEN);

  for ( ; wc > 0; wc--){
    printf("%s ", &words[wc][0]);
  }
  printf("%s%c\n", &words[0][0], p);

  return EXIT_SUCCESS;
}

int parse_words(char words[][WORD_LEN + 1], char *p, int num_words, int word_size)
{
  char in;
  int i, j;
  i = j = 0;

  printf("Enter a sentence: ");
  while (i < num_words){
    in = getchar();
    if (in == ' ' || in == '\t') {
      words[i++][j] = '\0';
      j = 0;
    } else if (in == '.' || in == '?' || in == '!' || in == '\n'){
        words[i][j] = '\0';
        (in == '\n') ? (*p = '.') : (*p = in);
        break;
    } else {
      if (j < word_size)
        words[i][j++] = in;
    }
  }
  return i;
}
