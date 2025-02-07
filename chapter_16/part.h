#ifndef PART_H
#define PART_H

#define NAME_LENGTH 25

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
 * insert_part: Takes a part array and a part, and inserts the    *
 *              part at the correct position in the array. It does*
 *              this by scanning until it finds the correct pos,  *
 *              moving the remaining parts down one each, and then*
 *              inserting the new part into the correct spot      *
 ******************************************************************/
void insert_part(part *parts, part part);

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

/******************************************************************
 * find_part: Searches a part array and returns the array index   *
 *            that the part occupies, or -1 if the part does not  *
 *            exist.                                              *
 ******************************************************************/
int find_part(part *parts, int part_num);

#endif
