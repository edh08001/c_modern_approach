#include "readline.h"
#include <stdio.h>
#include <ctype.h>

void read_line(char *buf, int n)
{
  char ch;
  int i = 0;

  while (isspace(ch = getchar()))
    ;
  buf[i++] = ch; 
  while ((ch = getchar()) != EOF && ch != '\n')
  {
    if (i < n)
      buf[i++] = ch;
  }
  buf[i] = '\0';
}
