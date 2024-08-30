#include "shell.h"

/**
 * handle_exit - Handles the built-in `exit` command.
 * @args: An array of arguments.
 *
 * Task 0.4: Handles built-in commands.
 * Task 0.4.1: Handles `exit` with status.
 */
void handle_exit(char **args)
{
    int status = 0;

    if (args[1] != NULL)  /* If there's an argument, convert it to an exit status */
    {
        status = atoi(args[1]);
    }

    exit(status);
}

/**
 * handle_setenv - Handles the built-in `setenv` command.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * @overwrite: Overwrite the variable if it already exists.
 *
 * Task 1.0: Handles `setenv`.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || value == NULL)
    {
        perror("setenv");
        return (-1);
    }

    return (setenv(name, value, overwrite));
}

/**
 * handle_unsetenv - Handles the built-in `unsetenv` command.
 * @name: The name of the environment variable to remove.
 *
 * Task 1.0: Handles `unsetenv`.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_unsetenv(const char *name)
{
    if (name == NULL)
    {
        perror("unsetenv");
        return (-1);
    }

    return (unsetenv(name));
}
