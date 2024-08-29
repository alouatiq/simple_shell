#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* replace_variables - Replaces variables in the input command string.
* @args: The array of arguments to check for variables.
* @env: The environment variables array.
*
* This function scans the array of arguments and replaces any variables
* (e.g., $HOME) with their corresponding values from the environment.
* It supports built-in variables like $? and $$ for the last exit status
* and the current process ID, respectively.
*
* Return: A new array of arguments with variables replaced, or NULL on error.
*/
char **replace_variables(char **args, char **env)
{
int i;
char *var_value;
char *new_arg;

for (i = 0; args[i] != NULL; i++)
{
if (args[i][0] == '$')
{
if (_strcmp(args[i], "$?") == 0)
{
new_arg = int_to_string(last_exit_status);
}
else if (_strcmp(args[i], "$$") == 0)
{
new_arg = int_to_string(getpid());
}
else
{
var_value = get_env_value(&args[i][1], env);
new_arg = var_value ? _strdup(var_value) : _strdup("");
}

if (new_arg)
{
free(args[i]);
args[i] = new_arg;
}
else
{
perror("Memory allocation error");
return (NULL);
}
}
}

return (args);
}

/**
* get_env_value - Retrieves the value of an environment variable.
* @name: The name of the environment variable.
* @env: The environment variables array.
*
* This function searches the environment array for a variable name
* and returns its corresponding value.
*
* Return: The value of the environment variable, or NULL if not found.
*/
char *get_env_value(const char *name, char **env)
{
int i;
char *env_entry;
char *env_name;
char *env_value;

for (i = 0; env[i] != NULL; i++)
{
env_entry = _strdup(env[i]);
env_name = strtok(env_entry, "=");
env_value = strtok(NULL, "=");

if (_strcmp(name, env_name) == 0)
{
free(env_entry);
return (env_value);
}
free(env_entry);
}

return (NULL);
}

/**
* int_to_string - Converts an integer to a string.
* @num: The integer to convert.
*
* This function takes an integer value and converts it to a string.
*
* Return: The string representation of the integer, or NULL on error.
*/
char *int_to_string(int num)
{
char *str;
int length = snprintf(NULL, 0, "%d", num) + 1;

str = malloc(length);
if (!str)
{
perror("Memory allocation error");
return (NULL);
}
snprintf(str, length, "%d", num);

return (str);
}
