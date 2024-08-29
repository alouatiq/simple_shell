#include "main.h"

/**
 * aux_help - Displays help information for the builtin help command
 *
 * This function provides detailed usage information for the 'help' command.
 * It explains how to use the command and its purpose in displaying information
 * about other builtin commands.
 *
 * Usage: help [-dms] [pattern ...]
 *
 * The function writes the help message directly to STDOUT_FILENO using the write system call.
 *
 * Return: void
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_alias - Displays help information for the builtin alias command
 *
 * This function provides detailed usage information for the 'alias' command.
 * It explains how to use the command to define or display aliases in the shell.
 *
 * Usage: alias [-p] [name[=value]...]
 *
 * The function writes the help message directly to STDOUT_FILENO using the write system call.
 *
 * Return: void
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_cd - Displays help information for the builtin cd command
 *
 * This function provides detailed usage information for the 'cd' command.
 * It explains how to use the command to change the shell's working directory.
 *
 * Usage: cd [-L|[-P [-e]] [-@]] [dir]
 *
 * The function writes the help message directly to STDOUT_FILENO using the write system call.
 *
 * Return: void
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}
