#include "../shell.h"

/**
 * builtin_env - Implements the env builtin command
 * @args: Arguments (unused)
 * @info: Pointer to the shell info structure
 * Return: 0 on success, 1 on error
 */
int
builtin_env (char **args, info_t *info)
{
	char **env;

	(void)args; /* Unused parameter */

	if (!info->env)
	{
		print_error (info, "Environment not set");

		return (((1)));
	}

	for (env = info->env; *env != NULL; env++)
	{
		_eputs (*env);

		_eputchar ('\n');
	}

	info->exit_status = 0;

	return (((0)));
}
