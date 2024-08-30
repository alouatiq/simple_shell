#include "shell.h"

/**
 * handle_env - Handles the built-in `env` command.
 *
 * Task 1.0: Handles `env`.
 */
void handle_env(void)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}
