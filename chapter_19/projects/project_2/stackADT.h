#include <stdbool.h>

typedef struct stack_int *Stack;

Stack create_stack(void);
void destroy_stack(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int i);
int pop(Stack s);
