#include <stdbool.h>
#include <stdio.h>

struct point {
  int x, y;
};

struct rect {
  struct point top_left, bot_right;
};

int get_area(struct rect r) 
{
  int l, w;

  l = r.top_left.y - r.bot_right.y;
  w = r.bot_right.x - r.top_left.x;

  return l * w;
}

struct point get_center(struct rect r)
{
  int c_x, c_y;
  c_x = (r.bot_right.x + r.top_left.x)/2;
  c_y = (r.top_left.y + r.bot_right.y)/2;

  return (struct point) {c_x, c_y};
}

struct rect move_rect(struct rect r, int x, int y)
{
  return (struct rect) {.top_left.x = r.top_left.x + x,
                        .top_left.y = r.top_left.y + y,
                        .bot_right.x = r.bot_right.x + x,
                        .bot_right.y = r.bot_right.y + y};
}

bool lies_within(struct rect r, struct point p)
{
  return ((   r.top_left.x <= p.x && p.x <= r.bot_right.x)
          && (r.bot_right.y <= p.y && p.y <= r.top_left.y));
}

int main (void)
{
  struct point p1 = {10, 10};
  struct point p2 = {15, 5};

  struct rect r = {p1, p2};

  struct point c = get_center(r);

  printf("Area is: %d\n", get_area(r));
  printf("Center is: x = %d, y = %d\n", c.x, c.y);
  printf("12, 7 lies within: %d\n", lies_within(r, c));
  r = move_rect(r, 1, 1);
  printf("New locations after moving 1, 1 are:\nTL: x = %d y = %d\nBR: x = %d y = %d\n", r.top_left.x, r.top_left.y, r.bot_right.x, r.bot_right.y);

  return 1;
}
