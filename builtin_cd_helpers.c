#include "shell.h"
#include <string.h>
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

extern char **environ;

char *_getenv(const char *name)
{
size_t i, len = strlen(name);

for (i = 0; environ[i]; i++)
{
if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
return (environ[i] + len + 1);
}
return (NULL);
}
