#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#ifndef _MSC_VER
#include <unistd.h>
#include <io.h>
#endif
#define N 10

int
main (void)
{
    int arr[N];
    int i;
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        arr[i] = rand() % 10 + 1;
        printf ("%d",arr[N]);
    }
    printf("\n");
    int out = open("arr.dat",O_CREAT | O_TRUNC | O_WRONLY, 0666);//this returns a file descriptor to out if successful
    if(out > 0)
    {
        int n = write(out,arr,sizeof(arr));
        printf("%d bytes written\n",n);
        close(out); //closing the file descriptor returned on out variable
    }
    return (0);
}