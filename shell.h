#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void prompt(void);
char *read_command(void);
char **tokenize(char *command);
int execute_command(char *command);
void print_env(void);
char *find_command(char *command);
ssize_t _getline(char **buffer, size_t *bufsize);

char *_strcat(char *dest, const char *src);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *s);

#endif /* SHELL_H */
