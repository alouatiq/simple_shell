#include "shell.h"

/**
 * shell_non_interactive - Executes commands from a file
 * @filename: The name of the file containing the commands
 *
 * Task 1: Simple Shell 0.1
 *
 * Description: This function processes each line from the file
 * as if it were a command entered interactively.
 */
void shell_non_interactive(char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';  /* Remove newline character */
		}

		/* Skip empty lines */
		if (line[0] == '\0')
		{
			continue;
		}

		/* Execute the command */
		if (execute_command(line) == -1)
		{
			fprintf(stderr, "Error executing command: %s\n", line);
		}
	}

	if (line)
	{
		free(line);
	}
	fclose(file);
}
