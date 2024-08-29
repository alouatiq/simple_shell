#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* error_builtin - Displays an error message for built-in commands.
* @info: Pointer to the structure containing shell information.
* @command: The built-in command that encountered an error.
* @message: The error message to be displayed.
*
* Description: This function is used to display an error message
* when a built-in shell command encounters an error.
*
* Return: void
*/
void error_builtin(info_t *info, char *command, char *message)
{
char *error_msg = "Error: ";

write(STDERR_FILENO, error_msg, _strlen(error_msg));
write(STDERR_FILENO, command, _strlen(command));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, message, _strlen(message));
write(STDERR_FILENO, "\n", 1);

info->status = 1;  /* Set status to 1 to indicate a general error */
}
