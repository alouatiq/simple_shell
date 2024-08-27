#include "shell.h"

/**
 * my_setenv - Implements the setenv built-in command
 * @name: The environment variable name
 * @value: The value to set
 * @overwrite: Overwrite existing value if non-zero
 *
 * Task 9: setenv, unsetenv
 *
 * Return: 0 on success, -1 on failure
 */
int my_setenv(const char *name, const char *value, int overwrite)
{
	/* Code to implement setenv */
	if (name == NULL || value == NULL)
	{
		perror("No arguments");
		return (-1);
	}
	if (setenv(name, value, overwrite) != 0)
	{
		perror("setenv failed");
		return (-1);
	}
	return (0);

}

/**
 * my_unsetenv - Implements the unsetenv built-in command
 * @name: The environment variable name to remove
 *
 * Task 9: setenv, unsetenv
 *
 * Return: 0 on success, -1 on failure
 */
int my_unsetenv(const char *name)
{
	/* Code to implement unsetenv */
	if (name == NULL)
	{
		perror("Wrong arguments");
		return (-1);
	}
	
	if (unsetenv(name) != 0)
	{
		perror("unsetenv failed");
		return (-1);
	}
	return (0);
}
