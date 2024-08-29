#include "shell.h"
#include <limits.h>  /* For PATH_MAX */
#include <unistd.h>  /* For chdir, getcwd */
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

extern char *_getenv(const char *name);
extern int _setenv(const char *name, const char *value, int overwrite);

int builtin_cd(char **args, char **env)
{
char *dir, *oldpwd, cwd[PATH_MAX];

oldpwd = _getenv("OLDPWD");  /* Fetch the old working directory */

if (args[1] == NULL)  /* No argument, change to HOME */
dir = _getenv("HOME");
else
dir = args[1];

if (chdir(dir) != 0)  /* Change directory */
{
perror("hsh");
return (0);
}
else
{
if (getcwd(cwd, sizeof(cwd)) != NULL)  /* Get current working directory */
{
_setenv("OLDPWD", oldpwd, 1);  /* Update OLDPWD environment variable */
_setenv("PWD", cwd, 1);        /* Update PWD environment variable */
}
}
return (1);
}
