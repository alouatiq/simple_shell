#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Pointer to the value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
    int i, len;
    char *env_var;

    if (name == NULL || environ == NULL)
        return NULL;

    len = strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
        {
            env_var = &environ[i][len + 1];
            return env_var;
        }
    }

    return NULL;
}

/**
 * custom_getline - Read a line from stdin or a file
 * Task 6: Simple shell 0.1.1
 * Custom implementation of getline using getline for non-interactive
 * and read for interactive input. Handles both interactive and
 * non-interactive input with graceful EOF detection.
 *
 * Return: Pointer to the read line or NULL on failure or EOF
 */
char *custom_getline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int is_interactive = isatty(STDIN_FILENO);
    static char buffer[BUFFER_SIZE];
    static size_t buffer_pos = 0, buffer_size = 0;
    char *line_ptr;
    size_t line_size = 0;

    if (!is_interactive)
    {
        read = getline(&line, &len, input_stream);
        if (read == -1)
        {
            free(line);
            return NULL;
        }
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        return line;
    }

    line = malloc(line_size * sizeof(char));
    if (line == NULL) {
        perror("malloc");
        return NULL;
    }

    if (!is_interactive)
    {
        if (fgets(line, line_size, stdin) == NULL)
        {
            free(line);
            return NULL;
        }
        line[strcspn(line, "\n")] = '\0';  // Remove trailing newline
        return line;
    }

    while (1)
    {
        if (buf_pos >= buf_size)
        {
            bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
            {
                if (bytes_read < 0)
                    perror("read");
                if (line_pos == 0)
                {
                    free(line);
                    return NULL;  // EOF or error with no data read
                }
                break;  // EOF or error after reading some data
            }
            buf_size = bytes_read;
            buf_pos = 0;
        }

        if (line_pos >= line_size - 1)
        {
            line_size += BUFFER_SIZE;
            char *new_line = realloc(line, line_size);
            if (!new_line)
            {
                perror("realloc");
                free(line);
                return NULL;
            }
            line = new_line;
        }

        line[line_pos++] = buffer[buf_pos++];

        if (line[line_pos - 1] == '\n')
        {
            line[line_pos - 1] = '\0';
            return line;
        }
    }

    line[line_pos] = '\0';
    return line;
}

/**
 * split_line - Split a line into tokens without using strtok
 * @line: The line to split
 *
 * Return: Null-terminated array of tokens
 *
 * This function is part of Task 7: Simple shell 0.2.1
 * It implements a custom tokenization method to split the input into tokens,
 * which allows the shell to process commands with multiple arguments.
 */
char **split_line(char *line)
{
    int bufsize = BUFFER_SIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *current_token = NULL;
    int token_length = 0;
    int i;

    if (!tokens)
    {
        fprintf(stderr, "split_line: allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        {
            if (current_token != NULL)
            {
                current_token[token_length] = '\0';
                tokens[position] = current_token;
                position++;
                current_token = NULL;
                token_length = 0;

                if (position >= bufsize)
                {
                    bufsize += BUFFER_SIZE;
                    tokens = realloc(tokens, bufsize * sizeof(char*));
                    if (!tokens)
                    {
                        fprintf(stderr, "split_line: allocation error\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
        else
        {
            if (current_token == NULL)
            {
                current_token = malloc(BUFFER_SIZE * sizeof(char));
                if (!current_token)
                {
                    fprintf(stderr, "split_line: allocation error\n");
                    exit(EXIT_FAILURE);
                }
            }
            current_token[token_length] = line[i];
            token_length++;

            if (token_length >= BUFFER_SIZE)
            {
                fprintf(stderr, "split_line: token too long\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    if (current_token != NULL)
    {
        current_token[token_length] = '\0';
        tokens[position] = current_token;
        position++;
    }

    tokens[position] = NULL;
    return tokens;
}

/**
 * free_args - Free memory allocated for argument array
 * @args: Null-terminated array of argument strings
 */
void free_args(char **args)
{
    int i;

    if (args == NULL)
        return;

    for (i = 0; args[i] != NULL; i++)
    {
        free(args[i]);
    }
    free(args);
}
