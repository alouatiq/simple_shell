#include "shell.h"

int shell_env(char **args)
{
    char **env = environ;

    (void)args;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
    return 1;
}
