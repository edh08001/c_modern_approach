#include <stdio.h>
#include <stdlib.h>

char *read_line()
{
  int ch, i, size;
  char *str;
  i = 0;
  size = 10;

  while ((ch = getchar()) != '\n') {
    if (i == size-1){
      
    } 
    str[i++] = ch;

  }
  str[i] = '\0';
  return str;
}

void * my_malloc(int n)
{
  void * p = malloc(n);
  if (p == NULL) {
    printf("Insufficient memory for my_malloc");
    exit(EXIT_FAILURE);
  }

  return p;
}
