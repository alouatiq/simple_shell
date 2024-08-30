#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

extern char **environ;

/* Function prototypes */
void display_prompt(void);
void execute_command(char **args);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char **custom_tokenize(char *line);
void handle_exit(char **args);
int handle_setenv(const char *name, const char *value, int overwrite);
int handle_unsetenv(const char *name);
int handle_cd(char **args);
int handle_command_separators(char *line);
void handle_logical_operators(char *line);
int handle_alias(char **args);
char *handle_variable_replacement(char *line, int last_exit_status);
char *remove_comments(char *line);
int handle_file_input(const char *filename);
char *find_command_in_path(char *command);
int _setenv(const char *name, const char *value, int overwrite); /* Add this */
int _unsetenv(const char *name);                                 /* Add this */

#endif /* SHELL_H */
