#include "shell.h"

char *_strdup(const char *str)
{
    int len = strlen(str);
    char *dup = malloc((len + 1) * sizeof(char));

    if (!dup)
        return NULL;

    strcpy(dup, str);
    return dup;
}

int _strcmp(const char *s1, const char *s2)
{
    return strcmp(s1, s2);
}

char *_strcat(char *dest, const char *src)
{
    return strcat(dest, src);
}

char *_strcpy(char *dest, const char *src)
{
    return strcpy(dest, src);
}
