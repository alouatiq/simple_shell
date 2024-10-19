#include "shell.h"

/**
 * prompt - Prints the shell prompt
 */
void prompt(void)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
}

/**
 * get_command - Reads the user input
 *
 * Return: The input string
 */
char *get_command(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
