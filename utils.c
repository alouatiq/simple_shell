#include "shell.h"

/**
* _strdup - Duplicates a string.
* @s: The string to duplicate.
* This function allocates memory for and
* returns a copy of the given string.
* Return: A pointer to the duplicated string,
* or NULL if memory allocation fails.
*/
char *_strdup(const char *s)
{
char *dup;
size_t len = _strlen(s);

dup = malloc(len + 1);
if (dup == NULL)
{
perror("malloc");
return (NULL);
}
_strcpy(dup, s);
return (dup);
}

/**
* _strlen - Returns the length of a string.
* @s: The string to measure.
* This function returns the number of characters
* in the string, excluding
* the null-terminator.
* Return: The length of the string.
*/
size_t _strlen(const char *s)
{
size_t len = 0;

while (s[len] != '\0')
{
len++;
}
return (len);
}

/**
* _strcmp - Compares two strings.
* @s1: The first string.
* @s2: The second string.
* This function compares two strings
* lexicographically.
* Return: An integer less than, equal to,
* or greater than zero if s1 is found,
* respectively, to be less than, to match,
* or be greater than s2.
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
* _strcpy - Copies a string to a destination buffer.
* @dest: The destination buffer.
* @src: The source string.
* This function copies the string pointed
* to by src, including the null-terminator,
* to the buffer pointed to by dest.
* Return: A pointer to the destination string.
*/
char *_strcpy(char *dest, const char *src)
{
char *ptr = dest;

while ((*dest++ = *src++))
;
return (ptr);
}
