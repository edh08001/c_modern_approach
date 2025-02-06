#include <stdbool.h>
#include <stdio.h>

#define BRIGHT_FACTOR 0.7

struct color {
  int red, green, blue;
};

struct color make_color(int red, int green, int blue)
{
  return (struct color) {red, green, blue};
}

int get_red(struct color *c)
{
  return c->red;
}

bool equal_color(struct color *c1, struct color *c2)
{
  return (   c1->red == c2->red 
          && c1->green == c2->green
          && c1->blue == c2->blue);
}

struct color brighter(struct color *c) 
{
  if (c->red == 0 && c->green == 0 && c->blue == 0){
    c->red = c->green = c->blue = 3;
    return *c;
  } else {
    if (c->red < 3) 
      c->red = 3 / BRIGHT_FACTOR;
    else if (c->red / BRIGHT_FACTOR > 255)
      c->red = 255;
    else
      c->red /= BRIGHT_FACTOR;

    if (c->green < 3) 
      c->green = 3 / BRIGHT_FACTOR;
    else if (c->green / BRIGHT_FACTOR > 255)
      c->green = 255;
    else
      c->green /= BRIGHT_FACTOR;

    if (c->blue < 3) 
      c->blue = 3 / BRIGHT_FACTOR;
    else if (c->blue / BRIGHT_FACTOR > 255)
      c->blue = 255;
    else
      c->blue /= BRIGHT_FACTOR;

    return *c;
  }
}

struct color darker(struct color *c) 
{
  c->red *= BRIGHT_FACTOR;
  c->green *= BRIGHT_FACTOR;
  c->blue *= BRIGHT_FACTOR;

  return *c;
}

int main(void)
{

  struct color c = make_color(250, 150, 1);
  c = brighter(&c);
  printf("Red: %d Green: %d Blue: %d\n", c.red, c.green, c.blue);


  return 1;
}
