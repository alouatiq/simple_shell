#include "shell.h"

/**
 * find_command_in_path - Searches for a command in the directories listed in `PATH`.
 * @command: The command to search for.
 *
 * Task 0.3: Searches for commands in `PATH`.
 *
 * Return: The full path to the command if found, otherwise NULL.
 */
char *find_command_in_path(char *command)
{
	char *path, *path_copy, *dir;
	char full_path[1024];
	struct stat st;

	if (command == NULL)
	    return (NULL);

	/* Check if command is an absolute or relative path */
	if (command[0] == '/' || command[0] == '.')
	{
	    if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
	        return (strdup(command));
	    return (NULL);
	}

	path = getenv("PATH");
	if (path == NULL)
	    return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
	    return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
	    snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
	    if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
	    {
	        free(path_copy);
	        return (strdup(full_path));
	    }
	    dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
