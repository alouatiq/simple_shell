#include "../shell.h"

/**
 * execute_logical_ops - Execute commands with logical operators
 * @commands: Array of commands separated by logical operators
 * @num_commands: Number of commands
 * Return: Status of the last executed command
 */
int execute_logical_ops(char **commands, int num_commands)
{
    int i, status = 0;
    int execute_next = 1;

    for (i = 0; i < num_commands; i++)
    {
        if (execute_next)
        {
            status = execute_command(commands[i]);

            if (i < num_commands - 1)
            {
                if (strcmp(commands[i + 1], "&&") == 0)
                {
                    execute_next = (status == 0);
                    i++;
                }
                else if (strcmp(commands[i + 1], "||") == 0)
                {
                    execute_next = (status != 0);
                    i++;
                }
            }
        }
        else
        {
            if (strcmp(commands[i], "&&") == 0)
            {
                execute_next = (status == 0);
            }
            else if (strcmp(commands[i], "||") == 0)
            {
                execute_next = (status != 0);
            }
        }
    }

    return status;
}

/**
 * split_logical_ops - Split input into commands based on logical operators
 * @input: Input string
 * @num_commands: Pointer to store the number of commands
 * Return: Array of commands
 */
char **split_logical_ops(char *input, int *num_commands)
{
    char **commands = NULL;
    char *token;
    int i = 0;

    commands = malloc(sizeof(char *) * MAX_COMMAND);
    if (!commands)
        return NULL;

    token = strtok(input, " \t\n");
    while (token != NULL)
    {
        if (strcmp(token, "&&") == 0 || strcmp(token, "||") == 0)
        {
            commands[i++] = strdup(token);
            token = strtok(NULL, " \t\n");
            if (token)
                commands[i++] = strdup(token);
        }
        else
        {
            commands[i++] = strdup(token);
        }
        token = strtok(NULL, " \t\n");
    }

    commands[i] = NULL;
    *num_commands = i;

    return commands;
}