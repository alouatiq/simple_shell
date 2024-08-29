#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Task 1: Basic Shell Implementation */
/* Task 2: Handle Command Line Arguments */
/* Task 3: Handle PATH */
/* Task 4: Implement Built-in exit */
/* Task 5: Implement Built-in env */

/* Function Prototypes */
void prompt(void);
char *read_command(void);

/**
 * tokenize - Splits a command string into tokens.
 * @command: The command string to tokenize.
 *
 * This function splits the command string
 * into individual tokens (arguments)
 * using space as a delimiter.
 *
 * Return: An array of tokens, or NULL on failure.
 */


char **tokenize(char *command);  /* Task 2 */
void execute_command(char **args);

/**
 * print_env - Prints the environment variables
 * to the standard output.
 */

void print_env(void);  /* Task 5 */

/**
 * find_command - Searches for a command in
 * the system PATH.
 * @command: The name of the command to search for.
 *
 * This function searches for the specified
 * command in the directories listed
 * in the system PATH environment variable.
 *
 * Return: The full path to the command, or
 * NULL if not found.
 */


char *find_command(char *command);  /* Task 3 */

/**
 * _getline - Reads an entire line from standard input.
 * @buffer: A pointer to the buffer where the line will be stored.
 * @bufsize: The size of the buffer.
 * @stream: The input stream to read from.
 *
 * This function reads a line of input from
 * the specified stream and stores it
 * in the buffer.
 *
 * Return: The number of characters read, or-1 on failure or EOF.
 */

int _getline(char **buffer, size_t *bufsize, FILE *stream);  /* Task 6 */

#endif /* SHELL_H */
