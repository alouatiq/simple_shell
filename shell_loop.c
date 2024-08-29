#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* shell_loop - Main loop of the shell, continuously processing user input.
* @env: The environment variables array.
*
* This function is responsible for the main loop of the shell, where it
* repeatedly prompts the user for input, processes the input, and executes
* commands. It handles both interactive and non-interactive modes.
*/
void shell_loop(char **env)
{
char *input;
char **args;
int status = 1;

while (status)
{
if (isatty(STDIN_FILENO))
prompt();  /* Display prompt in interactive mode */

input = read_command();  /* Read the command input */

if (input == NULL)  /* Handle EOF */
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
break;
}

args = split_line(input);  /* Split the input into arguments */
if (args == NULL)
{
free(input);
continue;
}

args = replace_variables(args, env);  /* Replace variables in the arguments */
if (args == NULL)
{
free(input);
free_args(args);
continue;
}

status = execute_command(args, env);  /* Execute the command */

free(input);
free_args(args);
}
}

/**
* free_args - Frees the memory allocated for arguments array.
* @args: The arguments array to free.
*
* This function frees the memory allocated for the array of command arguments.
*/
void free_args(char **args)
{
int i;

if (args == NULL)
return;

for (i = 0; args[i] != NULL; i++)
free(args[i]);

free(args);
}
