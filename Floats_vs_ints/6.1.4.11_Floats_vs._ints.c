#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <float.h>

#define _show_exc(x)	printf(#x"=%s; ", fetestexcept(x) ? "ON" : "OFF")

#pragma STDC FENV_ACCESS ON

void
show_exc (void)
{
  _show_exc (FE_DIVBYZERO);
  _show_exc (FE_INEXACT);
  _show_exc (FE_INVALID);
  _show_exc (FE_OVERFLOW);
  _show_exc (FE_UNDERFLOW);
  puts ("");
}

int
main (void)
{
  show_exc ();
  float x = 1.f, y = 0.f, z1 = x / y;
  show_exc ();
  float z2 = sqrtf (-x);
  show_exc ();
  float z3 = x / 1234.5678f;
  show_exc ();
  float z4 = x / FLT_MAX;
  z4 /= FLT_MAX;
  show_exc ();
  float z5 = x / FLT_MIN;
  z5 /= FLT_MIN;
  show_exc ();
  fexcept_t flags;
  fegetexceptflag (&flags, FE_ALL_EXCEPT);
  feclearexcept (FE_ALL_EXCEPT);
  show_exc ();
  feraiseexcept (FE_OVERFLOW | FE_UNDERFLOW);
  show_exc ();
  fesetexceptflag (&flags, FE_DIVBYZERO);
  show_exc ();
  return 0;
}