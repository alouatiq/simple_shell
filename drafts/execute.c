#include "shell.h"

int execute(char **args)
{
    if (args[0] == NULL)
    {
        return 1; // An empty command was entered.
    }

    if (_strcmp(args[0], "cd") == 0)
    {
        return shell_cd(args);
    }
    if (_strcmp(args[0], "exit") == 0)
    {
        return shell_exit(args);
    }
    if (_strcmp(args[0], "env") == 0)
    {
        return shell_env(args);
    }
    if (_strcmp(args[0], "setenv") == 0)
    {
        return shell_setenv(args);
    }
    if (_strcmp(args[0], "unsetenv") == 0)
    {
        return shell_unsetenv(args);
    }

    return run_command(args);
}

int run_command(char **args)
{
    pid_t pid;
    int status;
    char *cmd = find_command(args[0]);

    if (cmd == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 1;
    }

    pid = fork();
    if (pid == 0)
    {
        if (execve(cmd, args, environ) == -1)
        {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("shell");
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(cmd);
    return 1;
}
