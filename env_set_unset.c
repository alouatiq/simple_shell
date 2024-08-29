#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* setenv_builtin - Sets or updates an environment variable.
* @args: An array of arguments where args[1] is the variable name and
*        args[2] is the value.
*
* Task: This function sets or updates the value of an environment
* variable. If the variable does not exist, it is created.
*
* Return: 0 on success, or 1 on failure.
*/
int setenv_builtin(char **args)
{
if (!args[1] || !args[2])
{
write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
return (1);
}

if (_setenv(args[1], args[2], 1) == -1)
{
perror("setenv error");
return (1);
}

return (0);
}

/**
* unsetenv_builtin - Removes an environment variable.
* @args: An array of arguments where args[1] is the variable name.
*
* Task: This function removes an environment variable if it exists.
*
* Return: 0 on success, or 1 on failure.
*/
int unsetenv_builtin(char **args)
{
if (!args[1])
{
write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
return (1);
}

if (_unsetenv(args[1]) == -1)
{
perror("unsetenv error");
return (1);
}

return (0);
}

/**
* _setenv - Changes or adds an environment variable.
* @name: The name of the environment variable.
* @value: The value of the environment variable.
* @overwrite: Flag to indicate whether to overwrite an existing variable.
*
* Task: This function sets or updates the value of an environment
* variable. If the variable does not exist, it is created. If overwrite is
* set to 0, an existing variable is not updated.
*
* Return: 0 on success, or -1 on failure.
*/
int _setenv(const char *name, const char *value, int overwrite)
{
char *new_var;
size_t len;

if (!name || !value)
return (-1);

if (getenv(name) && !overwrite)
return (0);

len = _strlen(name) + _strlen(value) + 2;
new_var = malloc(len);
if (!new_var)
return (-1);

_strcpy(new_var, name);
_strcat(new_var, "=");
_strcat(new_var, value);

if (putenv(new_var) != 0)
{
free(new_var);
return (-1);
}

return (0);
}

/**
* _unsetenv - Removes an environment variable.
* @name: The name of the environment variable to remove.
*
* Task: This function removes the environment variable specified by
* name. If the variable does not exist, the function does nothing.
*
* Return: 0 on success, or -1 on failure.
*/
int _unsetenv(const char *name)
{
char **env = environ;
char **new_env;
size_t len = 0, name_len = _strlen(name);
int i, j;

while (env[len])
len++;

new_env = malloc(sizeof(char *) * len);
if (!new_env)
return (-1);

for (i = 0, j = 0; env[i]; i++)
{
if (_strncmp(env[i], name, name_len) != 0 || env[i][name_len] != '=')
new_env[j++] = env[i];
}

new_env[j] = NULL;
environ = new_env;

return (0);
}
