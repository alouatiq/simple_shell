#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

static char *check_command_with_slash(char *command);
static char *search_command_in_path(char *command);
static char *build_full_path(char *dir, char *command);

/**
 * find_command_in_path - Searches for a command in the system's PATH
 * @command: The command to search for
 *
 * Description: This function searches the directories listed in the PATH
 * environment variable for the specified command. If the command is found,
 * the full path to the command is returned. If the command is not found,
 * the function returns NULL.
 *
 * Return: A pointer to a string containing the full path to the command,
 * or NULL if the command is not found.
 */
char *find_command_in_path(char *command)
{
	if (command == NULL || *command == '\0')
		return (NULL);

	if (strchr(command, '/'))
		return (check_command_with_slash(command));

	return (search_command_in_path(command));
}

/**
 * check_command_with_slash - Checks if a command with a slash exists
 * @command: The command to check
 *
 * Return: A duplicate of the command if it exists, NULL otherwise
 */
static char *check_command_with_slash(char *command)
{
	struct stat st;

	return ((stat(command, &st) == 0) ? strdup(command) : NULL);
}

/**
 * search_command_in_path - Searches for a command in PATH directories
 * @command: The command to search for
 *
 * Return: The full path of the command if found, NULL otherwise
 */
static char *search_command_in_path(char *command)
{
	char *path_env, *path, *token, *saveptr, *full_path;

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path = strdup(path_env);
	if (path == NULL)
		return (NULL);

	token = strtok_r(path, ":", &saveptr);
	while (token != NULL)
	{
		full_path = build_full_path(token, command);
		if (full_path != NULL)
		{
			free(path);
			return (full_path);
		}
		token = strtok_r(NULL, ":", &saveptr);
	}
	free(path);
	return (NULL);
}

/**
 * build_full_path - Builds and checks the full path of a command
 * @dir: The directory to check
 * @command: The command to append to the directory
 *
 * Return: The full path if the command exists, NULL otherwise
 */
static char *build_full_path(char *dir, char *command)
{
	char *full_path;
	size_t dir_len, command_len;
	struct stat st;

	dir_len = strlen(dir);
	command_len = strlen(command);
	full_path = malloc(dir_len + command_len + 2);
	if (full_path == NULL)
		return (NULL);

	snprintf(full_path, dir_len + command_len + 2, "%s/%s", dir, command);
	if (stat(full_path, &st) == 0)
		return (full_path);

	free(full_path);
	return (NULL);
}
