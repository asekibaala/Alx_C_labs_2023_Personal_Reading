#include <stdio.h>
#include <unistd.h>

int main ()
{
  pid_t ppid = getppid();
  printf("The parent process ID is: %d\n",ppid);
  return 0;
}
