#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* read_command_input - Reads a line of input from the user.
* This function reads a line of input from the user and returns it as a string.
* It handles memory allocation for the input buffer.
* Return: A pointer to the input string, or NULL on EOF or error.
*/
char *read_command_input(void)
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters;
char *start;

characters = getline(&buffer, &bufsize, stdin);
if (characters == -1)
{
free(buffer);
return (NULL);
}

start = buffer;
while (*start && (*start == ' ' || *start == '\t'))
start++;

if (*start == '\0' || *start == '\n')
{
free(buffer);
return (NULL);
}

buffer[characters - 1] = '\0'; /* Remove the newline character */
return (buffer);
}

/**
* split_command_input - Splits the input command string into arguments.
* @line: The input command string.
* This function tokenizes the input command string into individual arguments
* and returns them as an array of strings.
* Return: An array of arguments, or NULL on failure.
*/
char **split_command_input(char *line)
{
int bufsize = BUFFER_SIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("allocation error");
exit(EXIT_FAILURE);
}

token = strtok(line, TOKEN_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += BUFFER_SIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("allocation error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, TOKEN_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
