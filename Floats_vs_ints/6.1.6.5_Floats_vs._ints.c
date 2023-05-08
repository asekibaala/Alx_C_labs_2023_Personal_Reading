#include <stdio.h>
#include <gmp.h>

#define N  	10
#define	PREC	1024

int
main (void)
{
  int i;
  mpf_t val, two;
  mpf_init2 (val, PREC);
  mpf_init2 (two, PREC);
  mpf_set_d (val, 2.);
  mpf_set (two, val);

  for (i = 0; i < N; i++)
    mpf_sqrt (val, val);
  for (i = 0; i < N; i++)
    mpf_mul (val, val, val);

  mpf_init2 (dif, PREC);
  mpf_sub (dif, val, two);
  mpf_abs (dif, dif);
  double difd = mpf_get_d (dif);
  printf ("%e\n", difd);
  return 0;
}

/*
line 11: floating-point variables are represented as an mpf_t type;
line 12: the mpf_init2() function initializes the variable and sets the number of precision bits it uses (we’ve decided to use 1024 bits for the purpose)
line 14: the mpf_set_d() function sets the value of the mpf_t variable using another value of type double;
line 15: the mpf_set() function assigns the value of the second argument to the first one;
line 18: the invocation:
mpf_sqrt(x,y)
works like

x = sqrt(y)
line 20: the invocation:
mpf_mul(x,y,z)
acts as:

x = y * z
line 24: mpf_abs(x,y) is an equivalent of x = abs(y)
line 25: the mpf_get_d() function converts the mpf_t value into a double;
*/