#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* check_syntax_error - Checks for syntax errors in the input command.
* @input: The input command string.
*
* Description: This function checks for common syntax errors such as
* misplaced semicolons, pipes, or logical operators.
* It returns 1 if a syntax error is found and 0 otherwise.
*
* Return: 1 if syntax error is found, 0 otherwise.
*/
int check_syntax_error(char *input)
{
int i = 0, error = 0;
char prev_char = 0;

while (input[i])
{
if (input[i] == ';' || input[i] == '|' || input[i] == '&')
{
if (i == 0 || input[i + 1] == ';' || input[i + 1] == '|' || input[i + 1] == '&')
{
error = 1;
break;
}
if (prev_char == ';' || prev_char == '|' || prev_char == '&')
{
error = 1;
break;
}
}
if (input[i] != ' ' && input[i] != '\t')
prev_char = input[i];
i++;
}
if (error)
write(STDERR_FILENO, "Syntax error: invalid syntax\n", 29);

return (error);
}

/**
* print_syntax_error - Prints a specific syntax error message.
* @input: The input command string.
* @index: The position of the error.
* @expected: The expected character or token.
*
* Description: This function prints a specific error message, including
* the position of the error and what was expected.
*
* Return: void.
*/
void print_syntax_error(char *input, int index, char *expected)
{
write(STDERR_FILENO, "Syntax error near unexpected token '", 37);
write(STDERR_FILENO, expected, _strlen(expected));
write(STDERR_FILENO, "' at position ", 14);
print_number(index + 1); /* +1 to convert to 1-based index */
write(STDERR_FILENO, " in command: ", 13);
write(STDOUT_FILENO, input, _strlen(input));
write(STDERR_FILENO, "\n", 1);
}

/**
* print_number - Prints an integer to the standard output.
* @n: The integer to print.
*
* Description: This function converts an integer to a string
* and prints it to the standard output.
*
* Return: void.
*/
void print_number(int n)
{
char buffer[10];
int i = 0;

if (n == 0)
{
write(STDOUT_FILENO, "0", 1);
return;
}

while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}

while (--i >= 0)
write(STDOUT_FILENO, &buffer[i], 1);
}
