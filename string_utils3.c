#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* _strdup - Duplicates a string.
* @str: The string to duplicate.
*
* Description: This function allocates memory for and creates a copy of
* the given string.
*
* Return: A pointer to the duplicated string, or NULL if memory allocation
* fails.
*/
char *_strdup(const char *str)
{
char *dup;
size_t len;

if (str == NULL)
return (NULL);

len = _strlen(str);
dup = malloc((len + 1) * sizeof(char));
if (dup == NULL)
return (NULL);

_strcpy(dup, str);
return (dup);
}

/**
* _strcat - Concatenates two strings.
* @dest: The destination string.
* @src: The source string.
*
* Description: This function appends the src string to the dest string,
* overwriting the terminating null byte (\0) at the end of dest, and then adds
* a terminating null byte.
*
* Return: A pointer to the resulting string dest.
*/
char *_strcat(char *dest, const char *src)
{
char *ptr = dest + _strlen(dest);

while (*src != '\0')
*ptr++ = *src++;

*ptr = '\0';
return (dest);
}

/**
* _strcpy - Copies a string to a destination buffer.
* @dest: The destination buffer.
* @src: The source string.
*
* Description: This function copies the string pointed to by src, including
* the terminating null byte (\0), to the buffer pointed to by dest.
*
* Return: A pointer to the destination string dest.
*/
char *_strcpy(char *dest, const char *src)
{
char *ptr = dest;

while (*src)
*dest++ = *src++;
*dest = '\0';

return (ptr);
}

/**
* _strrev - Reverses a string in place.
* @str: The string to reverse.
*
* Description: This function reverses the order of characters in the given
* string.
*
* Return: A pointer to the reversed string.
*/
char *_strrev(char *str)
{
int len = _strlen(str);
int i;
char temp;

for (i = 0; i < len / 2; i++)
{
temp = str[i];
str[i] = str[len - i - 1];
str[len - i - 1] = temp;
}

return (str);
}

/**
* _strtok - Tokenizes a string.
* @str: The string to tokenize.
* @delim: The delimiter characters.
* Description: This function splits a string into tokens based on the
* specified delimiter characters. It is similar
* to the standard strtok function.
* Return: A pointer to the next token, or NULL if there are no more tokens.
*/
char *_strtok(char *str, const char *delim)
{
static char *last;
char *tok;

if (str == NULL)
str = last;

while (*str && _strchr(delim, *str))
str++;

if (*str == '\0')
{
last = str;
return (NULL);
}

tok = str;
while (*str && !_strchr(delim, *str))
str++;

if (*str)
*str++ = '\0';

last = str;
return (tok);
}
