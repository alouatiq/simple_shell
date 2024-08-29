#include "shell.h"

/**
 * _strcspn - Calculates the length of the initial segment of 's' !in 'reject'
 * @line: The string to be scanned.
 * @reject: The string containing the characters to be rejected.
 *
 * Return: length of segment of line !in reject
 */
size_t _strcspn(const char *line, const char *reject)
{
	size_t j;
	size_t length = 0;
	int found;

	while (line[length] != '\0')
	{
		found = 0;

		for (j = 0; reject[j] != '\0'; j++)
		{
			if (line[length] == reject[j])
			{
				found = 1;
				break;
			}
		}
		if (found)
			break;
		length++;
	}
	return (length);
}
