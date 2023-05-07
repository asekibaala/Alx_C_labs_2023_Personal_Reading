#include <stdio.h>
#include <math.h>
#include <fenv.h>

#pragma STDC FENV_ACCESS ON

int
main (void)
{
  float x = 2.f;
  float y = 3.f;
  fesetround (FE_TONEAREST);
  printf ("%.7f ", x / y);
  printf ("%.7f\n", (-x) / y);
  fesetround (FE_UPWARD);
  printf ("%.7f ", x / y);
  printf ("%.7f\n", (-x) / y);
  fesetround (FE_DOWNWARD);
  printf ("%.7f ", x / y);
  printf ("%.7f\n", (-x) / y);
  fesetround (FE_TOWARDZERO);
  printf ("%.7f ", x / y);
  printf ("%.7f\n", (-x) / y);
  return 0;
}