#ifndef READ_LINE_H
#define READ_LINE_H

#define WORD_SIZE 20

/**********************************************************
 * read_line: Prompts the user to input text and stores   *
 *            the input into a variable sized array.      *
 *            Returns a pointer to the string for storage *
 *            in an array of string pointers.             *
 **********************************************************/
int read_line(char str[], int n);

/**********************************************************
 * my_malloc: Attempts to create a pointer with size n.   *
 *            If successful, returns it, if not prints an *
 *            error message and exits program.            *
 **********************************************************/
void *my_malloc(int n);

#endif
