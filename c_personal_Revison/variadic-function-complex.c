#include <stdarg.h>

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

char *
concat (char *str, ...)
{
  if (str == NULL)
    return NULL;
  int totlen = strlen (str);
  va_list lenlist, strlist;
  va_start (lenlist, str);
  va_copy (strlist, lenlist);
  char *p = va_arg (lenlist, char *);
  while (p)
    {
      totlen += strlen (p);
      p = va_arg (lenlist, char *);
    };
  va_end (lenlist);
  char *newstr = malloc (totlen);
  strcpy (newstr, str);
  p = va_arg (strlist, char *);
  while (p)
    {
      strcat (newstr, p);
      p = va_arg (strlist, char *);
    }
  va_end (strlist);
  return newstr;
}

int
main (void)
{
  char *s1 = concat ("Mary ", "had ", "a little lamb", NULL);
  char *s2 = concat ("Single string", NULL);
  printf ("%s\n", s1);
  printf ("%s\n", s2);
  free (s1);
  free (s2);
  return 0;
}

/*

We’ve written a function that concatenates all the received strings into a newly allocated one and returns the pointer to it. The function has to be invoked with at least one, not NULL, char * pointer, and the variable parameter list must (must!) be ended with the NULL pointer, which plays the role of the guardian.

We’d like to draw your attention to the following issues:

we have to review the variable parameter list twice: firstly, to count the total length of all strings being concatenated (we want to be sparing when it comes to allocating the memory) and secondly, to actually concatenate the strings; that doubled walk can be done in many ways, but we’ve decided to use two lists named lenlist and strlist (line 13)
we initialize lenlist in the conventional way (line 14)
the strlist may be initialized in the same manner but we want to show you one more macro from stdarg.h and have decided just to assign the strlist using the current value of the lenlist; can we use a regular assignment (=) for this purpose? No, we can’t, because the actual nature of the va_list is something we don’t know, and we don’t know if an assignment will do the job here (e.g. some implementation may use an array to store the list – an assignment wouldn’t handle it)
this is why we’ve used the va_copy() macro (line 15) – it just assigns the right argument to the left one, but does it in a way which works everywhere and every time;
note: the list initialized via va_copy() has to be “ended” in the same way as the one obtained from va_start() – hence the va_end() macro is needed for the strlist too (line 29)
both while loops (lines 17 and 25) iterate through the variable part of the parameter list, fetching pointers of type char* from them.
You may ask what will happen if someone forgets about the guardian and there’s no NULL at the end of the parameter list.

Good question.

Try it yourself. The results may be crucial. Don’t be surprised.

Note: va_copy() returns no value.

*/