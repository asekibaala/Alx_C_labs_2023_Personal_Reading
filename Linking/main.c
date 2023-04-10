#include <stdio.h>
#include "main.h"  // calling the library through a header file
/*int add (int x, int y);*/ //calling the library through a direct global function definition.
int 
main  (void)
{
 int result = add(60,98);

 printf ("The result is %d\n",result);

 return 0;
}