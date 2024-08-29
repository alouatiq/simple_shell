#include "shell.h"

/* Task 2: Handle Command Line Arguments */
/* Task 7: Implement Tokenization Without strtok */

char **tokenize(char *command)
{
    char **tokens;
    size_t i = 0;
    char *token;

    tokens = malloc(64 * sizeof(char *));
    if (tokens == NULL)
    {
        perror("malloc");
        return NULL;
    }

    token = strtok(command, " ");
    while (token != NULL)
    {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    return tokens;
}
