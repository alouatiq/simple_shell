#include "../shell.h"

/**
 * builtin_unsetenv - Implements the unsetenv builtin command
 * @args: Arguments (variable name)
 * Return: Always returns 1 to continue executing
 */
int builtin_unsetenv(char **args)
{
    if (!args[1])
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return (1);
    }

    if (unsetenv(args[1]) != 0)
    {
        perror("unsetenv");
    }

    return (1);
}