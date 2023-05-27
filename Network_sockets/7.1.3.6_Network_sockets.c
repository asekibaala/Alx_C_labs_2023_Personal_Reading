#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define CALL(x) if(counter++ && !(x))error(#x,_LINE_,counter)

int counter = 2;

void
error (char *action, int line, int retc)
{
  fprintf (stderr, "'%s' in line #%d failed - client terminated\n",action,line);
  exit (retc);
  
}

int main (int argc, char *argv[])
{
  if (argc != 4)
    {
      fprintf (stderr,"usage %s server_addr service_no number_no\n",argv[0]);
      return 1;
    }

  int port = 0;
  CALL(sscanf(argv[2],"%d",&port) == 1 && port >= 1 && port <= 65535);

  int numno = 0;
  CALL (sscanf (argv[3],"%d",&numno) == 1 && numno >= 0 && numno <= 10);

  struct hostent *hent = NULL;
  CALL ((hent = gethostbyname (argv[1])) != NULL);

  struct protent *pent;
  CALL ((pent = getprotobyname ("tcp")) != NULL);

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons (ports);
  addr.sin_addr = * ((struct in_addr *) hent->h_addr);
  memset (addr.sin_zero, 0, 8);

  int sock;
  CALL ((sock = socket(AF_INET, SOCK_STREAM, pent->p_proto)) > 0);
  CALL ((connect (sock, (struct sockaddr *) &addr, sizeof(struct sockaddr)))== 0);

  char *draw_cmd = "DRAW\r\n", *quit_cmd = "QUIT\r\n";

  if (numno == 0)
    {
      char *exitcmd = "EXIT\r\n";
      CALL (write (sock,exitcmd, strlen(exitcmd)) ==  strlen(exitcmd));
      close (sock);
      return 0;
    }

  while (numno--)
    {
      CALL (write(sock,draw_cmd,strlen(draw_cmd)) == strlen(draw_cmd));
      char buff[16];
      int readin = 0;
      CALL((readin = read (sock,buff, sizeof(buff))) > 0);
      buff[readin] = '\0';
      printf ("%s\n",buff);
      if (numno)
	sleep(1);   
    }
  CALL (write(sock,quit_cmd, strlen(quit_cmd)) == strlen (quit_cmd));

  close (sock);

  return 0;
}

/*
line 8: we modify our old CALL() macro a bit – we add a counter incremented on each macro expansion; this helps us to return different error codes for each possible reason; we also output the number of the source line where the error occurs (more details soon in the error() function body);
line 12: the error() function outputs the error message to stdout and exits the program with the appropriate error code;
line 23: the client needs three arguments to start its work:
the server’s address given either in symbolic form or as an IP address;
the service number where the server is waiting for our connections;
the number of numbers to draw; we assign a special meaning for zero here – it sends the EXIT request, forcing the server to stop the execution.
line 31: we look into arg 2 to check if the port number is specified correctly;
line 34: we do the same with arg 3 (numbers to draw)
line 37: we apply arg 1 to gethostbyname() to look for the server’s IP (note: the function accepts the host address as an IP address written in dotted form, too – it simply converts it into packed binary form)
line 40: we look for the TCP number;
line 43: we fill the struct sockaddr_in with the complete service address (note the htons() function in line 37)
line 49: we create the socket;
line 51: we try to connect to our (still non-existent) server;
line 56: if arg 3 was specified as zero, we send the EXIT command to the server and finish our work;
line 64: otherwise we send as many DRAW commands as specified in arg 3;
line 69: we read the server’s response and print it to stdout;
line 76: we end the connection by sending the QUIT command to the server.

*/
