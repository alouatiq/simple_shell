#include "shell.h"

/**
 * handle_command_separators - Handles command separators `;`.
 * @line: The input line containing the commands.
 *
 * Task 1.0: Handles command separators `;`.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_command_separators(char *line)
{
    char *command;
    int status = 0;

    command = strtok(line, ";");
    while (command != NULL)
    {
        status = process_command(command);  /* Assume process_command handles individual commands */
        if (status == -1)
            return (-1);

        command = strtok(NULL, ";");
    }

    return (0);
}

/**
 * handle_logical_operators - Handles logical operators `&&` and `||`.
 * @line: The input line containing the commands.
 *
 * Task 1.0: Handles logical operators `&&` and `||`.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_logical_operators(char *line)
{
    char *command;
    int status = 0;

    command = strtok(line, "&& ||");
    while (command != NULL)
    {
        status = process_command(command);
        if (status == -1 && strstr(line, "&&"))
            return (-1);  /* If command fails and using `&&`, stop execution */

        if (status == 0 && strstr(line, "||"))
            return (0);  /* If command succeeds and using `||`, stop execution */

        command = strtok(NULL, "&& ||");
    }

    return (0);
}
