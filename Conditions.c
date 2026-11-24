#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Returns 1 if x is prime and 0 otherwise */
int isPrime(int x) {
  int isPrime = 1;

  if (x <= 1)
    isPrime = 0;
  else if (x == 2)
    isPrime = 1;
  else if (x % 2 == 0)
    isPrime = 0;
  else {
    for (int i = 3; i * i <= x; i += 2) {
      if (x % i == 0) {
        isPrime = 0;
        break;
      }
    }
  }

  if (isPrime)
    printf("isPrime: 1 (The number is prime)\n");
  else
    printf("isPrime: 0 (The number is not prime)\n");

  return isPrime;
}

/* Returns 1 if gcd(x,2)=1 and 0 otherwise */
int isGcd1(int x) {
  if (x % 2 == 1) {
    printf("isGcd1: 1 (The number is odd)\n");
    return 1;
  }

  printf("isGcd1: 0 (The number is even)\n");
  return 0;
}

/* Returns 1 if (9^x-2) mod 5 = 2 and 0 otherwise */
int is2mod5(int x) {
  int result = 1;

  for (int i = 0; i < x; i++) {
    result = (result * 9) % 5;
  }

  int condition = (result - 2 + 5) % 5 == 2;

  if (condition)
    printf("is2mod5: 1 (The remainder is two)\n");
  else
    printf("is2mod5: 0 (The remainder is not two)\n");

  return condition;
}

int main(void) {
  int x;
  int p, q, r;

  printf("What number do you want to test?\n");
  scanf("%d", &x);
  p = isPrime(x);
  q = isGcd1(x);
  r = is2mod5(x);

  if ((p && !r) || !(p || !q || r) || (!p && !q && r)) {
    printf("\nYou have found a valid x\n");
    printf("p is %d, q is %d, and r is %d\n", p, q, r);
  } else {
    printf("\nTry again!\n");
  }

  return EXIT_SUCCESS;
}