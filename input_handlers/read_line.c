#include "../shell.h"

#define BUFFER_SIZE 1024

/**
 * read_line - Custom getline function
 * Return: Pointer to the line read from stdin
 */
char *read_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_pos = 0;
	static int buf_size = 0;
	char *line = NULL;
	int line_size = 0;
	int line_pos = 0;
	char c;

	while (1)
	{
	    if (buf_pos >= buf_size)
	    {
	        buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	        buf_pos = 0;
	        if (buf_size <= 0)
	        {
	            if (line_size > 0)
	                break;
	            return (NULL);
	        }
	    }

	    c = buffer[buf_pos++];

	    if (line_pos >= line_size)
	    {
	        line_size += 32;
	        line = _realloc(line, line_size, line_size - 32);
	        if (!line)
	        {
	            print_error(NULL, "realloc");
	            exit(EXIT_FAILURE);
	        }
	    }

	    line[line_pos++] = c;

	    if (c == '\n')
	    {
	        line[line_pos - 1] = '\0'; /* Replace newline with null terminator */
	        return (line);
	    }
	}

	return (line);
}