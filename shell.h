#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* External variable declaration */
extern char **environ;

/* Function prototypes */
void prompt(void);
char *read_line(void);
char **split_line(char *line);
int execute(char *input);
int launch(char **args);

/* Built-in function prototypes */
int shell_exit(char **args);
int shell_env(char **args);
int shell_cd(char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);

/* Helper function prototypes */
char *_getenv(const char *name);
char *which(char *cmd);
char *custom_getline(void);
void free_args(char **args);

#endif /* SHELL_H */
