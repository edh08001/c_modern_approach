#include <stdio.h>

int main(void)
{
  int prefix, id, code, num, digit;
  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &prefix, &id, &code, &num, &digit);
  printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n", 
         prefix, id, code, num, digit);
  return 0;
}
