#include "shell.h"

/**
 * free_all - Function that frees all buffers
 * @buffer1: First buffer to be free
 * @buffer2: Second buffer to be freed
 * @buffer3: Third buffer to be freed
 *
 * Return: void
 */
void free_all(char **buffer1, char **buffer2, char *buffer3)
{
	int i;

	if (buffer1)
	{
		for(i = 0; buffer1[i] != NULL; i++)
			free(buffer1[i]);
		free(buffer1);
	}

	if (buffer2)
	{
		for(i = 0; buffer2[i] != NULL; i++)
			free(buffer2[i]);
		free(buffer2);
	}

	if (buffer3)
		free(buffer3);
}
