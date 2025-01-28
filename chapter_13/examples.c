#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 50

/****************************************************
 * Represents the actual process of reading through *
 * the query and assigning the strings to the       *
 * reminder array                                   *
 ****************************************************/
int read_line(char s[], int n);

/****************************************************
 * Capitalizes every letter in the array. Requires  *
 * the array to be a null terminated string. Results*
 * undefined with no null termination               *
 ****************************************************/
void capitalize(char s[], int n);

int main(int argc, char *argv[])
{

  int i, j;
  char s[N + 1];

  read_line(s, N);

  capitalize(s, N);

  printf("%s\n", s);

  return EXIT_SUCCESS;
}

int read_line(char s[], int n)
{
  int in, i = 0;

  while((in = getchar()) != '\n'){
    if (i < n) {
      s[i++] = in;
    }
  }
  s[i] = '\0';
  return i;
}

void capitalize(char s[], int n)
{
  char *p = s;
  while((*s++ = toupper(*p++)))
    ;
}
