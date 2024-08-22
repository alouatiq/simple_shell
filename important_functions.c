#include "shell.h"

/**
 * get_arguments - function that transforms a sentence into an array of arguments
 * @buffer: the pointer to the sentence to be split
 *
 * Return: Pointer to the array of arguments
 */
char **get_arguments(char *buffer)
{
	char *str, **arguments, *token, *temp;
	int i, count;

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
	temp = str;
	count = 0;

	// Count the number of spaces in the input to determine the number of arguments
	while (*temp)
	{
		if (*temp == ' ')
			count++;
		temp++;
	}

	// Allocate memory for the array of arguments (including NULL terminator)
	arguments = malloc((count + 2) * sizeof(char *));

	if (arguments == NULL) // Check if malloc failed
	{
		perror("malloc failed");
		free(str);
		return (NULL);
	}

	i = 0;
	token = strtok(str, " "); // Tokenize the string by spaces
	arguments[i] = token;

	i++;

	// Continue tokenizing the string and storing tokens in the arguments array
	while (token != NULL)
	{
		arguments[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arguments[i] = NULL; // Null-terminate the array of arguments

	return (arguments);
}
