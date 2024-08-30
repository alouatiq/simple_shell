#include "shell.h"
#include <string.h>  /* Include this line to resolve the strdup issue */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    // Your existing code
}

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
        tokens[i++] = strdup(token);  /* Ensure strdup is declared by including <string.h> */
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
