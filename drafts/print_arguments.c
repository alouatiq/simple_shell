#include <stdio.h>
#include <unistd.h>

/**
 * Program that prints the arguments of a string without using argc
 *
 * Return: always à
 */
int main (int argc, char **argv)
{
	int i = 1;
	argc = argc;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
