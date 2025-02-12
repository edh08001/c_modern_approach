#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

#define WORD_LENGTH 20
#define MAX_WORDS 100


int compare(const void *a1, const void *a2);

int main(void)
{
  int i, len, word_count;
  char str[WORD_LENGTH + 1];
  char *words[MAX_WORDS];

  i = word_count = 0;

  for(;;){
    printf("Enter word: ");
    len = read_line(str, WORD_LENGTH);
    char* word = malloc(len + 1);
    if (word == NULL){
      printf("Error: Not enough memory for another word");
      exit(EXIT_FAILURE);
    }

    strcpy(word, str);

    if (len == 0){
      break;
    }
    else{  
      words[i++] = word;
      word_count++;
    }     
  }

  qsort((char *)words, word_count, sizeof(char*), compare);

  printf("\nIn sorted order:");
  for (i = 0; i < word_count; i++){
    printf(" %s", words[i]);
  }
  printf("\n");
}

int compare(const void *a1, const void *a2)
{

  return strcmp(*(char **)a1, *(char **)a2);
}
