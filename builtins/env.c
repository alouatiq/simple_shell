#include "../shell.h"

/**
 * builtin_env - Implements the env builtin command
 * @args: Arguments (unused)
 * Return: Always returns 1 to continue executing
 */
int builtin_env(char **args)
{
    char **env;
    (void)args;  // Unused parameter

    for (env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }

    return (1);
}