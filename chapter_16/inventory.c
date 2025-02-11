#include <stdio.h>
#include <stdlib.h>
#include "part.h"
#include "inventory.h"
#include "readline.h"

#define ARRLEN(arr) (sizeof (arr) / sizeof (arr[0]))

void * my_malloc(int n);

int main(void)
{
  num_parts = 0;
  inventory_size = 2;

  char ch[2];
  part *parts = my_malloc(sizeof(part) * inventory_size);

  for (;;){
    printf("Enter Menu Option (i,s,u,c,p,q): ");
    read_line(ch, 1);
    switch(ch[0]){
      case 'i': add_part(&parts, inventory_size); 
      break;
      case 's': search_part(parts);
      break;
      case 'u': update_part_quantity(parts);
      break;
      case 'c': update_part_price(parts);
      break;
      case 'p': display_all_parts(parts);
      break;
      case 'q': return 1; 
      break;
    }
  }
}

void * my_malloc(int n)
{
  void * p = malloc(n);
  if (p == NULL) {
    printf("Insufficient memory for my_malloc");
    exit(EXIT_FAILURE);
  }

  return p;
}
