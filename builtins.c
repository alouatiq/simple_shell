#include "shell.h"

/**
 * shell_exit - Built-in command to exit the shell.
 * @args: Argument list (not used in this function).
 *
 * Return: (0) to signal exit in the main loop.
 */
int shell_exit(char **args)
{
    (void)args; /* Suppress unused parameter warning */
    return (0);
}

/**
 * shell_env - Built-in command to print environment variables.
 * @args: Argument list (not used in this function).
 *
 * Return: (1) to continue the shell loop.
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
    return (1);
}

/**
 * check_builtin - Checks if a command is a built-in command and executes it.
 * @args: Argument list for the command.
 *
 * Return: (1) if the command is a built-in, (0) otherwise.
 */
int check_builtin(char **args)
{
    if (strcmp(args[0], "exit") == 0)
        return (shell_exit(args));
    else if (strcmp(args[0], "env") == 0)
        return (shell_env(args));
    
    return (0);
}
