#include "shell.h"

/**
 * _getline - Custom implementation of getline function.
 * @buffer: A pointer to the buffer where the line will be stored.
 * @bufsize: The size of the buffer.
 *
 * Return: The number of characters read, or -1 on failure or EOF.
 */
ssize_t _getline(char **buffer, size_t *bufsize)
{
	ssize_t len = 0;
	char *buf = NULL;

	if (buffer == NULL || bufsize == NULL)
		return (-1);

	buf = malloc(1024);
	if (buf == NULL)
		return (-1);

	while (1)
	{
		ssize_t r = read(STDIN_FILENO, buf + len, 1);

		if (r == -1)
		{
			free(buf);
			return (-1);
		}
		else if (r == 0)
		{
			if (len == 0)
			{
				free(buf);
				return (-1);
			}
			break;
		}
		else
		{
			if (buf[len] == '\n')
			{
				buf[len + 1] = '\0';
				break;
			}
			len++;
		}
	}

	*buffer = buf;
	*bufsize = len + 1;

	return (len);
}
