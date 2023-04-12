#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name[10];
    int age; 
}person_t;

int 
cmp (const void *v1, const void *v2)
{
    return (((person_t *)v1)->age - ((person_t *)v2)->age);
}
int 
main (void)
{
    person_t pp[] = { {"Zulu",23}, {"Sierra",40},{"Bravo",15},
    {"Lima",9}

    };
    qsort (pp, sizeof (pp) / sizeof (person_t),sizeof(person_t),cmp);
    int i;
    i =0; 
    while (i < sizeof (pp) / sizeof (person_t))
    {
        printf("(%s, %d)\n",pp[i].name,pp[i].age);
        i++;
    }
    return 0;
}