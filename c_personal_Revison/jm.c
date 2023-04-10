#include <stdio.h>

int main() {
  char jm[100];
 /*char *ptr = jm;*/ 

  printf("Enter a string: ");
  scanf("%[^\n]s", jm);

  printf("You entered: %s\n", jm);

  return 0;
}
