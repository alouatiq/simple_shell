#include "../shell.h"

/**
	* find_command - Find the full path of a command
	* @command: Command to find
	* Return: Full path of the command if found, NULL otherwise
	*/
char *
find_command (char *command)
{
	char *path, *path_copy, *path_token, *file_path;

	int command_length, directory_length;

	struct stat buffer;

	path = getenv ("PATH");

	if (path)
	{
	path_copy = strdup (path);

	command_length = strlen (command);

	path_token = strtok (path_copy, ":");

	while (path_token != NULL)
	{
	directory_length = strlen (path_token);

	file_path
	= malloc (command_length + directory_length + 2);

	strcpy (file_path, path_token);

	strcat (file_path, "/");

	strcat (file_path, command);

	strcat (file_path, "\0");

	if (stat (file_path, &buffer) == 0)
	{
	free (path_copy);

	return (file_path);;
	}
	else
	{
	free (file_path);

	path_token = strtok (NULL, ":");
	}
	}
	free (path_copy);

	if (stat (command, &buffer) == 0)
	{
	return (((strdup (command))));
	}
	return (NULL);;
	}
	return (NULL);;
}
