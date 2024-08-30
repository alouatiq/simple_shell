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


int _setenv(const char *name, const char *value, int overwrite) {
    char *env_var;
    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    size_t len = name_len + value_len + 2; /* +2 for '=' and null terminator */

    /* Check if the variable exists */
    env_var = getenv(name);
    if (env_var != NULL && !overwrite) {
        return 0; /* Do not overwrite existing variable */
    }

    /* Allocate memory for the new environment variable */
    env_var = malloc(len);
    if (env_var == NULL) {
        return -1; /* Memory allocation failed */
    }

    /* Create the environment variable */
    strcpy(env_var, name);
    strcat(env_var, "=");
    strcat(env_var, value);

    /* Add or modify the environment variable */
    if (putenv(env_var) != 0) {
        free(env_var);
        return -1; /* putenv failed */
    }

    return 0;
}

int _unsetenv(const char *name) {
    char **envp = environ;
    size_t name_len = strlen(name);

    while (*envp != NULL) {
        if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=') {
            char **next_envp = envp;

            /* Shift remaining environment variables down */
            do {
                *next_envp = *(next_envp + 1);
                next_envp++;
            } while (*next_envp != NULL);

            break;
        }
        envp++;
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

    return (_setenv(name, value, overwrite)); /* Use custom _setenv */
}

int handle_unsetenv(const char *name) {
    if (name == NULL) {
        perror("unsetenv");
        return (-1);
    }

    return (_unsetenv(name)); /* Use custom _unsetenv */
}
