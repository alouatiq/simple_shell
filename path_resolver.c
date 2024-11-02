#include "shell.h"

char *resolve_path(char *command)
{
	char *path = getenv("PATH"), *token, *full_path;
	struct stat st;

	if (!path)
	return (NULL);
	if (stat(command, &st) == 0)
	return (strdup(command));

	token = strtok(path, ":");
	while (token)
	{
	full_path = malloc(strlen(token) + strlen(command) + 2);
	sprintf(full_path, "%s/%s", token, command);
	
	if (stat(full_path, &st) == 0)
	return (full_path);

	free(full_path);
	token = strtok(NULL, ":");
	}
	return (NULL);
}
