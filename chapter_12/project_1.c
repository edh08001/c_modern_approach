#include <stdio.h>
#include <stdlib.h>

#define N 100

/*****************************************
* Changes all array elements to 0        *
*****************************************/
void print_reverse(char *in, char *end);

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

  print_reverse(in, end);

  return EXIT_SUCCESS;
}

char* get_entry(char *in, int n){
  char c, *end, *p = in;
  int i;

  printf("Enter a message: ");
  for (i = 0; i < n; i++){
    scanf("%c", &c);
    if (c == '\n') 
      return end;
    else { 
      end = p;
      *p++ =  c;
    }
  }
  return end;
}


void print_reverse(char *in, char *end){
  printf("Reversal is: ");
  do {
    printf("%c", *end);
  } while (--end >= in);
  printf("\n");
}
