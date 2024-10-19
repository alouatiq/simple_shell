#include "shell.h"

/**
 * _getline - Custom implementation of getline
 * @lineptr: Pointer to the buffer to store the line
 * @n: Size of the buffer
 * @stream: The input stream
 *
 * Return: Number of characters read, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t read_chars;
    size_t i = 0;
    char c;

    if (*lineptr == NULL)
    {
        *lineptr = malloc(128);
        if (*lineptr == NULL)
            return (-1);
        *n = 128;
    }

    while ((read_chars = read(fileno(stream), &c, 1)) > 0)
    {
        if (i >= *n - 1)
        {
            *lineptr = realloc(*lineptr, *n * 2);
            if (*lineptr == NULL)
                return (-1);
            *n *= 2;
        }
        (*lineptr)[i++] = c;
        if (c == '\n')
            break;
    }

    if (read_chars == -1 || (read_chars == 0 && i == 0))
        return (-1);

    (*lineptr)[i] = '\0';
    return (i);
}
