#include "../shell.h"

typedef struct
{
	char *name;

	int (*func) (char **, info_t *);

} builtin_t;

/**
 * builtin_handler - Handle builtin commands
 * @args: Arguments passed to the command
 * @info: Shell info structure
 * Return: 0 if builtin was executed, -1 if not a builtin
 */
int
builtin_handler (char **args, info_t *info)
{
	builtin_t builtins[] = { { "exit", builtin_exit },
				 { "env", builtin_env },
				 { "setenv", builtin_setenv },
				 { "unsetenv", builtin_unsetenv },
				 { "cd", builtin_cd },
				 { "alias", builtin_alias },
				 { NULL, NULL } };

	int i;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp (args[0], builtins[i].name) == 0)
		{
			return (((builtins[i].func (args, info))));
		}
	}

	return (((-1))); /*
			  *  Not a builtin command
			  */
}
