#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>

typedef struct builtin_s
{
char *name;
int (*func)(char **args, char **env);
} builtin_t;

extern char *_getenv(const char *name);
extern int _setenv(const char *name, const char *value, int overwrite);
extern int _unsetenv(const char *name);
extern void _puts(const char *str);

#endif /* SHELL_H */
