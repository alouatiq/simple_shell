#include "shell.h"

/**
 * main - entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;
    int status = 1;

    (void)argc;
    (void)argv;

    while (status)
    {
        printf("$ ");
        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            printf("\n");
            break;
        }
        line[read - 1] = '\0';  // Remove newline character

        args = parse_line(line);
        if (args[0] != NULL)
        {
            status = execute(args);
        }

        free(args);
    }

    free(line);
    return (0);
}