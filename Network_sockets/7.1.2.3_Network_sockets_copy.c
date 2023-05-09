#include <stdio.h>
#ifdef _WIN32 /*More generic identifier for Windows systems.*/
#include <Winsock2.h>
#pragma comment(lib, "ws2_32.lib") /*Linking to library name used on Windows*/
#else
#include <netdb.h>
#endif

int main(void) {
#ifdef _WIN32
  WSADATA wsa;
  WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
  printf("%d\n", getprotobyname("tcp")->p_proto);
#ifdef _WIN32
  WSACleanup();
#endif
  return 0;
}

/*manual compilation linking to the libray gcc 7.1.2.3_Network_sockets.c -o a2.exe -lws2_32 */