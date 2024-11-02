#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * parse_command - Splits a command string into an array of arguments
 * @command: The command string to be split
 *
 * Return: An array of arguments (NULL terminated)
 */
char **parse_command(char *command)
{
    char **args = malloc(64 * sizeof(char *));  /* Allocate memory for arguments */
    char *token;
    int i = 0;

    if (!args)  /* Check if memory allocation was successful */
    {
        perror("allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, " \t\r\n\a");  /* Split the command into tokens */
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " \t\r\n\a");
    }
    args[i] = NULL;  /* Null terminate the array */
    return args;
}
