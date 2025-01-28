#include <stdio.h>

int main(void){
  int i = 2; int j = 3;
  int k = i * j == 6;
  int x = 5;
  int y = 1;

  int a, b, c;
  a = 3; b = 4; c = 5;

  int i2a = 2; int j2a = 1;

  int i3b = 7; int j3b = 8; int k3b = 9;

  printf("Exercise 1a: %d\n", k);
  printf("Exercise 1d: %d\n", a % b + a < c);
  printf("Exercise 2b: %d\n", !!i2a + !j2a);
  printf("Exercise 3b expr: %d\n", i3b - 7 && j3b++ < k3b);
  printf("Exercise 3b answ: %d %d %d\n", i3b, j3b, k3b);
  printf("Exercise 4: %d\n", (x >= y) - (x <= y));

  int n = 1;
  switch(n - 1){
    case 0: printf("zero");
    case 1: printf("one");
    case 2: printf("two");
  }
  return 0;
  


}

