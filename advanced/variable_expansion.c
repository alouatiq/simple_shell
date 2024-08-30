#include "../shell.h"

/**
 * expand_variables - Expand variables in the command
 * @command: Command string to expand
 * @status: Exit status of the last command
 * Return: Expanded command string
 */
char *expand_variables(char *command, int status)
{
    char *expanded = malloc(MAX_COMMAND_LENGTH);
    char *ptr = command;
    int i = 0;

    while (*ptr)
    {
        if (*ptr == '$' && *(ptr + 1) == '?')
        {
            i += sprintf(expanded + i, "%d", status);
            ptr += 2;
        }
        else if (*ptr == '$' && *(ptr + 1) == '$')
        {
            i += sprintf(expanded + i, "%d", getpid());
            ptr += 2;
        }
        else if (*ptr == '$')
        {
            char var_name[MAX_VAR_NAME];
            int j = 0;
            ptr++;
            while (isalnum(*ptr) || *ptr == '_')
            {
                var_name[j++] = *ptr++;
            }
            var_name[j] = '\0';
            char *value = getenv(var_name);
            if (value)
            {
                i += sprintf(expanded + i, "%s", value);
            }
        }
        else
        {
            expanded[i++] = *ptr++;
        }
    }
    expanded[i] = '\0';

    return (expanded);
}