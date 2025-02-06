#include <stdio.h>

struct fraction {
  int numerator, denominator;
};

struct fraction reduce(struct fraction frac) 
{
  int i, gcd = 1;
  for (i = 2; i <= frac.numerator; i++){
    if (frac.numerator % i == 0 && frac.denominator % i == 0)
      gcd = i;
  }
  return (struct fraction) {.numerator = frac.numerator/gcd,
                            .denominator = frac.denominator/gcd};
}

struct fraction add(struct fraction frac1, struct fraction frac2)
{

  int calc_num = (frac1.numerator * frac2.denominator) + (frac2.numerator * frac1.denominator);
  int calc_den = frac1.denominator * frac2.denominator;

  return reduce((struct fraction) {calc_num, calc_den});
  
}

struct fraction subtract(struct fraction frac1, struct fraction frac2)
{

  int calc_num = (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
  int calc_den = frac1.denominator * frac2.denominator;

  return reduce((struct fraction) {calc_num, calc_den});
  
}

struct fraction multiply(struct fraction frac1, struct fraction frac2)
{

  int calc_num = frac1.numerator * frac2.numerator;
  int calc_den = frac1.denominator * frac2.denominator;

  return reduce((struct fraction) {calc_num, calc_den});
  
}

struct fraction divide(struct fraction frac1, struct fraction frac2)
{

  int calc_num = frac1.numerator * frac2.denominator;
  int calc_den = frac1.denominator * frac2.numerator;

  return reduce((struct fraction) {calc_num, calc_den});
  
}

int main(void)
{
  struct fraction f = {6, 12};
  struct fraction nf = reduce(f);

  struct fraction af = {1, 2};
  struct fraction af2 = {1, 3};
  struct fraction af_add = add(af, af2);
  struct fraction af_sub = subtract(af, af2);
  struct fraction af_mul = multiply(af, af2);
  struct fraction af_div = divide(af, af2);

  printf("%d/%d reduces to %d/%d\n", f.numerator, f.denominator,
                                     nf.numerator, nf.denominator);

  printf("%d/%d + %d/%d = %d/%d\n", af.numerator, af.denominator,
                                    af2.numerator, af2.denominator,
                                    af_add.numerator, af_add.denominator);

  printf("%d/%d - %d/%d = %d/%d\n", af.numerator, af.denominator,
                                    af2.numerator, af2.denominator,
                                    af_sub.numerator, af_sub.denominator);
  
  printf("%d/%d * %d/%d = %d/%d\n", af.numerator, af.denominator,
                                    af2.numerator, af2.denominator,
                                    af_mul.numerator, af_mul.denominator);

  printf("%d/%d / %d/%d = %d/%d\n", af.numerator, af.denominator,
                                    af2.numerator, af2.denominator,
                                    af_div.numerator, af_div.denominator);
  return 1;
}

