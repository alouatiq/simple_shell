#include "main.h"

/**
 * error_env - Generate error message for env command failures
 * @datash: Pointer to data_shell struct containing shell data
 *
 * This function creates an error message when the env command fails to
 * add or remove environment variables. It handles scenarios such as:
 * - Attempting to set an invalid environment variable name
 * - Insufficient permissions to modify the environment
 * - Memory allocation failures during environment modification
 *
 * The error message is constructed using:
 * - Shell name (datash->av[0])
 * - Command counter (datash->counter)
 * - Failed command name (datash->args[0])
 *
 * The function uses dynamic memory allocation to create the error string,
 * which must be freed by the caller after use.
 *
 * Return: Dynamically allocated string containing the error message,
 *         or NULL if memory allocation fails
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	free(ver_str);

	return (error);
}

/**
 * error_path_126 - Generate error message for path and permission denied failures
 * @datash: Pointer to data_shell structure containing relevant information
 *
 * This function creates an error message when a command execution fails due to:
 * - Permission issues (e.g., executable file exists but user lacks execute permission)
 * - Invalid path (e.g., directory in path doesn't exist or isn't accessible)
 *
 * The error message is constructed using:
 * - Shell name (datash->av[0])
 * - Error counter (datash->counter)
 * - Command that caused the error (datash->args[0])
 *
 * The function uses dynamic memory allocation to create the error string,
 * which must be freed by the caller after use.
 *
 * Return: Dynamically allocated string containing the formatted error message,
 *         or NULL if memory allocation fails
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);
	if (ver_str == NULL)
		return (NULL);

	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");

	free(ver_str);
	return (error);
}
