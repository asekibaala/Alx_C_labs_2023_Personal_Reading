#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int
main (void)
{
    int v = fork();
    if (v == 0)
    {
        printf("I am a child process\n");
        return 0;
    }
    else if(v >0 )
    {
        printf("I am a parent\n");
        return 0;
    }

    else
    {
        printf("for() failed - %s\n",strerror(errno));
    }
}