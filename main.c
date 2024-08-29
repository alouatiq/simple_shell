#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments.
 *
 * This function sets up the shell environment, enters the main loop to
 * read and execute commands, and handles any necessary cleanup.
 *
 * Return: 0 on success, or an error code on failure.
 */


/* Task 1: Basic Shell Implementation */
/* Task 2: Handle Command Line Arguments */
/* Task 4: Implement Built-in exit */
/* Task 5: Implement Built-in env */

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

args = tokenize(command);  /* Task 2: Tokenize the input command */
if (args == NULL)
{
free(command);
continue;
}

if (strcmp(args[0], "exit") == 0)  /* Task 4: Implement exit */
{
free(args);
free(command);
exit(0);
}

if (strcmp(args[0], "env") == 0)  /* Task 5: Implement env */
{
print_env();
}
else
{
execute_command(args);  /* Task 1: Execute the command */
}

free(args);
free(command);
}

return 0;
}
