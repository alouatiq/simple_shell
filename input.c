#include "shell.h"
#include <string.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
        return -1;

    char *buf = malloc(128);
    if (buf == NULL)
        return -1;

    size_t pos = 0;
    int ch;

    while ((ch = fgetc(stream)) != EOF && ch != '\n')
    {
        if (pos >= 128 - 1)
        {
            buf = realloc(buf, pos + 2);
            if (buf == NULL)
                return -1;
        }
        buf[pos++] = ch;
    }

    buf[pos] = '\0';
    *lineptr = buf;
    *n = pos;

    return pos;
}

char **custom_tokenize(char *line)
{
    char **tokens = malloc(64 * sizeof(char *));
    char *token;
    size_t i = 0;

    token = strtok(line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[i] = NULL;

    return tokens;
}
