#include "shell.h"

/**
 * contains_seperator - Checks if a command contains a seperator
 * @command: String to be checked
 * @sep: The seperator to be checked (should be null terminated
 *
 * Return: 0 if the command has seperators and -1 otherwise
 */
int contains_seperator(char *command, char *sep)
{
	int i, j;
	char *str = command;

	i = 0;

	if (command == NULL || sep == NULL)
	{
		perror("command_seperator not given enough arguments");
		return (-1);
	}
	while (str[i] != '\0')
	{
		if (str[i] == sep[0])
		{
			j = 0;
			while (sep[j] != '\0' && str[i + j] == sep[j])
				j++;

			if (sep[j] == '\0')
			{
				return (0);
			}
		}
		i++;
	}

	return (-1);
}

/**
 * built_ins - Function to handle built_ins in _execute command
 * @args: An array of arguments
 * @i: Number of arguments
 *
 * Return: 0 if sucessful and -1 if failure;
 */
int built_ins(char *args[], int i)
{
	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(args[0], "setenv") == 0 && i == 3)
	{
		my_setenv(args[1], args[2], 1);
		return (0);
	}
	else if (_strcmp(args[0], "unsetenv") == 0 && i == 2)
	{
		my_unsetenv(args[1]);
		return (0);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		change_directory(args[1]);
		return (0);
	}
	return (-1);
}
/**
 * tokenise - function that tockenises string
 * @command: String to be tokenised
 * @arg_count: Int to store number of arguments
 *
 * Return: Tockenised string
 */
char **tokenise(char *command, int *arg_count)
{
	char **args = malloc(100 * sizeof(char *));
	char *token;
	int i = 0;

	if (args == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}

	token = _strtok(command, " \n");
	while (token != NULL && i < 99)
	{
		args[i++] = token;
		token = _strtok(NULL, " \n");
	}
	args[i] = NULL; /* Null-terminate the arguments array */
	*arg_count = i;
	return (args);
}

/**
 * _executing - Function calls fork and executes commands
 * @args: array of arguments
 *
 * Return: 0 if success and -1 otherwise
 */
int _executing(char **args)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        free(args);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        extern char **environ;

        if (execve(args[0], args, environ) == -1)
        {
            /* Print error in the required format */
            dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
            free(args);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    free(args);
    return (0);
}

/**
 * execute_command - Parses and executes a command
 * @command: The command string to be executed
 *
 * Task 2: Simple Shell 0.2
 *
 * Description: This function will fork a new process and use execve
 * to run the command. It handles the parsing of the command and
 * its arguments, assuming the command is either an absolute path
 * or in the current directory.
 *
 * Return: 0 on success, or -1 on failure
 */
int execute_command(char *command)
{
	char **args; /* Array to hold arguments */
	int i = 0;

	if (contains_seperator(command, ";") == 0)
	{
		handle_command_separator(command);
		return (0);
	}
	args = tokenise(command, &i);
	if (args == NULL)
		return (-1);
	if (built_ins(args, i) == 0)
	{
		free(args);
		return (0);
	}
	 _executing(args);
	return (0);
}
