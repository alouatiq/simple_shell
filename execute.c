#include "shell.h"

/* Forward declarations for helper functions */
char *find_next_operator(char *token, char *operator);
void trim_whitespace(char *str);
int execute_command(char **args);

/* Task 1: Simple shell 0.1 - Command execution */
/* Task 11: Implement the ';' command separator */
/* Task 12: Implement the '&&' and '||' shell logical operators */
/**
 * execute - Execute a command or multiple commands separated by ';', '&&', or '||'
 * @input: Input string containing one or more commands
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int execute(char *input)
{
    char *saveptr, *cmd_copy, *token, *next_token;
    char **args;
    int last_status = 0;
    char operator = ';';
    int should_execute = 1;

    if (!input || !*input)
        return 1;

    cmd_copy = strdup(input);
    if (!cmd_copy)
    {
        perror("execute: memory allocation error");
        return 1;
    }

    token = strtok_r(cmd_copy, ";", &saveptr);
    while (token != NULL)
    {
        operator = ';';  /* Reset operator at the beginning of each iteration */
        should_execute = 1;  /* Reset execution flag */

        /* Process commands separated by '&&' or '||' */
        while (*token != '\0')
        {
            /* Find next operator and split the command */
            next_token = find_next_operator(token, &operator);
            if (next_token)
            {
                *next_token = '\0';
                next_token += 2;  /* Skip the operator */
            }

            /* Prepare the command for execution */
            trim_whitespace(token);
            args = split_line(token);
            if (!args)
            {
                perror("execute: memory allocation error");
                free(cmd_copy);
                return 1;
            }

            /* Execute the command if conditions are met */
            if (args[0] != NULL && should_execute)
            {
                last_status = execute_command(args);

                /* Determine if the next command should be executed */
                if (operator == '&')
                    should_execute = (last_status == 0);
                else if (operator == '|')
                    should_execute = (last_status != 0);
                else
                    should_execute = 1;  /* For ';' operator */
            }

            free_args(args);

            /* Move to the next command in the chain */
            token = next_token;

            /* Break if we've reached the end of the current command chain */
            if (operator == ';' || !token)
                break;
        }

        /* Move to the next command after ';' */
        token = strtok_r(NULL, ";", &saveptr);
    }

    free(cmd_copy);
    return 1; /* Always return 1 to continue the shell */
}

/**
 * find_next_operator - Find the next '&&' or '||' operator in the command string
 * @token: The command string to search
 * @operator: Pointer to store the found operator
 *
 * Return: Pointer to the start of the operator, or NULL if not found
 */
char *find_next_operator(char *token, char *operator)
{
    int in_quotes = 0;
    char quote_char = 0;
    char *and_op = NULL, *or_op = NULL;
    char *p;

    for (p = token; *p != '\0'; p++) {
        if (*p == '\'' || *p == '"') {
            if (!in_quotes) {
                in_quotes = 1;
                quote_char = *p;
            } else if (*p == quote_char) {
                in_quotes = 0;
            }
        } else if (!in_quotes) {
            if (p[0] == '\\') {
                if (p[1] == '&' || p[1] == '|') {
                    p++; /* Skip escaped character */
                }
            } else if (p[0] == '&' && p[1] == '&' && !and_op) {
                and_op = p;
                break;
            } else if (p[0] == '|' && p[1] == '|' && !or_op) {
                or_op = p;
                break;
            }
        }
    }

    if (and_op) {
        *operator = '&';
        return and_op;
    } else if (or_op) {
        *operator = '|';
        return or_op;
    }
    return NULL;
}

/**
 * trim_whitespace - Remove trailing whitespace from a string
 * @str: The string to trim
 */
void trim_whitespace(char *str)
{
    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t'))
        *end-- = '\0';
}

/**
 * execute_command - Execute a single command
 * @args: Null-terminated array of command arguments
 *
 * Return: Exit status of the command
 */
int execute_command(char **args)
{
    int status;

    if (strcmp(args[0], "exit") == 0)
        status = shell_exit(args);
    else if (strcmp(args[0], "env") == 0)
        status = shell_env(args);
    else if (strcmp(args[0], "cd") == 0)
        status = shell_cd(args);
    else if (strcmp(args[0], "setenv") == 0)
        status = shell_setenv(args);
    else if (strcmp(args[0], "unsetenv") == 0)
        status = shell_unsetenv(args);
    else
        status = launch(args);

    return status;
}

/**
 * launch - Launch a program
 * @args: Null-terminated array of arguments
 *
 * Return: 0 if the command executed successfully, 1 otherwise
 *
 * Task 1: Simple shell 0.1
 * Task 3: Simple shell 0.3 - Handle the PATH
 * This function handles the execution of commands, including:
 * - Searching for the command in PATH
 * - Forking a child process only if the command exists
 * - Executing the command
 * - Waiting for the child process to complete
 */
int launch(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path;

    cmd_path = which(args[0]);
    if (cmd_path == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 1;
    }

    pid = fork();
    if (pid == 0)
    {
        if (execve(cmd_path, args, environ) == -1)
        {
            perror("launch");
        }
        free(cmd_path);
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("launch");
    }
    else
    {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(cmd_path);
    return WEXITSTATUS(status);
}

/**
 * which - Search for a command in the PATH
 * @cmd: The command to search for
 *
 * Return: Full path of the command if found, NULL otherwise
 *
 * Task 1: Simple shell 0.1 - Handle PATH to find and execute programs
 * Task 3: Simple shell 0.3 - Ensure PATH is handled correctly
 * This function searches for the command in each directory specified in PATH
 * If the command is found, it returns the full path; otherwise, it returns NULL
 */
char *which(char *cmd)
{
    char *path, *path_copy, *dir, *file_path;
    int cmd_length, dir_length;
    struct stat buffer;

    path = _getenv("PATH");
    if (path)
    {
        path_copy = strdup(path);
        cmd_length = strlen(cmd);
        dir = path_copy;
        while (*dir)
        {
            char *next_dir = strchr(dir, ':');
            if (next_dir)
                *next_dir = '\0';

            dir_length = strlen(dir);
            file_path = malloc(cmd_length + dir_length + 2);
            strcpy(file_path, dir);
            strcat(file_path, "/");
            strcat(file_path, cmd);

            if (stat(file_path, &buffer) == 0)
            {
                free(path_copy);
                return file_path;
            }

            free(file_path);
            if (next_dir)
                dir = next_dir + 1;
            else
                break;
        }
        free(path_copy);
        if (stat(cmd, &buffer) == 0)
        {
            return strdup(cmd);
        }
    }
    return NULL;
}
