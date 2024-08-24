#include "shell.h"

/**
 * main - Entry point
 * Description: Super simple shell program
 * Return: Always 0 (success)
 */
int main(void)
{
	ssize_t r;                // Number of characters read by getline
	size_t n;                 // Size of the buffer
	char *buffer, *path, **arguments, *path_env, *path_copy, *dir;
	int status, found;        // Status of the child process and command found flag
	pid_t child;              // Process ID of the child process

	buffer = NULL;
	n = 0;

	while (1) // Infinite loop to keep the shell running
	{
		printf("#cisfun$ "); // Display the shell prompt
		r = getline(&buffer, &n, stdin); // Read the input command

		if (r == -1) // Check if getline failed
		{
			perror("getline failed");
			free(buffer);
			return (-1);
		}
		buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character from the input
		arguments = get_arguments(buffer); // Split the input into arguments

		if (arguments == NULL || arguments[0] == NULL) // Check if arguments are NULL or empty
		{
			free(arguments);
			continue;
		}
		if (arguments[0][0] == '.' && arguments[0][0] == '/') // If the command is an absolute path, use it as is
			path = strdup(arguments[0]);
		else if (arguments[0][0] == '/')
			path = strdup(arguments[0]);
		else // Otherwise, search for the command in the PATH
		{
			path_env = getenv("PATH"); // Get the PATH environment variable
			path_copy = strdup(path_env); // Duplicate the PATH string to avoid modifying the original

			dir = strtok(path_copy, ":"); // Tokenize the PATH by colons
			found = 0;

			// Iterate through each directory in the PATH
			while (dir != NULL)
			{
				// Allocate memory for the full path of the command
				path = malloc(strlen(dir) + strlen(arguments[0]) + 2);
				if (path == NULL) // Check if malloc failed
				{
					perror("malloc failed");
					free(buffer);
					free(arguments);
					free(path_copy);
					return (-1);
				}

				// Construct the full path of the command
				snprintf(path, strlen(dir) + strlen(arguments[0]) + 2, "%s/%s", dir, arguments[0]);

				// Check if the command is executable
				if (access(path, X_OK) == 0)
				{
					found = 1; // Command found
					break;
				}
				free(path); // Free the path if the command is not found in this directory
				dir = strtok(NULL, ":"); // Continue to the next directory
			}
			free(path_copy); // Free the duplicated PATH string
			if (!found) // If the command was not found in any directory
			{
				perror("Command not found");
				free(buffer);
				free(arguments);
				free(path);
				continue;
			}
		}

		child = fork(); // Fork a new process

		if (child == -1) // Check if fork failed
		{
			perror("fork failed");
			free(buffer);
			free(path);
			free(arguments);
			return (-1);
		}

		if (child == 0) // Child process
		{
			printf("Executing command: %s\n", path);
			execve(path, arguments, environ); // Execute the command
			perror("execve failed"); // If execve returns, it must have failed
			free(buffer);
			free(arguments);
			free(path);
			exit(EXIT_FAILURE);
		}
		else // Parent process
		{
			wait(&status); // Wait for the child process to finish
		}
		path = strdup(arguments[0]);
		free(arguments); // Free the arguments array
		free(path); // Free the path string
		buffer = NULL;// Prepare for next input
		n = 0;
	}
	return (0); // Return success
}
