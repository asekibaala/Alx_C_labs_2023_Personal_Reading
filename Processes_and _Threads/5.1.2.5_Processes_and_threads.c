#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SECS 5
int 
main(void)
{
    int pid = fork ();
    if (pid == 0)
    {
        printf("Hi, I am a child with PID=%d and I am going to sleep for %d Seconds...\n",getpid (), SECS);
        sleep(SECS);
        printf("Hi again I am a child and i woke up !\n")
        return 27;
    }
    else if (pid == -1)
    {
        fprintf(stderr,"Fork failed: %s\n", strerror(errno));
        return 1;
    }
    printf("Hi, i am a parent and I am waiting for my child to finish...\n");
    int status, child = wait(&status);
    printf("PID=%d, retcode=%d\n",child, WEXITSTATUS (status));
    return 0;

}