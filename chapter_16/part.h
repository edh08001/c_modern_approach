#ifndef PART_H
#define PART_H

#define NAME_LENGTH 25

extern int num_parts;

typedef struct {
  int part_number;
  char part_name[NAME_LENGTH+1];
  int on_hand;
} part;

/******************************************************************
 * add_part: Adds a part to the part database. Accepts an array   *
 *           which will store the database, as well as the max    *
 *           size of the array to check that there is space to    *
 *           store additional parts. If there is no space, this   *
 *           function will display an error message.              *
 ******************************************************************/
void add_part(part *parts, int n);

/******************************************************************
 * search_part: Takes a part by number and lists the name as well *
 *             as the quantity currently available.               *
 ******************************************************************/
void search_part(part *parts);

/******************************************************************
 * update_quantity: When given a part and a quantity, this will   *
 *                  update the quantity of the part pointed to.   *
 *                  This function takes both positive and         *
 *                  negative values to increment or decrement     *
 ******************************************************************/
void update_part_quantity(part *parts);

/******************************************************************
 * display_all: Takes a parts array and prints the item name, the *
 *              item id, and the current quantity. Goes through   *
 *              all parts in the database in the order they were  *
 *              submitted                                         *
 ******************************************************************/
void display_all_parts(part *parts);

#endif
