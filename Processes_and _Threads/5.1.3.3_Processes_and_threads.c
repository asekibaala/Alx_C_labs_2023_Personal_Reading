#include <stdio.h>
#include <process.h>

int 
main(int argc, char *argv[], char **envp)
{
    char *myenv[2] ={"Path=if the path be beautiful, lets us not ask where it leads.",NULL};
    execl ("5.1.1.8_Processes_and_threads.exe","5.1.1.8_Processes_and_threads.exe","arg1","arg2",NULL,myenv)
    printf("Something really bad happened - we should not be here\n");
        
    return 1;
}
