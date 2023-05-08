#include <stdio.h>

int
main (void)
{
  int i;
  long long fact = 1;

  for (i = 1; i <= 21; i++)
    {
      fact *= i;
      printf ("%2d! = %lld\n", i, fact);
    }
  return 0;
}