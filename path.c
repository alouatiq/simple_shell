#include "shell.h"

/**
 * find_command - Searches for a command in the system PATH.
 * @command: The name of the command to search for.
 *
 * This function searches for the specified command in the directories listed
 * in the system PATH environment variable. If the command is found, the full
 * path to the command is returned; otherwise, NULL is returned.
 *
 * Return: The full path to the command, or NULL if not found.
 */


/* Task 3: Handle PATH */

char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *token;
	char *full_path;
	struct stat st;

	if (path == NULL)  /* Check if PATH is not set */
	{
	    fprintf(stderr, "Error: PATH variable is not set.\n");
	    return NULL;
	}

	if (stat(command, &st) == 0)  /* If command is an absolute or relative path */
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
