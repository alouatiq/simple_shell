#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* display_help_setenv - Display help information for the 'setenv' builtin.
*/
void display_help_setenv(void)
{
_puts("setenv: setenv [variable] [value]\n");
_puts("    Set an environment variable.\n");
_puts("    The 'setenv' command creates or modifies an environment\n");
_puts("    variable. If the variable does not exist, it is created.\n");
}

/**
* display_help_unsetenv - Display help information for the 'unsetenv' builtin.
*/
void display_help_unsetenv(void)
{
_puts("unsetenv: unsetenv [variable]\n");
_puts("    Remove an environment variable.\n");
_puts("    The 'unsetenv' command deletes the specified environment\n");
_puts("    variable from the shell's environment.\n");
}

/**
* display_help_alias - Display help information for the 'alias' builtin.
*/
void display_help_alias(void)
{
_puts("alias: alias [name[='value'] ...]\n");
_puts("    Define or display aliases.\n");
_puts("    An alias is a shortcut for a command.\n");
_puts("    Without arguments, 'alias' prints the list of aliases.\n");
}
