#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;          //data stored in the node
  struct node *next;  //pointer to the next node in the list
};

void add_to_list(struct node **list, int n);

struct node *search_list(struct node *list, int n);

struct node *delete_from_list(struct node *list, int n);

void delete_list(struct node *list);

struct node *first = NULL;

int main(void)
{

  add_to_list(&first, 10);
  add_to_list(&first, 20);
  add_to_list(&first, 30);
  add_to_list(&first, 40);
  add_to_list(&first, 50);

  first = delete_from_list(first, 50);
  struct node *head = first;

  do{
    printf("%d ", head->value);
    head = head->next;
  }while (head != NULL);

  printf("\n");
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
  struct node *head, *del;

  if (list->value == n) {
    return list->next;
  }
  
  for (head = list; 
       head->next && head->next->value != n; 
       head = head->next)
    ;

  del = head->next;
  head->next = del->next;
  free(del); 

  return list;
}

void delete_list(struct node *list)
{ 
  struct node *prev;

  do {
    prev = list;
    list = list->next;
    free(prev);
  } while (list != NULL);
}
