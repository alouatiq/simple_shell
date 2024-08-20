#include "shell.h"

int main(void)
{
    char *line;
    char **args;
    int status = 1;

    do {
        prompt();
        line = read_line();
        args = tokenize(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}
