#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* print_error - Prints an error message to standard error.
* @shell_name: The name of the shell or program.
* @command: The command that caused the error.
* @message: The specific error message to display.
*
* Task: This function formats and prints an error message to the standard
* error stream. It is used to display errors related to command execution
* or other shell operations.
*/
void print_error(char *shell_name, char *command, char *message)
{
_fprintf(stderr, "%s: %s: %s\n", shell_name, command, message);
}

/**
* error_cd - Displays an error message when the "cd" command fails.
* @shell_name: The name of the shell or program.
* @command: The "cd" command.
* @arg: The directory that could not be changed to.
*
* Task: This function prints an error message when the "cd" command fails,
* indicating that the specified directory could not be accessed.
*/
void error_cd(char *shell_name, char *command, char *arg)
{
_fprintf(stderr, "%s: %s: %s: can't cd to %s\n", shell_name, command, strerror(errno), arg);
}

/**
* error_not_found - Displays an error message when a command is not found.
* @shell_name: The name of the shell or program.
* @command: The command that was not found.
*
* Task: This function prints an error message indicating that the specified
* command was not found in the system's PATH.
*/
void error_not_found(char *shell_name, char *command)
{
_fprintf(stderr, "%s: %s: command not found\n", shell_name, command);
}

/**
* error_exit_status - Displays an error message for invalid exit status.
* @shell_name: The name of the shell or program.
* @command: The "exit" command.
* @arg: The invalid exit status provided.
*
* Task: This function prints an error message when an invalid exit status
* is provided to the "exit" command, indicating that the exit status must
* be a numeric value.
*/
void error_exit_status(char *shell_name, char *command, char *arg)
{
_fprintf(stderr, "%s: %s: %s: numeric argument required\n", shell_name, command, arg);
}

/**
* error_permission_denied - Displays an error message for permission denied.
* @shell_name: The name of the shell or program.
* @command: The command that caused the permission denied error.
*
* Task: This function prints an error message indicating that the user does
* not have the necessary permissions to execute the specified command.
*/
void error_permission_denied(char *shell_name, char *command)
{
_fprintf(stderr, "%s: %s: Permission denied\n", shell_name, command);
}
