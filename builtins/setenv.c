#include "../shell.h"

/**
 * builtin_setenv - Implements the setenv builtin command
 * @args: Arguments (variable name and value)
 * Return: Always returns 1 to continue executing
 */
int builtin_setenv(char **args)
{
    if (!args[1] || !args[2])
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return (1);
    }

    if (setenv(args[1], args[2], 1) != 0)
    {
        perror("setenv");
    }

    return (1);
}