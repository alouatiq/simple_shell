#include "shell.h"

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
        }
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

void free_tokens(char **tokens)
{
    for (int i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}
