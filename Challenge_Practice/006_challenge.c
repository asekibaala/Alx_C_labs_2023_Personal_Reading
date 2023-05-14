#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char command[100];
  while (1)
    {
      printf("$ ");
      fflush(stdout);
      fgets(command, 100, stdin);
      printf("%s\n", command);
    }
  return 0;
}
