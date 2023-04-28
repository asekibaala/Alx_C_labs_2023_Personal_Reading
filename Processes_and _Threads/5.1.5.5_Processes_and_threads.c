#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS 50

pthread_mutex mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;
int cnt = 0;
void *
thread (void *data)
{
    int *p = (int *)data;
    sleep (2);
    if (*p%2)
    {
        //      pthread_mutex_lock(&mutex);
        int s , c;
        s = sum;
        c = cnt;
        c = c +1;
        s = s+*p;
        sum = s;
        cnt = c;
        //      pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int 
main (void)
{
    pthread_t threads[THREADS];
    int data[THREADS];

    for (int i=0; i < THREADS; i++)
        data[i] = i + 1;
    for (int i = 0; i < THREADS; i++)
        pthread_create (threads + i, NULL, thread, data + i);
    for (int i = 0; i < THREADS; i++)
        pthread_join (threads[i], NULL);
  printf ("Results: cnt=%d, sum=%d\n", cnt, sum);
  return 0;

}