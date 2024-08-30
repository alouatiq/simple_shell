#include "../shell.h"

/**
 * builtin_cd - Implements the cd builtin command
 * @args: Arguments (directory)
 * Return: Always returns 1 to continue executing
 */
int builtin_cd(char **args)
{
    char *dir = args[1];
    char cwd[1024];
    char *home = getenv("HOME");

    if (!dir)
        dir = home ? home : "/";
    else if (strcmp(dir, "-") == 0)
    {
        dir = getenv("OLDPWD");
        if (!dir)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return (1);
        }
        printf("%s\n", dir);
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        return (1);
    }

    if (chdir(dir) == 0)
    {
        setenv("OLDPWD", cwd, 1);
        if (getcwd(cwd, sizeof(cwd)) == NULL)
        {
            perror("getcwd");
            return (1);
        }
        setenv("PWD", cwd, 1);
    }
    else
    {
        perror("cd");
    }

    return (1);
}