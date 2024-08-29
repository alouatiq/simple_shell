#include <stdio.h>
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

void help_cd(void)
{
puts("cd: cd [directory]\n");
puts("   Change the current directory to DIR.\n");
puts("   The default DIR is the value of the HOME shell variable.\n");
}

void help_exit(void)
{
puts("exit: exit [n]\n");
puts("   Exits the shell with a status of N.\n");
puts("   If N is omitted, the exit status is that of the last command executed.\n");
}
