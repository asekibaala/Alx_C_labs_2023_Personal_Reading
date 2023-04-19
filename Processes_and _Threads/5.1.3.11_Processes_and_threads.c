#include <windows.h>
#include <stdio.h>

#define CHILDERN 3

int 
main (void)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi [CHILDERN]; //we define an array of PROCESS_INFORMATION structures (one structure per child)
    char argline[50];
    memset(&si,0,sizeof(si)); //setting block of memory using memset() for the stuct variable si of STARTUPINFO
    memset(&pi,0, sizeof(pi));//setting block of memory using memset() for the stuct variable pi of PROCESS_INFORMATION
    si.cb = sizeof(si); // first field, named cb, stores the actual size of the structure
    int i;
    for (i=0; i<CHILDERN; i++)
    {
        sprintf(argline,"5.1.1.6_Processes_and_threads.exe process=%d arg1 arg2",i+1);
        if (CreateProcess(NULL, argline, NULL, NULL, 0, 0, "Path=C:\\My\\Path\0\0", NULL,&si, pi + i) == 0)
        {
            printf ("CreateProcess #%d failed (%d).\n",i+1,GetLastError());
            return 2;
        }
        printf ("Process #%d Created: handle=%p, identifier=%d\n",i+1,pi[i].hProcess,pi[i].dwProcessId); 
    }
    for (i=CHILDERN - 1; i >= 0; i--)
    {
        WaitForSingleObject (pi[i].hProcess,INFINITE);
        CloseHandle (pi[i].hProcess);/*his is an obligatory step and must be performed to 
                                      avoid memory leaks (the CloseHandle() function releases all resources related to the handle)*/
        CloseHandle (pi[i].hThread);
        printf("Process #%d terminated.\n",i+1);
    }
    return 0;
}