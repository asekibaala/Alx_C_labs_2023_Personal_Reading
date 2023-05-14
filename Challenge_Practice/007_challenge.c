#include <stdio.h>
#include <stdlib.h>

int main ()
{
  char *prompt = "($ )";
  char *lineptr;
  size_t n = 0;
  ssize_t nchars_read;

  while (1)
    {
      printf("%s", prompt);
      nchars_read = getline(&lineptr, &n, stdin);
      if (nchars_read == -1)
	{
	  break;
	}
      printf ("%s\n",lineptr);
    }
  free (lineptr);
  return 0;
}
