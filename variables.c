#include "shell.h"

/* Handles variable replacement ($?, $$, etc.) */
char *handle_variable_replacement(char *line, int last_exit_status)
{
    char *new_line = malloc(1024);
    if (new_line == NULL)
        return NULL;

    char *ptr = new_line;
    while (*line)
    {
        if (*line == '$' && *(line + 1) == '?')
        {
            ptr += sprintf(ptr, "%d", last_exit_status);
            line += 2;
        }
        else if (*line == '$' && *(line + 1) == '$')
        {
            ptr += sprintf(ptr, "%d", getpid());
            line += 2;
        }
        else
        {
            *ptr++ = *line++;
        }
    }
    *ptr = '\0';

    return new_line;
}
