#include "shell.h"

/* Task 1: Basic Shell Implementation */
/* Task 2: Handle Command Line Arguments */

void prompt(void)
{
    write(STDOUT_FILENO, "#cisfun$ ", 9);  /* Display the shell prompt */
}

char *read_command(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    characters = _getline(&buffer, &bufsize);  /* Task 6: Use custom getline function */

    if (characters == -1)  /* Handle EOF (Ctrl+D) */
    {
        free(buffer);
        return NULL;
    }

    buffer[characters - 1] = '\0';  /* Remove the newline character */
    return buffer;
}
