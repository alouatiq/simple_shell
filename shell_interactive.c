#include "shell.h"

/**
 * process_input - Processes user input in interactive mode
 * @line: Pointer to the input line
 * @len: Pointer to the size of the buffer for getline
 *
 * Return: 0 to continue, 1 to exit the shell
 */
int process_input(char **line, size_t *len)
{
	ssize_t read;
	int result;

	read = getline(line, len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
			write(STDOUT_FILENO, "\n", 1);
		free(*line);
		return (1);
	}

	(*line)[read - 1] = '\0';
	if ((*line)[0] == '\0')
		return (0);

	result = execute_command(*line);
	if (result == -1)
		fprintf(stderr, "Error executing command\n");
	else if (result == 2)
	{
		free(*line);
		return (1);
	}
	return (0);
}

/**
 * shell_interactive - Runs the shell in interactive mode
 *
 * Description: This function handles the main loop of the shell
 * in interactive mode, where it displays a prompt, waits for input,
 * and then processes the input.
 */
void shell_interactive(void)
{
	char *line = NULL;
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		if (process_input(&line, &len))
			exit(EXIT_SUCCESS);
	}
}
