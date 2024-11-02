#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_len;
	int status = 1;

	while (status)
	{
	if (isatty(STDIN_FILENO))
	printf("$ ");
	read_len = getline(&line, &len, stdin);
	if (read_len == -1)
	{
	free(line);
	break;
	}
	line[read_len - 1] = '\0'; /* Remove newline character */
	status = execute_line(line);
	}
	free(line);
	return 0;
}
