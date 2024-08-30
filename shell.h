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

/* Task 0.1: Core Shell Functionality */
void display_prompt(void);                     /* Displays the shell prompt */
void execute_command(char **args);             /* Executes external commands */

/* Task 0.1.1: Custom getline function */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream); /* Custom getline function */

/* Task 0.2.1: Custom tokenization function */
char **custom_tokenize(char *line);            /* Custom tokenization of command input */

/* Task 0.4: Handle the exit built-in */
void handle_exit(char **args);                 /* Handles the exit built-in command */

/* Task 0.4.1: Handle exit with status */
void handle_exit_with_status(char **args);     /* Handles exit with status */

/* Task 1.0: Handle the env built-in */
void handle_env(void);                         /* Handles the env built-in command */

/* Task 1.0: Handle setenv and unsetenv */
int handle_setenv(const char *name, const char *value, int overwrite);  /* Handles setenv */
int handle_unsetenv(const char *name);         /* Handles unsetenv */

/* Task 1.0: Handle the cd command */
int handle_cd(char **args);                    /* Handles the cd built-in command */

/* Task 1.0: Handle command separators (;) */
int handle_command_separators(char *line);     /* Handles command separators (e.g., ;) */

void handle_logical_operators(char *line);     /* Handles logical operators (&& and ||) */

/* Task 1.0: Handle aliases */
int handle_alias(char **args);                 /* Handles alias built-in command */

/* Task 1.0: Handle variable replacement ($?, $$, etc.) */
char *handle_variable_replacement(char *line, int last_exit_status); /* Handles variable replacement */

/* Task 1.0: Handle comments (#) */
char *remove_comments(char *line);             /* Removes comments from input */

/* Task 1.0: Handle file input */
int handle_file_input(const char *filename);   /* Handles reading commands from a file */

/* Task 0.3: Search for commands in PATH */
char *find_command_in_path(char *command);     /* Finds command in PATH */

#endif /* SHELL_H */
