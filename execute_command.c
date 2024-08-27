#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * execute_command - Parses and executes a command
 * @command: The command string to be executed
 *
 * Task 2: Simple Shell 0.2
 *
 * Description: This function will fork a new process and use execve
 * to run the command. It handles the parsing of the command and
 * its arguments, assuming the command is either an absolute path
 * or in the current directory.
 *
 * Return: 0 on success, or -1 on failure
 */
int execute_command(char *command)
{
	char *args[100]; /* Array to hold arguments */
	char *token;
	int i = 0;
	pid_t pid;
	int status;

	/* Split the command into arguments */
	token = _strtok(command, " \n");
	while (token != NULL && i < 99)
	{
		args[i++] = token;
		token = _strtok(NULL, " \n");
	}
	args[i] = NULL; /* Null-terminate the arguments array */

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (strcmp(args[0], "setenv") == 0 && i == 3)
		return (my_setenv(args[1], args[2], 1));
	else if (strcmp(args[0], "unsetenv") == 0 && i == 2)
		return (my_unsetenv(args[1]));
	else if (strcmp(args[0], "cd") == 0)
	{
		change_directory(args[1]);
		return (0);
	}

	/* Fork a new process */
	pid = fork();
	if (pid == -1)
	{
		/* Error forking */
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	/* Child process: Execute the command */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process: Wait for the child to finish */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
