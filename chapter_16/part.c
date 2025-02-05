#include "part.h"
#include "readline.h"
#include <stdio.h>
#include <stdbool.h>

extern int num_parts;

void add_part(part *parts, int n)
{
  if (num_parts < n) {
    part part;
    char ch;
    unsigned long size;
    printf("Enter Part Number: ");
    scanf("%d", &part.part_number);
    printf("Enter Part Name: ");
    read_line(part.part_name, NAME_LENGTH);
    printf("Enter Part Quantity: ");
    scanf("%d", &part.on_hand);
    parts[num_parts++] = part;
    printf("\n");
  } else {
    printf("Error: unique part count reached, part not added.\n");
  }
}

void search_part(part *parts)
{
  int part_num, i;
  bool found = false;
  printf("Enter Part Number: ");
  scanf("%d", &part_num);
  for (i = 0; i < num_parts; i++){
    if (parts[i].part_number == part_num){
      printf("Part Name: %s\n", parts[i].part_name);
      printf("Part Quantity: %d\n\n", parts[i].on_hand);
      found = true;
    }
  }
  if (!found) printf("No part with that id exists.\n");
}

void update_part_quantity(part *parts) 
{
  int qty, part_num, i;
  bool found = false;
  printf("Enter Part Number: ");
  scanf("%d", &part_num);
  for (i = 0; i < num_parts; i++){
    if (parts[i].part_number == part_num){
      printf("Enter Part Quantity Adjustment: ");
      scanf("%d", &qty);
      parts[i].on_hand += qty;
      found = true;
    }
  }
  if (!found){
    printf("No part with that id exists.\n");
  }
  printf("\n");
}

void display_all_parts(part *parts) 
{
  printf("Part Number  |  Part Name                    |  Part Qty\n");
  for (int i = 0; i < num_parts; i++){
    printf("%-16d%-32s%d\n", parts[i].part_number, parts[i].part_name, parts[i].on_hand);
  }
  printf("\n");
}


