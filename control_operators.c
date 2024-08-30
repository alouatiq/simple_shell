#include "shell.h"

int handle_command_separators(char *line)
{
    char *command;
    int status = 0;

    command = strtok(line, ";");
    while (command != NULL)
    {
        status = process_command(command);
        command = strtok(NULL, ";");
    }

    return status;
}

void handle_logical_operators(char *line)
{
    char *command;
    int status = 0;
    int execute_next = 1;

    command = strtok(line, "&&||");
    while (command != NULL)
    {
        if (execute_next)
        {
            status = process_command(command);
            if (strstr(line, "&&") != NULL)
            {
                execute_next = (status == 0);
            }
            else if (strstr(line, "||") != NULL)
            {
                execute_next = (status != 0);
            }
        }
        command = strtok(NULL, "&&||");
    }
}
