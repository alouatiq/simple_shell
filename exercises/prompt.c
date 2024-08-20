#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * prompt - function that prints a $ untill after getting an argument
 *
 * Return: Void
 */
int main(void)
{
	ssize_t r;
	char *buffer = NULL;
	size_t n = 0;

	printf("$");
	while ((r = (getline(&buffer, &n, stdin))) > 0)
	{
		printf("%s$", buffer);
	}
	free(buffer);
	return (0);
}
