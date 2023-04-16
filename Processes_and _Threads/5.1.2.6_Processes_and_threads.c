#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SECS 10
#define CHILDREN 3

int 
main(void)
{
    int c;
    for (c =0; c < CHILDREN; c++)
    {
        int pid = fork ();
        if (pid == 0)
        {
            srand (getpid());
            int secs = rand () % SECS + 1;
            printf("Child: PID=%d sleep=%d secs\n",getpid(),secs);
            sleep(secs);
            printf("Child: PID=%d woke up !\n",getpid());
            return 27;
        }
        else if (pid == -1)
        {
            fprintf (stderr, "Fork failed: %s\n", strerror(errno));
            return 1;
        }

    }
    printf ("Parent is waiting...\n");
    for (c=0; c < CHILDREN; c++)
    {
        int status, child = wait (&status);
        printf("Parent: Child exited: PID=%d, retcode=%d\n",child,WEXITSTATUS (status));
    }
    return 0;
}