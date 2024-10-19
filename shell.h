#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* Function prototypes */
void prompt(void);
void execute(char **args);
char *get_command(void);
char **parse_command(char *command);
char *find_in_path(char *command);
int handle_builtin(char **args);
void free_memory(char **args);

extern char **environ;

#endif /* SHELL_H */
