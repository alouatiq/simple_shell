#include "shell.h"

void handle_exit(char **args)
{
    int status = 0;

    if (args[1] != NULL)
        status = atoi(args[1]);

    exit(status);
}

int handle_setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || value == NULL)
    {
        perror("setenv");
        return (-1);
    }

    return (_setenv(name, value, overwrite));
}

int handle_unsetenv(const char *name)
{
    if (name == NULL)
    {
        perror("unsetenv");
        return (-1);
    }

    return (_unsetenv(name));
}
