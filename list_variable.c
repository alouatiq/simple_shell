#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* add_variable_node - Adds a new variable node at the end of the list.
* @head: A pointer to the head of the list.
* @name: The name of the variable.
* @value: The value of the variable.
*
* Description: This function creates a new variable node with the given
* name and value and adds it at the end of the list.
*
* Return: A pointer to the new node, or NULL if it fails.
*/
var_list_t *add_variable_node(var_list_t **head, char *name, char *value)
{
var_list_t *new_node, *temp;

new_node = malloc(sizeof(var_list_t));
if (new_node == NULL)
return (NULL);

new_node->name = _strdup(name);
new_node->value = _strdup(value);
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
}
else
{
temp = *head;
while (temp->next)
temp = temp->next;
temp->next = new_node;
}

return (new_node);
}

/**
* get_variable_node - Retrieves a variable node by name.
* @head: A pointer to the head of the list.
* @name: The name of the variable to retrieve.
*
* Description: This function searches for a variable node by its name
* in the list and returns it if found.
*
* Return: A pointer to the node if found, or NULL if not found.
*/
var_list_t *get_variable_node(var_list_t *head, char *name)
{
var_list_t *temp = head;

while (temp)
{
if (_strcmp(temp->name, name) == 0)
return (temp);
temp = temp->next;
}

return (NULL);
}

/**
* free_variable_list - Frees the entire list of variables.
* @head: A pointer to the head of the list.
*
* Description: This function frees all the nodes in the list, releasing
* the memory allocated for each variable's name and value.
*
* Return: void
*/
void free_variable_list(var_list_t *head)
{
var_list_t *temp;

while (head)
{
temp = head;
head = head->next;
free(temp->name);
free(temp->value);
free(temp);
}
}
