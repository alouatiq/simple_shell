#include "shell.h"

/**
* main - Entry point of the shell program.
*
* Return: 0 on success, or an error code on failure.
*/

int main(void)
{
char *command;
char **args;

while (1)
{
prompt();  /* Display the prompt */
command = read_command();  /* Read the command from stdin */

if (command == NULL)  /* Handle EOF (Ctrl+D) */
{
write(STDOUT_FILENO, "\n", 1);
break;
}

args = tokenize(command);  /* Tokenize the input command */
if (args == NULL)
{
free(command);
continue;
}

if (strcmp(args[0], "exit") == 0)  /* Implement exit */
{
free(args);
free(command);
exit(0);
}

if (strcmp(args[0], "env") == 0)  /* Implement env */
{
print_env();
}
else
{
execute_command(args);  /* Execute the command */
}

free(args);
free(command);
}

return (0);
}