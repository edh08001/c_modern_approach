#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STR_LEN 50

/********************************************
 * Read input from user and store in a null *
 * terminated string                        *
 ********************************************/
int read_string(char input[], int n);

/********************************************
 * Reverses the string supplied             *
 ********************************************/
bool reverse(char *message);

int main(int argc, char *argv[])
{
  char s[STR_LEN+1];
  read_string(s, STR_LEN);

  reverse(s);
  printf("%d\n", reverse(s));

  return EXIT_SUCCESS;
}
 
int read_string(char input[], int n)
{
  printf("Enter a sentence: ");
  int in, i = 0, day;
  while((in = getchar()) != '\n'){
    if (i < n) {
      input[i++] = in;
    }
  }
  input[i] = '\0';
  return i;
}

bool reverse(char *message) 
{
  char *end;
  end = &message[strlen(message)-1];

  do {
    if (*end != *message)
      return false;
  } while (--end > ++message);
  return true;
}
