#include "../shell.h"

/**
 * builtin_exit - Implements the exit builtin command
 * @args: Arguments (exit status)
 * Return: Always returns 0 to terminate the shell
 */
int builtin_exit(char **args)
{
    int status = 0;

    if (args[1])
    {
        status = atoi(args[1]);
    }

    // Free any allocated memory, close file descriptors, etc.
    // ...

    exit(status);
}