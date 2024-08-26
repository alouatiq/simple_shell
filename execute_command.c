#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * execute_command - Parses and executes a command
 * @line: The command string to be executed
 *
 * Task 3: Simple Shell 0.3
 *
 * Description: This function forks a new process and uses execve to run
 * the command. It manually searches for the command in the directories
 * listed in the PATH environment variable. The command string is parsed
 * into arguments, and if the command is found and executable, it is
 * executed in the child process. The parent process waits for the child
 * process to complete.
 *
 * Return: 0 on success, or -1 on failure
 */
int execute_command(char *line)
{
    char **arguments, **path_list;
    char *found = NULL;
    pid_t child;
    int status;
    int i = 0; /* Initialize an index variable for iteration */

    if (line == NULL) /* Checking if line has been successfully parsed */
        return (-1);

    arguments = str_tokenize(line, " "); /* Separating input into array */
    path_list = str_tokenize(getenv("PATH"), ":"); /* Separating PATH into array */

    if (arguments == NULL || path_list == NULL) /* Check for allocation failures */
    {
        free_all(arguments, path_list, NULL);
        return (-1);
    }

    /* Manually search for the command in each directory in PATH */
    for (i = 0; path_list[i] != NULL; i++)
    {
        found = malloc(strlen(path_list[i]) + strlen(arguments[0]) + 2); /* 2 for '/' and '\0' */
        if (found == NULL)
        {
            free_all(arguments, path_list, NULL);
            return (-1);
        }

        strcpy(found, path_list[i]);
        strcat(found, "/");
        strcat(found, arguments[0]);

        if (access(found, X_OK) == 0) /* Check if the command is executable */
            break;

        free(found);
        found = NULL;
    }

    if (found == NULL) /* Command not found in any PATH directory */
    {
        free_all(arguments, path_list, NULL);
        perror("Command not found");
        return (-1);
    }

    child = fork();

    if (child == -1) /* Checking if fork was successful */
    {
        free_all(arguments, path_list, found);
        perror("Fork failed");
        return (-1);
    }
    if (child == 0) /* Child process */
    {
        execve(found, arguments, NULL);
        perror("execve failed"); /* execve returns only on failure */
        free_all(arguments, path_list, found);
        exit(EXIT_FAILURE);
    }
    else /* Parent process */
    {
        if (wait(&status) == -1) /* Wait for the child process */
        {
            free_all(arguments, path_list, found);
            perror("Wait failed");
            return (-1);
        }
    }

    free_all(arguments, path_list, found);
    return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
}
