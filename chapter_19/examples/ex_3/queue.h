#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

void insert_item(Item x);
void remove_next_item(void);
Item get_next_item(void);
Item get_last_item(void);
bool is_empty(void);
bool is_full(void);

#endif
