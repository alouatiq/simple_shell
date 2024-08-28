#include "shell.h"

/**
 * str_tockenise - function transforms a sentence into an array of arguments
 * @buffer: the pointer to the sentence to be split
 * @del: string used to seperate the buffer parsed
 *
 * Return: Pointer to the array of arguments
 */
char **str_tockenise(char *buffer, char *del)
{
	char *str, **arguments, *tok;
	int i = 0, j, count = 0;

	if (buffer == NULL || del == NULL)
		return (NULL);
	str = strdup(buffer);
	if (str == NULL)
	{
		perror("strdup failed");
		return (NULL);
	}
	/* Count the delimeters in input to determine the number of tockens*/
	while (str[count] != '\0')
	{
		if (str[count] == *del)
			count++;
	}
	arguments = malloc((count + 2) * sizeof(char *));
	if (arguments == NULL) /* Check if malloc failed*/
	{
		perror("malloc failed");
		free(str);
		return (NULL);
	}
	for (tok = strtok(str, del); tok != NULL; tok = strtok(NULL, del))
	{
		arguments[i] = strdup(tok);
		if (arguments[i] == NULL)
		{
			perror("strdup failed");
			for (j = 0; j < i; j++)
				free(arguments[j]);
			free_all(arguments, NULL, str);
			return (NULL);
		}
		i++;
	}
	arguments[i] = NULL; /* Null-terminate the array of arguments*/
	free(str);
	return (arguments);
}
