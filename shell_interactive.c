#include "shell.h"

/**
 * shell_interactive - Runs the shell in interactive mode
 *
 * Task 1: Simple Shell 0.1
 *
 * Description: This function handles the main loop of the shell
 * in interactive mode, where it displays a prompt, waits for input,
 * and then processes the input.
 */
void shell_interactive(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
	_printf("#cisfun$ ");
	errno = 0;
	read = my_getline(&line, &len, stdin);
	if (read == -1)
	{
		if (errno == EINTR || errno == EAGAIN)
			continue;
		else if (errno == 0)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		else
		{
			perror("getline failed");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	if (read == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	line[_strcspn(line, "\n")] = 0;
	if (_strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	execute_command(line);
	}
	free(line); /* Free allocated memory */
}
