#include "shell.h"

/**
 * find_command - Finds the full path of a command.
 * @command: The command to find.
 *
 * Return: The full path if found, otherwise NULL.
 */
char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *token;
	char full_path[1024];

	if (command[0] == '/')
		return (command);

	token = strtok(path, ":");
	while (token != NULL)
	{
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
			return (full_path);

		token = strtok(NULL, ":");
	}

	return (NULL);
}
