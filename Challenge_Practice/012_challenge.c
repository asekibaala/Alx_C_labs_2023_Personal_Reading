#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TOK_BUFSIZE 128


char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
        char **newptr;
        unsigned int i;

        if (ptr == NULL)
                return (malloc(sizeof(char *) * new_size));

        if (new_size == old_size)
                return (ptr);

        newptr = malloc(sizeof(char *) * new_size);
        if (newptr == NULL)
                return (NULL);

        for (i = 0; i < old_size; i++)
                newptr[i] = ptr[i];

        free(ptr);

        return (newptr);
}

char **split_line(char *input )
{
        size_t bsize;
        size_t i;
        char **tokens = NULL;
        char *token = NULL;
        char TOK_DELIM[] = " ";

        bsize = TOK_BUFSIZE;
        tokens = malloc(sizeof(char *) * (bsize));
        if (tokens == NULL)
        {
                write(STDERR_FILENO, ": allocation error\n", 18);
                exit(EXIT_FAILURE);
        }

        token = strtok(input,TOK_DELIM);
        tokens[0] = token;

        for (i = 1; token != NULL; i++)
        {
                if (i == bsize)
                {
                    bsize += TOK_BUFSIZE;
                        tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
                        if (tokens == NULL)
                        {
                                write(STDERR_FILENO, ": allocation error\n", 18);
                                exit(EXIT_FAILURE);
                        }
                }
                token = strtok(NULL, TOK_DELIM);
                tokens[i] = token;
        }

        return (tokens);
}

int main ()
{
   char str[] = "This is a test string.";
    char **words = split_line(str);

    for (int i = 0; words[i] != NULL; i++)
    {
        printf("%s\n", words[i]);
      //  free(words[i]);
    }
    free(words);
    return 0;
}

