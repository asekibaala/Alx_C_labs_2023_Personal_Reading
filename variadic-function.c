#include <stdarg.h>

#include <stdio.h>

int
sum (int n, ...)
{
  va_list list; //defining a list to keep track of the parameters
  va_start (list, n); //intilizing the list
  int tot = 0;
  while (n--)
    {
      int v = va_arg (list, int); //picking a value while moving to the next one
      tot += v;
    }
  va_end (list); //closig the list after processing 
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