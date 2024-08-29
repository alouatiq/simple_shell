#include "shell.h"

/* Task 1: Basic Shell Implementation */
/* Task 2: Handle Command Line Arguments */
/* Task 3: Handle PATH */
/* Task 5: Implement Built-in env */

void execute_command(char **args)
{
pid_t pid;
int status;
char *command = args[0];

command = find_command(command);  /* Task 3: Find command in PATH */

if (command == NULL)  /* Command not found */
{
perror(args[0]);
return;
}

pid = fork();  /* Create a new process */

if (pid == -1)  /* Error during fork */
{
perror("Error:");
return;
}
else if (pid == 0)  /* Child process */
{
if (execve(command, args, NULL) == -1)
{
perror(args[0]);  /* Print an error if execve fails */
exit(EXIT_FAILURE);  /* Exit the child process */
}
}
else  /* Parent process */
{
wait(&status);  /* Wait for the child process to finish */
}

if (command != args[0])
free(command);  /* Free the command path if it was dynamically allocated */
}
