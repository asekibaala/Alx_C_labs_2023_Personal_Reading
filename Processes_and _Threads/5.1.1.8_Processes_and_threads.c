#include <stdio.h>
#include <stdlib.h>

int 
main()
{
    char *nam = "CPPINSTITUTE";
    char *val ="YES";
    char *prg = "./nameofprg";// executable containing variable to set value for
    int ret = system(prg); // storing the return value to check if command executed successfully

    printf ("ret =%d\n---------\n", ret);
    setenv(nam, val, 1);
    printf ("ret =%d\n---------\n", ret);
    unsetenv (nam);
    ret = system(prg);
    printf ("ret =%d\n---------\n", ret);

    return 0;
}