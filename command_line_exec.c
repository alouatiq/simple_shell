#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* execute_command_line - Executes a command line.
* @args: An array of arguments where args[0] is the command to execute.
*
* Task: This function forks a child process to execute the given command.
* If the command is found, it is executed in the child process.
* The parent process waits for the child process to complete.
*
* Return: 0 on success, or -1 on failure.
*/
int execute_command_line(char **args)
{
pid_t pid;
int status;
char *command;

if (!args || !args[0])
return (-1);

command = find_command_path(args[0]);
if (!command)
{
write(STDERR_FILENO, args[0], _strlen(args[0]));
write(STDERR_FILENO, ": command not found\n", 20);
return (-1);
}

pid = fork();
if (pid == -1)
{
perror("fork");
free(command);
return (-1);
}
else if (pid == 0)
{
if (execve(command, args, environ) == -1)
{
perror("execve");
free(command);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}

free(command);
return (0);
}

/**
* find_command_path - Finds the full path of a command.
* @command: The command to find.
*
* Task: This function searches the directories listed in the PATH
* environment variable for the specified command. If the command is found,
* the full path is returned; otherwise, NULL is returned.
*
* Return: The full path of the command, or NULL if not found.
*/
char *find_command_path(char *command)
{
char *path = getenv("PATH");
char *token, *full_path;
struct stat st;

if (!path)
return (NULL);

if (stat(command, &st) == 0)
return (_strdup(command));

token = _strtok(path, ":");
while (token)
{
full_path = malloc(_strlen(token) + _strlen(command) + 2);
if (!full_path)
return (NULL);

_strcpy(full_path, token);
_strcat(full_path, "/");
_strcat(full_path, command);

if (stat(full_path, &st) == 0)
return (full_path);

free(full_path);
token = _strtok(NULL, ":");
}

return (NULL);
}
