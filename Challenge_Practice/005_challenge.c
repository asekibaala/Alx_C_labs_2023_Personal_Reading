#include <stdio.h>
int main (int argc, char *argv[])
{
  int i;
  for (i =1; argv[i] != NULL; i++)
    {
      printf("%s ",argv[i]);
    }
  printf("\n");
  return 0;
}
