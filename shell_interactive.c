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
	/* Display the prompt */
	_printf("#cisfun$ ");

        /* Read the input line */
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		/* Handle end of file or read error */
		if (feof(stdin))
			exit(EXIT_SUCCESS); /* Exit on EOF */
		else
			perror("getline failed");
	}
	line[strcspn(line, "\n")] = 0;

	if (strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	/* Execute the command*/
	execute_command(line);
	}
	free(line); /* Free allocated memory */
}
