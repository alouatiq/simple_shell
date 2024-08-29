#include "shell.h"

/**
 * prompt - Displays the shell prompt.
 */
void prompt(void)
{
	_puts("#cisfun$ ");
}

/**
 * read_command - Reads a command from the user input.
 *
 * Return: The command entered by the user.
 */
char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = _getline(&command, &len);
	if (nread == -1)
	{
		free(command);
		return (NULL);
	}

	return (command);
}
