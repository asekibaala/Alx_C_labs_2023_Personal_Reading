#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define THREADS 3

typedef struct
{
    char msg[20];
    int retval
} DATA;

DWORD WINAPI
thread (LPVOID data)
{
    DATA *dat = (DATA *)data;
    DWORD self = GetCurrentThreadId();
    printf ("Thread %xd started:\'%s\'\n",self, dat->msg);
    srand (self);
    DWORD delay = rand () % 5 + 1;
    Sleep (delay * 1000);
    printf("Thread %xd finished\n",self);
    dat->retval = delay;
    return 0;
}
int 
main (void)
{
    HANDLE threads[THREADS];
    DWORD thrdids[THREADS];
    DATA data[THREADS];

    printf ("main () started....\n");
    for (int i =0; i < THREADS; i++)
    {
        sprintf(data[i].msg, "Thread #%d!", i+1);
        threads[i] = CreateThread (NULL,0,thread,data + i,0,thrdids + i);
    }
    for ( int i =0; i < THREADS; i++)
    {
        WaitForSingleObject (threads[i],INFINITE);
        printf("Thread %d completed: %ld\n",i+1,data[i].retval);
    }
    return 0;
}

/*

The CreateThread() function creates and launches a new thread:

HANDLE WINAPI CreateThread(
    LPSECURITY_ATTRIBUTES   lpThreadAttributes,
    SIZE_T  dwStackSize,
    LPTHREAD_START_ROUTINElpStartAddress,
    LPVOIDlpParameter,
    DWORD   dwCreationFlags,
    LPDWORD lpThreadId
);

a pointer to a set of desired thread attributes, or NULL to use standard attributes;
a stack size for the thread, or zero to use the default stack size;
a pointer to a worker thread function;
a pointer to arbitrary data;
a bit mask with the thread’s creation flags, or zero to use the default flags;
a pointer to a variable where the newly created thread ID will be placed (note: the thread ID is not the same as the thread’s handle)
The function returns:

a handle of the created thread if successful;
a NULL pointer otherwise.


Waiting for a thread is performed by the function WaitForSingleObject(), which you already know.

If you want to wait for more than one thread, you may use the WaitForMultipleObjects() function:

DWORD WINAPI WaitForMultipleObjects(
    DWORD   nCount,
    HANDLE  *lpHandles,
    BOOL    bWaitAll,
    DWORD   dwMillisceonds
);

The function uses the following parameters:

the number of threads to wait for;
a pointer to a vector containing the threads’ handles;
TRUE (non-zero) if you want to wait for all the handles, or FALSE (zero) if you’re going to wait for any of the listed handles;
the maximum time you agree to wait, or INFINITE to wait for the desired effect indefinitely.

*/