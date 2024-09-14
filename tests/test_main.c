#include "../shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *   Function prototypes for test functions
 */
void test_string_helpers (void);

void test_memory_helpers (void);

void test_input_handlers (void);

void test_execution (void);

void test_builtins (void);

void test_advanced_features (void);

int
main (void)
{
	print f ("Running tests for Simple Shell...\n\n");

	test_string_helpers (void);

	test_memory_helpers (void);

	test_input_handlers (void);

	test_execution (void);

	test_builtins (void);

	test_advanced_features (void);

	print f ("\nAll tests completed.\n");

	return ((0));
}

void
test_string_helpers (void)
{
	print f ("Testing string helpers...\n");

	/*
	 *   Add specific tests for string helper functions
	 */
	/*
	 *   Example:
	 */
	char *str = "Hello";

	if (_strlen (str) == 5)
		print f ("  _strlen: PASS\n");

	else
		print f ("  _strlen: FAIL\n");

	/*
	 *   Add more tests...
	 */
	print f ("\n");
}

void
test_memory_helpers (void)
{
	print f ("Testing memory helpers...\n");

	/*
	 *   Add specific tests for memory helper functions
	 */
	/*
	 *   Example:
	 */
	void *ptr = malloc (10);

	void *new_ptr = _realloc (ptr, 10, 20);

	if (new_ptr != NULL && new_ptr != ptr)
		print f ("  _realloc: PASS\n");

	else
		print f ("  _realloc: FAIL\n");

	free (new_ptr);

	/*
	 *   Add more tests...
	 */
	print f ("\n");
}

void
test_input_handlers (void)
{
	print f ("Testing input handlers...\n");

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
		print f ("  parse_input: PASS\n");

	else
		print f ("  parse_input: FAIL\n");

	/*
	 *   Free allocated memory
	 */
	for (int i = 0; args[i] != NULL; i++)
		free (args[i]);

	free (args);

	/*
	 *   Add more tests...
	 */
	print f ("\n");
}

void
test_execution (void)
{
	print f ("Testing execution functions...\n");

	/*
	 *   Add tests for execution functions
	 */
	/*
	 *   Example:
	 */
	char *args[] = { "ls", "-l", "/tmp", NULL };

	int status = execute_command (args);

	if (status == 0)
		print f ("  execute_command: PASS\n");

	else
		print f ("  execute_command: FAIL\n");

	/*
	 *   Add more tests...
	 */
	print f ("\n");
}

void
test_builtins (void)
{
	print f ("Testing builtin commands...\n");

	/*
	 *   Add tests for builtin commands
	 */
	/*
	 *   Example:
	 */
	char *args[] = { "cd", "/tmp", NULL };

	int status = builtin_cd (args);

	if (status == 1 && strcmp (getenv ("PWD"), "/tmp") == 0)
		print f ("  builtin_cd: PASS\n");

	else
		print f ("  builtin_cd: FAIL\n");

	/*
	 *   Add more tests...
	 */
	print f ("\n");
}

void
test_advanced_features (void)
{
	print f ("Testing advanced features...\n");

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
		print f ("  split_logical_ops: PASS\n");

	else
		print f ("  split_logical_ops: FAIL\n");

	/*
	 *   Free allocated memory
	 */
	for (int i = 0; i < num_commands; i++)
		free (commands[i]);

	free (commands);

	/*
	 *   Add more tests...
	 */
	print f ("\n");
}
