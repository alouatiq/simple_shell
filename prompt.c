#include "shell.h"

/**
* prompt - Displays the shell prompt to the standard output.
*
* This function writes the shell prompt "#cisfun$ " to the standard output.
*/

void prompt(void)
{
write(STDOUT_FILENO, "#cisfun$ ", 9);
}
