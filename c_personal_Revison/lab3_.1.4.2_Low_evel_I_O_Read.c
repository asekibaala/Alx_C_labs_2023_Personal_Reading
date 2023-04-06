#include <stdio.h>
#include <fcntl.h>
#ifndef _MSC_VER
#include <unistd.h>
#include <io.h>
#endif
#define N 10
int 
main(void)
{
    int arr[N];
    int in = open("arr.dat",O_RDONLY); // returns a file descriptor to in
    if(in > 0)
    {
        int n = read(in,arr,sizeof(arr));
        printf("%d bytes read in \n",n);
        close (in);
    }

    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d",arr[i]);
    }

    return (0);
}