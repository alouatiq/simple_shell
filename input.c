#include "shell.h"

/**
 * my_getline - Custom implementation of getline function.
 * @lineptr: Pointer to the buffer where the input line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: The input stream to read from (usually stdin).
 *
 * Task 0.1.1: Handles input-related functions.
 * Task 0.1.1: Implements custom `my_getline` function.
 *
 * Return: The number of characters read (including the newline character), or -1 on failure.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t num_read = 0;
    size_t pos = 0;
    char ch;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return (-1);

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;  // Default initial buffer size
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return (-1);
    }

    while ((ch = fgetc(stream)) != EOF)
    {
        if (pos >= *n - 1)
        {
            *n *= 2;  // Double the buffer size
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL)
                return (-1);
        }

        (*lineptr)[pos++] = ch;
        num_read++;

        if (ch == '\n')
            break;
    }

    if (num_read == 0 || ferror(stream))
        return (-1);

    (*lineptr)[pos] = '\0';  // Null-terminate the string

    return (num_read);
}

/**
 * custom_tokenize - Custom function to tokenize a string into an array of tokens.
 * @line: The input string to tokenize.
 *
 * Task 0.2.1: Implements custom tokenization.
 *
 * Return: An array of tokens, or NULL on failure.
 */
char **custom_tokenize(char *line)
{
    char **tokens = NULL;
    char *token;
    size_t i = 0;
    size_t buffer_size = 10;

    if (line == NULL)
        return (NULL);

    tokens = malloc(buffer_size * sizeof(char *));
    if (tokens == NULL)
        return (NULL);

    token = strtok(line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[i++] = strdup(token);
        if (i >= buffer_size)
        {
            buffer_size *= 2;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if (tokens == NULL)
                return (NULL);
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[i] = NULL;

    return (tokens);
}
