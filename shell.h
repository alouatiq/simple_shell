#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 *  Error types for cd command
 */
#define ERR_NO_DIR 1
#define ERR_PERMISSION 2
#define ERR_HOME_NOT_SET 3
#define ERR_OLDPWD_NOT_SET 4
#define ERR_TOO_MANY_ARGS 5

int _putchar(char c);

/*
 *  Constants
 */
#define MAX_COMMAND 100
#define MAX_COMMAND_LENGTH 1024
#define MAX_VAR_NAME 100
#define MAX_ARGS 64
#define MAX_PATH 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*
 *  Structure for the info_t type used in error handling and state management
 */
typedef struct {
	char *fname;
	char **argv;
	int line_count;
	int exit_status;
	char *input_line;
	char **env;
} info_t;

/*
 *  Function prototypes
 */
char **parse_input(char *input);

int execute_command(char **args, info_t *info);

int _strcmp(const char *s1, const char *s2);

char *_strdup(const char *str);

char *_strtok_r(char *str, const char *delim, char **saveptr);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *expand_variables(char *command, info_t *info);

char *_getenv(const char *name, char **env);

int _strlen(const char *s);

char *_itoa(int value, char *str, int base);

void print_error(info_t *info, char *estr);

/*
 *  Input handlers
 */
char *read_line(void);

char **parse_input(char *input);

/*
 *  Execution
 */
int execute_command(char **args, info_t *info);

char *find_command(char *command);

int fork_command(char **args, info_t *info);

/*
 *  Builtins
 */
int builtin_exit(char **args, info_t *info);

int builtin_env(char **args, info_t *info);

int builtin_setenv(char **args, info_t *info);

int builtin_unsetenv(char **args, info_t *info);

int builtin_cd(char **args, info_t *info);

int builtin_alias(char **args, info_t *info);

int builtin_handler(char **args, info_t *info);

/*
 *  Helpers
 */
/*
 *  String helpers
 */
int _strlen(const char *s);

int _strcmp(const char *s1, const char *s2);

int _strncmp(const char *s1, const char *s2, size_t n);

char *_strdup(const char *str);

char *_strcat(char *dest, const char *src);

char *_strchr(char *s, char c);

char *_strcpy(char *dest, const char *src);

size_t _strspn(const char *s, const char *accept);

size_t _strcspn(const char *s, const char *reject);

/*
 *  Memory helpers
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void *_memset(void *s, int b, unsigned int n);

void ffree(char **pp);

/*
 *  Error handling functions
 */
int error_cd(info_t *info, int error_type, const char *dir);

void _eputs(const char *str);

int _eputchar(char c);

int print_d(int input, int fd);

void print_error(info_t *info, char *estr);

/*
 *  Advanced features
 */
/*
 *  Logical operators
 */
int execute_logical_ops(char **commands, int num_commands, info_t *info);

char **split_logical_ops(char *input, int *num_commands);
void free_commands(char **commands, int num_commands);

/*
 *  Variable expansion
 */
char *expand_variables(char *command, info_t *info);

/*
 *  Comment handler
 */
char *remove_comments(char *command);

/*
 *  File input
 */
int execute_file(const char *filename, info_t *info);

/*
 *  Environment variable handlers
 */
char *_getenv(const char *name, char **env);

int _setenv(char **env, const char *name, const char *value, int overwrite);

int _unsetenv(char **env, const char *name);

/*
 *  Main loop
 */
void shell_loop(info_t *info);

void free_tokens(char **tokens);
void free_strdup(char *str);
extern char **environ;

#endif /* SHELL_H */
