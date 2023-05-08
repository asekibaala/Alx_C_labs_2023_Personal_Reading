#include <stdio.h>
#include <math.h>

#define  N  10

int
main (void)
{
  int i;
  float val = 2.;

  for (i = 0; i < N; i++)
    val = sqrtf (val);
  for (i = 0; i < N; i++)
    val *= val;
  printf ("%e\n", fabs (val - 2.));
  return 0;
}