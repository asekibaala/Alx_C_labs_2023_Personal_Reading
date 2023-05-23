#include "main.h"

/**
 * free_data - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 * This code snippet defines a function named set_data that takes two 
 * arguments: a pointer to a structure named data_shell and a pointer to an array of strings av.
 * Within the function, the data_shell structure is initialized with various values. 
 * The av argument is assigned to the av member of the data_shell structure, and 
 * the input, args, status, and counter members are initialized to NULL, NULL, 0, and 1 
 * respectively.Next, a for loop is used to count the number of strings in the
 *  environ array (which is an external variable containing the environment variables). 
 * The datash->_environ member is then assigned a newly-allocated array of char * pointers 
 * with a size of i + 1.Another for loop is used to copy the contents of each environment 
 * variable string to the datash->_environ array using the _strdup function, which creates 
 * a new copy of the string.Finally, the last element 
 * of the datash->_environ array is set to NULL and the pid member is initialized 
 * with the process ID (PID) of the current process converted to a string using 
 * the aux_itoa function.
 * 
 */
void set_data(data_shell *datash, char **av) 
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}


/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT,get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
