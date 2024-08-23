#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>      // Standard I/O functions
#include <stdlib.h>     // Standard library functions
#include <unistd.h>     // POSIX API functions (e.g., fork, exec, etc.)
#include <string.h>     // String handling functions
#include <sys/types.h>  // Data types used in system calls
#include <errno.h>      // Error number definitions

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

#endif /* SHELL_H */
