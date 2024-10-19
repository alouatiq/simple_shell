#include "shell.h"

/**
 * execute - Executes a command by creating a child process
 * @args: Argument array (command and its options)
 */
void execute(char **args)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Error");
        return;
    }
    if (pid == 0)  // Child process
    {
        if (execve(args[0], args, environ) == -1)
            perror(args[0]);
        exit(EXIT_FAILURE);
    }
    else  // Parent process
    {
        wait(NULL);
    }
}
