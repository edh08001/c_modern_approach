#include <stdio.h>
#include "read_string.h"

int read_string(char reminder[], int n)
{
  int in, i = 0, day;
  while((in = getchar()) != '\n'){
    if (i < n) {
      reminder[i++] = in;
    }
  }
  reminder[i] = '\0';
  return i;
}
