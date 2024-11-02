#include "shell.h"

/* Add any string utility functions here if needed */
#include "shell.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
    int len = 0;

    while (s && s[len])
        len++;
    return len;
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, negative if s1 < s2, positive if s1 > s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

/**
 * _strcpy - Copies a string.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
    char *start = dest;

    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return start;
}

/**
 * _strdup - Duplicates a string.
 * @s: The input string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *_strdup(const char *s)
{
    char *dup;
    int len;

    if (!s)
        return NULL;

    len = _strlen(s);
    dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return NULL;

    _strcpy(dup, s);
    return dup;
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
    char *ptr = dest + _strlen(dest);

    while (*src)
        *ptr++ = *src++;
    *ptr = '\0';
    return dest;
}
