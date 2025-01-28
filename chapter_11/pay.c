#include <stdio.h>
#include <stdlib.h>

/************************************************************
 * Calculates and stores the change in various sized bills  *
 * based on the entered whole dollar amount                 *
 ************************************************************/
void pay_amount(int dollars, int *twenties, int *tens,
                int *fives, int *ones);

int main(int argc, char *argv[])
{
  int twenties, tens, fives, ones;
  twenties = tens = fives = ones = 0;

  pay_amount(136, &twenties, &tens, &fives, &ones);

  printf("You will receive the following change: \n");
  printf("%d Twenties\n", twenties);
  printf("%d Tens\n", tens);
  printf("%d Fives\n", fives);
  printf("%d Ones\n", ones);
  return EXIT_SUCCESS;
}

void pay_amount(int dollars, int *twenties, int *tens,
                int *fives, int *ones)
{
    *twenties = dollars / 20;
    dollars %= 20;
    *tens = dollars / 10;
    dollars %= 10;
    *fives = dollars / 5;
    dollars %= 5;
    *ones = dollars;
}

