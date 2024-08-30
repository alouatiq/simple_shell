#include "../shell.h"

/**
 * is_delim - Check if character is a delimiter
 * @c: Character to check
 * @delims: String of delimiter characters
 * Return: 1 if true, 0 if false
 */
static int is_delim(char c, const char *delims)
{
    while (*delims)
        if (c == *delims++)
            return (1);
    return (0);
}

/**
 * _strtok - Custom strtok function
 * @str: String to tokenize
 * @delims: String of delimiter characters
 * Return: Pointer to the next token or NULL
 */
static char *_strtok(char *str, const char *delims)
{
    static char *p;
    if (str)
        p = str;
    else if (!p)
        return (0);
    str = p + strspn(p, delims);
    p = str + strcspn(str, delims);
    if (p == str)
        return (p = 0);
    p = *p ? *p = 0, p + 1 : 0;
    return (str);
}

/**
 * parse_input - Tokenize and parse user input
 * @input: String to parse
 * Return: Array of strings (tokens)
 */
char **parse_input(char *input)
{
    int bufsize = MAX_ARGS, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = _strtok(input, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = _strdup(token);
        position++;

        if (position >= bufsize)
        {
            bufsize += MAX_ARGS;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = _strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return (tokens);
}