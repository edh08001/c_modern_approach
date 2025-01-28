#include <stdio.h>

int main(int argc, char *argv[])
{

  int n;
  printf("This program displays the square of n numbers, incrementing by 1 until n\n");
  printf("Enter a number: ");
  scanf("%d", &n);

  int i = 1;

  while (i <= n)
  {
    printf("%d%10d\n", i, i * i);
    i++;
  }

  return 0;
}
