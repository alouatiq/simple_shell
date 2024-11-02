#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Function Prototypes */
int execute_line(char *line);
char **tokenize_line(char *line);
int execute_command(char **args);
int check_builtin(char **args);
int shell_exit(char **args);
int shell_env(char **args);
char *resolve_path(char *command);
void free_tokens(char **tokens);

/* Custom getline implementation if needed */
ssize_t getline_custom(char **lineptr, size_t *n, FILE *stream);
int expand_variables(char **args);

/* External environment variable */
extern char **environ;

#endif /* SHELL_H */
