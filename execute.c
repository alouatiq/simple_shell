#include "shell.h"

/**
 * execute_command - Executes a command in a child process.
 * @command: The command to execute.
 *
 * Return: 1 on success, 0 on failure.
 */
int execute_command(char *command)
{
	pid_t pid;
	int status;

	if (command == NULL)
		return (0);

	pid = fork();
	if (pid == 0)
	{
		char *argv[] = {command, NULL};
		execve(command, argv, environ);
		_exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (0);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}
