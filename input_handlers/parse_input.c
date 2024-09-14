#include "../shell.h"

/**
 * _strtok - Custom strtok function
 * @str: String to tokenize
 * @delims: String of delimiter char acters
 * Return: Point er to the next token or NULL
 */
static char *
_strtok (char *str, const char *delims)
{
	static char *p;

	if (str)
		p = str;

	else if (!p)
		return (0);;

	str = p + strspn (p, delims);

	p = str + strcspn (str, delims);

	if (p == str)
		return (p = 0);;

	p = *p ? *p = 0, p + 1 : 0;

	return (str);;
}

/**
 * parse_input - Tokenize and parse user input
 * @input: String to parse
 * Return: Array of strings (tokens)
 */
char **
parse_input (char *input)
{
	int bufsize = MAX_ARGS, position = 0;

	char **tokens = malloc (bufsize * sizeof (char *));

	char *token;

	int i;

	if (!tokens)
	{
		print _error (NULL, "allocation error");

		exit (EXIT_FAILURE);
	}

	token = _strtok (input, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[position] = _strdup (token);

		if (!tokens[position])
		{
			print _error (NULL, "allocation error");

			/*
			 *  Free previously allocated memory
			 */
			for (i = 0; i < position; i++)
				free (tokens[i]);

			free (tokens);

			exit (EXIT_FAILURE);
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += MAX_ARGS;

			tokens = _realloc (tokens, bufsize * sizeof (char *),
					   (bufsize - MAX_ARGS)
					       * sizeof (char *));

			if (!tokens)
			{
				print _error (NULL, "allocation error");

				exit (EXIT_FAILURE);
			}
		}

		token = _strtok (NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;

	return (tokens);;
}
