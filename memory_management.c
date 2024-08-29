#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* safe_malloc - Allocates memory and checks if the allocation was successful.
* @size: The size of memory to allocate.
*
* Description: This function allocates memory using malloc and checks if
* the allocation was successful. If not, it exits the program with a
* failure status.
*
* Return: A pointer to the allocated memory, or exits with failure if it fails.
*/
void *safe_malloc(size_t size)
{
void *ptr;

ptr = malloc(size);
if (ptr == NULL)
{
perror("Error: memory allocation failed");
exit(EXIT_FAILURE);
}

return (ptr);
}

/**
* _realloc - Reallocates a memory block to a new size.
* @ptr: A pointer to the memory block previously allocated.
* @old_size: The size in bytes of the allocated space for ptr.
* @new_size: The size in bytes of the new memory block.
*
* Description: This function reallocates a memory block to a new size,
* keeping the content of the original memory block up to the minimum of
* the old and new sizes. If the new size is larger, the added memory is
* not initialized.
*
* Return: A pointer to the reallocated memory block, or NULL if it fails.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;

if (new_size == old_size)
return (ptr);

if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}

if (ptr == NULL)
return (safe_malloc(new_size));

new_ptr = safe_malloc(new_size);
if (new_ptr == NULL)
return (NULL);

_memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
free(ptr);

return (new_ptr);
}

/**
* free_double_ptr - Frees a double pointer (array of pointers).
* @ptr: The double pointer to free.
*
* Description: This function frees each element in the array of pointers
* and then frees the array itself.
*
* Return: void
*/
void free_double_ptr(char **ptr)
{
int i;

if (ptr == NULL)
return;

for (i = 0; ptr[i] != NULL; i++)
free(ptr[i]);

free(ptr);
}

/**
* _memcpy - Copies memory area.
* @dest: The destination memory area.
* @src: The source memory area.
* @n: The number of bytes to copy.
*
* Description: This function copies n bytes from memory area src to
* memory area dest.
*
* Return: A pointer to dest.
*/
void *_memcpy(void *dest, const void *src, unsigned int n)
{
char *d = dest;
const char *s = src;
unsigned int i;

for (i = 0; i < n; i++)
d[i] = s[i];

return (dest);
}
