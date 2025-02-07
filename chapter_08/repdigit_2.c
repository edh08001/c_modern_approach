/* Determines whether a digit repeats in a user entered number */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define NEXT_DIGIT (input%i/(i/10))

int main(int argc, char *argv[])
{
  bool digit_seen[10] = {false};
  bool repeat_flag = false;
  long input;

  printf("Enter a number: ");
  scanf("%ld", &input);

  digit_seen[input % 10] = true;
  for (long i = 100; NEXT_DIGIT != 0; i *= 10){
    if (digit_seen[NEXT_DIGIT]){
      printf("Repeated Digit\n");
      repeat_flag = true;
      break;
    } else {
      digit_seen[NEXT_DIGIT] = true;
    }
  }

  if (!repeat_flag) printf("No Repeated Digit\n");

  return EXIT_SUCCESS;
}
