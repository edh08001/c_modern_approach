#include <stdio.h>

typedef struct {
  double real, imaginary;
} Complex;

Complex make_complex(double x, double y)
{
  return (Complex) {.real = x, .imaginary = y};
}

Complex add_complex(Complex x, Complex y)
{
  return (Complex) {.real = x.real + y.real, 
                           .imaginary = x.imaginary + y.imaginary};
}

int main(void)
{
  Complex c1, c2, c3;

  c1 = make_complex(1.0, 0.0);
  c2.real = 1.0;
  c2.imaginary = 0.0;

  c3 = add_complex(c1, c2);

  printf("%lf, %lf\n", c3.real, c3.imaginary);

  return 1;

}
