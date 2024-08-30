#include "../shell.h"

/**
 * fork_command - Create a child process and execute the command
 * @args: Null terminated array of command arguments
 * Return: 1 if the shell should continue, 0 if it should terminate
 */
int fork_command(char **args)
{
    pid_t pid;
    int status;
    char *command_path;

    command_path = find_command(args[0]);
    if (command_path == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 1;
    }

    pid = fork();
    if (pid == 0)
    {
        // Child process
        if (execve(command_path, args, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        // Error forking
        perror("fork");
    }
    else
    {
        // Parent process
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(command_path);
    return 1;
}