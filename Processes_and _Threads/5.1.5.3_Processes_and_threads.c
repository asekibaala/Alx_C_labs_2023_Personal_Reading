#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 3

void *
thread (void *data)
{
    char *msg = (char *)data;
    pthread_t self = pthread_self();
    srand (self);
    printf ("Thread %x started:\'%s\'\n",self,msg);
    long delay = rand () % 5 + 1;
    sleep (delay);
    printf ("Thread %x finished\n",self);
    return (void *) delay;
}
int 
main (void)
{
    pthread_t threads[THREADS];
    char data[THREADS][20];
    printf("main() started...\n");
    for (int i =0; i < THREADS; i++)
    {
        sprintf(data[i],"Thread #%d!",i+1);
        pthread_create (threads + i,NULL, thread, data[i]);
    }
    for (int i =0; i < THREADS; i++)
    {
        long retval;
        pthread_join (threads[i],(void *) &retval);
        printf ("Thread %d joined: %ld\n",i+1,retval);
    }
    return 0;
}