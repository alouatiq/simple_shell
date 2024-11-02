#include "shell.h"

/**
	* _strcmp - Compare two strings
	* @s1: First string
	* @s2: Second string
	*
	* Return: 0 if the strings are equal, otherwise a non-zero value
	*/
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}
