#include <math.h>
#include <stdio.h>

#define DISP(f,x) printf(#f "(%g) = %g\n", (x), (f(x)))
#define DISP2(f,x,y) printf(#f "(%d,%d) = %d\n", (x), (y), (f((x),(y))))

int sum(int x, int y);

int main(void)
{
  DISP(sqrt, 3.0);
  DISP2(sum, 2, 3+5);


}

int sum(int x, int y)
{

  return x + y;
}
