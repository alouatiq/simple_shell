#include "shell.h"

/* Handles file input as a command source */
int handle_file_input(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("fopen");
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;
    int status = 1;

    while ((read = my_getline(&line, &len, file)) != -1)
    {
        args = custom_tokenize(line);
        status = execute_command(args);
        free(args);
        if (status == 0)
            break;
    }

    free(line);
    fclose(file);
    return status;
}
