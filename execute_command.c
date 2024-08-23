#include "shell.h"

/**
 * execute_command - Function to execute a command given to shell program
 * @line: Pointer to the command to be executed
 *
 * Return: 0 on sucess and -1 on failure
 */
int execute_command(char *line);
{
	char **arguments, **path_list, found;
	pid_t child;

	if (line == NULL)/* Checking if line has been sucessfully parsed*/
		return (-1);

	arguments = str_tockenise(line, " ");/*seperating input into array*/
	path_list = str_tockenise(PATH, ":");/*seperating path into array*/

	if (arguments == NULL || str_tockenise == NULL)
	{
		free_all(arguments, path_list, NULL);
		return (-1);
	}
	found = command_check(arguments[i], path_list);/* get command */

	if (found == NULL)/*checking if command is executable*/
	{
		free_all(arguments, path_list, NULL);
		return (-1);
	}

	child = fork();

	if (child == -1)/*checking if fork was sucessful*/
	{
		free_all(arguments, path_list, NULL);
		return (-1);
	}
	if (child == 0)
	{
		execve(found, arguments, NULL);
		perror("execve failed");
		free_all(arguments, path_list, NULL);
		return (-1);/* since execve returns only when failed*/
	}
	status = wait();
	free_all(arguments, path_list, NULL);
	return (0);
}
