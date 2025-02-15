#ifndef STACKADT2_H
#define STACKADT2_H

#include <stdbool.h>

typedef int Item;

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(const Stack s);
bool is_full(const Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif
