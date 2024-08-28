#include "shell.h"
#include <stdio.h>

int execute_external_command(char **args);

/**
 * contains_separator - Checks if a command contains a separator
 * @command: String to be checked
 * @sep: The separator to be checked (should be null terminated)
 *
 * Return: 0 if the command has separators and -1 otherwise
 */
int contains_separator(char *command, char *sep)
{
	int i, j;
	char *str = command;

	if (command == NULL || sep == NULL)
	{
		perror("command_separator not given enough arguments");
		return (-1);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == sep[0])
		{
			for (j = 0; sep[j] != '\0' && str[i + j] == sep[j]; j++)
				;
			if (sep[j] == '\0')
				return (0);
		}
	}

	return (-1);
}

/**
 * built_ins - Function to handle built-ins in _execute command
 * @args: An array of arguments
 * @i: Number of arguments
 *
 * Return: 0 if successful, -1 if failure, and 2 for exit
 */
int built_ins(char *args[], int i)
{
	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	if (_strcmp(args[0], "setenv") == 0 && i == 3)
		return (my_setenv(args[1], args[2], 1));
	if (_strcmp(args[0], "unsetenv") == 0 && i == 2)
		return (my_unsetenv(args[1]));
	if (_strcmp(args[0], "cd") == 0)
	{
		if (i > 2)
		{
			fprintf(stderr, "cd: too many arguments\n");
			return (-1);
		}
		change_directory(i == 1 ? NULL : args[1]);
		return (0);  /* Assume success, change if needed */
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		if (i > 2)
		{
			fprintf(stderr, "exit: too many arguments\n");
			return (-1);
		}
		if (i == 2)
		{
			int status = atoi(args[1]);

			exit(status);
		}
		return (2);  /* Signal to main loop to exit */
	}
	return (-1);
}

/**
 * tokenise - function that tokenises string
 * @command: String to be tokenised
 * @arg_count: Int to store number of arguments
 *
 * Return: Tokenised string
 */
char **tokenise(char *command, int *arg_count)
{
	char **args = malloc(100 * sizeof(char *));
	char *token;
	int i = 0, j;

	if (args == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}

	token = _strtok(command, " \n");
	while (token != NULL && i < 99)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup failed");
			for (j = 0; j < i; j++)
				free(args[j]);
			free(args);
			return (NULL);
		}
		i++;
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
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			/* Print error in the required format */
			dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}

/**
 * execute_command - Parses and executes a command
 * @command: The command string to be executed
 *
 * Description: This function handles the parsing of the command and
 * executes it. It only handles simple, one-word commands without arguments.
 *
 * Return: 0 on success, -1 on failure, 2 for exit
 */
int execute_command(char *command)
{
	char *args[2];
	pid_t pid;
	int status;

	/* Remove leading and trailing whitespace */
	while (*command == ' ' || *command == '\t')
		command++;

	if (*command == '\0')
		return (0);  /* Empty command, do nothing */

	/* Check for the exit command */
	if (_strcmp(command, "exit") == 0)
		return (2);  /* Signal to main loop to exit */

	/* Set up arguments for execve */
	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			/* Print error in the required format */
			dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}

/**
 * execute_external_command - Executes an external command
 * @args: Array of command arguments
 *
 * Description: This function resolves the command path using PATH
 * and executes the command using fork and execve.
 *
 * Return: 0 on success, -1 on failure
 */
int execute_external_command(char **args)
{
	char *full_path = NULL;
	int ret_val = 0;
	char *temp;

	full_path = find_command_in_path(args[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (-1);
	}

	temp = args[0];
	args[0] = full_path;
	ret_val = _executing(args);
	args[0] = temp;  /* Restore original args[0] */

	free(full_path);
	return (ret_val);
}

/**
 * free_args - Frees memory allocated for command arguments
 * @args: Array of command arguments
 *
 * Description: This function frees the memory allocated for each argument
 * in the array and then frees the array itself.
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
