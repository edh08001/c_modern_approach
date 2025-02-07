#define RECTANGLE 0
#define CIRCLE 1
#define PI 3.14159

struct point {
  int x, y;
};

struct shape {
  int shape_kind;
  struct point center;
  union {
    struct {
      int height, width;
    } rectangle;
    struct {
      int radius;
    } circle;
  } u;
} s;

int area(struct shape *s)
{
  if (s->shape_kind == RECTANGLE)
    return s->u.rectangle.width * s->u.rectangle.height;
  else
    return PI * (s->u.circle.radius * s->u.circle.radius);
}

void move(struct shape *s, int x, int y)
{
  s->center.x += x;
  s->center.y += y;
}

void scale(struct shape *s, double factor)
{
  if (s->shape_kind == RECTANGLE){
    s->u.rectangle.width *= factor;
    s->u.rectangle.height *= factor;
  } else {
    s->u.circle.radius *= factor;
  }
}

int main(void)
{
   
}
