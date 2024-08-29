#include "shell.h"

/**
 * prompt - Displays the shell prompt to the standard output.
 *
 * This function writes the shell prompt "#cisfun$ " to the standard output.
 */


/* Task 1: Basic Shell Implementation */


void prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);  /* Display the shell prompt */
}

/**
 * read_command - Reads a command from the user input.
 *
 * This function reads a line of input from the user, removes the newline character,
 * and returns the command string. It handles memory allocation for the command buffer.
 *
 * Return: A pointer to the command string, or NULL on EOF or error.
 */

/* Task 2: Handle Command Line Arguments */

char *read_command(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	/* Task 6: Use custom getline function with the correct arguments */
	characters = _getline(&buffer, &bufsize, stdin);  /* Use stdin as the input stream */

	if (characters == -1)  /* Handle EOF (Ctrl+D) */
	{
	    free(buffer);
	    return NULL;
	}

	buffer[characters - 1] = '\0';  /* Remove the newline character */
	return buffer;
}
