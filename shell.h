#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>      /* Standard I/O functions*/
#include <stdlib.h>     /* Standard library functions*/
#include <unistd.h>     /* POSIX API functions (e.g., fork, exec, etc.)*/
#include <string.h>     /* String handling functions*/
#include <sys/types.h>  /* Data types used in system calls*/
#include <errno.h>      /* Error number definitions*/
#include <sys/types.h>  /* Data types used in system calls*/
#include <sys/wait.h>   /* Macros related to process termination*/
#include <fcntl.h>

extern char **environ;

/* Function prototypes */

/* Starts the shell in interactive mode */
/* Task 1: Simple Shell 0.1 */
void shell_interactive(void);

/* Runs the shell in non-interactive mode */
/* Task 1: Simple Shell 0.1 */
void shell_non_interactive(char *filename);

/* Function to execute a command */
/* Task 2: Simple Shell 0.2 */
int execute_command(char *command);

/* Additional tasks declarations */

/* Task 3: Simple Shell 0.3 */
char *find_command_in_path(char *command);

/* Task 4: Simple Shell 0.4 - Exit built-in command handled in execute_command */

/* Task 5: Simple Shell 1.0 - Print environment*/
void print_env(void);

/* Task 6: Simple Shell 0.1.1 - Custom getline*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

/* Task 7: Simple Shell 0.2.1 - Custom strtok*/
char *_strtok(char *str, char *delim);

/* Task 8: Exit with arguments*/
void _exiting(char *command);

/* Task 9: setenv, unsetenv */
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);

/* Task 10: cd command */
void change_directory(char *path);

/* Task 11: Command Separator */
void handle_command_separator(char *command);

/* Task 12: Logical Operators */
void handle_logical_operators(char *command);

/* Task 13: Alias */
void handle_alias(char **args);

/* Task 14: Variable Replacement */
void handle_variable_replacement(char *command);

/* Task 15: Comments */
void remove_comments(char *command);

/* Task 16: File Input */
void execute_file_commands(char *filename);

/* Additional Utility Functions */
char *find_command_in_path(char *command);
void handle_exit(char *command);
void print_env(void);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void my_strtok(char *str, char *delim, char **tokens);
int my_setenv(const char *name, const char *value, int overwrite);
int my_unsetenv(const char *name);
char **str_tockenise(char *buffer, char *del);
void free_all(char **buffer1, char **buffer2, char *buffer3);
char *command_check(char *command, char **path_list);
int _printf(char *buffer);
int _strlen(char *string);
int _strcmp(char *first, char *second);
size_t _strcspn(const char *line, const char *reject);
void free_args(char **args);
int execute_external_command(char **args);

/* New function for processing input in shell_interactive */
int process_input(char **line, size_t *len);

#endif /* SHELL_H */
