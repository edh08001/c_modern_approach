#include <stdio.h>

struct _ufloat {
    unsigned int frac:23;
    unsigned int exp:8;
    unsigned int sign:1;
};

void print_decimal(unsigned int n)
{
    int i;
    for (i = 31; i >= 0; i--){
        printf("%d", (n & (1 << i)) ? 1 : 0);
    }
    printf("\n");
}

int main(void)
{
    struct _ufloat f = {
        .frac = 0,
        .exp = 128,
        .sign = 1,
    };
    
    float *test = (float*) &f;
 
    printf("%f\n", *test); 
}
