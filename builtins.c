#include "shell.h"

/**
 * shell_exit - Built-in command to exit the shell.
 * @args: Argument list (not used in this function).
 *
 * Return: 0 to signal exit in the main loop.
 */
int shell_exit(char **args)
{
    (void)args; /* Suppress unused parameter warning */
    return 0; /* Return 0 to signal exit in main loop */
}

/**
 * shell_env - Built-in command to print environment variables.
 * @args: Argument list (not used in this function).
 *
 * Return: 1 to continue the shell loop.
 */
int shell_env(char **args)
{
    char **env = environ;

    (void)args; /* Suppress unused parameter warning */

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
    return 1;
}
