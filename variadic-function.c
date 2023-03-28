#include <stdarg.h>

#include <stdio.h>

int
sum (int n, ...)
{
  va_list list;
  va_start (list, n);
  int tot = 0;
  while (n--)
    {
      int v = va_arg (list, int);
      tot += v;
    }
  va_end (list);
  return tot;
}

int
main (void)
{
  printf ("%d\n", sum (0));
  printf ("%d\n", sum (2, 1, 3));
  printf ("%d\n", sum (10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1));
  return 0;
}