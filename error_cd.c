#include "shell.h"

/**
 * error_cd - Handles various cd command errors
 * @info: The parameter & return info struct
 * @error_type: The type of error encountered
 * @dir: The directory involved in the error (can be NULL)
 *
 * Return: Always returns 0
 */
int error_cd(info_t *info, int error_type, const char *dir)
{
	char *error_msg;

	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": cd: ");

	switch (error_type)
	{
	    case ERR_NO_DIR:
	        error_msg = "can't cd to ";
	        _eputs(error_msg);
	        _eputs(dir); /* dir is already const char *, no need for casting */
	        break;
	    case ERR_PERMISSION:
	        error_msg = "Permission denied";
	        _eputs(error_msg);
	        break;
	    case ERR_HOME_NOT_SET:
	        error_msg = "HOME not set";
	        _eputs(error_msg);
	        break;
	    case ERR_OLDPWD_NOT_SET:
	        error_msg = "OLDPWD not set";
	        _eputs(error_msg);
	        break;
	    case ERR_TOO_MANY_ARGS:
	        error_msg = "too many arguments";
	        _eputs(error_msg);
	        break;
	    default:
	        error_msg = "Unknown error";
	        _eputs(error_msg);
	}

	_eputchar('\n');

	return (0);
}