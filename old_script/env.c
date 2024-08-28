#include "shell.h"

/**
 * print_env - Function that prints env
 *
 * Return: NULL
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		_printf(*env);
		env++;
	}
	_printf("\n");
}
