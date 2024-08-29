#include "shell.h"

/* This file can be used to implement utility functions */
/* For example, a function to free memory, string manipulation, etc. */

/* Duplicate a string */
char *_strdup(const char *s)
{
    char *dup;
    size_t len = strlen(s);

    dup = malloc(len + 1);
    if (dup == NULL)
    {
        perror("malloc");
        return NULL;
    }
    strcpy(dup, s);
    return dup;
}

/* Calculate the length of a string */
size_t _strlen(const char *s)
{
    size_t len = 0;

    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

/* Compare two strings */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

/* Copy a string */
char *_strcpy(char *dest, const char *src)
{
    char *ptr = dest;

    while ((*dest++ = *src++))
        ;
    return ptr;
}
