#include <stdio.h>

#define NAME_LEN 60

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

void print_part (struct part *p)
{
  printf("Part number: %d\n", p->number);
  printf("Part name: %s\n", p->name);
  printf("Part qty: %d\n", p->on_hand);
}

