#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
    int data;
    struct node *next;
};

struct stack_int {
    struct node *top;
};

void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create_stack(void)
{
    Stack s = malloc(sizeof(struct stack_int));
    if (s == NULL)
        terminate("Unable to create new stack.");
    s->top = NULL;
    return s;
}

void destroy_stack(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while(s->top != NULL)
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Unable to create new node.");
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack s)
{
    int i;
    struct node *old_top;

    if (is_empty(s))
        terminate("Error in pop: stack is empty");

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    free(old_top);
    return i;
}
