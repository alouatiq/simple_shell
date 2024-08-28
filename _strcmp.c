#include "shell.h"

/**
 * _strcmp - Function that compares two strings
 * @first: first string
 * @second: The second string
 *
 * Return: 0 if strings are itentical -1 if second < first and 1 for reverse
 */
int _strcmp(char *first, char *second)
{
	int i;
	char *f, *s;

	f = first;
	s = second;
	i = 0;

	while (f[i] != '\0' && s[i])
	{
		if (first[i] != second[i])
			return ((first[i] < second[i]) ? -1 : 1);
		i++;
	}
	if (f[i] != '\0')
		return (1);
	else if (s[i] != '\0')
		return (-1);
	return (0);
}
int main(void)
{
	printf("%d", _strcmp("vasitha", "vasitha"));
	printf("%d", _strcmp("vasitha", "vasitha123"));
	printf("%d", _strcmp("vasitha123", "vasitha"));
	printf("%d", _strcmp("vasitha", "Felsimbom"));
	printf("%d", _strcmp("vasitha", "vasiros"));
	return (0);
}
