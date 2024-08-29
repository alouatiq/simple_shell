#include "shell.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: Pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
	char *d = dest;

	while (*d)
		d++;
	while ((*d++ = *src++))
		;

	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string to measure.
 *
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Difference between the first two differing characters.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strcpy - Copies a string to another buffer.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: Pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*d++ = *src++))
		;

	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @s: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
 */
char *_strdup(const char *s)
{
	char *dup = malloc(_strlen(s) + 1);

	if (dup == NULL)
		return (NULL);

	_strcpy(dup, s);
	return (dup);
}
