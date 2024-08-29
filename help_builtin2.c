#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* help_setenv - Displays help information for the `setenv` command.
*
* Description: This function provides detailed help information
* for the `setenv` built-in command, explaining how it can be used
* to set or modify environment variables.
*
* Return: void
*/
void help_setenv(void)
{
_puts("setenv: setenv [VARIABLE] [VALUE]\n");
_puts("   Initialize a new environment variable,
or modify an existing one.\n");
_puts("\n   Sets the environment variable VARIABLE to VALUE. If VARIABLE\n");
_puts("   already exists in the environment, the value is replaced.\n");
}

/**
* help_unsetenv - Displays help information for the `unsetenv` command.
*
* Description: This function provides detailed help information
* for the `unsetenv` built-in command, explaining how it can be used
* to remove environment variables.
*
* Return: void
*/
void help_unsetenv(void)
{
_puts("unsetenv: unsetenv [VARIABLE]\n");
_puts("   Remove an environment variable.\n");
_puts("\n   Removes the variable VARIABLE from the environment.\n");
_puts("   If VARIABLE does not exist, an error is printed.\n");
}

/**
* help_alias - Displays help information for the `alias` command.
*
* Description: This function provides detailed help information
* for the `alias` built-in command, explaining how it can be used
* to define or display aliases.
*
* Return: void
*/
void help_alias(void)
{
_puts("alias: alias [NAME[='VALUE'] ...]\n");
_puts("   Define or display aliases.\n");
_puts("\n   Without arguments, `alias` prints
the list of aliases in the reusable\n");
_puts("   form `alias NAME=VALUE` on standard output.\n");
_puts("   Otherwise, an alias is defined for
each NAME whose VALUE is given.\n");
}
