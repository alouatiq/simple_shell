#include "shell.h"

/**
 * change_directory - Implements the cd built-in command
 * @path: The path to change to
 *
 * Task 10: cd
 *
 * Description: This function changes the current directory of the process.
 */
void change_directory(char *path)
{
    if (path == NULL)
        path = getenv("HOME"); /* Default to home directory */

    if (chdir(path) == -1) {
        perror("cd");
    } else {
        /* Update PWD environment variable */
        setenv("PWD", getcwd(NULL, 0), 1);
    }
}
