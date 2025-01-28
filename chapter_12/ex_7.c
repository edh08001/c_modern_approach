#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

/*****************************************************
 * Searches through an array of size n for a key     *
 * specified by the user.                            *
 *****************************************************/
bool search(const int a[], int n, int key);

int main(int argc, char *argv[])
{
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bool found = search(a, N, 6);

  printf("Found %d? %s\n", 6, (found == 1 ? "True": "False"));
  

  return EXIT_SUCCESS;
}

bool search(const int a[], int n, int key){
  int *p, i;
  bool found = false;

  while (i++ < n){
    if (*a++ == key) found = true;
  }

  return found;
}
