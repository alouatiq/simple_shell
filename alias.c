#include "shell.h"

typedef struct alias {
    char *name;
    char *value;
    struct alias *next;
} alias_t;

alias_t *alias_list = NULL;

/**
 * handle_alias - Handles the alias command.
 * @args: An array of arguments.
 *
 * Task 1.0: Handles aliases.
 *
 * Return: 0 on success, -1 on failure.
 */
int handle_alias(char **args)
{
    alias_t *temp = alias_list;

    if (args[1] == NULL)
    {
        /* Print all aliases */
        while (temp != NULL)
        {
            printf("%s='%s'\n", temp->name, temp->value);
            temp = temp->next;
        }
    }
    else
    {
        char *name = strtok(args[1], "=");
        char *value = strtok(NULL, "=");

        if (value == NULL)
        {
            /* Print specific alias */
            while (temp != NULL)
            {
                if (strcmp(temp->name, name) == 0)
                {
                    printf("%s='%s'\n", temp->name, temp->value);
                    return (0);
                }
                temp = temp->next;
            }
            return (-1);
        }
        else
        {
            /* Set or update alias */
            alias_t *new_alias = malloc(sizeof(alias_t));
            if (new_alias == NULL)
                return (-1);

            new_alias->name = strdup(name);
            new_alias->value = strdup(value);
            new_alias->next = alias_list;
            alias_list = new_alias;
        }
    }

    return (0);
}
