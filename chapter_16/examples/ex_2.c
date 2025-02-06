struct c {
  double real, imaginary;
} c3;

int main(void)
{
  struct c c1 = {0.0, 1.0};
  struct c c2 = {1.0, 0.0};

  c1.real = c2.real;
  c1.imaginary = c2.imaginary;

  c3.real = c1.real + c2.real;
  c3.imaginary = c1.imaginary + c2.imaginary;

}
