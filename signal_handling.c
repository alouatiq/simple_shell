
#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* handle_sigint - Handles the SIGINT signal (Ctrl+C).
* @sig: The signal number.
*
* Task: Implement signal handling for SIGINT.
* Return: void
*/
void handle_sigint(int sig)
{
(void)sig;
write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
* setup_signal_handlers - Sets up signal handlers for the shell.
*
* Task: Initialize signal handling mechanisms.
* Return: void
*/
void setup_signal_handlers(void)
{
signal(SIGINT, handle_sigint);
}
