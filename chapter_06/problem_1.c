#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  float entry, max = 0.0f;

  do 
  {
    printf("Enter a number: ");
    scanf("%f", &entry);
    if (entry > max) 
    {
      max = entry;
    }
  } while (entry >= 0.0f);

  printf("\nThe largest number entered was %.4f\n", max);

  return EXIT_SUCCESS;
}
