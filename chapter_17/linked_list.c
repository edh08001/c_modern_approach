#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;          //data stored in the node
  struct node *next;  //pointer to the next node in the list
};

void add_to_list(struct node **list, int n);

struct node *search_list(struct node *list, int n);

struct node *delete_from_list(struct node *list, int n);

struct node *first = NULL;

int main(void)
{

  add_to_list(&first, 10);
  add_to_list(&first, 20);

}

void add_to_list(struct node **list, int n)
{
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed in add_to_list\n");
    exit(EXIT_FAILURE);
  }

  new_node->value = n;
  new_node->next = *list;
  *list = new_node;
}

struct node *search_list(struct node *list, int n)
{
  struct node *p;

  for (p = list; p != NULL; p = p->next){
    if (p->value == n)
      return p;
  }
  return NULL;

  //---Much more straightforward way below---
  //while (list != NULL && list->value != n)
  //  list = list->next;
  //return list;
}

struct node *delete_from_list(struct node *list, int n)
{
  struct node *cur, *prev;

  for (cur = list, prev = NULL;
       cur != NULL && cur->value != n;
       prev = cur, cur = cur->next)
    ;

  if (cur == NULL)
    return list;              //n was not found
  if (prev == NULL)
    list = list->next;        //n was the first node
  else 
    prev->next = cur->next;   //n was some other node

  free(cur);
  return list;
}

