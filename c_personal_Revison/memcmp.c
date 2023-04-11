#include <string.h>
#include <stdio.h>

typedef struct
{
  int i;
  float f;
} str_t;

int
main (void)
{
  str_t s1 = { 1, 1.23 }, s2 =
  {
  1, 3.21};

  printf ("%d\n", memcmp (&s1, &s1, sizeof (str_t)));
  printf ("%d\n", memcmp (&s1, &s2, sizeof (str_t)));
  return 0;
}