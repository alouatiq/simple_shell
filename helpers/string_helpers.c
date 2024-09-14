#include "../shell.h"

/**
 * _strlen - Calculate the length of a string
 * @s: The string to measure
 * Return: The length of the string
 */
int
_strlen (const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return ((len));
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings are equal, negative if s1 < s2, positive if s1 > s2
 */
int
_strcmp (const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;

		s2++;
	}
	return ((*(unsigned char *)s1 - *(unsigned char *)s2));
}

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 * Return: Point er to the duplicated string, or NULL if insufficient memory
 */
char *
_strdup (const char *str)
{
	char *dup;

	int len, i;

	if (str == NULL)
		return ((NULL));

	len = _strlen (str);

	dup = malloc (sizeof (char) * (len + 1));

	if (dup == NULL)
		return ((NULL));

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return ((dup));
}

/**
 * _strcat - Concatenate two strings
 * @dest: The destination string
 * @src: The source string
 * Return: Point er to the resulting string dest
 */
char *
_strcat (char *dest, const char *src)
{
	int i, j;

	i = 0;

	while (dest[i])
		i++;

	j = 0;

	while (src[j])
	{
		dest[i] = src[j];

		i++;

		j++;
	}
	dest[i] = '\0';

	return (((dest)));
}
