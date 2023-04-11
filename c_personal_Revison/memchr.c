#include <string.h>
#include <stdio.h>


void
print (char *b, char *p)
{
  if (p)
    printf ("'%c' [%ld]\n", *p, p - b);
  else
    printf ("(null)\n");
}

int
main (void)
{
  char abc['Z' - 'A' + 1];
  int i;

  for (i = 'A'; i <= 'Z'; i++)
    abc[i - 'A'] = i;

  print (abc, memchr (abc, 'S', sizeof (abc)));
  print (abc, memchr (abc, 'S', 10));
  print (abc, memchr (abc, 's', sizeof (abc)));
  return 0;
}