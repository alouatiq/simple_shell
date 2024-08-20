#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point
 * Description: Executes the command ls -l /tmp in 5 different child processes.
 * Return: Null
 */
int main (void)
{
	pid_t child;
	int status;

	int i = 0;
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	while (i < 5)
	{
		child = fork();
		if (child == -1)
		{
			perror("fork failed");
			return (-1);
		}
		if (child == 0)
		{
			execve("/bin/ls", argv, NULL);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			i++;
		}
	}
	return (0);
}
