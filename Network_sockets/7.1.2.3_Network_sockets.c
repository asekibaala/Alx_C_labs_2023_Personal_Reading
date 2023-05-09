#include <stdio.h>
#ifdef _MSC_VER
#include <Winsock2.h>
#pragma comment (lib,"ws2_32.lib")
#else
#include <netdb.h>
#endif

int 
main (void)
{
    #ifdef _MSC_VER
        WSADATA wsa;
        WSAStartup (0x0202, &wsa); /* can also be WSAStartup(MAKEWORD(2, 2), &wsa); */
    #endif
        printf("%d\n",getprotobyname ("tcp")->p_proto);
    #ifdef _MSC_VER
        WSACleanup();
    #endif
return

}
/*
 please note: replace MSC_VER with _WIN32 since it is a more generic identifier for Windows systems.

Due to the usage of conditional compilation directives, it will successfully compile and run both in Unix/Linux and MS Windows.

Note:

all the needed headers and symbols for the CL compiler are provided by the <Winsock2.h> header file;
the #pragma comment directive is used by the CL compiler to properly link an additional library named ws2_32.lib;
the WSAStartup() function must be invoked in the MS Windows environment before any other socket function is used; the function takes two arguments:
the desired Winsock version (a value consisting of two bytes denoting major and minor version of Winsock; 0x0202 means “version 2.2”); a predefined macro named MAKEWORD() may be used for the same purpose;
the pointer to a structure where the function stores the current Winsock configuration.
the WSACleanup() function should be invoked before the program completes.
*/