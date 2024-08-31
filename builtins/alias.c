#include "../shell.h"

#define MAX_ALIASES 100

typedef struct {
	char *name;
	char *value;
} alias_t;

alias_t aliases[MAX_ALIASES];
int alias_count = 0;

/**
 * find_alias - Find an alias by name
 * @name: Name of the alias to find
 * Return: Pointer to the alias if found, NULL otherwise
 */
alias_t *find_alias(const char *name)
{
	int i;
	for (i = 0; i < alias_count; i++)
	{
	    if (_strcmp(aliases[i].name, name) == 0)
	    {
	        return &aliases[i];
	    }
	}
	return (NULL);
}

/**
 * print_alias - Print an alias
 * @alias: Pointer to the alias to print
 */
void print_alias(const alias_t *alias)
{
	printf("%s='%s'\n", alias->name, alias->value);
}

/**
 * add_alias - Add or update an alias
 * @name: Name of the alias
 * @value: Value of the alias
 * Return: 0 on success, -1 on failure
 */
int add_alias(const char *name, const char *value)
{
	alias_t *existing = find_alias(name);
	if (existing)
	{
	    /* Update existing alias */
	    free(existing->value);
	    existing->value = _strdup(value);
	    return (existing->value ? 0 : -1);
	}
	else if (alias_count < MAX_ALIASES)
	{
	    /* Add new alias */
	    aliases[alias_count].name = _strdup(name);
	    aliases[alias_count].value = _strdup(value);
	    if (aliases[alias_count].name && aliases[alias_count].value)
	    {
	        alias_count++;
	        return (0);
	    }
	    /* Clean up if allocation failed */
	    free(aliases[alias_count].name);
	    free(aliases[alias_count].value);
	}
	return (-1);
}

/**
 * builtin_alias - Handle the alias builtin command
 * @args: Arguments passed to the alias command
 * @info: Shell info structure
 * Return: 0 on success, 1 on failure
 */
int builtin_alias(char **args, info_t *info)
{
	int i;
	char *equals_sign;

	if (args[1] == NULL)
	{
	    /* Print all aliases */
	    for (i = 0; i < alias_count; i++)
	    {
	        print_alias(&aliases[i]);
	    }
	}
	else
	{
	    for (i = 1; args[i]; i++)
	    {
	        equals_sign = _strchr(args[i], '=');
	        if (equals_sign)
	        {
	            /* Define a new alias */
	            *equals_sign = '\0';
	            if (add_alias(args[i], equals_sign + 1) == -1)
	            {
	                print_error(info, "Failed to add alias");
	                return (1);
	            }
	        }
	        else
	        {
	            /* Print specific alias */
	            alias_t *alias = find_alias(args[i]);
	            if (alias)
	            {
	                print_alias(alias);
	            }
	            else
	            {
	                print_error(info, "Alias not found");
	                return (1);
	            }
	        }
	    }
	}
	return (0);
}