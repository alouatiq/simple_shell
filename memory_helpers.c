#include "shell.h"
#include <string.h>

/**
 * _realloc - Reallocates a memory block to a new size.
 * @ptr: Pointer to the previous memory block.
 * @old_size: The size of the old memory block.
 * @new_size: The size of the new memory block.
 *
 * Return: (Pointer) to the newly allocated memory block, or (NULL) on failure.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;
    size_t min_size;

    if (new_size == old_size)
        return (ptr);
    if (new_size == 0 && ptr)
    {
        free(ptr);
        return (NULL);
    }
    if (!ptr)
        return (malloc(new_size));

    new_ptr = malloc(new_size);
    if (!new_ptr)
        return (NULL);

    min_size = old_size < new_size ? old_size : new_size;
    memcpy(new_ptr, ptr, min_size);
    free(ptr);
    return (new_ptr);
}

/**
 * _memset - Fills a block of memory with a constant byte.
 * @s: Pointer to the memory block.
 * @c: The byte to fill the memory with.
 * @n: The number of bytes to fill.
 *
 * Return: (Pointer) to the memory block.
 */
void *_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;

    while (n--)
        *ptr++ = (unsigned char)c;
    return (s);
}
