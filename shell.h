#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_PATH 1024

/* helpers constants and structures */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Structure for the info_t type used in error handling */
typedef struct {
    char *fname;
    char **argv;
    int line_count;
    /* Add other fields as needed */
} info_t;

/* input_handlers */
char *read_line(void);
char **parse_input(char *input);

/* execution */
int execute_command(char **args);
char *find_command(char *command);
int fork_command(char **args);

/* builtins */
int builtin_handler(char **args);
int builtin_exit(char **args);
int builtin_env(char **args);
int builtin_setenv(char **args);
int builtin_unsetenv(char **args);
int builtin_cd(char **args);
int builtin_alias(char **args);

/* helpers */
/* string_helpers.c */
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);

/* memory_helpers.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_memset(void *s, int b, unsigned int n);
void ffree(char **pp);

/* error_handlers.c */
void _eputs(char *str);
int _eputchar(char c);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);

#endif /* SHELL_H */