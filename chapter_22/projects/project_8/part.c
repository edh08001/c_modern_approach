#include "part.h"
#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int num_parts, inventory_size; //declared in inventory.c

void add_part(part **parts, int n)
{
  if (num_parts >= n) {
    part *temp = realloc(*parts, sizeof(part) * (inventory_size * 2));
    if (temp == NULL){
      printf("Error: unique part count reached, part not added.\n");
      exit(EXIT_FAILURE);
    } else {
      inventory_size *= 2;
      *parts = temp;
    }
  }

  part part;
  int part_number;
  char ch;
  printf("Enter Part Number: ");
  scanf("%d", &part_number);
  if (find_part(*parts, part_number) >= 0) {
    printf("Part number already exists.\n\n");
  } else {
    part.part_number = part_number;
    printf("Enter Part Name: ");
    read_line(part.part_name, NAME_LENGTH);
    printf("Enter Part Quantity: ");
    scanf("%d", &part.on_hand);
    printf("Enter Part Price: ");
    scanf("%lf", &part.price);
    (*parts)[num_parts++] = part;
    //insert_part(*parts, part);
    printf("\n");
  }
}

void insert_part(part *parts, part p)
{
  int i, j;
  part t1, t2; 
  bool inserted = false;

  for (i = 0; i < num_parts; i++){
    if (p.part_number < parts[i].part_number){
      t2 = parts[i];
      for (j = i; j < num_parts; j++){
        t1 = parts[j+1];
        parts[j+1] = t2; 
        t2 = t1;
      }
      parts[i] = p;
      inserted = true;
      break;
    }
  }

  if (!inserted) parts[i] = p;

  num_parts++;
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

void update_part_price(part *parts) 
{
  int part_num, i;
  double price;
  printf("Enter Part Number: ");
  scanf("%d", &part_num);
  i = find_part(parts, part_num);
  if (i >= 0) {
    printf("Enter New Part Price: ");
    scanf("%lf", &price);
    parts[i].price += price;
  } else {
    printf("Part number not found.\n");
  }
  printf("\n");
}

void display_all_parts(part *parts) 
{
  qsort(parts, num_parts, sizeof(part), compare_parts);
  printf("Part Number  |  Part Name                    |  Part Qty  |  Part Price\n");
  for (int i = 0; i < num_parts; i++){
    printf("%-16d%-32s%-13d%.2lf\n", parts[i].part_number, parts[i].part_name, parts[i].on_hand, parts[i].price);
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

int compare_parts(const void *p1, const void *p2)
{
  const part *q1 = p1;
  const part *q2 = p2;
  
  return q1->part_number - q2->part_number;
}
