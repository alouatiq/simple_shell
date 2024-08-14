#include "shell.h"

char *find_command(char *cmd)
{
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");
    struct stat st;
    char full_path[1024];

    if (stat(cmd, &st) == 0)
    {
        return _strdup(cmd);
    }

    while (dir != NULL)
    {
        _strcpy(full_path, dir);
        _strcat(full_path, "/");
        _strcat(full_path, cmd);

        if (stat(full_path, &st) == 0)
        {
            return _strdup(full_path);
        }

        dir = strtok(NULL, ":");
    }

    return NULL;
}
