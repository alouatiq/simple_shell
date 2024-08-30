#include "shell.h"

int handle_cd(char **args)
{
    char *dir;
    char cwd[1024];

    if (args[1] == NULL)
    {
        dir = getenv("HOME");
        if (dir == NULL)
        {
            perror("cd");
            return (-1);
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {
        dir = getenv("OLDPWD");
        if (dir == NULL)
        {
            perror("cd");
            return (-1);
        }
        printf("%s\n", dir);
    }
    else
    {
        dir = args[1];
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        return (-1);
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
        return (-1);
    }

    _setenv("OLDPWD", cwd, 1);
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        _setenv("PWD", cwd, 1);
    }

    return (0);
}
