#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage:%s filename\n", argv[0]);
        return 1;
    }

    struct stat st;
    if (stat(argv[1], &st) == 0)
    {
        if (S_ISREG(st.st_mode))
        {
            char newname[16];
            srand(time(NULL));
            sprintf(newname, "link_%d", rand());
            if (CreateSymbolicLink(newname, argv[1], 0) == 0)
            {
                DWORD errorMessageID = GetLastError();
                LPSTR messageBuffer = NULL;
                size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                    NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
                printf("link failed: %s\n", messageBuffer);
                LocalFree(messageBuffer);
                return 3;
            }
            printf("Link \"%s\" created\n", newname);
        }
    }
    else
    {
        printf("%s does not exist or is not a regular file\n", argv[1]);
        return 2;
    }
    return 0;
}
