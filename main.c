#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;
    int status = 1;

    while (status)
    {
        display_prompt();
        read = my_getline(&line, &len, stdin);
        if (read == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        args = custom_tokenize(line);
        status = execute_command(args);
        free(args);
    }

    free(line);
    return (0);
}
