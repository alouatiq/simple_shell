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
char **tokenize(char *command);  /* Task 2 */
void execute_command(char **args);
void print_env(void);  /* Task 5 */
char *find_command(char *command);  /* Task 3 */
int _getline(char **buffer, size_t *bufsize);  /* Task 6 */

#endif /* SHELL_H */
