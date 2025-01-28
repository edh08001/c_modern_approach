#include <stdio.h>
#include <stdlib.h>

/************************************************************
 * Reduces a fraction to its lowest form                    *
 ************************************************************/
void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator);

int main(int argc, char *argv[])
{
  int numerator, denominator, reduced_numerator, reduced_denominator;

  printf("Enter a Fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);


  printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

  return EXIT_SUCCESS;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator)
{
  int remainder = 0, original_numerator, original_denominator;
  original_numerator = numerator;
  original_denominator = denominator;

  while (denominator != 0) 
  {
    remainder = numerator % denominator;
    numerator = denominator;
    denominator = remainder;
  }
  *reduced_numerator = original_numerator / numerator;
  *reduced_denominator = original_denominator / numerator;

}
