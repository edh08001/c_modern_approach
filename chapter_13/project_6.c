#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PLANETS 9

/*****************************************************************
* Makes the string inputted all uppercase. Requires a nul term   *
* string otherwise potential buffer overflow                     *
******************************************************************/
bool compare_caseless(char *planet, char *input);

int main(int argc, char *argv[])
{
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  char *output[8];
  int i, j;

  
  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++)
      if (compare_caseless(planets[j], argv[i])) {
        printf("%s is planet %d\n", planets[j], j + 1);
        break;
      }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return EXIT_SUCCESS;
}

bool compare_caseless(char *planet, char *input)
{
  
    while((toupper(*planet++) == toupper(*input++)))
      if (*planet == '\0')
          break;

    if (*input == '\0')
      return true;
    else
      return false;
}
