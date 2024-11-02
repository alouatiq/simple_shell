#include "shell.h"

int execute_line(char *line)
{
    char **args;
    int status = 1;

    args = tokenize_line(line);
    if (!args)
        return status;

    if (args[0])
    {
        if (check_builtin(args) == 0)
            status = execute_command(args);
    }

    free_tokens(args);
    return status;
}
