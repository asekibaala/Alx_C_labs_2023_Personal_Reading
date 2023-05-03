#include <stdio.h>

int main (void)
{
    int x = 1;
    while (x != x + 1)
    {
        x *= 2;
    }
printf("%d\n",x);

return 0;
}