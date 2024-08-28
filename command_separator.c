#include "shell.h"

/**
 * handle_command_separator - Handles command separator `;`
 * @command: The command string containing multiple commands separated by `;`
 *
 * Task 11: Command Separator (`;`)
 *
 * Description: function will split the command on `;` and execute each one.
 */
void handle_command_separator(char *command)
{
	char *token, *end;

	token = _strtok(command, ";");

	while (token != NULL)
	{
		while (*token == '\n' || *token == '\t' || *token == ' ')
			token++;
		if (*token == '\0')
		{
			token = _strtok(NULL, ";");
			continue;
		}
		end = token + _strlen(token) - 1;

		while (end > token && (*end == '\n' || *end == '\t' || *end == ' '))
			end--;
		 *(end + 1) = '\0';

		execute_command(token);
		token = _strtok(NULL, ";");
	}
	if (token == NULL && _strlen(command) > 0 &&
	command[_strlen(command) - 1] == ';')
	{
		execute_command("");
	}
}
