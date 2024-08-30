#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Simple structure to store aliases */
typedef struct alias_s
{
    char *name;
    char *value;
    struct alias_s *next;
} alias_t;

static alias_t *alias_list = NULL;

/* Function to add or update an alias */
int handle_alias(char **args)
{
    alias_t *new_alias, *temp;
    char *name, *value;

    if (args[1] == NULL) /* If no arguments are given, print all aliases */
    {
        temp = alias_list;
        while (temp)
        {
            printf("%s='%s'\n", temp->name, temp->value);
            temp = temp->next;
        }
        return (0);
    }

    for (int i = 1; args[i] != NULL; i++)
    {
        name = strtok(args[i], "=");
        value = strtok(NULL, "=");

        if (value == NULL) /* If only the alias name is given, print its value */
        {
            temp = alias_list;
            while (temp)
            {
                if (strcmp(temp->name, name) == 0)
                {
                    printf("%s='%s'\n", temp->name, temp->value);
                    break;
                }
                temp = temp->next;
            }
        }
        else /* Add or update the alias */
        {
            temp = alias_list;
            while (temp)
            {
                if (strcmp(temp->name, name) == 0)
                {
                    free(temp->value);
                    temp->value = strdup(value);
                    return (0);
                }
                temp = temp->next;
            }

            new_alias = malloc(sizeof(alias_t));
            if (!new_alias)
                return (-1);

            new_alias->name = strdup(name);
            new_alias->value = strdup(value);
            new_alias->next = alias_list;
            alias_list = new_alias;
        }
    }

    return (0);
}

/* Function to replace an alias with its value in a command */
char *replace_alias(char *command)
{
    alias_t *temp = alias_list;

    while (temp)
    {
        if (strcmp(temp->name, command) == 0)
        {
            return (strdup(temp->value));
        }
        temp = temp->next;
    }

    return (command);
}
