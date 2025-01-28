#include <stdlib.h>

/**************************************************
 * Swaps two variables using pointers             *
 **************************************************/
void swap(int *p, int *q);

int main(int argc, char *argv[])
{

  return EXIT_SUCCESS;
}

void swap(int *p, int *q){
  int temp = *p;
  *p = *q;
  *q = temp;
}
