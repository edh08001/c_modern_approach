#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DIGITNUM 10056

int check(int x, int y, int n);

int gcd(int m, int n);

int gcd_r(int m, int n);

int day_of_year(int month, int day, int year);

int num_digits(int num);

int from_right(int num, int moves);

int main(int argc, char *argv[])
{
  printf("Check 1: %d\n", check(1, 2, 3));
  printf("Check 2: %d\n", check(1, 4, 3));
  printf("GCD of 10 and 12 is %d\n", gcd(10, 12));
  printf("GCD of 10 and 12 is %d\n", gcd_r(10, 12));
  printf("Day number for 03/20/2023: %d\n", day_of_year(03, 20, 2023));
  printf("Number of digits in %d is %d\n", DIGITNUM, num_digits(DIGITNUM));
  printf("Number %d is %d digits from the right of %d\n", from_right(DIGITNUM, 3), 3, DIGITNUM);
  return EXIT_SUCCESS;

}

int check(int x, int y, int n){

  return (x >= 0 && x < n && y >= 0 && y < n);
}

int gcd(int m, int n){
  int remainder; 

  while (n != 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  return m; 
}

int gcd_r(int m, int n){
  if(n == 0) return m;
  
  return gcd_r(n, m%n); 
}

int day_of_year(int month, int day, int year){
    
  bool leap = false;
  if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
    leap = true;
  }


  int i, total = 0, month_days[12] = {31, (leap ? 29 : 28), 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31};

  for(i = month - 2; i >= 0; i--){
    total += month_days[i];
  }
  
  return total + day;
}

int num_digits(int num){
  int count = 0;

  do {
    num /= 10;
    count++;
  } while (num != 0);

  return count;
}

int from_right(int num, int moves){
  int count = 0, remainder = 0;

  do {
    remainder = num % 10;
    num /= 10;
    count++;
  } while (count <= moves);

  return remainder;
}
