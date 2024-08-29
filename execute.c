#include "shell.h"

/**
* execute_command - Executes a command with arguments.
* @args: An array of arguments, with the
* first element being the command.
*
* This function forks a child process to
* execute the given command.
* If the command is found in the PATH, it
* is executed; otherwise, an error is printed.
*/

#include "shell.h"

extern char **environ;

void execute_command(char **args)
{
pid_t pid;
int status;
char *command = args[0];

command = find_command(command);  /* Find command in PATH */

if (command == NULL)  /* Command not found */
{
fprintf(stderr, "%s: Command not found\n", args[0]);
return;
}

pid = fork();  /* Create a new process */

if (pid == -1)  /* Error during fork */
{
perror("Error during fork");
return;
}
else if (pid == 0)  /* Child process */
{
if (execve(command, args, environ) == -1)  /* Execute the command */
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else  /* Parent process */
{
wait(&status);  /* Wait for the child process to finish */
}

if (command != args[0])
free(command);  /* Free the command path if it was dynamically allocated */
}
