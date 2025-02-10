#include <stdlib.h>
#include <stdio.h>

void * my_malloc(int n);

struct point {int x, y;};
struct rectangle {struct point upper_left, lower_right;};

int main(void)
{
  struct rectangle *p = my_malloc(sizeof(struct rectangle));

  p->upper_left.x = 10;
  p->upper_left.y = 25;
  p->lower_right.x = 20;
  p->lower_right.y = 15;

}

void * my_malloc(int n)
{
  void * p = malloc(n);
  if (p == NULL) {
    printf("Insufficient memory for my_malloc");
    exit(EXIT_FAILURE);
  }

  return p;
}
