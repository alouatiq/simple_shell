#include "../shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test_string_helpers ()
{
	printf ("Testing string helpers...\n");

	/*
	 *   Test _strlen
	 */
	char *str = "Hello, World!";

	if (_strlen (str) == 13)
		printf ("  _strlen: PASS\n");

	else
		printf ("  _strlen: FAIL\n");

	/*
	 *   Test _strcmp
	 */
	if (_strcmp ("hello", "hello") == 0 && _strcmp ("hello", "world") < 0)
		printf ("  _strcmp: PASS\n");

	else
		printf ("  _strcmp: FAIL\n");

	/*
	 *   Test _strdup
	 */
	char *dup = _strdup (str);

	if (dup != NULL && strcmp (dup, str) == 0)
		printf ("  _strdup: PASS\n");

	else
		printf ("  _strdup: FAIL\n");

	free (dup);

	/*
	 *   Test _strcat
	 */
	char dest[20] = "Hello, ";

	_strcat (dest, "World!");

	if (strcmp (dest, "Hello, World!") == 0)
		printf ("  _strcat: PASS\n");

	else
		printf ("  _strcat: FAIL\n");

	printf ("\n");
}
