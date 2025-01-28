#include <stdio.h>
#include <stdlib.h>

long do_math(int x);

int main(int argc, char *argv[])
{

  printf("Math is %ld\n", do_math(5));

  return EXIT_SUCCESS;
}

long do_math(int x){
  long x_a, x_b, x_c, x_d, x_e;
  x_a = x_b = x_c = x_d = x_e = x;

  for(int i = 0; i < 4; i++){
    x_a *= x;
    if (i < 3){
      x_b *= x;
    }
    if (i < 2){
      x_c *= x;
    }
    if (i < 1){
      x_d *= x;
    }
  }
  x_a *= 3;
  x_b *= 2;
  x_c *= 5;
  x_e *= 7;

  return (x_a + x_b - x_c - x_d + x_e - 6);

}
