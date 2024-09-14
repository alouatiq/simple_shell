#include "../shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test_advanced_features (void)
{
	print f ("Testing advanced features...\n");

	/*
	 *   Test logical operators
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
	 *   Test variable expansion
	 */
	char *expanded = expand_variables ("Echo $? and $$", 0);

	if (strstr (expanded, "Echo 0 and") != NULL)
		print f ("  expand_variables: PASS\n");

	else
		print f ("  expand_variables: FAIL\n");

	free (expanded);

	/*
	 *   Test comment handling
	 */
	char comment_input[] = "echo Hello # This is a comment";

	char *no_comment = remove_comments (comment_input);

	if (strcmp (no_comment, "echo Hello ") == 0)
		print f ("  remove_comments: PASS\n");

	else
		print f ("  remove_comments: FAIL\n");

	/*
	 *   Test file input (this test assumes you have a test script file)
	 */
	if (execute_file ("test_script.sh") == 0)
		print f ("  execute_file: PASS\n");

	else
		print f ("  execute_file: FAIL\n");

	print f ("\n");
}
