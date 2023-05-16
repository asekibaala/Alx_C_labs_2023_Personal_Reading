#include "main.h"

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
*/

void set_data(data_shell *datash, char **av)
{
  unsigned int i;
  datash->av =av;
  datash->input = NULL;
  datash->args = NULL;
  datash->status = 0;
  datash->counter = 1;

  for (i = 0; environ[i]; i++)
      ;
  /*Allocating memory for the member of the struct data*/
  datash->_environ = malloc(sizeof(char *) * (i+1));

  /*Duplicate environ and work with a copy _environ*/
  for (i = 0; environ[i]; i++)
    {
      datash->_environ[i] = _strdup(environ[i]);
    }
  /*assign the last element Null*/
  datash->_environ[i] = NULL;
  datash->pid = aux_itoa(getpid());
  
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument value
 *
 * Return: 0 on success.
 */

int main (int ac, char **av)
{
  data_shell datash;
  (void) ac;

  signal(SIGINT, get_sigint);
  printf("\nLodaing.................\n");
}
