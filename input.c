#include "shell.h"
#include <stdlib.h>  /* Required for malloc, realloc */
#include <string.h>  /* Required for strlen, strcpy */

/* Custom strdup implementation */
char *my_strdup(const char *s)
{
    char *d = malloc(strlen(s) + 1);  /* Allocate memory for the duplicate string */
    if (d == NULL) return NULL;       /* Return NULL if memory allocation fails */
    strcpy(d, s);                     /* Copy the string to the allocated memory */
    return d;                         /* Return the duplicate string */
}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        return -1;
    }

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
        tokens[i++] = my_strdup(token);  /* Use custom strdup function */
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
