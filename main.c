#include "shell.h"

extern char **environ;

/**
 * main - Entry point for the simple shell
 *
 * Return: Exit status of the shell
 */
int
main ()
{
	char *line = NULL;

	size_t len = 0;

	ssize_t read;

	char **args;

	int status = 1;

	info_t info = { 0 }; /*
			      *  Initialize info structure
			      */
	int i;

	/*
	 *  Initialize the info structure
	 */
	info.fname = "hsh"; /*
			     *  Or whatever your shell's name is
			     */
	info.argv = NULL;   /* Set this if you pass command line arguments to
			       your shell */
	info.env = environ; /*
			     *  Use the global environ
			     */

	while (status)
	{
		info.line_count++;

		if (isatty (STDIN_FILENO))
			printf ("$ ");

		read = getline (&line, &len, stdin);

		if (read == -1)
		{
			if (isatty (STDIN_FILENO))
				printf ("\n");

			break;
		}

		info.input_line = line;

		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0'; /*
						*  Remove newline char acter
						*/

		args = parse_input (line);

		if (args == NULL)
		{
			print_error (&info, "Memory allocation error");

			continue;
		}

		if (args[0] != NULL)
		{
			status = execute_command (args, &info);

			if (status == -2)
			{
				/*
				 *  Exit command was called
				 */
				free (args);

				break;
			}
		}

		free (args);
	}

	free (line);

	/*
	 *  Perform any final cleanup
	 */
	if (info.env != environ)
	{
		for (i = 0; info.env[i]; i++)
			free (info.env[i]);

		free (info.env);
	}

	/*
	 *  Close any open file descriptors
	 */
	for (i = 3; i < 20; i++)
		close (i);

	return (info.exit_status);;
}
