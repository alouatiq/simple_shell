#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* display_help_cd - Display help information for the 'cd' builtin.
*/
void display_help_cd(void)
{
_puts("cd: cd [directory]\n");
_puts("    Change the shell working directory.\n");
_puts("    If no argument is given, the command changes the\n");
_puts("    current directory to the value of the HOME variable.\n");
}

/**
* display_help_exit - Display help information for the 'exit' builtin.
*/
void display_help_exit(void)
{
_puts("exit: exit [n]\n");
_puts("    Exit the shell.\n");
_puts("    The exit status is given by 'n'. If 'n' is omitted,\n");
_puts("    the exit status is that of the last command executed.\n");
}

/**
* display_help_env - Display help information for the 'env' builtin.
*/
void display_help_env(void)
{
_puts("env: env\n");
_puts("    Print the environment of the shell.\n");
_puts("    This command lists all the environment variables\n");
_puts("    that are set in the shell session.\n");
}
