#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: This program implements a simple UNIX command line interpreter.
 * It can run in both interactive and non-interactive modes.
 *
 * Return: Exit status of the shell
 */
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		/* No arguments, start the shell in interactive mode */
		shell_interactive();
	}
	else if (argc == 2)
	{
		/* If one argument is passed, treat it as a script file */
		shell_non_interactive(argv[1]);
	}
	else
	{
		/* If more than one argument, print usage and exit */
		fprintf(stderr, "Usage: %s [script_file]\n", argv[0]);
		return (1);
	}

	return (0);
}
