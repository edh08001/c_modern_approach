#include <stdio.h>
#include <stdlib.h>

union _ufloat {
    float f_rep;
    struct {
        unsigned int frac:23;
        unsigned int exp:8;
        unsigned int sign:1;
    } s_rep;
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
    div_t my_test = div(7, 3);

    printf("Quotient: %d, Remainder: %d\n", my_test.quot, my_test.rem);
    union _ufloat f;
    f.s_rep.frac = 0;
    f.s_rep.exp = 128;
    f.s_rep.sign = 1;

    
    float *test = (float*) &f.s_rep;
 
    printf("%f\n", f.f_rep); 
    printf("%f\n", *test);

}
