#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/*
 *struct data - struct that contains all relevant data on runtime
 *@av: argument vector
 *@input:command line wirtten by user
 *@args: tokens of the command line
 *@status: last status of the shell
 *@counter: lines counter
 *@_environ: environment variable
 *@pid: process ID of the shell
*/

typedef struct data
{
  char **av;
  char *input;
  char **args;
  char status;
  int counter;
  char **_environ;
  char *pid;
  
}data_shell;

void get_sigint(int sig);
char *_strdup(const char *s);
int _strlen(const char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
char *aux_itoa(int n);
int get_len(int n);
void shell_loop(data_shell *datash);

#endif
