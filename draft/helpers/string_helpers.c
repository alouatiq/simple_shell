#include "../shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
	* _putchar - writes the character c to stdout
	* @c: The character to print
	*
	* Return: On success 1.
	* On error, -1 is returned, and errno is set appropriately.
	*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
	* _strlen - Calculate the length of a string
	* @s: The string to measure
	* Return: The length of the string
	*/
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
	len++;

	return (len);
}

/**
	* _strcmp - Compare two strings
	* @s1: First string
	* @s2: Second string
	* Return: 0 if strings are equal, negative if s1 < s2, positive if s1 > s2
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
	* _strdup - Duplicate a string
	* @str: The string to duplicate
	* Return: Pointer to the duplicated string, or NULL if insufficient memory
	*/
char *_strdup(const char *str)
{
	char *dup;
	int len, i;

	if (str == NULL)
	return NULL;

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	return NULL;

	for (i = 0; i <= len; i++)
	dup[i] = str[i];

	return dup;
}

void free_strdup(char *str)
{
	if (str != NULL)
	{
	free(str);
	str = NULL;
	}
}

/**
	* _strcat - Concatenate two strings
	* @dest: The destination string
	* @src: The source string
	* Return: Pointer to the resulting string dest
	*/
char *_strcat(char *dest, const char *src)
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

	return (dest);
}

/**
	* _strncmp - Compare n characters of two strings
	* @s1: First string
	* @s2: Second string
	* @n: Number of characters to compare
	* Return: 0 if strings are equal, negative if s1 < s2, positive if s1 > s2
	*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
	++s1;
	++s2;
	--n;
	}
	if (n == 0)
	return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
	* _strcpy - Copy a string
	* @dest: Destination string
	* @src: Source string
	* Return: Pointer to dest
	*/
char *_strcpy(char *dest, const char *src)
{
	char *d = dest;
	while ((*d++ = *src++))
	;
	return (dest);
}

/**
	* _strspn - Get length of a prefix substring
	* @s: String to be scanned
	* @accept: String containing the characters to match
	* Return: Number of characters in the initial segment of s which consist only
	* of characters from accept
	*/
size_t _strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	size_t count = 0;

	for (p = s; *p != '\0'; ++p)
	{
	for (a = accept; *a != '\0'; ++a)
	{
	if (*p == *a)
	break;
	}
	if (*a == '\0')
	return (count);
	++count;
	}
	return (count);
}

/**
	* _strcspn - Get length of a prefix substring
	* @s: String to be scanned
	* @reject: String containing the characters to not match
	* Return: Number of characters in the initial segment of s which are not in reject
	*/
size_t _strcspn(const char *s, const char *reject)
{
	const char *p;
	const char *r;
	size_t count = 0;

	for (p = s; *p != '\0'; ++p)
	{
	for (r = reject; *r != '\0'; ++r)
	{
	if (*p == *r)
	return (count);
	}
	++count;
	}
	return (count);
}

/**
	* _strchr - Locate character in string
	* @s: String to search
	* @c: Character to find
	* Return: Pointer to the first occurrence of the character c in the string s,
	* or NULL if the character is not found
	*/
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
	if (*s == c)
	return (s);
	s++;
	}
	if (*s == c)
	return (s);
	return (NULL);
}

/**
	* _getenv - Get an environment variable
	* @name: Name of the environment variable
	* @env: Array of environment variables
	* Return: Pointer to the value in the environment, or NULL if there is no match
	*/
char *_getenv(const char *name, char **env)
{
	int i, len;

	len = _strlen(name);
	for (i = 0; env[i] != NULL; i++)
	{
	if (_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
	return (&env[i][len + 1]);
	}
	return (NULL);
}

/**
	* _setenv - Change or add an environment variable
	* @env: Array of environment variables
	* @name: Name of the environment variable
	* @value: Value to set
	* @overwrite: Flag to overwrite existing variable
	* Return: 0 on success, -1 on failure
	*/
int _setenv(char **env, const char *name, const char *value, int overwrite)
{
	int i, len;
	char *new_var;

	if (!name || !value)
	return (-1);

	len = _strlen(name);
	for (i = 0; env[i] != NULL; i++)
	{
	if (_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
	{
	if (!overwrite)
	return (0);
	free(env[i]);
	break;
	}
	}

	new_var = malloc(_strlen(name) + _strlen(value) + 2);
	if (!new_var)
	return (-1);

	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);

	env[i] = new_var;
	if (env[i + 1] == NULL)
	env[i + 1] = NULL;

	return (0);
}

/**
	* _unsetenv - Remove an environment variable
	* @env: Array of environment variables
	* @name: Name of the environment variable to remove
	* Return: 0 on success, -1 on failure
	*/
int _unsetenv(char **env, const char *name)
{
	int i, j, len;

	if (!name)
	return (-1);

	len = _strlen(name);
	for (i = 0; env[i] != NULL; i++)
	{
	if (_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
	{
	free(env[i]);
	for (j = i; env[j] != NULL; j++)
	env[j] = env[j + 1];
	return (0);
	}
	}
	return (-1);
}

/**
	* _strtok_r - Extract tokens from strings
	* @str: String to tokenize
	* @delim: Delimiter characters
	* @saveptr: Pointer to a char * variable that is used internally
	* Return: Pointer to the next token, or NULL if there are no more tokens
	*/
char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *end;

	if (str == NULL)
	str = *saveptr;

	if (*str == '\0')
	{
	*saveptr = str;
	return (NULL);
	}

	str += _strspn(str, delim);
	if (*str == '\0')
	{
	*saveptr = str;
	return (NULL);
	}

	end = str + _strcspn(str, delim);
	if (*end == '\0')
	{
	*saveptr = end;
	return (str);
	}

	*end = '\0';
	*saveptr = end + 1;
	return (str);
}

/**
	* _itoa - Convert integer to string
	* @value: Integer to convert
	* @str: Buffer to store the result
	* @base: Numerical base for conversion
	* Return: Pointer to the resulting string
	*/
char *_itoa(int value, char *str, int base)
{
	char *rc;
	char *ptr;
	char *low;
	int negative = 0;

	if (base < 2 || base > 36)
	{
	*str = '\0';
	return (str);
	}

	rc = ptr = str;

	if (value < 0 && base == 10)
	{
	negative = 1;
	value = -value;
	}

	do
	{
	*ptr++ = "0123456789abcdefghijklmnopqrstuvwxyz"[value % base];
	value /= base;
	} while (value);

	if (negative)
	*ptr++ = '-';

	*ptr-- = '\0';
	low = str;

	while (low < ptr)
	{
	char tmp = *low;
	*low++ = *ptr;
	*ptr-- = tmp;
	}

	return (rc);
}
