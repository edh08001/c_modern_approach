#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SENTENCE_SIZE 50

/*******************************************************
 * Computes the average word length and returns it as  *
 * an integer. Requires a nul terminated string        *
 *******************************************************/
double compute_average_word_length(const char *sentence);

int main(int argc, char *argv[])
{
  double avg;
  char sentence[SENTENCE_SIZE + 1];

  printf("Enter a sentence: ");
  fgets(sentence, SENTENCE_SIZE, stdin);

  avg = compute_average_word_length(sentence);

  printf("Average word length: %.1lf\n", avg);

  return EXIT_SUCCESS;
}

double compute_average_word_length(const char *sentence)
{
  int length, count, total;
  length = count = total = 0;
  char c;

  do { 
    if (*sentence == ' ' || *sentence == '.'){
      total += length;
      length = 0;
      count++;
    } 
    c = toupper(*sentence);
    if (65 <= c && c <= 90){
      length++;
    }
  } while (*++sentence);

  return (double) total / count;
}
