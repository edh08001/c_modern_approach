#include <stdio.h>


int main(int argc, char *argv[])
{

  int grade;
  printf("Enter a two digit number: ");
  scanf("%d", &grade);
  
  char *tens[] = {"", "", "Twenty", "Thirty", "Forty",
                  "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                   "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

  char *ones[] = {"", "One", "Two", "Three", "Four", "Five",
                  "Six", "Seven", "Eight", "Nine"};

  if (grade / 10 > 1){
    printf("%s ", tens[grade/10]);
    printf("%s\n", ones[grade%10]);
  } else if (grade / 10 == 1) {
    printf("%s\n", teens[grade%10]);
  } else {
    printf("%s\n", ones[grade%10]);
  }

  return 0;
}

