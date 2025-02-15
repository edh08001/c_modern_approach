#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define QUEUE_SIZE 100

Item contents[QUEUE_SIZE];
int head = 0;

void terminate(char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void insert_item(int x)
{
  int i;

  if (is_full()) 
    terminate("Cannot insert, queue is full");

  for (i = head; i > 0; i--){
    contents[i] = contents[i-1];
  }
  contents[i] = x;
  head++;
}

void remove_next_item(void)
{
  head--; 
}

Item get_next_item(void)
{
  if (is_empty())
    terminate("Cannot get first, queue is empty.");
    
  return contents[--head];
}

Item get_last_item(void)
{
  if (is_empty())
    printf("Cannot get last, queue is empty.\n");
   
  return contents[0];
}

bool is_empty(void)
{
  return head == 0;
}

bool is_full(void)
{
  return head == QUEUE_SIZE;
}
