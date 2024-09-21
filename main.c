#include "shell.h"

/* Function prototypes */
void initialize_info(info_t *info);
int process_command(char **args, info_t *info);
void cleanup(info_t *info, char *line);

/**
 * main - Entry point for the simple shell
 *
 * Return: Exit status of the shell
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int status = 1;
	info_t info = {0}; /* Initialize info structure */

	initialize_info(&info);

	while (status)
	{
		info.line_count++;
		if (isatty(STDIN_FILENO))
			printf("$ ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		info.input_line = line;
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0'; /* Remove newline character */

		args = parse_input(line);
		if (args == NULL)
		{
			print_error(&info, "Memory allocation error");
			continue;
		}

		if (args[0] != NULL)
			status = process_command(args, &info);

		free_tokens(args);
	}

	cleanup(&info, line);

	return (info.exit_status);
}

/**
 * initialize_info - Initialize the info structure
 * @info: Pointer to the info structure
 */
void initialize_info(info_t *info)
{
	info->fname = "hsh"; /* Or whatever your shell's name is */
	info->argv = NULL;   /* Set this if you pass command line arguments */
	info->env = environ; /* Use the global environ */
}

/**
 * process_command - Process and execute a command
 * @args: Array of command arguments
 * @info: Pointer to the info structure
 *
 * Return: Status of command execution
 */
int process_command(char **args, info_t *info)
{
	int status = execute_command(args, info);

	if (status == -2)
	{
		/* Exit command was called */
		return (-2);
	}

	return (status);
}

/**
 * cleanup - Perform final cleanup operations
 * @info: Pointer to the info structure
 * @line: Input line to be freed
 */
void cleanup(info_t *info, char *line)
{
	int i;

	free(line);

	/* Perform any final cleanup */
	if (info->env != environ)
	{
		for (i = 0; info->env[i]; i++)
			free(info->env[i]);
		free(info->env);
	}

	/* Close any open file descriptors */
	for (i = 3; i < 20; i++)
		close(i);
}
