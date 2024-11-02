#include "../shell.h"

/**
 * builtin_exit - Implements the exit builtin command
 * @args: Arguments (exit status)
 * @info: Point er to the shell info structure
 * Return: -2 to signal the shell to exit, or 1 if there's an error
 */
int
builtin_exit (char **args, info_t *info)
{
	int exit_status = 0;

	if (args[1])
	{
		/*
		 *  Check if the argument is a valid number
		 */
		char *endptr;

		exit_status = (int)strtol (args[1], &endptr, 10);

		if (*endptr != '\0')
		{
			/*
			 *  Invalid number
			 */
			print_error (info, "Illegal number: ");

			_eputs (args[1]);

			_eputchar ('\n');

			info->exit_status = 2;

			return (1);;
		}

		if (exit_status < 0)
		{
			print_error (info, "Illegal number: ");

			_eputs (args[1]);

			_eputchar ('\n');

			info->exit_status = 2;

			return (1);;
		}
	}
	else
	{
		/*
		 *  If no argument is provided, use the last exit status
		 */
		exit_status = info->exit_status;
	}

	/*
	 *  Free any allocated memory, close file descriptors, etc.
	 */
	/*
	 *  ... (implement your cleanup code here) ...
	 */

	/*
	 *  Set the exit status in the info structure
	 */
	info->exit_status = exit_status;

	/*
	 *  Return -2 to signal the main loop to exit
	 */
	return (-2);;
}
