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

extern char **environ;

void prompt(void);
char *read_line(void);
char **tokenize(char *line);
int execute(char **args);
int shell_cd(char **args);
int shell_exit(char **args);
int shell_env(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);

char *find_command(char *cmd);
int run_command(char **args);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);

#endif /* SHELL_H */
