#include "shell.h"

/* Task 3: Handle PATH */

char *find_command(char *command)
{
    char *path = getenv("PATH");
    char *token;
    char *full_path;
    struct stat st;

    if (stat(command, &st) == 0)  /* If command is an absolute path */
    {
        return command;
    }

    token = strtok(path, ":");
    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL)
        {
            perror("malloc");
            return NULL;
        }

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (stat(full_path, &st) == 0)  /* If command is found in PATH */
        {
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    return NULL;  /* Command not found in PATH */
}
