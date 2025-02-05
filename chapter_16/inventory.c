#include <stdio.h>
#include "part.h"
#include "inventory.h"
#include "readline.h"

#define MAX_PARTS 100

int main(void)
{
  int num_parts = 0;

  char ch[2];
  part parts[MAX_PARTS];


  for (;;){
    printf("Enter Menu Option (i,s,u,p,q): ");
    read_line(ch, 2);
    switch(ch[0]){
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
