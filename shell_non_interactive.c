#include "shell.h"

/**
 * shell_non_interactive - Executes commands from a file
 * @filename: The name of the file containing the commands
 *
 * Task 1: Simple Shell 0.1
 *
 * Description: This function processes each line from the file
 * as if it were a command entered interactively.
 */
void shell_non_interactive(char *filename)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        /* Execute each line as a command */
        execute_command(line);
    }

    free(line); /* Free allocated memory */
    fclose(file); /* Close the file */
}
