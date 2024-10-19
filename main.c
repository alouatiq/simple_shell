#include "shell.h"

/**
 * main - Entry point of the shell
 *
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
    char *command;
    char **args;

    while (1)
    {
        prompt();
        command = get_command();
        if (command == NULL)
        {
            free(command);
            break;
        }
        args = parse_command(command);
        if (args == NULL)
        {
            free(command);
            continue;
        }
        if (handle_builtin(args) == 0)
            execute(args);
        free_memory(args);
        free(command);
    }
    return (0);
}
