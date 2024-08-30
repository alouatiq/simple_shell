#include "shell.h"

int execute_command(char **args)
{
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return (1);

    if (strcmp(args[0], "exit") == 0)
        handle_exit(args);
    else if (strcmp(args[0], "env") == 0)
        handle_env(); /* This line now correctly refers to the function */
    else if (strcmp(args[0], "setenv") == 0)
        return handle_setenv(args[1], args[2], 1);
    else if (strcmp(args[0], "unsetenv") == 0)
        return handle_unsetenv(args[1]);
    else if (strcmp(args[0], "cd") == 0)
        return handle_cd(args);

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
            perror("hsh");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        perror("hsh");
    else
        waitpid(pid, &status, 0);

    return (1);
}
