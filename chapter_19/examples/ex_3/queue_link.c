#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


struct node {
  Item item;
  struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;

void terminate(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void insert_item(Item x)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    terminate("Error allocating memory for new node.");

  new_node->item = x;
  new_node->next = last;

  if(is_empty())
    first = new_node;

  last = new_node;
}

void remove_next_item(void)
{
  if (is_empty())
    terminate("Cannot remove item, queue is empty.");

  struct node *new_first = last;

  while(new_first->next->next != NULL)
    new_first = new_first->next;

  first = new_first;
}

Item get_next_item(void)
{
  return first->item;
}

Item get_last_item(void)
{
  return last->item;
}

bool is_empty(void)
{
  return (first == NULL);
}

bool is_full(void)
{
  return false;
}
