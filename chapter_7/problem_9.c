/* This program takes a user input time in 12h format and provides the 24h equivalent */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  int hr, min;
  char tod;


  printf("Enter a time in 12h format: ");
  scanf("%d:%d %c", &hr, &min, &tod);

  tod = toupper(tod); 

  if (tod == 65) {
    if (hr == 12){
      printf("00:%d\n", min);
    } else {
      printf("%d:%d\n", hr, min);
    }
  } else if (tod == 80) {
    if (hr == 12){
      printf("%d:%d\n", hr, min);
    }
    else {
      printf("%d:%d\n", hr + 12, min);
    }
  }

  return 0;
}

