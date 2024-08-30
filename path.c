#include "shell.h"

char *find_command_in_path(char *command)
{
    char *path = getenv("PATH");
    char *token, *full_path;
    struct stat st;

    token = strtok(path, ":");
    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(command) + 2);
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (stat(full_path, &st) == 0)
            return full_path;

        free(full_path);
        token = strtok(NULL, ":");
    }

    return NULL;
}
