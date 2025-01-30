#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define ALPHABET 26

void read_word(char counts[]);

bool equal_array(const char *counts1, const char *counts2);

int main(int argc, char *argv[])
{
  bool match = true;
  int index = 0;
  char in;
  char word_1_counts[ALPHABET] = {0};
  char word_2_counts[ALPHABET] = {0};

  printf("Enter first word: ");
  read_word(word_1_counts);

  printf("Enter second word: ");
  read_word(word_2_counts);

  if (equal_array(word_1_counts, word_2_counts)){
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }
  
  return EXIT_SUCCESS;
}

void read_word(char counts[]){
  int index = 0;
  char in;

  while((in = getchar()) != '\n'){
    if (isalpha(in)){
      counts[tolower(in) - 'a'] += 1;
    }
  }
  index = 0;
}

bool equal_array(const char *counts1, const char *counts2){
  for(int i = 0; i < ALPHABET; i++){
    if (counts1[i] != counts2[i]){
      return false;
    }
  }
  return true;
}

