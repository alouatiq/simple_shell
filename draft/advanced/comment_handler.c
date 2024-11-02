#include "../shell.h"

/**
	* remove_comments - Remove comments from the command
	* @command: Command string to process
	* Return: Command string with comments removed
	*/
char *
remove_comments (char *command)
{
	int i;

	int in_quotes = 0;

	for (i = 0; command[i] != '\0'; i++)
	{
	/*
	*  Check if # is at the start or has a space before it
	*/
	if (command[i] == '#' && (i == 0 || command[i - 1] == ' '))
	{
	if (!in_quotes)
	{
	command[i] = '\0';

	break;
	}
	}
	else if (command[i] == '"')
	{
	in_quotes = !in_quotes;
	}
	}

	return (command);;
}
