#include <stdio.h>
#include <stdlib.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void)
{
  #pragma ident "foo"
  IDENT(foo)
}
