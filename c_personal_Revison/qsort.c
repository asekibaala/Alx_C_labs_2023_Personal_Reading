#include <stdio.h>
#include <stdlib.h>

int
cmp(const void *v1, const void *v2)
{
    float vv1 = *((float *)v1);
    float vv2 = *((float *)v2);

    if (vv1 > vv2)
        return 1;
    if (vv2 > vv1)
        return -1;
}
int 
main (void)
{
    float t[] = {3.,1.,5.,4.,2.,0.005,0.777,0.87,0.77,0.989,0.777};
    qsort (t,11,sizeof(t[0]),cmp);
    int i;
    for (i=0; i < 11; i++)
        printf ("%f; ", t[i]);
    printf("\n");
    return 0;
}