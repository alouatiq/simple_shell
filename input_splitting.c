#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* split_line - Splits a command string into an array of arguments.
* @line: The command string to be split.
*
* This function tokenizes the command string using spaces as delimiters
* and returns an array of arguments. The last element of the array is
* set to NULL.
*
* Return: A pointer to an array of strings (arguments), or NULL on failure.
*/
char **split_line(char *line)
{
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("allocation error");
return (NULL);
}

token = strtok(line, TOK_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("allocation error");
return (NULL);
}
}

token = strtok(NULL, TOK_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
