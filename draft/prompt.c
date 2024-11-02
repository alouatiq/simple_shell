#include "shell.h"

/**
	* prompt - Displays the shell prompt
	*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
}
