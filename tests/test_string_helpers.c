#include "../shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test_string_helpers (void)
{
	print f ("Testing string helpers...\n");

	/*
	 *   Test _strlen
	 */
	char *str = "Hello, World!";

	if (_strlen (str) == 13)
		print f ("  _strlen: PASS\n");

	else
		print f ("  _strlen: FAIL\n");

	/*
	 *   Test _strcmp
	 */
	if (_strcmp ("hello", "hello") == 0 && _strcmp ("hello", "world") < 0)
		print f ("  _strcmp: PASS\n");

	else
		print f ("  _strcmp: FAIL\n");

	/*
	 *   Test _strdup
	 */
	char *dup = _strdup (str);

	if (dup != NULL && strcmp (dup, str) == 0)
		print f ("  _strdup: PASS\n");

	else
		print f ("  _strdup: FAIL\n");

	free (dup);

	/*
	 *   Test _strcat
	 */
	char dest[20] = "Hello, ";

	_strcat (dest, "World!");

	if (strcmp (dest, "Hello, World!") == 0)
		print f ("  _strcat: PASS\n");

	else
		print f ("  _strcat: FAIL\n");

	print f ("\n");
}
