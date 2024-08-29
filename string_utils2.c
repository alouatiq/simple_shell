#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* _strncmp - Compares two strings up to a given number of characters.
* @s1: The first string.
* @s2: The second string.
* @n: The number of characters to compare.
*
* Description: This function compares up to n characters of the strings s1
* and s2.
*
* Return: An integer less than, equal to, or greater than zero if s1 (or the
* first n bytes thereof) is found to be less than, to match, or be greater than
* s2, respectively.
*/
int _strncmp(char *s1, char *s2, int n)
{
while (n && *s1 && (*s1 == *s2))
{
s1++;
s2++;
n--;
}
if (n == 0)
return (0);
else
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
* _strchr - Locates a character in a string.
* @s: The string to search.
* @c: The character to find.
*
* Description: This function locates the first occurrence of c in the string s.
*
* Return: A pointer to the first occurrence of c
* in s, or NULL if c is not found.
*/
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}
if (c == '\0')
return (s);

return (NULL);
}

/**
* _strspn - Gets the length of a prefix substring.
* @s: The string to be searched.
* @accept: The prefix to be measured.
*
* Description: This function calculates the length of the initial segment of s
* which consists entirely of bytes in accept.
*
* Return: The number of bytes in the initial segment of s which consist only of
* bytes from accept.
*/
int _strspn(char *s, char *accept)
{
int len = 0;
char *a;

while (*s)
{
for (a = accept; *a; a++)
{
if (*s == *a)
break;
}
if (*a == '\0')
break;
len++;
s++;
}
return (len);
}

/**
* _strcspn - Calculates the length of the initial
* segment of s which does not contain any of the bytes in reject.
* @s: The string to be scanned.
* @reject: The string containing the bytes to match.
*
* Description: This function calculates the length of the initial segment of s
* which consists entirely of bytes not in reject.
*
* Return: The number of bytes in the initial segment
* of s which are not in reject.
*/
int _strcspn(char *s, char *reject)
{
int len = 0;
char *r;

while (*s)
{
for (r = reject; *r; r++)
{
if (*s == *r)
return (len);
}
len++;
s++;
}
return (len);
}

/**
* _strpbrk - Searches a string for any of a set of bytes.
* @s: The string to be scanned.
* @accept: The string containing the characters to match.
*
* Description: This function locates the first occurrence in the string s of
* any of the bytes in the string accept.
*
* Return: A pointer to the byte in s that matches one of the bytes in accept,
* or NULL if no such byte is found.
*/
char *_strpbrk(char *s, char *accept)
{
char *a;

while (*s)
{
for (a = accept; *a; a++)
{
if (*s == *a)
return (s);
}
s++;
}
return (NULL);
}
