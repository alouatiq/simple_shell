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

void prompt(void);
char *read_command(void);
char **tokenize(char *command);
void execute_command(char **args);
char *find_command(char *command);
void print_env(void);
int _getline(char **buffer, size_t *bufsize, FILE *stream);
char *_strdup(const char *s);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);

#endif /* SHELL_H */
