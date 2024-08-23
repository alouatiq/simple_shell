#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>      // Standard I/O functions
#include <stdlib.h>     // Standard library functions
#include <unistd.h>     // POSIX API functions (e.g., fork, exec, etc.)
#include <string.h>     // String handling functions
#include <sys/types.h>  // Data types used in system calls
#include <errno.h>      // Error number definitions
#include <sys/types.h>  // Data types used in system calls
#include <sys/wait.h>   // Macros related to process termination

/* Function prototypes */

/* Starts the shell in interactive mode */
/* Task 1: Simple Shell 0.1 */
void shell_interactive(void);

/* Runs the shell in non-interactive mode */
/* Task 1: Simple Shell 0.1 */
void shell_non_interactive(char *filename);

/* Function to execute a command */
/* Task 2: Simple Shell 0.2 */
void execute_command(char *command);

/* Additional tasks declarations */

/* Task 3: Simple Shell 0.3 */
char *find_command_in_path(char *command);

/* Task 4: Simple Shell 0.4 */
void handle_exit(char *command);

/* Task 5: Simple Shell 1.0 */
void print_env(void);

/* Task 6: Simple Shell 0.1.1 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

/* Task 7: Simple Shell 0.2.1 */
void my_strtok(char *str, char *delim, char **tokens);

/* Task 9: setenv, unsetenv */
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);

#endif /* SHELL_H */
