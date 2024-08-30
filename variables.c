#include "shell.h"

/**
 * handle_variable_replacement - Handles variable replacement in the command line.
 * @line: The input line containing the command.
 * @last_exit_status: The status of the last executed command.
 *
 * Task 1.0: Handles variable replacement (`$?`, `$$`, etc.).
 *
 * Return: A new string with variables replaced, or NULL on failure.
 */
char *handle_variable_replacement(char *line, int last_exit_status)
{
    char *new_line, *var_start;
    char buffer[32];
    int pid = getpid();

    new_line = strdup(line);
    if (new_line == NULL)
        return (NULL);

    var_start = strstr(new_line, "$?");
    if (var_start)
    {
        snprintf(buffer, sizeof(buffer), "%d", last_exit_status);
        memmove(var_start + strlen(buffer), var_start + 2, strlen(var_start + 2) + 1);
        memcpy(var_start, buffer, strlen(buffer));
    }

    var_start = strstr(new_line, "$$");
    if (var_start)
    {
        snprintf(buffer, sizeof(buffer), "%d", pid);
        memmove(var_start + strlen(buffer), var_start + 2, strlen(var_start + 2) + 1);
        memcpy(var_start, buffer, strlen(buffer));
    }

    return (new_line);
}
