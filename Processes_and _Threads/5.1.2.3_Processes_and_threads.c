#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

char text[] = "ORIGINAL";

int main()
{
    int v = fork ();
    if (v == 0)
    {
        strcpy(text , "CHILD");
        printf("I am a child: %s\n", text);
        return 0;
    }
    else if (v > 0)
    {
        strcpy(text, "PARENT");
        printf("I am a parent: %s\n",text);
        return 0;
    }
    else 
    {
        printf("fork() failed - %s\n",strerror(errno));
        return 1;
    }
}
