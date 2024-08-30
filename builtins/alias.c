#include "../shell.h"

#define MAX_ALIASES 100

typedef struct {
    char *name;
    char *value;
} alias_t;

static alias_t aliases[MAX_ALIASES];
static int alias_count = 0;

/**
 * print_alias - Print a single alias
 * @alias: Alias to print
 */
void print_alias(alias_t *alias)
{
    printf("%s='%s'\n", alias->name, alias->value);
}

/**
 * find_alias - Find an alias by name
 * @name: Name of the alias to find
 * Return: Pointer to the alias if found, NULL otherwise
 */
alias_t *find_alias(const char *name)
{
    for (int i = 0; i < alias_count; i++)
    {
        if (strcmp(aliases[i].name, name) == 0)
            return &aliases[i];
    }
    return NULL;
}

/**
 * set_alias - Set or update an alias
 * @name: Name of the alias
 * @value: Value of the alias
 */
void set_alias(const char *name, const char *value)
{
    alias_t *existing = find_alias(name);
    if (existing)
    {
        free(existing->value);
        existing->value = strdup(value);
    }
    else if (alias_count < MAX_ALIASES)
    {
        aliases[alias_count].name = strdup(name);
        aliases[alias_count].value = strdup(value);
        alias_count++;
    }
    else
    {
        fprintf(stderr, "alias: too many aliases\n");
    }
}

/**
 * builtin_alias - Implements the alias builtin command
 * @args: Arguments
 * Return: Always returns 1 to continue executing
 */
int builtin_alias(char **args)
{
    if (!args[1])
    {
        for (int i = 0; i < alias_count; i++)
            print_alias(&aliases[i]);
    }
    else
    {
        for (int i = 1; args[i]; i++)
        {
            char *equals = strchr(args[i], '=');
            if (equals)
            {
                *equals = '\0';
                set_alias(args[i], equals + 1);
            }
            else
            {
                alias_t *alias = find_alias(args[i]);
                if (alias)
                    print_alias(alias);
                else
                    fprintf(stderr, "alias: %s not found\n", args[i]);
            }
        }
    }
    return (1);
}