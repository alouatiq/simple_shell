#include "shell.h"

/**
 * execute_file_commands - Executes commands from a file
 * @filename: The name of the file containing commands
 *
 * Task 16: File as Input
 *
 * Description: This function reads a file line by line and executes each command.
 */
void execute_file_commands(char *filename)
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
        /* Remove comments from the line */
        remove_comments(line);

        /* Execute each line as a command */
        execute_command(line);
    }

    free(line); /* Free allocated memory */
    fclose(file); /* Close the file */
}
