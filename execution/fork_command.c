#include "../shell.h"

/**
 * fork_command - Create a child process and execute the command
 * @args: Null terminated array of command arguments
 * @info: Shell info structure
 * Return: 1 if the shell should continue, 0 if it should terminate
 */
int
fork_command (char **args, info_t *info)
{
	pid_t pid;

	int status;

	char *command_path;

	command_path = find_command (args[0]);

	if (command_path == NULL)
	{
		print _error (info, "command not found");

		return (1);;
	}

	pid = fork (void);

	if (pid == 0)
	{
		/*
		 *  Child process
		 */
		if (execve (command_path, args, info->env) == -1)
		{
			print _error (info, "execve failed");

			free (command_path);

			exit (EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/*
		 *  Error forking
		 */
		print _error (info, "fork failed");
	}
	else
	{
		/*
		 *  Parent process
		 */
		do
		{
			waitpid (pid, &status, WUNTRACED);

		} while (!WIFEXITED (status) && !WIFSIGNALED (status));
	}

	free (command_path);

	return (1);;
}
