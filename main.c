#include "shell.h"
#include "input.h"

int main(int argc, char **argv)
{
    char *line = NULL;
    char **args;
    size_t len = 0;
    ssize_t read;
    int last_exit_status = 0;
    char *command_path;

    if (argc > 1)
    {
        handle_file_input(argv[1]);
        return 0;
    }

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("($) ");

        read = my_getline(&line, &len, stdin);
        if (read == -1)
        {
            if (feof(stdin))
            {
                free(line);
                exit(last_exit_status);
            }
            perror(argv[0]);
            continue;
        }

        line[strcspn(line, "\n")] = '\0'; /* Remove newline character */
        line = remove_comments(line);     /* Handle comments */
        if (strlen(line) == 0)
            continue;

        args = custom_tokenize(line);
        if (args == NULL || args[0] == NULL)
        {
            free(args);
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            handle_exit_with_status(args);
        }
        else if (strcmp(args[0], "env") == 0)
        {
            handle_env();
        }
        else if (strcmp(args[0], "setenv") == 0)
        {
            if (handle_setenv(args[1], args[2], 1) == -1)
                perror(argv[0]);
        }
        else if (strcmp(args[0], "unsetenv") == 0)
        {
            if (handle_unsetenv(args[1]) == -1)
                perror(argv[0]);
        }
        else if (strcmp(args[0], "cd") == 0)
        {
            if (handle_cd(args) == -1)
                perror(argv[0]);
        }
        else
        {
            command_path = find_command_in_path(args[0]);
            if (command_path)
            {
                free(args[0]);
                args[0] = command_path;
                execute_command(args);
            }
            else
            {
                fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
                last_exit_status = 127;
            }
        }

        free(args);
    }

    free(line);
    return 0;
}
