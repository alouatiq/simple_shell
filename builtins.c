#include "shell.h"

int check_builtin(char **args)
{
    if (strcmp(args[0], "exit") == 0)
        return shell_exit(args);
    else if (strcmp(args[0], "env") == 0)
        return shell_env(args);
    
    return 0;
}

int shell_exit(char **args)
{
    (void)args;
    return 0; // Return 0 to signal exit in main loop
}

int shell_env(char **args)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
    return 1;
}
