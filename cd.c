#include "shell.h"

/**
 * handle_cd - Handles the built-in `cd` command.
 * @args: An array of arguments.
 *
 * Task 1.0: Handles `cd`.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_cd(char **args)
{
	char *dir;
	char cwd[1024];

	if (args[1] == NULL)  /* No argument provided, go to HOME */
	{
	    dir = getenv("HOME");
	    if (dir == NULL)
	    {
	        perror("cd");
	        return (-1);
	    }
	}
	else if (strcmp(args[1], "-") == 0)  /* Change to previous directory */
	{
	    dir = getenv("OLDPWD");
	    if (dir == NULL)
	    {
	        perror("cd");
	        return (-1);
	    }
	    printf("%s\n", dir);
	}
	else
	{
	    dir = args[1];
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
	    perror("getcwd");
	    return (-1);
	}

	if (chdir(dir) != 0)  /* Change directory */
	{
	    perror("cd");
	    return (-1);
	}

	/* Update environment variables */
	setenv("OLDPWD", cwd, 1);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
	    setenv("PWD", cwd, 1);
	}

	return (0);
}
