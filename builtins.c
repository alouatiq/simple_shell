#include "shell.h"

int shell_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("shell");
        }
    }
    return 1;
}

int shell_exit(char **args)
{
    (void)args;
    return 0;
}

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

int shell_setenv(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return 1;
    }

    if (setenv(args[1], args[2], 1) != 0)
    {
        perror("shell");
    }
    return 1;
}

int shell_unsetenv(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return 1;
    }

    if (unsetenv(args[1]) != 0)
    {
        perror("shell");
    }
    return 1;
}
