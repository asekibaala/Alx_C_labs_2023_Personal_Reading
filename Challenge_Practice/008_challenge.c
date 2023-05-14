#include <stdio.h>
#include <stdlib.h>

size_t _getline(char *s, size_t n, FILE *stream)

{
  size_t i =0;
  char c;

  while ((c = getc(stream)) !=EOF && c != '\n' && i < n)
    {
      s[i++]=c;
    }
  s[i] = '\0';

  return i;
  
}
