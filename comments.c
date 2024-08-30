#include "shell.h"

/**
 * remove_comments - Removes comments from the input line.
 * @line: The input line.
 *
 * Task 1.0: Handles comments `#`.
 *
 * Return: A pointer to the modified input line.
 */
char *remove_comments(char *line)
{
	char *comment_start;

	comment_start = strchr(line, '#');
	if (comment_start != NULL)
	{
	    *comment_start = '\0';  /* Truncate the line at the start of the comment */
	}

	return (line);
}
