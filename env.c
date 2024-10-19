#include "shell.h"

/**
 * env_builtin - Prints the environment variables
 */
void env_builtin(void)
{
    for (int i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);
}
