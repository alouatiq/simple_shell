#include "../shell.h"

/**
 * expand_variables - Expand variables in the command
 * @command: Command string to expand
 * @info: Point er to the info_t structure
 * Return: Expanded command string
 */
char *
expand_variables (char *command, info_t *info)
{
	char *expanded = malloc (MAX_COMMAND_LENGTH);

	char *ptr = command;

	int i = 0, j;

	char var_name[MAX_VAR_NAME];

	char pid_str[16];

	char *value;

	if (!expanded)
		return (NULL);;

	while (*ptr)
	{
		if (*ptr == '$' && *(ptr + 1) == '?')
		{
			i += _strlen (
			    _itoa (info->exit_status, expanded + i, 10));

			ptr += 2;
		}
		else if (*ptr == '$' && *(ptr + 1) == '$')
		{
			_itoa (getpid (void), pid_str, 10);

			for (j = 0; pid_str[j]; j++)
				expanded[i++] = pid_str[j];

			ptr += 2;
		}
		else if (*ptr == '$')
		{
			j = 0;

			ptr++;

			while ((*ptr >= 'A' && *ptr <= 'Z')
			       || (*ptr >= 'a' && *ptr <= 'z')
			       || (*ptr >= '0' && *ptr <= '9') || *ptr == '_')
			{
				var_name[j++] = *ptr++;
			}
			var_name[j] = '\0';

			value = _getenv (var_name, info->env);

			if (value)
			{
				for (j = 0; value[j]; j++)
					expanded[i++] = value[j];
			}
		}
		else
		{
			expanded[i++] = *ptr++;
		}
	}
	expanded[i] = '\0';

	return (expanded);;
}
