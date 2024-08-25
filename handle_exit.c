#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * handle_exit - Implements the exit built-in command
 * @command: The command string, possibly containing an exit status
 *
 * Task 4: Simple Shell 0.4 (Implement the `exit` built-in command)
 * Task 8: Simple Shell 0.4.1 (Handle arguments for the built-in `exit`)
 *
 * Description: This function handles the `exit` command. If an optional
 * status argument is provided, the shell exits with that status. If no
 * status is provided, the shell exits with the status 0.
 */
void handle_exit(char *command)
{
    char *args = strtok(command, " ");
    char *status_str = strtok(NULL, " ");
    int status;

    if (status_str != NULL) {
        /* Convert the status argument to an integer */
        status = atoi(status_str);
        exit(status);
    } else {
        /* If no status is provided, exit with 0 */
        exit(EXIT_SUCCESS);
    }
}
