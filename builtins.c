#include "shell.h"

extern char **environ;

/**
 * shell_exit - Built-in command to exit the shell
 * @args: Arguments (args[1] is the optional exit status)
 *
 * Return: Does not return, exits the program
 *
 * Task 4: Simple shell 0.4 - Implement the exit built-in, that exits the shell
 * Task 8: Simple shell 0.4.1 - Handle arguments for the exit built-in
 */
int shell_exit(char **args)
{
    int status = EXIT_SUCCESS;

    if (args[1] != NULL)
    {
        char *endptr;
        long val = strtol(args[1], &endptr, 10);

        if (*endptr != '\0' || val < 0 || val > 255)
        {
            fprintf(stderr, "exit: Illegal number: %s\n", args[1]);
            return 1;
        }
        status = (int)val;
    }

    exit(status);
}

/**
 * shell_env - Built-in command to print the current environment
 * @args: Arguments (not used)
 *
 * Return: 1 to continue executing
 *
 * Task 5: Simple shell 1.0 - Implement the env built-in, that prints the current environment
 */
int shell_env(char **args)
{
    int i;
    (void)args; /* Unused parameter */

    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    return 1;
}

/**
 * shell_cd - Built-in command to change directory
 * @args: Arguments (args[1] is the directory to change to)
 *
 * Return: 1 to continue executing
 *
 * Task 10: cd - Implement the builtin command cd
 * This function implements the following requirements:
 * 1. Changes the current directory of the process
 * 2. Command syntax: cd [DIRECTORY]
 * 3. If no argument is given, the command is interpreted as cd $HOME
 * 4. Handles the command cd -
 * 5. Updates the PWD environment variable when changing directory
 * 6. Handles errors and updates OLDPWD environment variable
 */
int shell_cd(char **args)
{
    char *dir = args[1];
    char cwd[1024], *oldpwd;

    oldpwd = _getenv("PWD");
    if (oldpwd == NULL)
    {
        fprintf(stderr, "cd: Unable to get current directory\n");
        return 1;
    }

    if (dir == NULL || strcmp(dir, "~") == 0)
    {
        dir = _getenv("HOME");
        if (dir == NULL)
        {
            fprintf(stderr, "cd: No home directory found\n");
            return 1;
        }
    }
    else if (strcmp(dir, "-") == 0)
    {
        dir = _getenv("OLDPWD");
        if (dir == NULL)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return 1;
        }
        printf("%s\n", dir);
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
    }
    else
    {
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            setenv("OLDPWD", oldpwd, 1);
            setenv("PWD", cwd, 1);
        }
        else
        {
            perror("getcwd");
        }
    }
    return 1;
}

/**
 * shell_setenv - Initialize a new environment variable, or modify an existing one
 * @args: Arguments (args[1] is the variable name, args[2] is the value)
 *
 * Return: 1 to continue executing, 0 if setenv fails
 *
 * Task 9: Simple shell 1.0 - Implement the setenv built-in command
 */
int shell_setenv(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        fprintf(stderr, "setenv: Too few arguments\n");
        return 1;
    }

    if (setenv(args[1], args[2], 1) != 0)
    {
        perror("setenv");
        return 0;
    }

    return 1;
}

/**
 * shell_unsetenv - Remove an environment variable
 * @args: Arguments (args[1] is the variable name to remove)
 *
 * Return: 1 to continue executing, 0 if unsetenv fails
 *
 * Task 9: Simple shell 1.0 - Implement the unsetenv built-in command
 */
int shell_unsetenv(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "unsetenv: Too few arguments\n");
        return 1;
    }

    if (unsetenv(args[1]) != 0)
    {
        perror("unsetenv");
        return 0;
    }

    return 1;
}
