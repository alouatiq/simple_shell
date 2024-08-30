#include "shell.h"
#include <stdlib.h>  /* Required for setenv and unsetenv */

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

int handle_setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || value == NULL)
    {
        perror("setenv");
        return (-1);
    }

    return (setenv(name, value, overwrite));  /* setenv needs stdlib.h */
}

int handle_unsetenv(const char *name)
{
    if (name == NULL)
    {
        perror("unsetenv");
        return (-1);
    }

    return (unsetenv(name));  /* unsetenv needs stdlib.h */
}
