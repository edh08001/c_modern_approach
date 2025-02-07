#include <stdio.h>
#include <stdlib.h>
#define RATE_INCREASES 5
#define MONTHS 12

int main(int argc, char *argv[])
{
  int rate, years; 
  float values[RATE_INCREASES] ;
  
  for (int i = 0; i < RATE_INCREASES; i++) 
    values[i] = 100.00;

  printf("Enter interest rate: ");
  scanf("%d", &rate);
  printf("Enter number of years: ");
  scanf("%d", &years);

  printf("Years");
  for(int i = 0; i < RATE_INCREASES; i++){
    printf("%9d%%", rate + i);
  }
  printf("\n");

  for (int i = 0; i < years; i++){
    printf("%3d     ", i + 1);
    for(int j = 0; j < RATE_INCREASES; j++){
      for (int k = 0; k < MONTHS; k++){
        values[j] = values[j] * (1 + ((float) (rate + j) / 100.00));
      }
      printf("%9.2f ", values[j]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
