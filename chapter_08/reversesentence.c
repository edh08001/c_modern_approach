/* This program reverses the words in a sentence */
#include <stdio.h>
#include <stdlib.h>

#define SENTENCE_SIZE 100

int main(int argc, char *argv[])
{
  char sentence[SENTENCE_SIZE];
  char in, punctuation;
  int index = 0;

  for(int i = 0; i < SENTENCE_SIZE; i++)
    sentence[i] = ' ';

  printf("Enter a sentence: ");
  while((in = getchar()) != '\n'){
    
    if(in == '.' || in == '!' || in == '?'){
      punctuation = in;
      break;
    }
    sentence[index] = in;
    index++;
  }
  
  for(int i = index - 1; i >= 0; i--){
    if(sentence[i] == ' ' || i == 0){
      for(int j = (i == 0 ? i : i + 1); j < index; j++){
        printf("%c", sentence[j]);
      }

      if (i != 0)
        printf(" ");
      else
        printf("%c", punctuation);

      index = i;
    }
  }
  printf("\n");

  return EXIT_SUCCESS;
}
