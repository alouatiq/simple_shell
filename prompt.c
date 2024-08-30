#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 *
 * This function prints the shell prompt to the standard output,
 * indicating that the shell is ready to accept a command.
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, "($) ", 4);
}
