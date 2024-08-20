#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * strsplit - program that splits sentence to different words
 *
 * Return: Null
 */
int main(int argc, char **argv)
{
	char *str;
	char *tocken;

	if (argc != 2)
	{
		printf("Usage: %s <sentence>\n", argv[0]);
		return (1);
	}
	str = strdup(argv[1]);

	if (str == NULL)
	{
		perror("strdup failed");
		return(1);
	}
	tocken = strtok(str, " ");

	while (tocken != NULL)
	{
		printf("%s\n", tocken);
		tocken = strtok(NULL, " ");
	}
	free(str);
	return (0);
}
