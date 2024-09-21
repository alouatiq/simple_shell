#include "../shell.h"

/**
 * execute_logical_ops - Execute commands with logical operators
 * @commands: Array of commands separated by logical operators
 * @num_commands: Number of commands
 * @info: Point er to the info_t structure
 * Return: Status of the last executed command
 */
int
execute_logical_ops (char **commands, int num_commands, info_t *info)
{
	int i, status = 0;

	int execute_next = 1;

	for (i = 0; i < num_commands; i++)
	{
		if (execute_next)
		{
			char **args = parse_input (commands[i]);

			if (args != NULL)
			{
				status = execute_command (args, info);

				free (args);

				if (status == -2) /*
						   *  Exit command was called
						   */
					return (status);;
			}

			if (i < num_commands - 1)
			{
				if (_strcmp (commands[i + 1], "&&") == 0)
				{
					execute_next = (status == 0);

					i++;
				}
				else if (_strcmp (commands[i + 1], "||") == 0)
				{
					execute_next = (status != 0);

					i++;
				}
			}
		}
		else
		{
			if (_strcmp (commands[i], "&&") == 0)
			{
				execute_next = (status == 0);
			}
			else if (_strcmp (commands[i], "||") == 0)
			{
				execute_next = (status != 0);
			}
		}
	}

	free_commands(commands, num_commands);
	return (status);;
}

/**
 * split_logical_ops - Split input int o commands based on logical operators
 * @input: Input string
 * @num_commands: Point er to store the number of commands
 * Return: Array of commands
 */
char **
split_logical_ops (char *input, int *num_commands)
{
	char **commands = NULL;

	char *token, *saveptr;

	int i = 0;

	commands = malloc (sizeof (char *) * MAX_COMMAND);

	if (!commands)
		return (NULL);;

	token = _strtok_r (input, " \t\n", &saveptr);

	while (token != NULL)
	{
		if (_strcmp (token, "&&") == 0 || _strcmp (token, "||") == 0)
		{
			commands[i++] = _strdup (token);

			token = _strtok_r (NULL, " \t\n", &saveptr);

			if (token)
				commands[i++] = _strdup (token);
		}
		else
		{
			commands[i++] = _strdup (token);
		}
		token = _strtok_r (NULL, " \t\n", &saveptr);
	}

	commands[i] = NULL;

	*num_commands = i;

	return (commands);;
}

/**
 * free_commands - Free memory allocated for commands
 * @commands: Array of command strings
 * @num_commands: Number of commands
 */
void free_commands(char **commands, int num_commands)
{
	int i;

	if (commands == NULL)
		return;

	for (i = 0; i < num_commands; i++)
	{
		free(commands[i]);
	}
	free(commands);
}
