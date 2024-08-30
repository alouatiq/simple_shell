#include "shell.h"

/* Removes comments from the line */
char *remove_comments(char *line)
{
    char *new_line = strdup(line);
    char *hash_pos = strchr(new_line, '#');

    if (hash_pos != NULL)
        *hash_pos = '\0';

    return new_line;
}
