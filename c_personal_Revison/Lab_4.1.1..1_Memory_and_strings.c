#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int
asprintf (char **buf, char *frm, ...)
{
    va_list var;
    va_start (var, frm);
    int size = vsnprintf (NULL, 0, frm, var);
    *buf = calloc (size +1, 1);
    va_end (var);
    va_start (var, frm);
    vsnprintf (*buf, 30, frm, var);
    va_end (var);

    return size;
}
int
main (void)
{
    char *msg;
    asprintf(&msg, "Mary %s %c littl%x lamb.","had",'a',14);
    printf("%s\n",msg);
    return 0;

}