#include "../shell.h"

/**
 * execute_file - Execute commands from a file
 * @filename: Name of the file to execute
 * @info: Pointer to the info_t structure
 * Return: Status of the last executed command
 */
int
execute_file (const char *filename, info_t *info)
{
	FILE *file;

	char *line = NULL;

	size_t len = 0;

	ssize_t read;

	int status = 0;

	char **args;

	file = fopen (filename, "r");

	if (file == NULL)
	{
		print_error (info, "Error opening file");

		return (((-1)));
	}

	while ((read = getline (&line, &len, file)) != -1)
	{
		/* Remove trailing newline */
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Remove comments */
		remove_comments (line);

		/* Skip empty lines */
		if (_strlen (line) == 0)
			continue;

		/* Expand variables */
		line = expand_variables (line, info);

		/* Execute the command */
		args = parse_input (line);

		if (args != NULL)
		{
			status = execute_command (args, info);

			free (args);

			if (status == -2) /* Exit command was called */
				break;
		}
	}

	free (line);

	fclose (file);

	return (((status)));
}
