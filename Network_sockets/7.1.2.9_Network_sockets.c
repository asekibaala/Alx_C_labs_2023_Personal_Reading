#include <stdio.h>
#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <netdb.h>
#endif

int 
main (void)
{
    #ifdef _WIN32
        WSADATA wsa;
        WSAStartup(0x0202,&wsa);
    #endif
        printf("%d\n",ntohs(getservbyname("http","tcp")->s_port)); /*using ntohs() gives a correct port number eliminating the endian issue*/
    #ifdef _WIN32
        WSACleanup ();
    #endif
    return 0;
}