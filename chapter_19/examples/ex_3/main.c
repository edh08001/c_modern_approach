#include <stdio.h>
#include "queue.h"

int main(void)
{
  insert_item(10);
  insert_item(20);
  insert_item(30);

  printf("First item is: %d\n", get_next_item());
  remove_next_item();
  printf("First item is: %d\n", get_next_item());
  printf("Last item is: %d\n", get_last_item());
}
