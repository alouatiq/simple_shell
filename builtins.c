#include "shell.h"

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}
