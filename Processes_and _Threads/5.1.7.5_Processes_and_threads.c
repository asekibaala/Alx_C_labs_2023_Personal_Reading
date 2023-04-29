#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define THREADS 50

HANDLE mutex;
int sum = 0;
int cnt = 0;

DWORD WINAPI
thread (LPVOID * data)
{
    int *p = (int *) data;
    Sleep (2000);
    if (*p % 2)
    {
        WaitForSingleObject (mutex, INFINITE);
        int s , c;
        s = sum;
        c = cnt;
        c = c + 1;
        s = s + *p;

        sum = s;
        cnt = c;
        ReleaseMutex (mutex);
    }
    return 0;
}
int 
main (void)
{
    HANDLE threads[THREADS];
    DWORD thrdids[THREADS];
    int data[THREADS];

    mutex = CreateMutex (NULL, FALSE, NULL);
    for (int i =0; i < THREADS; i++)
    {
        data[i] = i + 1;
    }
    for (int i = 0; i < THREADS; i++)
    {
        threads[i] = CreateThread (NULL,0,thread,data + i, 0, thrdids + i);
        if (threads[i] == NULL)
        {
            printf ("ERROR %d\n",i);
            exit (0);
        }
    }
    WaitForMultipleObjects (THREADS,threads, TRUE ,INFINITE);
    for (int i = 0; i < THREADS; i++)
    {
        CloseHandle (threads[i]);
    }
    printf("Results: cnt=%d, sum=%d\n", cnt, sum);
    CloseHandle(mutex);
    return 0;
}

/*
HANDLE WINAPI CreateMutex(
    LPSECURITY_ATTRIBUTES   lpMutexAttributes,
    BOOL    bInitialOwner,
    LPCTSTR lpName
);

the first argument denotes the security attributes for the new mutex (NULL means that the default attributes will be used)
if TRUE, the new mutex is initially locked by the creator; FALSE creates an unlocked mutex just like in Pthreads or C11; note: MS Windows uses the terms obtain a mutex or own a mutex instead of lock a mutex; similarly, unlocking a mutex is refferred to as releasing a mutex.
the last argument is the name of the newly created mutex, or NULL for an unnamed mutex.
The result is:

a mutex’s handle on success;
NULL otherwise.
To avoid any memory leaks, the thread’s handle should be freed by CloseHandle().
*/