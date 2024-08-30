#include "main.h"

/**
 * cd_error_no_dir - Handles error when directory doesn't exist
 * @dir: The directory that was not found
 *
 * This function prints an error message when the specified directory
 * for the cd command does not exist or is not accessible.
 */
void cd_error_no_dir(const char *dir)
{
    char *error_msg = "cd: can't cd to ";
    write(STDERR_FILENO, error_msg, _strlen(error_msg));
    write(STDERR_FILENO, dir, _strlen(dir));
    write(STDERR_FILENO, "\n", 1);
}

/**
 * cd_error_permission - Handles error when user lacks permission
 * @dir: The directory that the user can't access
 *
 * This function prints an error message when the user doesn't have
 * permission to access the specified directory for the cd command.
 */
void cd_error_permission(const char *dir)
{
    char *error_msg = "cd: permission denied: ";
    write(STDERR_FILENO, error_msg, _strlen(error_msg));
    write(STDERR_FILENO, dir, _strlen(dir));
    write(STDERR_FILENO, "\n", 1);
}

/**
 * cd_error_home_not_set - Handles error when HOME is not set
 *
 * This function prints an error message when the cd command is used
 * without arguments and the HOME environment variable is not set.
 */
void cd_error_home_not_set(void)
{
    char *error_msg = "cd: HOME not set\n";
    write(STDERR_FILENO, error_msg, _strlen(error_msg));
}

/**
 * cd_error_oldpwd_not_set - Handles error when OLDPWD is not set
 *
 * This function prints an error message when the cd - command is used
 * and the OLDPWD environment variable is not set.
 */
void cd_error_oldpwd_not_set(void)
{
    char *error_msg = "cd: OLDPWD not set\n";
    write(STDERR_FILENO, error_msg, _strlen(error_msg));
}

/**
 * cd_error_too_many_args - Handles error when too many arguments are provided
 *
 * This function prints an error message when the cd command is used
 * with too many arguments.
 */
void cd_error_too_many_args(void)
{
    char *error_msg = "cd: too many arguments\n";
    write(STDERR_FILENO, error_msg, _strlen(error_msg));
}
