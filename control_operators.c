#include "shell.h"

/**
 * handle_command_separators - Handles command separators `;`.
 * @line: The input line containing the commands.
 *
 * Task 1.0: Handles command separators `;`.
 *
 * Return: 0 on success, -1 on failure.
 */

int process_command(char *command);

int handle_command_separators(char *line) {
    char *command;
    int status = 0;

    command = strtok(line, ";");
    while (command != NULL) {
        status = process_command(command);  /* Call to process individual commands */
        command = strtok(NULL, ";");
    }

    return status;
}

void handle_logical_operators(char *line) {
    char *command;
    int status = 0;
    int execute_next = 1;  /* Flag to indicate whether the next command should be executed */

    command = strtok(line, "&&||");
    while (command != NULL) {
        if (execute_next) {
            status = process_command(command);  /* Process the command */
            if (strstr(line, "&&") != NULL) {
                execute_next = (status == 0);  /* Continue only if last command was successful */
            } else if (strstr(line, "||") != NULL) {
                execute_next = (status != 0);  /* Continue only if last command failed */
            }
        }
        command = strtok(NULL, "&&||");
    }
}
