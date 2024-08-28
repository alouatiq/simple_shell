#include "shell.h"

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
	int result;

	if (!lineptr || !n || !stream)
	{
		errno = EINVAL;
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*n = 128; /* Initial buffer size */
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			errno = ENOMEM;
			return (-1);
		}
	}
	result = read_characters(lineptr, n, stream, &num_read);
	if (result == -1)
		return (-1);

	(*lineptr)[num_read] = '\0';
	return (num_read);
}
/**
 * read_characters - Reads characters from the stream
 * @lineptr: Pointer to the buffer that will store the line
 * @n: Pointer to the size of the buffer
 * @stream: The input stream to read from
 * @num_read: Pointer to the number of characters read
 *
 * Return: 0 on success, -1 on failure or EOF
 */
int read_characters(char **lineptr, size_t *n, FILE *stream, size_t *num_read)
{
	int ch;
	size_t new_size;

	while ((ch = fgetc(stream)) != EOF)
	{
		/* Resize buffer if necessary */
		if (num_read + 1 >= *n)
		{
			new_size = *n * 2;
			if (resize_buffer(lineptr, n, new_size) == -1)
			{
				return (-1);
			}
		}
		(*lineptr)[num_read++] = ch;

		if (ch == '\n')
			break;
	}
	if (num_read == 0 && ch == EOF)
	{
		errno = 0;
		return (-1); /* End of file with no characters read */
	}
	return (num_read);
}

/**
 * resize_buffer - Resizes the buffer if necessary
 * @lineptr: Pointer to the buffer that will store the line
 * @n: Pointer to the size of the buffer
 * @new_size: The new size of the buffer
 *
 * Return: 0 on success, -1 on failure
 */
int resize_buffer(char **lineptr, size_t *n, size_t new_size)
{
	char *new_ptr = realloc(*lineptr, new_size);

	if (!new_ptr)
	{
		errno = ENOMEM;
		return (-1);
	}
	*lineptr = new_ptr;
	*n = new_size;
	return (0);
}
