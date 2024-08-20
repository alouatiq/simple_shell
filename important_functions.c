#include "shell.h"

/**
 * get_arguments - function that transforms a sentence into an array arguments
 * @buffer: the pointer of the sentence to be split
 * Return: Pointer to array of sentence
 */
char **get_arguments(char *buffer)
{
	char *str, **arguments, *tocken, *temp;
	int i, count;

	if (buffer == NULL)
	{
		return (NULL);
	}
	str = strdup(buffer);

	if (str == NULL)
	{
		perror("strdup failed");
		return (NULL);
	}
	temp = str;
	count = 0;

	while (*temp)
	{
		if (*temp == ' ')
			count++;
		temp++;
	}
	arguments = malloc((count + 2) *sizeof(char *));

	if (arguments == NULL)
	{
		perror("malloc failed");
		free(str);
		return (NULL);
	}
	i = 0;
	tocken = strtok(str, " ");
	arguments[i] = tocken;

	i++;

	while (tocken != NULL)
	{
		arguments[i] = tocken;
		tocken = strtok(NULL, " ");
		i++;
	}
	arguments[i] = NULL;

	return (arguments);
}
