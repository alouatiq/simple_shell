#include "shell.h"

/**
	* env_builtin - Prints the environment variables
	*/
void env_builtin(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
	printf("%s\n", environ[i]);
	}
}
