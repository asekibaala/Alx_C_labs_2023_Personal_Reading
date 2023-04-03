#include <stdio.h>
#include <stdlib.h>
#define N 5

void
print(float *t, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%f; ",t[i]);
    printf("\n");
}

int 
main (void)
{
    float *t1 = malloc (N * sizeof(float));
    float *t2 = calloc (N, sizeof(float));
    print (t1, N);
    print(t2, N);
    free(t1);
    free(t2);

    return 0;
}