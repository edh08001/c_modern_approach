#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define D 7 
#define H 24
#define FREEZING 32

/*******************************************
 * Find the temp that equals freezing (32) *
 *******************************************/ 
bool find_freeze(int a[D][H], int n);

bool search(const int a[], int n, int key);

int main(int argc, char *argv[])
{
  int a[D][H] = {[1][2] = 32};

  printf("%d\n", find_freeze(a, H));

  return EXIT_SUCCESS;
}

bool find_freeze(int a[D][H], int n)
{
  int (*p)[H] = &a[0];
  bool found = false;

  do {
    found = search(p[0], H, 32);
    if (found) break;
  } while (++p < &a[D]);

  return found;
}

bool search(const int a[], int n, int key){
  int i = 0;

  bool found = false;

  while (i++ < n){
    if (*a++ == key) found = true;
  }

  return found;
}
