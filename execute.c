/* execute.c */

#include "shell.h"

/**
 * execute_command - Handles the execution of a command.
 * @args: An array of arguments.
 *
 * Task 0.1: Handles the execution of commands.
 * Task 0.2: Executes commands with arguments.
 * Task 0.3: Ensures the shell checks command existence before forking.
 * Task 0.4: Minor updates to accommodate the `exit` built-in if needed.
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args == NULL || args[0] == NULL)
	    return;

	pid = fork();
	if (pid == 0)  /* Child process */
	{
	    if (execve(args[0], args, environ) == -1)
	    {
	        perror("hsh");
	        exit(EXIT_FAILURE);
	    }
	}
	else if (pid < 0)  /* Forking error */
	{
	    perror("hsh");
	}
	else  /* Parent process */
	{
	    do {
	        waitpid(pid, &status, WUNTRACED);
	    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/* Task 7: Replace strtok with custom tokenization logic */
/* ... custom_tokenize function implementation ... */

/* Task 8: Handle exit with status */
/* ... handle_exit_with_status function implementation ... */

/* Task 9: Handle setenv and unsetenv commands */
/* ... handle_setenv, handle_unsetenv function implementations ... */

/* Task 10: Handle cd command */
/* ... handle_cd function implementation ... */

/* Task 11: Handle command separators (;) */
/* ... handle_command_separators function implementation ... */

/* Task 12: Handle logical operators (&&, ||) */
/* ... handle_logical_operators function implementation ... */

/* Task 13: Handle aliases */
/* ... handle_alias function implementation ... */

/* Task 14: Handle variable replacement ($?, $$) */
/* ... handle_variable_replacement function implementation ... */

/* Task 15: Handle comments (#) */
/* ... remove_comments function implementation ... */

/* Task 16: Handle file input as command source */
/* ... handle_file_input function implementation ... */
