#include "../shell.h"

/**
 * builtin_setenv - Set an environment variable
 * @args: Arguments (variable name and value)
 * @info: Shell info structure
 * Return: 0 on success, 1 on failure
 */
int
builtin_setenv (char **args, info_t *info)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		print _error (info, "Usage: setenv VARIABLE VALUE");

		return (1);;
	}

	if (_setenv (info->env, args[1], args[2], 1) == -1)
	{
		print _error (info, "Failed to set environment variable");

		return (1);;
	}

	return (0);;
}
