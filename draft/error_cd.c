#include "shell.h"

/**
	* print_error_prefix - Prints the error prefix
	* @info: The parameter & return info struct
	*/
static void print_error_prefix(info_t *info)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": cd: ");
}

/**
	* print_error_message - Prints the error message
	* @error_msg: The error message to print
	* @dir: The directory involved in the error (can be NULL)
	*/
static void print_error_message(const char *error_msg, const char *dir)
{
	_eputs(error_msg);
	if (dir)
	_eputs(dir);
	_eputchar('\n');
}

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
	print_error_prefix(info);

	switch (error_type)
	{
	case ERR_NO_DIR:
	print_error_message("can't cd to ", dir);
	break;
	case ERR_PERMISSION:
	print_error_message("Permission denied", NULL);
	break;
	case ERR_HOME_NOT_SET:
	print_error_message("HOME not set", NULL);
	break;
	case ERR_OLDPWD_NOT_SET:
	print_error_message("OLDPWD not set", NULL);
	break;
	case ERR_TOO_MANY_ARGS:
	print_error_message("too many arguments", NULL);
	break;
	default:
	print_error_message("Unknown error", NULL);
	}

	return (0);
}
