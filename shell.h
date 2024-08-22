#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>      // Standard I/O functions
#include <stdlib.h>     // Standard library functions
#include <unistd.h>     // POSIX API functions (e.g., fork, exec, etc.)
#include <string.h>     // String handling functions
#include <sys/types.h>  // Data types used in system calls
#include <sys/wait.h>   // Macros related to process termination
#include <sys/stat.h>   // Data returned by the stat() function
#include <errno.h>      // Error number definitions

// Function to split a buffer into an array of arguments
char **get_arguments(char *buffer);

// External environment variable pointer
extern char **environ;

// Function prototypes for the shell
void prompt(void);              // Display the shell prompt
char *read_line(void);          // Read a line of input
char **tokenize(char *line);    // Tokenize the input line
int execute(char **args);       // Execute a command
int shell_cd(char **args);      // Change directory (cd built-in)
int shell_exit(char **args);    // Exit the shell (exit built-in)
int shell_env(char **args);     // Print environment variables (env built-in)
int shell_setenv(char **args);  // Set environment variables (setenv built-in)
int shell_unsetenv(char **args);// Unset environment variables (unsetenv built-in)

char *find_command(char *cmd);  // Find a command in the PATH
int run_command(char **args);   // Fork and run a command
char *_strdup(const char *str); // Duplicate a string
int _strcmp(const char *s1, const char *s2); // Compare two strings
char *_strcat(char *dest, const char *src);  // Concatenate two strings
char *_strcpy(char *dest, const char *src);  // Copy a string

#endif /* SHELL_H */
