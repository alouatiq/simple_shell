#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * tokenize_line - Splits a line into tokens (words) based on spaces.
 * @line: The input line to be tokenized.
 *
 * Return: An array of tokens, or NULL on failure.
 */
char **tokenize_line(char *line)
{
    char **tokens = NULL;
    char *token;
    int bufsize = 64, i = 0;

    tokens = malloc(sizeof(char *) * bufsize);
    if (!tokens)
        return NULL;

    token = strtok(line, " ");
    while (token)
    {
        tokens[i++] = strdup(token);
        if (i >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, sizeof(char *) * bufsize);
            if (!tokens)
                return NULL;
        }
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

/**
 * free_tokens - Frees a NULL-terminated array of strings.
 * @tokens: Array of strings to be freed.
 */
void free_tokens(char **tokens)
{
    int i; /* Move the variable declaration outside the for loop */

    if (tokens)
    {
        for (i = 0; tokens[i]; i++)
            free(tokens[i]);
        free(tokens);
    }
}
