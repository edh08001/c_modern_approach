#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  int total, length, count;
  float avg;
  char in;
  total = count = 0;

  printf("Enter a sentence: ");

  while((in = getchar()) != '\n'){
    in = toupper(in);
    if (in == ' ' || in == '.'){
      total += length;
      length = 0;
      count++;
    } else if (65 <= in && in <= 90){
      length++;
    }
  }

  avg = (float) total / count;

  printf("Average word length: %.1f\n", avg);

  return EXIT_SUCCESS;
}
