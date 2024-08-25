#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Define a simple structure to hold alias data */
typedef struct alias {
    char *name;
    char *value;
    struct alias *next;
} alias_t;

alias_t *alias_list = NULL;

/**
 * set_alias - Adds or updates an alias
 * @name: The name of the alias
 * @value: The command the alias represents
 *
 * Description: This function adds a new alias or updates an existing alias.
 */
void set_alias(char *name, char *value)
{
    alias_t *current = alias_list;

    /* Check if alias already exists and update it */
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            free(current->value);
            current->value = strdup(value);
            return;
        }
        current = current->next;
    }

    /* Create a new alias if it doesn't exist */
    alias_t *new_alias = malloc(sizeof(alias_t));
    if (!new_alias) {
        perror("malloc");
        return;
    }
    new_alias->name = strdup(name);
    new_alias->value = strdup(value);
    new_alias->next = alias_list;
    alias_list = new_alias;
}

/**
 * print_alias - Prints a single alias in the form name='value'
 * @alias: The alias to print
 */
void print_alias(alias_t *alias)
{
    printf("%s='%s'\n", alias->name, alias->value);
}

/**
 * get_alias - Retrieves an alias by name
 * @name: The name of the alias to retrieve
 *
 * Return: The alias structure, or NULL if not found.
 */
alias_t *get_alias(char *name)
{
    alias_t *current = alias_list;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }

    return NULL;
}

/**
 * print_all_aliases - Prints all aliases
 */
void print_all_aliases(void)
{
    alias_t *current = alias_list;

    while (current != NULL) {
        print_alias(current);
        current = current->next;
    }
}

/**
 * handle_alias - Implements the alias built-in command
 * @args: The arguments passed to the alias command
 *
 * Description: This function handles the `alias` built-in command, which can
 * create new aliases, display specific aliases, or list all aliases.
 */
void handle_alias(char **args)
{
    int i;
    char *name, *value;
    alias_t *alias;

    if (args[1] == NULL) {
        /* No arguments: print all aliases */
        print_all_aliases();
        return;
    }

    for (i = 1; args[i] != NULL; i++) {
        name = strtok(args[i], "=");
        value = strtok(NULL, "");

        if (value != NULL) {
            /* If value is provided, set or update the alias */
            set_alias(name, value);
        } else {
            /* If no value is provided, print the alias */
            alias = get_alias(name);
            if (alias != NULL)
                print_alias(alias);
        }
    }
}
