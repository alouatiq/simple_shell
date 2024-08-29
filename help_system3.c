#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* display_general_help - Display general help information for the shell.
*/
void display_general_help(void)
{
_puts("Simple Shell Help\n");
_puts("These shell commands are defined internally.\n");
_puts("Type 'help' to see this list.\n");
_puts("Use 'help [name]' to find out more about the function '[name]'.\n");
_puts("\nBuilt-in commands:\n");
_puts("cd: Change the shell working directory.\n");
_puts("exit: Exit the shell.\n");
_puts("env: Print the environment of the shell.\n");
_puts("setenv: Set an environment variable.\n");
_puts("unsetenv: Remove an environment variable.\n");
_puts("alias: Define or display aliases.\n");
}
