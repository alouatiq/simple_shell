#include "shell.h"

/**
 * shell_non_interactive - Executes commands from a file
 * @filename: The name of the file containing the commands
 *
 * Task 1: Simple Shell 0.1
 *
 * Description: This function processes each line from the file
 * as if it were a command entered interactively.
 */
void shell_non_interactive(char *filename)
{
    int file;
    char *line;
    ssize_t r;

    file = open(filename,O_RDONLY);
    if (file == -1)
    {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
	 line = malloc(100);
	 if (line == NULL)
	 {
		 perror("malloc failed");
		 close(file);
		 exit(-1);
	 }
	 r = read(file, line, 100);
	 if (r == -1)
	 {
		 perror("read failed");
		 free(line);
		 close(file);
		 exit(-1);
	 }
	if (r == 0)
	{
		free(line);
		break;
	}
	line[r] = '\0';
        /* Execute each line as a command */
        execute_command(line);
	free(line);
   }
	close(file); /* Close the file */
}
