#include "../shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test_builtins (void)
{
	print f ("Testing builtin commands...\n");

	/*
	 *   Test exit builtin
	 */
	char *exit_args[] = { "exit", NULL };

	if (builtin_exit (exit_args) == 0)
		print f ("  builtin_exit: PASS\n");

	else
		print f ("  builtin_exit: FAIL\n");

	/*
	 *   Test env builtin
	 */
	char *env_args[] = { "env", NULL };

	if (builtin_env (env_args) == 1)
		print f ("  builtin_env: PASS\n");

	else
		print f ("  builtin_env: FAIL\n");

	/*
	 *   Test cd builtin
	 */
	char *cd_args[] = { "cd", "/tmp", NULL };

	if (builtin_cd (cd_args) == 1 && strcmp (getenv ("PWD"), "/tmp") == 0)
		print f ("  builtin_cd: PASS\n");

	else
		print f ("  builtin_cd: FAIL\n");

	/*
	 *   Test setenv builtin
	 */
	char *setenv_args[] = { "setenv", "TEST_VAR", "test_value", NULL };

	if (builtin_setenv (setenv_args) == 1
	    && strcmp (getenv ("TEST_VAR"), "test_value") == 0)
		print f ("  builtin_setenv: PASS\n");

	else
		print f ("  builtin_setenv: FAIL\n");

	/*
	 *   Test unsetenv builtin
	 */
	char *unsetenv_args[] = { "unsetenv", "TEST_VAR", NULL };

	if (builtin_unsetenv (unsetenv_args) == 1
	    && getenv ("TEST_VAR") == NULL)
		print f ("  builtin_unsetenv: PASS\n");

	else
		print f ("  builtin_unsetenv: FAIL\n");

	print f ("\n");
}
