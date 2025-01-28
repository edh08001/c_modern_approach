#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int one, two, three, four, five, six, seven,
  eight, nine, ten, eleven, twelve, thirteen, fourteen,
  fifteen, sixteen;

  printf("Enter the numbers from 1 to 16 in any order:\n");
  scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", 
        &one, &two, &three, &four,
        &five, &six, &seven, &eight,
        &nine, &ten, &eleven, &twelve,
        &thirteen, &fourteen, &fifteen, &sixteen);
  printf("\n%3.2d%3.2d%3.2d%3.2d\n", one, two, three, four);
  printf("%3.2d%3.2d%3.2d%3.2d\n", five, six, seven, eight);
  printf("%3.2d%3.2d%3.2d%3.2d\n", nine, ten, eleven, twelve);
  printf("%3.2d%3.2d%3.2d%3.2d\n", thirteen, fourteen, fifteen, sixteen);
  printf("\nRow sums: %d %d %d %d\n", 
         (one + two + three + four),
         (five + six + seven + eight),
         (nine + ten + eleven + twelve),
         (thirteen + fourteen + fifteen + sixteen));
  printf("Column sums: %d %d %d %d\n",
         (one + five + nine + thirteen),
         (two + six + ten + fourteen),
         (three + seven + eleven + fifteen),
         (four + eight + twelve + sixteen));
  printf("Diagonal sums: %d %d\n",
         (one + six + eleven + sixteen),
         (four + seven + ten + thirteen));
  
  return EXIT_SUCCESS;
}
