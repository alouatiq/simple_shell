#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_getline - Custom implementation of the getline function
 * @lineptr: Pointer to the buffer that will store the line
 * @n: Pointer to the size of the buffer
 * @stream: The input stream to read from
 *
 * Return: The number of characters read, or -1 on failure or EOF
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t num_read = 0;
	int ch;
	size_t new_size;
	char *new_ptr;

	if (!lineptr || !n || !stream)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 128; /* Initial buffer size */
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((ch = fgetc(stream)) != EOF)
	{
		/* Resize buffer if necessary */
		if (num_read + 1 >= *n)
		{
			new_size = *n * 2;
			new_ptr = realloc(*lineptr, new_size);
			if (!new_ptr)
				return (-1);
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[num_read++] = ch;

		if (ch == '\n')
			break;
	}
	if (num_read == 0 && ch == EOF)
		return (-1); /* End of file with no characters read */

	(*lineptr)[num_read] = '\0'; /* Null-terminate the string */

	return (num_read);
}
