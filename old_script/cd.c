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
	static char *formal_working_dir;
	char *wd;

	if (path == NULL)
		path = getenv("HOME"); /* Default to home directory */

	else if (_strcmp(path, "-") == 0)
	{
		if (formal_working_dir != NULL) /*never been changed*/
			path = formal_working_dir;
		else
		{
			perror("cd failed: Your are in the root");
			return;
		}
	}
	else
	{
		/*updating the formal_working_dir with pwd before cd*/
		wd = getcwd(NULL, 0);

		if (wd != NULL)
		{
			if (formal_working_dir != NULL)
				free(formal_working_dir);
			formal_working_dir = wd;
		}
	}
	if (chdir(path) == -1)
		perror("cd failed");
	else
	{
		wd = getcwd(NULL, 0);

		if (wd != NULL)
		{
			setenv("PWD", wd, 1);
			free(wd);
		}
	}
}
