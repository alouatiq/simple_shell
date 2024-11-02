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

extern char **environ;

#endif /* SHELL_H */
