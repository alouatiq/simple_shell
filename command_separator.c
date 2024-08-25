#include "shell.h"

/**
 * handle_command_separator - Handles command separator `;`
 * @command: The command string containing multiple commands separated by `;`
 *
 * Task 11: Command Separator (`;`)
 *
 * Description: This function will split the command on `;` and execute each one.
 */
void handle_command_separator(char *command)
{
    char *token;
    token = strtok(command, ";");

    while (token != NULL) {
        execute_command(token);
        token = strtok(NULL, ";");
    }
}
