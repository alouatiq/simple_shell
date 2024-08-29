#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* main - Entry point of the shell program.
* @argc: Argument count.
* @argv: Argument vector (array of strings containing arguments).
*
* Task: Implement the main loop of the shell, handle command line arguments,
* and initiate the shell environment.
*
* Return: 0 on success, or an error code on failure.
*/
int main(int argc, char **argv)
{
(void)argc;  /* Unused parameter */
(void)argv;  /* Unused parameter */

/* Initialize signal handlers */
setup_signal_handlers();

/* Main shell loop */
shell_loop();

/* Cleanup and exit */
return (EXIT_SUCCESS);
}
