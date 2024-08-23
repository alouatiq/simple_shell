#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * check_getline_error - Function that checks if getline failed
 * @r: represents the return value of the getline function
 * Return: 0 on success and -1 on failure.
 */
int check_getline_error(int r)
{
	if (r == -1)
	{
		perror("getline failed");
		free(buffer);
		return (-1)
	}
	return(0);
}

/**
 * main - Entry point
 * Description: Executes the command ls -l /tmp in 5 different child processes.
 * Return: Null
 */
int main (void)
{
	pid_t child;
	int status, n, r;
	char *buffer;

	int i = 0;
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	/*infinite loop to keep shell running*/
	while (1)
	{
		printf("#cisfun$ ");/*printing prompt*/

		r = getline(&buffer, &n, stdin);/* Taking input from user*/

		if (check_getline_error(r) == -1)/*check if getline failed*/
			return (-1);


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
