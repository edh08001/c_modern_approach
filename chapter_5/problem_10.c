#include <stdio.h>
int main(int argc, char *argv[])
{

  int grade;
  printf("Enter a grade: ");
  scanf("%d", &grade);
  
  switch(grade / 10)
  {
    case(10): 
    case(9): printf("Grade: A\n");
             break;
    case(8): printf("Grade: B\n");
             break;
    case(7): printf("Grade: C\n");
             break;
    case(6): printf("Grade: D\n");
             break;
    default: printf("Grade: F\n");
             break;
  }

  return 0;
}
