#include <stdio.h>
int main(int argc, char *argv[])
{
  int d, next;
  printf("Enter a number to reverse: ");
  scanf("%d", &d);
  
  do 
  {
    printf("%d", d % 10);
    d = d / 10;
  } while (d != 0);

  printf("\n");
  
  return 0;
}

