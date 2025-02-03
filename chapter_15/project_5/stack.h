#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

/***********************************************************
 * make_empty: Empties the stack by setting top stack      *
 *             position == 0 (array location 0)            *
 ***********************************************************/
void make_empty(void);

/***********************************************************
 * is_empty: Returns true if stack has no elements by      *
 *           checking if top stack position = 0            *
 ***********************************************************/
bool is_empty(void);

/***********************************************************
 * is_full: Returns true if stack is at its max position,  *
 *          checking if top stack position = max           *
 ***********************************************************/
bool is_full(void);

/***********************************************************
 * push: Adds an integer to the top of the stack, at       *
 *       top, and increments top                           *
 ***********************************************************/
void push(int i);
 
/***********************************************************
 * pop: Removes the topmost element from the stack and     *
 *      returns it as an int. Decrements top so that the   *
 *      next position == the position that was popped      *
 ***********************************************************/
int pop(void);

#endif
