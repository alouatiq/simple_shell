#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* _atoi - Converts a string to an integer.
* @s: The string to be converted.
*
* Description: This function converts a string of digits (and possibly a sign)
* into an integer. It stops conversion at the first non-numeric character.
*
* Return: The integer value of the string.
*/
int _atoi(char *s)
{
int sign = 1;
unsigned int num = 0;

while (*s && (*s < '0' || *s > '9'))
{
if (*s == '-')
sign *= -1;
s++;
}
while (*s >= '0' && *s <= '9')
{
num = (num * 10) + (*s - '0');
s++;
}
return (num *sign);
}

/**
* _itoa - Converts an integer to a string.
* @num: The integer to be converted.
* @str: The buffer to store the converted string.
* @base: The base for the conversion (e.g., 10 for decimal, 2 for binary).
*
* Description: This function converts an integer to a string in the specified
* base and stores the result in the provided buffer.
*
* Return: A pointer to the resulting string.
*/
char *_itoa(int num, char *str, int base)
{
int i = 0;
int is_negative = 0;
int remainder;
char digits[] = "0123456789ABCDEF";

if (num == 0)
{
str[i++] = '0';
str[i] = '\0';
return (str);
}

if (num < 0 && base == 10)
{
is_negative = 1;
num = -num;
}

while (num != 0)
{
remainder = num % base;
str[i++] = digits[remainder];
num = num / base;
}

if (is_negative)
str[i++] = '-';

str[i] = '\0';

_reverse_string(str, i);
return (str);
}

/**
* _reverse_string - Reverses a string in place.
* @str: The string to reverse.
* @length: The length of the string.
*
* Description: This function reverses the characters in the string in place.
*
* Return: void
*/
void _reverse_string(char *str, int length)
{
int start = 0;
int end = length - 1;
char temp;

while (start < end)
{
temp = str[start];
str[start] = str[end];
str[end] = temp;
start++;
end--;
}
}

/**
* _error_exit - Prints an error message and exits the program.
* @msg: The error message to print.
* @status: The exit status to use when terminating the program.
*
* Description: This function prints an error message to stderr and then exits
* the program with the provided status code.
*
* Return: void
*/
void _error_exit(char *msg, int status)
{
write(STDERR_FILENO, msg, _strlen(msg));
exit(status);
}
