#include <stdio.h>
#ifdef _WIN32
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")
#else
#include <arpa/inet.h>
#include <netdb.h>
#endif

int
main (void)
{
    #ifdef _WIN32
        WSADATA wsa;
        WSAStartup(0x0202, &wsa);
    #endif
        printf("%s\n",
            inet_ntoa(*
                ((struct in_addr *)gethostbyname ("www.cppinstitute.org")->h_addr)));
    #ifdef _WIN32
        WSACleanup ();
    #endif
    return 0;
}
/*Line 19:gethostbyname() function gets only one argument – the name of the host,
        It returns a pointer to the structure filled with the host data, or NULL if there is no host of that name.
         IP address is data of type struct in_addr, so we type cast the returned value by gethostbyname()
         inet_ntoa() function gets only one argument – an internal form of an IP address , type casted above and 
         returns a pointer to a string containing a human-readable (dotted) form of the specified IP address.
*/