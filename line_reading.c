#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* _getline - Reads an entire line from input stream.
* @lineptr: Pointer to the buffer that will store the line.
* @n: Pointer to the size of the buffer.
* @stream: The input stream to read from.
*
* Task: Implement Custom getline
* Return: Number of characters read, or -1 on failure or EOF.
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
static char buffer[READ_BUF_SIZE];
static size_t i, len;
size_t j;
ssize_t ret = 0;
char *new_ptr;

if (!lineptr || !n || !stream)
return (-1);
if (!*lineptr)
{
*n = READ_BUF_SIZE;
*lineptr = malloc(*n);
if (!*lineptr)
return (-1);
}

while (1)
{
if (i >= len)
{
i = 0;
len = fread(buffer, 1, READ_BUF_SIZE, stream);
if (len <= 0)
return (-1);
}

for (j = i; j < len; j++)
{
if (buffer[j] == '\n')
{
ret += j - i + 1;
if (ret >= (ssize_t)*n)
{
*n *= 2;
new_ptr = realloc(*lineptr, *n);
if (!new_ptr)
return (-1);
*lineptr = new_ptr;
}
memcpy(*lineptr + ret - (j - i + 1), buffer + i, j - i + 1);
(*lineptr)[ret - 1] = '\0';
i = j + 1;
return (ret);
}
}

if (ret + len - i >= *n)
{
*n *= 2;
new_ptr = realloc(*lineptr, *n);
if (!new_ptr)
return (-1);
*lineptr = new_ptr;
}

memcpy(*lineptr + ret, buffer + i, len - i);
ret += len - i;
i = len;
}
}

/**
* read_line - Reads a line of input from the user.
*
* Task: Handle Command Line Arguments
* Return: Pointer to the line read, or NULL on failure.
*/
char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;

if (_getline(&line, &bufsize, stdin) == -1)
{
free(line);
return (NULL);
}
return (line);
}
