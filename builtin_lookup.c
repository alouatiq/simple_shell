#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

extern int builtin_cd(char **args, char **env);
extern int builtin_exit(char **args, char **env);
extern int builtin_env(char **args, char **env);
extern int builtin_setenv(char **args, char **env);
extern int builtin_unsetenv(char **args, char **env);
extern int builtin_help(char **args, char **env);

int builtin_lookup(char **args, char **env)
{
builtin_t builtins[] = {
{"cd", builtin_cd},
{"exit", builtin_exit},
{"env", builtin_env},
{"setenv", builtin_setenv},
{"unsetenv", builtin_unsetenv},
{"help", builtin_help},
{NULL, NULL}
};

int i;

for (i = 0; builtins[i].name != NULL; i++)
{
if (strcmp(args[0], builtins[i].name) == 0)
return (builtins[i].func(args, env));
}
return (0);  /* Command not found in builtins */
}
