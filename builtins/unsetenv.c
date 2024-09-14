#include "../shell.h"

/**
 * builtin_unsetenv - Unset an environment variable
 * @args: Arguments (variable name)
 * @info: Shell info structure
 * Return: 0 on success, 1 on failure
 */
int
builtin_unsetenv (char **args, info_t *info)
{
	if (args[1] == NULL)
	{
		print_error (info, "Usage: unsetenv VARIABLE");

		return (((1)));
	}

	if (_unsetenv (info->env, args[1]) == -1)
	{
		print_error (info, "Failed to unset environment variable");

		return (((1)));
	}

	return (((0)));
}
