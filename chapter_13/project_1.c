#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

int main(int argc, char *argv[])
{
  char *animals[N + 1];
  char animal[20], smallest_animal[20], largest_animal[20];
  int i = 0;
  do {
    printf("Enter word: ");
    fgets(animal, sizeof(animal), stdin);
    if (strcmp(smallest_animal, animal) > 0 || !strlen(smallest_animal))
      strcpy(smallest_animal, animal);
    if (strcmp(largest_animal, animal) < 0)
      strcpy(largest_animal, animal);
  } while (strlen(animal) != 5);

  printf("\nSmallest word: %s", smallest_animal);
  printf("Largest word: %s\n", largest_animal);

  return EXIT_SUCCESS;
}
