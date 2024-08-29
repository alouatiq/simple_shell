#include "shell.h"

/* Task 2: Handle Command Line Arguments */
/* Task 7: Implement Tokenization Without strtok */

char **tokenize(char *command)
{
    char **tokens;
    size_t bufsize = 64;
    size_t i = 0;
    char *token;
    char *delim = " ";

    tokens = malloc(bufsize * sizeof(char *));
    if (tokens == NULL)
    {
        perror("malloc");
        return NULL;
    }

    token = strtok(command, delim);  /* Use strtok for the first tokenization */
    while (token != NULL)
    {
        tokens[i++] = token;

        if (i >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (tokens == NULL)
            {
                perror("realloc");
                return NULL;
            }
        }

        token = strtok(NULL, delim);  /* Continue tokenizing the string */
    }
    tokens[i] = NULL;

    return tokens;
}
