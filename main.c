#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		_puts("#cisfun$ ");
		nread = _getline(&command, &len);
		if (nread == -1)
		{
			_puts("\n");
			break;
		}
		if (_strcmp(command, "exit\n") == 0)
			break;
		execute_command(command);
	}

	free(command);
	return (0);
}
