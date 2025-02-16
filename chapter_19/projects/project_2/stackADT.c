#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE_START 2;

struct stack_int {
    int *contents;
    int entries;
    int size;
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

    s->contents = malloc(sizeof(int) * s->size);

    if (s->contents == NULL)
        terminate("Unable to create initial container.");
    s->entries = 0;
    return s;
}

void destroy_stack(Stack s)
{
    free(s->contents);
    free(s);
}

void make_empty(Stack s)
{
    while(s->entries > 0)
        pop(s);
}

bool is_empty(Stack s)
{
    return s->entries == 0;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, int i)
{
    if (s->entries == s->size - 1){
        int *new_contents = realloc(s->contents, sizeof(int) * (s->size * 2));
        if (new_contents == NULL)
            terminate("Cannot resize contents.");
        s->size *= 2;
        s->contents = new_contents;
        free(new_contents);
    }

    s->contents[(s->entries)++] = i;
}

int pop(Stack s)
{
    return s->contents[--s->entries];
}
