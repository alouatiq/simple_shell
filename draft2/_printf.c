#include "shell.h"

/**
 * _printf - Function that prints to stdout
 * @buffer: Line to be printed
 *
 * Return: Number of characters printed
 */
int _printf(char *buffer)
{
	int w;

	if (buffer == NULL)
		return (-1);

	w =  write(STDOUT_FILENO, buffer, _strlen(buffer));

	if (w == -1)
		return (-1);

	return (w);
}
