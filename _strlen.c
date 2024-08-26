#include "shell.h"

/**
 * _strlen - Finds the length of a sstring
 * @string: String to be mesured
 *
 * Return: Length of the string
 */
int _strlen(char *string)
{
	int len =0;

	while (string[len] != '\0')
		len++;
	return (len);
}
