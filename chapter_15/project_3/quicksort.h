#ifndef QUICKSORT_H
#define QUICKSORT_H

/**************************************************************************
 * quicksort: Takes an array as well as a low and high element number     *
 *            (starting at 0 and a[max]) and calls split. Once split      *
 *            returns the position of the first positioned num, quicksort *
 *            recursively calls itself with ranges of 0 to pos-1 and      *
 *            pos+1 to max. Ends when min and max calls are equal or      *
 *            low > max.                                                  *
 **************************************************************************/
void quicksort(int a[], int low, int high);

/**************************************************************************
 * split: Takes an array and two positions within and orients the a[0]    *
 *        element where it needs to be in the array by placing all        *
 *        elements larger than it in later positions, and all elements    *
 *        smaller than it in earlier positions. Returns the position of   *
 *        the sorted element                                              *
 **************************************************************************/
int split(int a[], int low, int high);

#endif
