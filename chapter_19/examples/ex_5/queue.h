#include <stdbool.h>

typedef int Item;

typedef struct queue_fixed *Queue;

Queue create();
void destroy(Queue q);
void insert(Queue q, Item i);
void remove_first(Queue);
Item get_first_item(Queue);
Item get_last_item(Queue);
bool is_empty(Queue);

