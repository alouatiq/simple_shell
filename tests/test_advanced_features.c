#include "../shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test_advanced_features ()
{
	printf ("Testing advanced features...\n");

	/*
	 *   Test logical operators
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
	 *   Test variable expansion
	 */
	char *expanded = expand_variables ("Echo $? and $$", 0);

	if (strstr (expanded, "Echo 0 and") != NULL)
		printf ("  expand_variables: PASS\n");

	else
		printf ("  expand_variables: FAIL\n");

	free (expanded);

	/*
	 *   Test comment handling
	 */
	char comment_input[] = "echo Hello # This is a comment";

	char *no_comment = remove_comments (comment_input);

	if (strcmp (no_comment, "echo Hello ") == 0)
		printf ("  remove_comments: PASS\n");

	else
		printf ("  remove_comments: FAIL\n");

	/*
	 *   Test file input (this test assumes you have a test script file)
	 */
	if (execute_file("test_script.sh", &info) == 0)
		printf ("  execute_file: PASS\n");

	else
		printf ("  execute_file: FAIL\n");

	printf ("\n");
}
