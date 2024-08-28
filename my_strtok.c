#include "shell.h"

/**
 * _strtok - Custom implementation of the strtok function
 * @str: The string to be tokenized
 * @delim: The delimiter string used to split the tokens
 *
 * Description: This function tokenizes a string by splitting it into tokens
 * based on the specified delimiters. It stores the tokens in the provided
 * array. This implementation does not use the standard library's strtok.
 * Return: Pointer to array of tockens
 */
char *_strtok(char *str, char *delim)
{
	int i;
	char *tocken;
	static char *input;

	i = 0;

	/* If the string parameter is NULL, return NULL */
	if (str != NULL)
		input = str;

	if (input == NULL)
		return (NULL);

	tocken = input;

	while (input[i] != '\0')
	{
		if (input[i] == *delim)
		{
			input[i] = '\0';
			input += i + 1;
			return (tocken);
		}
		i++;
	}
	input = NULL;

	return (tocken);
}
