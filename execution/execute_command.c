#include "../shell.h"

/**
 * execute_command - Execute the parsed command
 * @args: Null terminated array of command arguments
 * Return: 1 if the shell should continue, 0 if it should terminate
 */
int execute_command(char **args)
{
    if (args[0] == NULL)
    {
        // An empty command was entered.
        return 1;
    }

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0)
        return builtin_exit(args);
    if (strcmp(args[0], "env") == 0)
        return builtin_env(args);
    if (strcmp(args[0], "cd") == 0)
        return builtin_cd(args);

    // If not a built-in command, try to execute it as an external command
    return fork_command(args);
}