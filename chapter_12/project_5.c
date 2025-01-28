/* This program reverses the word in a sentence */
#include <stdio.h>
#include <stdlib.h>

#define SENTENCE_SIZE 100

char* get_entry(char *in, char *punctuation, int n);

void print_reverse(char *sentence, char* end, char punctuation, int n);

int main(int argc, char *argv[])
{
  char *end;
  char sentence[SENTENCE_SIZE];
  char in, punctuation;
  int index = 0;

  for(int i = 0; i < SENTENCE_SIZE; i++)
    sentence[i] = ' ';

  end = get_entry(sentence, &punctuation, SENTENCE_SIZE);
  
  print_reverse(sentence, end, punctuation, SENTENCE_SIZE);

  return EXIT_SUCCESS;
}

void print_reverse(char *start, char* index, char punctuation, int n)
{
  char *word_end = index - 1, *word_start;
  do {
    if(*index == ' '){
      word_start = index + 1;
      do {
        printf("%c", *word_start++);
      } while (word_start <= word_end);
      printf("%c", ' ');
      word_end = index - 1;
    } else if (index == start) {
      word_start = index;
      do {
        printf("%c", *word_start++);
      } while (word_start <= word_end);
      printf("%c", punctuation);
    }
  } while (--index >= start);
  printf("\n");
}

char* get_entry(char *in, char *punctuation, int n){
  char c, *end;
  int i;

  printf("Enter a message: ");
  for (i = 0; i < n; i++){
    scanf("%c", &c);
    if (c == '\n') {
      return end;
    }
    else {
      if (c == '.' || c == '!' || c == '?') {
        *punctuation = c;
      }
      end = in;
      *in++ =  c;
    }
  }
  return end;
}

