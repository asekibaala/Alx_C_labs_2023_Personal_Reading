#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[10];
  int age;
} person_t;

person_t *
newperson (char *name, int age)
{
  person_t *new = malloc (sizeof (person_t));
  strcpy (new->name, name);
  new->age = age;
  return new;
}

int
cmp (const void *v1, const void *v2)
{
  int res = strcmp ((*(person_t **) v1)->name, (*(person_t **) v2)->name);
  if (res == 0)
    res = (*(person_t **) v1)->age - (*(person_t **) v2)->age;
  return res;
}

int
main (void)
{
  person_t *pp[] = { newperson ("Delta", 23),
    newperson ("Victor", 40),
    newperson ("Victor", 15),
    newperson ("Delta", 9)
  };

  qsort (pp, sizeof (pp) / sizeof (person_t *), sizeof (person_t *), cmp);
  int i;
  for (i = 0; i < sizeof (pp) / sizeof (person_t *); i++)
    {
      printf ("(%s, %d)\n", pp[i]->name, pp[i]->age);
      free (pp[i]);
    }
  return 0;
}