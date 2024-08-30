#include "shell.h"
#include <stdlib.h>  /* Required for putenv, malloc, free */
#include <string.h>  /* Required for strlen, strcpy, strcat */

/**
 * handle_exit - Handles the built-in `exit` command.
 * @args: An array of arguments.
 *
 * Task 0.4: Handles built-in commands.
 * Task 0.4.1: Handles `exit` with status.
 */


extern char **environ;

int _setenv(const char *name, const char *value, int overwrite) {
    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    size_t len = name_len + value_len + 2;  /* +2 for '=' and null terminator */
    char *env_var = malloc(len);
    char **envp;

    if (env_var == NULL) {
        return -1;  /* Memory allocation failed */
    }

    /* Check if the variable already exists */
    for (envp = environ; *envp != NULL; ++envp) {
        if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=') {
            if (!overwrite) {
                free(env_var);
                return 0;
            }
            strcpy(*envp + name_len + 1, value);  /* Overwrite existing value */
            free(env_var);
            return 0;
        }
    }

    /* Create new environment variable */
    snprintf(env_var, len, "%s=%s", name, value);

    /* Add the new environment variable to environ */
    for (envp = environ; *envp != NULL; ++envp);
    *envp = env_var;
    *(envp + 1) = NULL;

    return 0;
}

int _unsetenv(const char *name) {
    char **envp;
    size_t name_len = strlen(name);

    /* Locate the environment variable and remove it */
    for (envp = environ; *envp != NULL; ++envp) {
        if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=') {
            /* Shift the rest of the environment variables down */
            char **next_envp = envp;
            do {
                *next_envp = *(next_envp + 1);
                next_envp++;
            } while (*next_envp != NULL);

            break;
        }
    }

    return 0;
}

void handle_exit(char **args) {
    int status = 0;

    if (args[1] != NULL) {
        status = atoi(args[1]);
    }

    exit(status);
}

int handle_setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || value == NULL) {
        perror("setenv");
        return (-1);
    }

    return (_setenv(name, value, overwrite));
}

int handle_unsetenv(const char *name) {
    if (name == NULL) {
        perror("unsetenv");
        return (-1);
    }

    return (_unsetenv(name));
}
