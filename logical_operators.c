#include "shell.h"

/**
 * handle_logical_operators - Handles logical operators `&&` and `||`
 * @command: The command string containing logical operators
 *
 * Task 12: Logical Operators (`&&` and `||`)
 *
 * Description: This function parses the command string to handle the logical
 * operators `&&` and `||`, ensuring that commands are executed based on the
 * success or failure of previous commands.
 */

void handle_logical_operators(char *command)
{
    char *left_command, *right_command;
    int status;

    /* Handle `&&` operator */
    if ((left_command = strstr(command, "&&")) != NULL) {
        *left_command = '\0'; /* Split the command */
        right_command = left_command + 2; /* Move past the `&&` */

        execute_command(command); /* Execute the left command */
        if (WEXITSTATUS(status) == 0) { /* If the left command succeeded */
            execute_command(right_command); /* Execute the right command */
        }
        return;
    }

    /* Handle `||` operator */
    if ((left_command = strstr(command, "||")) != NULL) {
        *left_command = '\0'; /* Split the command */
        right_command = left_command + 2; /* Move past the `||` */

        execute_command(command); /* Execute the left command */
        if (WEXITSTATUS(status) != 0) { /* If the left command failed */
            execute_command(right_command); /* Execute the right command */
        }
        return;
    }

    /* If no logical operator is found, execute the command as usual */
    execute_command(command);
}
