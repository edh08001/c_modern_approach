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
    if (i % 24 == 1){
      printf("Press Enter to continue...");
      while (getchar() != '\n')
        ; /* Do nothing until enter is pressed */
    }
    printf("%d%20d\n", i, i * i);
    i++;
  }

  return 0;
}

