#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/**
 * find_command_in_path - Searches for a command in the system's PATH
 * @command: The command to search for
 *
 * Task 3: Simple Shell 0.3 (Handle the PATH)
 *
 * Description: This function searches the directories listed in the PATH
 * environment variable for the specified command. If the command is found,
 * the full path to the command is returned. If the command is not found,
 * the function returns NULL.
 *
 * Return: A pointer to a string containing the full path to the command,
 * or NULL if the command is not found.
 */
char *find_command_in_path(char *command)
{
    char *path_env, *path, *full_path;
    size_t command_len, path_len;
    char *token;
    struct stat st;

    if (command == NULL || *command == '\0') {
        return NULL;
    }

    /* If the command contains a slash, don't search in PATH */
    if (strchr(command, '/')) {
        if (stat(command, &st) == 0) {
            return strdup(command);
        } else {
            return NULL;
        }
    }

    /* Get the PATH environment variable */
    path_env = getenv("PATH");
    if (path_env == NULL) {
        return NULL;
    }

    /* Duplicate the PATH so we can tokenize it */
    path = strdup(path_env);
    if (path == NULL) {
        return NULL;
    }

    command_len = strlen(command);

    /* Tokenize the PATH */
    token = strtok(path, ":");
    while (token != NULL) {
        path_len = strlen(token);
        full_path = malloc(path_len + command_len + 2); /* +2 for '/' and '\0' */
        if (full_path == NULL) {
            free(path);
            return NULL;
        }

        /* Build the full path */
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        /* Check if the command exists at this path */
        if (stat(full_path, &st) == 0) {
            free(path);
            return full_path; /* Command found */
        }

        /* Free the full_path and try the next directory */
        free(full_path);
        token = strtok(NULL, ":");
    }

    /* Clean up */
    free(path);
    return NULL; /* Command not found in PATH */
}
