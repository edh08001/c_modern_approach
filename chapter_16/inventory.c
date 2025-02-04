#include <stdio.h>
#include "part.h"
#include  "inventory.h"

#define MAX_PARTS 100

int main(void)
{
  int num_parts = 0;

  char ch;
  part parts[MAX_PARTS];


  for (;;){
    while ((ch = getchar()) != '\n')
      ;
    printf("Enter Menu Option (i,s,u,p,q): ");
    ch = getchar();
    switch(ch){
      case 'i': add_part(parts, MAX_PARTS); 
      break;
      case 's': search_part(parts);
      break;
      case 'u': update_part_quantity(parts);
      break;
      case 'p': display_all_parts(parts);
      break;
      case 'q': return 1; 
      break;
    }
  }
}
