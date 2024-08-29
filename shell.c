#include "shell.h"

void prompt(void)
{
    write(STDOUT_FILENO, "#cisfun$ ", 9);  // Display the shell prompt
}

char *read_command(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    characters = getline(&buffer, &bufsize, stdin);  // Read the command line

    if (characters == -1)  // Handle EOF (Ctrl+D)
    {
        free(buffer);
        return NULL;
    }

    buffer[characters - 1] = '\0';  // Remove the newline character
    return buffer;
}

void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();  // Create a new process

    if (pid == -1)  // Error during fork
    {
        perror("Error:");
        return;
    }
    else if (pid == 0)  // Child process
    {
        char *argv[] = {command, NULL};  // No arguments, just the command

        if (execve(command, argv, NULL) == -1)
        {
            perror("./shell");  // Print an error if execve fails
        }
        exit(EXIT_FAILURE);  // Exit the child process
    }
    else  // Parent process
    {
        wait(&status);  // Wait for the child process to finish
    }
}
