#include "shell.h"

/**
 * find_in_path - Finds the executable in the PATH
 * @command: The command to find
 *
 * Return: Full path to the executable, or NULL if not found
 */
char *find_in_path(char *command)
{
    char *path = getenv("PATH"), *path_copy, *dir;
    char full_path[1024];

    if (path == NULL)
        return (NULL);

    path_copy = strdup(path);
    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (strdup(full_path));
        }
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return (NULL);
}
