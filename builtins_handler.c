#include "shell.h"

/**
 * execute_line - Parses and executes a line of input.
 * @line: The input line to execute.
 *
 * Return: (1) to continue the shell loop, or (0) to exit.
 */
int execute_line(char *line)
{
    char **args;
    int status = 1;

    /* Tokenize the input line */
    args = tokenize_line(line);
    if (!args || !args[0]) /* If no input was given */
    {
        free_tokens(args);
        return (status); /* Continue the loop */
    }

    /* Check if the command is a built-in */
    if (check_builtin(args) == 0)
    {
        free_tokens(args);
        return (0); /* Signal to exit if built-in command is `exit` */
    }

    /* If not a built-in, execute as a normal command */
    status = execute_command(args);
    free_tokens(args);

    return (status); /* Return the status to continue or exit */
}
