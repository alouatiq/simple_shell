#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* error_cd - Displays an error message for the `cd` command.
* @info: Pointer to the structure containing shell information.
* @arg: The directory argument passed to the `cd` command.
*
* Description: This function is used to display an error message
* when the `cd` command fails to change the directory.
*
* Return: void
*/
void error_cd(info_t *info, char *arg)
{
char *msg = "Error: can't cd to ";

write(STDERR_FILENO, msg, _strlen(msg));
write(STDERR_FILENO, arg, _strlen(arg));
write(STDERR_FILENO, "\n", 1);

info->status = 2;  /* Set status to 2 for a specific `cd` error */
}
