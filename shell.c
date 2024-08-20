#include "shell.h"

/**
 * main - Entry point
 * Description: Supper simple shell program
 * Return: Always 0 (sucess)
 */

int main(void)
{
	ssize_t r;
	size_t n;
	char *buffer, *path, **arguments, *path_env, *path_copy, *dir;
	int status, found;
	pid_t child;

	buffer = NULL;
	n = 0;

	while (1)
	{
		printf("#cisfun$ ");
		r = getline(&buffer, &n, stdin);

		if (r == -1)
		{
			perror("getline failed");
			free(buffer);
			return (-1);
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		arguments = get_arguments(buffer);

		if (arguments == NULL || arguments[0] == NULL)
		{
			free(arguments);
			continue;
		}
		if (arguments[0][0] == '/')
			path = strdup(arguments[0]);
		else
		{
			path_env = getenv("PATH");
			path_copy = strdup(path_env);
			dir = strtok(path_copy, ":");
			found = 0;

			while (dir != NULL)
			{
				path = malloc(strlen(dir) + strlen(arguments[0]) + 2);
				if (path == NULL)
				{
					perror("malloc failed");
					free(buffer);
					free(arguments);
					free(path_copy);
					return (-1);
				}
				snprintf(path, strlen(dir) + strlen(arguments[0]) + 2, "%s/%s", dir, arguments[0]);
				if (access(path, X_OK) == 0)
				{
					found = 1;
					break;
				}
				free(path);
				dir = strtok(NULL, ":");
			}
			free(path_copy);
			if (!found)
			{
				perror("Command not found");
				free(buffer);
				free(path);
				free(arguments);
				return (-1);
			}
		}
		child = fork();

		if (child == -1)
		{
			perror("fork failed");
			free(buffer);
			free(path);
			free(arguments);
			return (-1);
		}

		if (child == 0)
		{
			printf("Executing command: %s\n", path);
			execve(path, arguments, environ);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
		free(arguments);
		free(path);
	}
		free(buffer);
		return (0);
}
