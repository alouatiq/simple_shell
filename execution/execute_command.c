#include "../shell.h"

/**
 * execute_command - Execute the parsed command
 * @args: Null terminated array of command arguments
 * @info: Shell info structure
 * Return: 1 if the shell should continue, 0 if it should terminate
 */
int
execute_command (char **args, info_t *info)
{
	if (args[0] == NULL)
	{
		return (((1)));
	}

	/*
	 *  Check for built-in commands
	 */
	if (_strcmp (args[0], "exit") == 0)
		return ((builtin_exit (args, info)));

	if (_strcmp (args[0], "env") == 0)
		return ((builtin_env (args, info)));

	if (_strcmp (args[0], "setenv") == 0)
		return ((builtin_setenv (args, info)));

	if (_strcmp (args[0], "unsetenv") == 0)
		return ((builtin_unsetenv (args, info)));

	if (_strcmp (args[0], "cd") == 0)
		return ((builtin_cd (args, info)));

	if (_strcmp (args[0], "alias") == 0)
		return ((builtin_alias (args, info)));

	/*
	 *  If not a built-in command, fork and execute
	 */
	return ((fork_command (args, info)));
}
