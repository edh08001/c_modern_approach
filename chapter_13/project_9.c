/* This program counts the number of vowels in a sentence */

#include <stdio.h>
#include <ctype.h>

#define WORD_SIZE 20

/*****************************************************************
* Reads a user inputted string and converts it to an array of    *
* chars. Ignores any chars in strings longer than WORD_SIZE and  *
* appends the nul character at the end of the string             *
******************************************************************/
int read_string(char input[], int n);

/*****************************************************************
* takes an input string and outputs the count of vowels.         *
* Ignores any chars in strings longer than WORD_SIZE and         *
* appends the nul character at the end of the string             *
******************************************************************/
int compute_vowel_count(const char sentence[]);

int main(int argc, char *argv[])
{
  char in[WORD_SIZE];
  int vowels = 0;

  printf("Enter a sentence: ");
  read_string(in, WORD_SIZE);

  vowels = compute_vowel_count(in);
  
  printf("There are %d vowels.\n", vowels);

  return 0;
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

int compute_vowel_count(const char sentence[])
{
  int count = 0;
  char c;
  while(*sentence) { 
    c = toupper(*sentence++);
    switch(c){
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U': count++;
      /* fallthrough */
      break;
    }
  } 
  return count;
}
