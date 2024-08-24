#include "shell.h"

/**
 * free_all - Function that frees all buffers
 * @buffer1: First buffer to be free
 * @buffer2: Second buffer to be freed
 * @buffer3: Third buffer to be freed
 *
 * Return: void
 */
void free_all(char *buffer1, char *buffer2, char *buffer3)
{
	if (buffer1)
		free(buffer1);

	if (buffer2)
		free(buffer2);

	if (buffer3)
		free(buffer3);
}
