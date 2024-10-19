#include "shell.h"

/**
 * free_memory - Frees allocated memory for args array
 * @args: Argument array
 */
void free_memory(char **args)
{
    for (int i = 0; args[i]; i++)
        free(args[i]);
    free(args);
}
