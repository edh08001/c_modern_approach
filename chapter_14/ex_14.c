#include <stdio.h>

#define N 10
#define INC(x) x+1
#define SUB(x,y) x-y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR((x))*(x))
#define M1(x,y) int x##y
#define M2(x,y) #x #y

int main(void)
{

  int a[N], i, j, k, m;

  #ifdef N
    i = j;
  #else 
    j = i;
  #endif

    i = 10 * INC(j);
    i = SUB(j,k);
    i = SQR(SQR(j));
    i = CUBE(j);
    M1(j,k) = i;
    puts(M2(i,j));

    i = SQR(j);

  return 0;

}
