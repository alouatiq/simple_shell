#include "shell.h"

/**
 * command_check - Checks if a command is executable and returns the command
 * @command: string representing command to be checked
 * @path_list: pointer to array of paths
 *
 * Return: Apointer to the full command path if executable else, NULL
 */
char *command_check(char *command, char **path_list)
{
	int i;
	char *final_command;
	size_t com_len, path_len;

	final_command = NULL;

	if (command == NULL || path_list == NULL)
		return (NULL);
	com_len = strlen(command);

	for (i = 0; path_list[i] != NULL; i++)
	{
		path_len = strlen(path_list[i]);
		final_command = malloc(path_len + com_len + 2);

		if (final_command == NULL)
		{
			perror("malloc failed");
			return (NULL);
		}
		strcpy(final_command, path_list[i]);
		strcat(final_command, "/");
		strcat(final_command, command);

		if (access(final_command, X_OK) == 0)
		{
			return (final_command);
		}
		free(final_command);
		final_command = NULL;
	}
	return (NULL);

}
