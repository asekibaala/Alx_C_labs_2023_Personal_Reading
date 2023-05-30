#include <stdio.h>

#ifdef _MSC_VER
#include <Winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#endif

#ifdef _MSC_VER
#define CALL(x) if(!(x) && fprintf(stderr, "'%s' failed (error=%d)\n",#x,WSAGetLastError()))Exit(1)
#else
#define CALL(x) if(!(x) && fprintf(stderr, "'%s' failed (errno=%d)\n",#x,errno))Exit(1)
#endif

void
Exit (int retc)
{
#ifdef _MSC_VER
  WSACleanup ();
#endif
  exit (retc);
}

int
Write (int h, char *buf, int siz)
{
#ifdef _MSC_VER
  return send (h, buf, siz, 0);
#else
  return write (h, buf, siz);
#endif
}

int
Read (int h, char *buf, int siz)
{
#ifdef _MSC_VER
  return recv (h, buf, siz, 0);
#else
  return read (h, buf, siz);
#endif
}

int
Close (int h)
{
#ifdef _MSC_VER
  return closesocket (h);
#else
  return close (h);
#endif
}

int
main (int argc, char *argv[])
{
  if (argc != 2)
    {
      fprintf (stderr, "usage: %s site_addr\n", argv[0]);
      return 0;
    }

#ifdef _MSC_VER
  WSADATA wsa;
  WSAStartup (MAKEWORD (2, 2), &wsa);
#endif

  struct addrinfo hints, *info;

  memset (&hints, 0, sizeof (hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_CANONNAME;

  CALL (getaddrinfo (argv[1], "http", &hints, &info) == 0);

  char str[32];
  inet_ntop (info->ai_family,
	     &((struct sockaddr_in *) info->ai_addr)->sin_addr, str,
	     sizeof (str) - 1);
  printf ("%s -> %s\n", info->ai_canonname, str);

  struct sockaddr_in addr = *((struct sockaddr_in *) info->ai_addr);

  int sock;
  CALL ((sock = socket (AF_INET, SOCK_STREAM, info->ai_protocol)) > 0);

  CALL ((connect (sock, (struct sockaddr *) &addr, sizeof (struct sockaddr)))
	== 0);

  char buff[1024 + 1];
  sprintf (buff, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
	   argv[1]);

  CALL (Write (sock, buff, strlen (buff)) == strlen (buff));

  int readin = Read (sock, buff, sizeof (buff) - 1);
  while (readin > 0)
    {
      buff[readin] = '\0';
      printf ("%s", buff);
      readin = Read (sock, buff, sizeof (buff) - 1);
    }

  Close (sock);
  freeaddrinfo (info);
#ifdef _MSC_VER
  WSACleanup ();
#endif
  return 0;
}
/*
Note: the program contains a couple of #if directives – they allow the code to be compiled by Unix/Linux and MS Windows compilers. We’ve also added some wrappers – functions that hide the platform-dependent implementation under a unified interface.

Take a look at the code and decide for yourself whether the modifications have made the code clearer:

line 79: we begin to prepare hints for the getaddrinfo() invocation;
line 82: we want to use IP4 adresses;
line 83: we need a stream socket;
line 84: we want the function to find a canonical name (if any);
line 86: keep your fingers crossed as the getaddrinfo() function has been fired! We pass the host name (argv[1]) and service name (http) into it, hoping that it will return some useful data;
line 89: we make use of the IP4 address returned in the first info structure, and utilize the inet_ntop() function to print it to stdout;
line 94: we get the sockaddr_in structure that getaddrinfo() has prepared for us; we don’t have to construct it ourselves – what a relief!
line 97: this the last chance to use the data derived from the getaddrinfo() function;
line 117: we free the memory possibly allocated by the getaddrinfo() function.
Does the code work the same way as our first HTTP client? Compile it and try!


*/
