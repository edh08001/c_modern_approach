#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_LEN 50

/********************************************
 * Read input from user and store in a null *
 * terminated string                        *
 ********************************************/
int read_string(char input[], int n);


int main(int argc, char *argv[])
{
  int d, m, y;
  char *month[12] = {"January", "February", "March", "April",
                     "May", "June", "July", "August",
                     "September", "October", "November", "December"};

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m, &d, &y);
  printf("You entered the date %s %d, %d\n", month[m-1], d, y);

  return EXIT_SUCCESS;
}
 
int read_string(char input[], int n)
{
  int in, i = 0, day;
  while((in = getchar()) != '\n'){
    if (i < n) {
      input[i++] = in;
    }
  }
  input[i] = '\0';
  return i;
}


