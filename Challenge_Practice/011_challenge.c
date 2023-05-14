#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "This#is#a#test#string";
    char delim[] = "#";
    char *token ;
    token = strtok(str, delim);

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}
