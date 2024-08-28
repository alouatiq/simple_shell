#include "shell.h"

/**
 * validate_int - Checks if a string represents a valid int
 * @str: String to be checcked
 *
 * Return:1 if valid int, else 0
 */
int validate_int(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;

	while(*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * _atoi - Converts a string to an int
 * @str: The string to convert
 *
 * Return: The converted int.
 */
int _atoi(char *str)
{
	int number, sign;

	sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (sign * number);
}

/**
 * handle_exit - Implements the exit built-in command
 * @command: The command string, possibly containing an exit status
 *
 * Task 4: Simple Shell 0.4 (Implement the `exit` built-in command)
 * Task 8: Simple Shell 0.4.1 (Handle arguments for the built-in `exit`)
 *
 * Description: This function handles the `exit` command. If an optional
 * status argument is provided, the shell exits with that status. If no
 * status is provided, the shell exits with the status 0.
 */
void _exiting(char *command)
{
	char *status_str, *tocken;
	int status;

	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	tocken = _strtok(command, " ");

	if (strcmp(tocken, "exit") != 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	status_str = _strtok(NULL, " ");

	if (status_str != NULL)
	{
		if (validate_int(status_str) == 1)
		{
			/* Convert the status argument to an integer */
			status = _atoi(status_str);
			free(command);
			exit(status);
		}
		else
		{
			perror("exit needs a numerical argument");
			free(command);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		/* If no status is provided, exit with 0 */
		free(command);
		exit(EXIT_SUCCESS);
	}
}
