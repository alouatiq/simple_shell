#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

extern int _setenv(const char *name, const char *value, int overwrite);
extern int _unsetenv(const char *name);

int env_builtin(char **args, char **env)
{
int i;

for (i = 0; environ[i]; i++)
{
_puts(environ[i]);
_puts("\n");
}

return (1);
}

int setenv_builtin(char **args, char **env)
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
return (1);
}

if (_setenv(args[1], args[2], 1) == -1)
{
perror("hsh");
return (1);
}

return (1);
}

int unsetenv_builtin(char **args, char **env)
{
if (args[1] == NULL)
{
fprintf(stderr, "Usage: unsetenv VARIABLE\n");
return (1);
}

if (_unsetenv(args[1]) == -1)
{
perror("hsh");
return (1);
}

return (1);
}
