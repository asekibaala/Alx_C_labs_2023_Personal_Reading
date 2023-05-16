#include "main.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */

char *_strdup(const char *s)
{
  char *new;
  size_t len;

  len = _strlen(s);
  /*Allocate memory where to keep a copy of the string plus 1 for the null character*/
  new = malloc(sizeof(char) * (len + 1));
  if (new == NULL)
    {
      return (NULL);
    }
  _memcpy(new,s,len+1);
  return (new);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */

int _strlen(const char *s)
{
  int len;
  for (len = 0; s[len] !=0; len++)
    {
    }
  return (len);
}
