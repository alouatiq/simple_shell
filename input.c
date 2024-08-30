#include "shell.h"
#include <string.h>  /* Ensure this is included for strdup */
#include <stdlib.h>  /* Standard library for memory allocation functions */

/* Temporary implementation of my_getline to avoid warnings */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        return -1;
    }

    /* Dummy implementation just to avoid warnings for now */
    *lineptr = NULL;
    *n = 0;

    return 0;
}

/* Custom tokenization function */
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
        tokens[i++] = strdup(token);  /* strdup function is provided by <string.h> */
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
