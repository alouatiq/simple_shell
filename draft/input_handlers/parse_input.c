#include "../shell.h"

/**
	* _strtok - Custom strtok function
	* @str: String to tokenize
	* @delims: String of delimiter characters
	* Return: Pointer to the next token or NULL
	*/
static char *
_strtok(char *str, const char *delims)
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
char **
parse_input(char *input)
{
	int bufsize = MAX_ARGS, position = 0, i;
	char **tokens = NULL;
	char *token = NULL;
	char *input_copy = NULL;
	char **new_tokens = NULL;

	tokens = malloc(bufsize * sizeof(char *));
	input_copy = _strdup(input);

	if (!tokens || !input_copy)
	{
	free_strdup(input_copy);
	free(tokens);
	print_error(NULL, "allocation error");
	return NULL;
	}

	token = _strtok(input_copy, " \t\r\n\a");
	while (token != NULL)
	{
	tokens[position] = _strdup(token);
	if (!tokens[position])
	{
	print_error(NULL, "allocation error");
	for (i = 0; i < position; i++)
	free_strdup(tokens[i]);
	free(tokens);
	free_strdup(input_copy);
	return NULL;
	}
	position++;

	if (position >= bufsize)
	{
	bufsize += MAX_ARGS;
	new_tokens = _realloc(tokens, bufsize * sizeof(char *),
	(bufsize - MAX_ARGS) * sizeof(char *));
	if (!new_tokens)
	{
	print_error(NULL, "allocation error");
	for (i = 0; i < position; i++)
	free_strdup(tokens[i]);
	free(tokens);
	free_strdup(input_copy);
	return NULL;
	}
	tokens = new_tokens;
	}
	token = _strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	free_strdup(input_copy);
	return tokens;
}

/**
	* free_tokens - Free memory allocated for tokens
	* @tokens: Array of strings to free
	*/
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
	return;

	for (i = 0; tokens[i] != NULL; i++)
	{
	free_strdup(tokens[i]);
	}
	free(tokens);
}
