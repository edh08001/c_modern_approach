#include "part.h"
#include "readline.h"
#include <stdio.h>
#include <stdbool.h>

extern int num_parts;

void add_part(part *parts, int n)
{
  if (num_parts < n) {
    part part;
    int part_number;
    char ch;
    unsigned long size;
    printf("Enter Part Number: ");
    scanf("%d", &part_number);
    if (find_part(parts, part_number) >= 0) {
      printf("Part number already exists.\n\n");
    } else {
      part.part_number = part_number;
      printf("Enter Part Name: ");
      read_line(part.part_name, NAME_LENGTH);
      printf("Enter Part Quantity: ");
      scanf("%d", &part.on_hand);
      parts[num_parts++] = part;
      printf("\n");
    }
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
  i = find_part(parts, part_num);
  if (i >= 0) {
    printf("Part Name: %s\n", parts[i].part_name);
    printf("Part Quantity: %d\n\n", parts[i].on_hand);
  } else {
   printf("No part with that id exists.\n");
  }
}

void update_part_quantity(part *parts) 
{
  int qty, part_num, i;
  printf("Enter Part Number: ");
  scanf("%d", &part_num);
  i = find_part(parts, part_num);
  if (i >= 0) {
    printf("Enter Part Quantity Adjustment: ");
    scanf("%d", &qty);
    parts[i].on_hand += qty;
  } else {
    printf("Part number not found.\n");
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

int find_part(part *parts, int part_num)
{
  int i;
  for (i = 0; i < num_parts; i++){
    if (parts[i].part_number == part_num)
      return i;
  }
  return -1;
}
