#include "shell.h"
#include <stdio.h>
/**
 * print_env - Prints the current environment variables
 * Task 5: Simple Shell 1.0
 * Description: This function prints all the environment variables.
 */
void print_env(void)
{
    extern char **environ; /* Access the environment variables */
    char **env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}
