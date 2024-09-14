#include "../shell.h"

/**
 * _realloc - Reallocate a memory block
 * @ptr: Point er to the memory previously allocated
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the new memory block
 * Return: Point er to the newly allocated memory, or NULL if it fails
 */
void *
_realloc (void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	unsigned int i;

	if (new_size == old_size)
		return ((ptr));

	if (ptr == NULL)
	{
		new_ptr = malloc (new_size);

		if (new_ptr == NULL)
			return (((NULL)));

		return ((new_ptr));
	}

	if (new_size == 0 && ptr != NULL)
	{
		free (ptr);

		return (((NULL)));
	}

	new_ptr = malloc (new_size);

	if (new_ptr == NULL)
		return (((NULL)));

	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = ((char *)ptr)[i];

	free (ptr);

	return ((new_ptr));
}

/**
 * _memset - Fill memory with a constant byte
 * @s: Memory area to fill
 * @b: Constant byte to fill with
 * @n: Number of bytes to fill
 * Return: Point er to the memory area s
 */
void *
_memset (void *s, int b, unsigned int n)
{
	unsigned char *p = s;

	while (n--)
		*p++ = (unsigned char)b;

	return (((s)));
}

/**
 * ffree - Free a string of strings
 * @pp: String of strings
 */
void
ffree (char **pp)
{
	char **a = pp;

	if (!pp)
		return;

	while (*pp)
		free (*pp++);

	free (a);
}
