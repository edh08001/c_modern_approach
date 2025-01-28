#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define N 100

/*****************************************
* Checks if entry is a palindrome and    *
* prints 'Palindrome' or 'Not            *
* a palindrome depending                 *
*****************************************/
void palindrome(char *in, char *end);

/*****************************************
* Prompts for an entry from the user and *
* stores the result in an array of length*
* N                                      *
*****************************************/
char* get_entry(char in[], int n);


int main(int argc, char *argv[])
{

char in[N], *end;

  end = get_entry(in, N);

  palindrome(in, end);

  return EXIT_SUCCESS;
}

char* get_entry(char *in, int n){
  char c, *end;
  int i;

  printf("Enter a message: ");
  for (i = 0; i < n; i++){
    scanf("%c", &c);
    c = tolower(c);
    if (c == '\n') 
      return end;
    else if ('a' <= c && c <= 'z'){ 
      end = in;
      *in++ =  c;
    }
  }
  return end;
}


void palindrome(char *in, char *end){
  bool palindrome = true;
  do {
    if (*end-- != *in++){
      printf("Not a palindrome");
      palindrome = false;
      break;
    } 
  } while (end > in);
  if (palindrome) printf("Palindrome");
  printf("\n");
}
