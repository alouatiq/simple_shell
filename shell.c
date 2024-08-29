#include "shell.h"

/**
* read_command - Reads a command from the user input.
*
* This function reads a line of input from the user, removes the newline character,
* and returns the command string. It handles memory allocation for the command buffer.
*
* Return: A pointer to the command string, or NULL on EOF or error.
*/

char *read_command(void)
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters;
char *start;  /* Declare the variable at the beginning */

characters = _getline(&buffer, &bufsize, stdin);

if (characters == -1)  /* Handle EOF (Ctrl+D) */
{
free(buffer);
return (NULL);
}

start = buffer;  /* Initialize the variable after the getline call */
buffer[characters - 1] = '\0';  /* Remove the newline character */

return (start);
}
