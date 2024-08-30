#include "../shell.h"

/**
 * execute_file - Execute commands from a file
 * @filename: Name of the file to execute
 * Return: Status of the last executed command
 */
int execute_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int status = 0;

    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        // Remove trailing newline
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        // Remove comments
        line = remove_comments(line);

        // Skip empty lines
        if (strlen(line) == 0)
            continue;

        // Expand variables
        char *expanded = expand_variables(line, status);

        // Execute the command
        char **args = parse_input(expanded);
        status = execute_command(args);

        free(args);
        free(expanded);
    }

    free(line);
    fclose(file);
    return status;
}