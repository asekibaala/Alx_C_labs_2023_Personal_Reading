#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int 
main (void)
{
    printf("%d\n",fileno(stdin));
    close(23333); //input of a wrong file descriptor to catch error  no returned 
    printf("%d",errno);

    return (0);
}