#include "shell.h"

/**
	* handle_builtin - Handles built-in commands like "exit" and "env"
	* @args: Argument array
	*
	* Return: 1 if a built-in was executed, 0 otherwise
	*/
int handle_builtin(char **args)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
	exit(0);
	}
	if (strcmp(args[0], "env") == 0)
	{
	for (i = 0; environ[i]; i++)
	printf("%s\n", environ[i]);
	return (1);
	}
	return (0);
}
