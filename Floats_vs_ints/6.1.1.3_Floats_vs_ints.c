#include <stdio.h>

int main (void)
{
    double x = 1;
    while (x != x + 1)
    {
        x *= 2;
    }
printf("%f\n",x);

return 0;
}