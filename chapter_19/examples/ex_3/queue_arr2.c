#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define QUEUE_SIZE 100

Item contents[QUEUE_SIZE];
int next = 0, last = 0, size = 0; 

void terminate(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void insert_item(int x)
{
  if (is_full())
    terminate("Cannot insert item, queue is full.");

  if (last == QUEUE_SIZE - 1)
    last = 0;

  contents[last++] = x;
  size++;
}

void remove_next_item(void)
{
  if (is_empty())
    terminate("Cannot remove item, queue is empty.");

  size--;

  if (next == QUEUE_SIZE - 1)
    next = 0;
  else
    next++;
}

Item get_next_item(void)
{
  if (is_empty())
    terminate("Cannot get next item, queue is empty.");

  return contents[next];
}

Item get_last_item(void)
{
  if (is_empty())
    terminate("Cannot get last item, queue is empty.");

  if (last == 0 && size > 0)
    return contents[QUEUE_SIZE - 1];

  return contents[last-1];
   
}

bool is_empty(void)
{
  return size == 0;
}

bool is_full(void)
{
  return size == QUEUE_SIZE;
}
