#include "shell.h"

/**
 * get_arguments - function that transforms a sentence into an array of arguments
 * @buffer: the pointer to the sentence to be split
 *
 * Return: Pointer to the array of arguments
 */
char **get_arguments(char *buffer)
{
	char *str, **arguments, *token;
	int i, count, j;

	if (buffer == NULL) // Check if the input buffer is NULL
	{
		return (NULL);
	}

	str = strdup(buffer); // Duplicate the input buffer to avoid modifying the original string

	if (str == NULL) // Check if strdup failed
	{
		perror("strdup failed");
		return (NULL);
	}

	// Count the number of spaces in the input to determine the number of arguments
	token = strtok(str, " ");
	count = 0;
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}

	// Allocate memory for the array of arguments (including NULL terminator)
	arguments = malloc((count + 1) * sizeof(char *));

	if (arguments == NULL) // Check if malloc failed
	{
		perror("malloc failed");
		free(str);
		return (NULL);
	}

	str = strdup(buffer);
	token = strtok(str, " "); // Tokenize the string by spaces

	// Continue tokenizing the string and storing tokens in the arguments array
	i = 0;
	while (token != NULL)
	{
		arguments[i] = strdup(token);
		if (arguments[i] == NULL)
		{
			perror("strdup failed");
			for (j = 0; j < i; j++)
				free(arguments[j]);
			free(arguments);
			free(str);
			return (NULL);
		}
		token = strtok(NULL, " ");
		i++;
	}
	arguments[i] = NULL; // Null-terminate the array of arguments
	free(str);

	return (arguments);
}
