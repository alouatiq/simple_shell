#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* Constants */
#define MAX_COMMAND 100
#define MAX_COMMAND_LENGTH 1024
#define MAX_VAR_NAME 100
#define MAX_ARGS 64
#define MAX_PATH 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Structure for the info_t type used in error handling and state management */
typedef struct {
    char *fname;
    char **argv;
    int line_count;
    int exit_status;
    char *input_line;
    char **env;
} info_t;

/* Function prototypes */

/* Input handlers */
char *read_line(void);
char **parse_input(char *input);

/* Execution */
int execute_command(char **args, info_t *info);
char *find_command(char *command);
int fork_command(char **args, info_t *info);

/* Builtins */
int builtin_exit(char **args, info_t *info);
int builtin_env(char **args, info_t *info);
int builtin_setenv(char **args, info_t *info);
int builtin_unsetenv(char **args, info_t *info);
int builtin_cd(char **args, info_t *info);
int builtin_alias(char **args, info_t *info);
int builtin_handler(char **args, info_t *info);

/* Helpers */
/* String helpers */
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
char *_strchr(char *s, char c);

/* Memory helpers */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_memset(void *s, int b, unsigned int n);
void ffree(char **pp);

/* Error handlers */
void _eputs(char *str);
int _eputchar(char c);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);


/* Advanced features */
/* Logical operators */
int execute_logical_ops(char **commands, int num_commands, info_t *info);
char **split_logical_ops(char *input, int *num_commands);

/* Variable expansion */
char *expand_variables(char *command, info_t *info);

/* Comment handler */
char *remove_comments(char *command);

/* File input */
int execute_file(const char *filename, info_t *info);

/* Environment variable handlers */
char *_getenv(const char *name, char **env);
int _setenv(char **env, const char *name, const char *value, int overwrite);
int _unsetenv(char **env, const char *name);

/* Main loop */
void shell_loop(info_t *info);

#endif /* SHELL_H */