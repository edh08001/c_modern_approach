#ifndef WORD_H
#define WORD_H

#include <stdio.h>
/********************************************************************
 * read_word: Reads the next word from the input and stores it in   *
 *            word. Makes word empty if no word could be read       *
 *            beacuse of the end-of-file. Truncates the word if its *
 *            length exceeds len. Returns num of chars in word.     *
 ********************************************************************/
  
int read_word(char *word, int len, FILE *fp);

#endif
