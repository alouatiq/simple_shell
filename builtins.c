#include "shell.h"

/* Task 4: Implement Built-in exit */
/* Task 5: Implement Built-in env */
/* Task 9: Implement setenv and unsetenv */
/* Task 10: Implement cd Command */

void print_env(void)
{
    extern char **environ;
    char **env = environ;

    while (*env)
    {
        write(STDOUT_FILENO, *env, strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
        env++;
    }
}

/* Additional built-in commands (e.g., setenv, unsetenv, cd) can be added here */
