#include <stdio.h>

struct complex {
  double real, imaginary;
} ;

struct complex make_complex(double x, double y)
{
  return (struct complex) {.real = x, .imaginary = y};
}

struct complex add_complex(struct complex x, struct complex y)
{
  return (struct complex) {.real = x.real + y.real, 
                           .imaginary = x.imaginary + y.imaginary};
}

int main(void)
{
  struct complex c1, c2, c3;

  c1 = make_complex(1.0, 0.0);
  c2.real = 1.0;
  c2.imaginary = 0.0;

  c3 = add_complex(c1, c2);

  printf("%lf, %lf\n", c3.real, c3.imaginary);

  return 1;

}
