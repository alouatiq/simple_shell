#include "../shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Function prototypes for test functions
 */
void test_string_helpers ();

void test_memory_helpers ();

void test_input_handlers ();

void test_execution ();

void test_builtins ();

void test_advanced_features ();

int
main ()
{
	printf ("Running tests for Simple Shell...\n\n");

	test_string_helpers ();

	test_memory_helpers ();

	test_input_handlers ();

	test_execution ();

	test_builtins ();

	test_advanced_features ();

	printf ("\nAll tests completed.\n");

	return ((0));
}

void
test_string_helpers ()
{
	printf ("Testing string helpers...\n");

	/*
	 *   Add specific tests for string helper functions
	 */
	/*
	 *   Example:
	 */
	char *str = "Hello";

	if (_strlen (str) == 5)
		printf ("  _strlen: PASS\n");

	else
		printf ("  _strlen: FAIL\n");

	/*
	 *   Add more tests...
	 */
	printf ("\n");
}

void
test_memory_helpers ()
{
	printf ("Testing memory helpers...\n");

	/*
	 *   Add specific tests for memory helper functions
	 */
	/*
	 *   Example:
	 */
	void *ptr = malloc (10);

	void *new_ptr = _realloc (ptr, 10, 20);

	if (new_ptr != NULL && new_ptr != ptr)
		printf ("  _realloc: PASS\n");

	else
		printf ("  _realloc: FAIL\n");

	free (new_ptr);

	/*
	 *   Add more tests...
	 */
	printf ("\n");
}

void
test_input_handlers ()
{
	printf ("Testing input handlers...\n");

	/*
	 *   Add tests for input handling functions
	 */
	/*
	 *   Example:
	 */
	char input[] = "ls -l /tmp";

	char **args = parse_input (input);

	if (args != NULL && strcmp (args[0], "ls") == 0
	    && strcmp (args[1], "-l") == 0 && strcmp (args[2], "/tmp") == 0)
		printf ("  parse_input: PASS\n");

	else
		printf ("  parse_input: FAIL\n");

	/*
	 *   Free allocated memory
	 */
	for (int i = 0; args[i] != NULL; i++)
		free (args[i]);

	free (args);

	/*
	 *   Add more tests...
	 */
	printf ("\n");
}

void
test_execution ()
{
	printf ("Testing execution functions...\n");

	/*
	 *   Add tests for execution functions
	 */
	/*
	 *   Example:
	 */
	char *args[] = { "ls", "-l", "/tmp", NULL };

	int status = execute_command (args);

	if (status == 0)
		printf ("  execute_command: PASS\n");

	else
		printf ("  execute_command: FAIL\n");

	/*
	 *   Add more tests...
	 */
	printf ("\n");
}

void
test_builtins ()
{
	printf ("Testing builtin commands...\n");

	/*
	 *   Add tests for builtin commands
	 */
	/*
	 *   Example:
	 */
	char *args[] = { "cd", "/tmp", NULL };

	int status = builtin_cd (args);

	if (status == 1 && strcmp (getenv ("PWD"), "/tmp") == 0)
		printf ("  builtin_cd: PASS\n");

	else
		printf ("  builtin_cd: FAIL\n");

	/*
	 *   Add more tests...
	 */
	printf ("\n");
}

void
test_advanced_features ()
{
	printf ("Testing advanced features...\n");

	/*
	 *   Add tests for advanced features
	 */
	/*
	 *   Example:
	 */
	char input[] = "echo Hello && echo World";

	int num_commands;

	char **commands = split_logical_ops (input, &num_commands);

	if (num_commands == 3 && strcmp (commands[1], "&&") == 0)
		printf ("  split_logical_ops: PASS\n");

	else
		printf ("  split_logical_ops: FAIL\n");

	/*
	 *   Free allocated memory
	 */
	for (int i = 0; i < num_commands; i++)
		free (commands[i]);

	free (commands);

	/*
	 *   Add more tests...
	 */
	printf ("\n");
}
