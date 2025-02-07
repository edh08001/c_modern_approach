#include <math.h>
#include <stdio.h>

int main(void) {
  short input, output;
  int remainder;
  printf("Enter a number between 0 and 32767: ");
  scanf("%hi", &input);
  output += (input / (short)pow(8, 4) % 8 * 10000) +
            (input / (short)pow(8, 3) % 8 * 1000) + 
            (input / (short)pow(8, 2) % 8 * 100) +
            (input / 8 % 8 * 10) + input % 8;

  printf("The octal representation of that number is: %5.5d\n", output);
}
