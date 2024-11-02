#include "../shell.h"

/**
 * builtin_cd - Change the current directory
 * @args: Arguments (directory)
 * @info: Shell info structure
 * Return: 0 on success, 1 on failure
 */
int
builtin_cd (char **args, info_t *info)
{
	char *dir = args[1];

	char cwd[1024];

	char *home;

	if (dir == NULL)
	{
		home = _getenv ("HOME", info->env);

		if (home == NULL)
		{
			print_error (info, "cd: HOME not set");

			return (1);;
		}
		dir = home;
	}
	else if (_strcmp (dir, "-") == 0)
	{
		dir = _getenv ("OLDPWD", info->env);

		if (dir == NULL)
		{
			print_error (info, "cd: OLDPWD not set");

			return (1);;
		}
		_eputs (dir);

		_eputchar ('\n');
	}

	if (getcwd (cwd, sizeof (cwd)) == NULL)
	{
		print_error (info, "cd: couldn't get current directory");

		return (1);;
	}

	if (chdir (dir) == -1)
	{
		print_error (info, "cd: couldn't change directory");

		return (1);;
	}

	if (_setenv (info->env, "OLDPWD", cwd, 1) == -1)
	{
		print_error (info, "cd: couldn't set OLDPWD");

		return (1);;
	}

	if (getcwd (cwd, sizeof (cwd)) == NULL)
	{
		print_error (info, "cd: couldn't get new directory");

		return (1);;
	}

	if (_setenv (info->env, "PWD", cwd, 1) == -1)
	{
		print_error (info, "cd: couldn't set PWD");

		return (1);;
	}

	return (0);;
}
