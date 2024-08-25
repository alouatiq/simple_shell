#include "shell.h"

/**
 * my_strtok - Custom implementation of strtok function
 * @str: The string to tokenize
 * @delim: The delimiter characters
 * @tokens: Array to store the tokens
 *
 * Task 7: Simple Shell 0.2.1
 *
 * Description: This function will tokenize the string based on the delimiters.
 */
void my_strtok(char *str, char *delim, char **tokens)
{
   #include "shell.h"

/**
 * my_strtok - Custom implementation of the strtok function
 * @str: The string to be tokenized
 * @delim: The delimiter string used to split the tokens
 * @tokens: An array to store the resulting tokens
 *
 * Description: This function tokenizes a string by splitting it into tokens
 * based on the specified delimiters. It stores the tokens in the provided
 * array. This implementation does not use the standard library's strtok.
 */
void my_strtok(char *str, char *delim, char **tokens)
{
    int i = 0;
    char *token;

    /* If the input string is NULL, return NULL */
    if (str == NULL)
        return;

    /* Get the first token */
    token = strtok(str, delim);

    /* Walk through the rest of the tokens */
    while (token != NULL)
    {
        tokens[i++] = token;
        token = strtok(NULL, delim);
    }

    /* Null-terminate the array of tokens */
    tokens[i] = NULL;
}

}
