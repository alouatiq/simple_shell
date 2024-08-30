#include "../shell.h"

/**
 * builtin_handler - Identifies and executes builtin commands
 * @args: Null terminated array of command arguments
 * Return: 1 if the shell should continue, 0 if it should terminate
 */
int builtin_handler(char **args)
{
    builtin_t builtins[] = {
        {"exit", builtin_exit},
        {"env", builtin_env},
        {"setenv", builtin_setenv},
        {"unsetenv", builtin_unsetenv},
        {"cd", builtin_cd},
        {"alias", builtin_alias},
        {NULL, NULL}
    };

    for (int i = 0; builtins[i].name; i++)
    {
        if (strcmp(args[0], builtins[i].name) == 0)
            return (builtins[i].func(args));
    }

    return (-1);  // Not a builtin command
}