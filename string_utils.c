#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* _strlen - Returns the length of a string.
* @s: The string to measure.
*
* Description: This function calculates the length of a string, excluding the
* null terminator.
*
* Return: The length of the string.
*/
int _strlen(char *s)
{
int length = 0;

while (s[length] != '\0')
length++;
return (length);
}

/**
* _strcmp - Compares two strings.
* @s1: The first string.
* @s2: The second string.
*
* Description: This function compares two strings lexicographically.
*
* Return: An integer less than, equal to, or greater than zero if s1 is found
* to be less than, to match, or be greater than s2, respectively.
*/
int _strcmp(char *s1, char *s2)
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
*
* Description: This function copies the string pointed to by src, including
* the null terminator, to the buffer pointed to by dest.
*
* Return: A pointer to the destination string.
*/
char *_strcpy(char *dest, char *src)
{
char *ptr = dest;

while ((*dest++ = *src++))
;
return (ptr);
}

/**
* _strcat - Concatenates two strings.
* @dest: The destination buffer.
* @src: The source string to append to dest.
*
* Description: This function appends the src string to the dest string,
* overwriting the null terminator at the end of dest, and then adds a new null
* terminator.
*
* Return: A pointer to the resulting string dest.
*/
char *_strcat(char *dest, char *src)
{
char *ptr = dest + _strlen(dest);

while (*src != '\0')
*ptr++ = *src++;
*ptr = '\0';

return (dest);
}

/**
* _strdup - Duplicates a string.
* @str: The string to duplicate.
*
* Description: This function allocates memory for and returns a copy of the
* given string.
*
* Return: A pointer to the duplicated string,
* or NULL if memory allocation fails.
*/
char *_strdup(char *str)
{
char *dup;
int len;

if (str == NULL)
return (NULL);

len = _strlen(str);
dup = malloc((len + 1) * sizeof(char));

if (dup == NULL)
return (NULL);

_strcpy(dup, str);

return (dup);
}
