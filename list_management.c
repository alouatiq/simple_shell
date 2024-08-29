#include "shell.h"
#include <stdio.h>     /* For standard I/O functions */
#include <stdlib.h>    /* For general utilities like malloc, free, getenv, etc. */
#include <string.h>    /* For string manipulation functions like strcpy, strlen, etc. */
#include <unistd.h>    /* For system calls like execve, fork, chdir, etc. */
#include <sys/types.h> /* For types like pid_t */
#include <sys/stat.h>  /* For file status functions like stat */
#include <limits.h>    /* For limits like PATH_MAX */

/**
* add_node - Adds a new node at the beginning of a linked list.
* @head: A pointer to the head of the list.
* @str: The string to be included in the new node.
*
* Return: The address of the new element, or NULL if it failed.
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = _strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

new_node->len = _strlen(str);
new_node->next = *head;
*head = new_node;

return (new_node);
}

/**
* add_node_end - Adds a new node at the end of a linked list.
* @head: A pointer to the head of the list.
* @str: The string to be included in the new node.
*
* Return: The address of the new element, or NULL if it failed.
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node, *temp;

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = _strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

new_node->len = _strlen(str);
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
* free_list - Frees a linked list.
* @head: A pointer to the head of the list to be freed.
*
* Return: void
*/
void free_list(list_t *head)
{
list_t *temp;

while (head)
{
temp = head->next;
free(head->str);
free(head);
head = temp;
}
}

/**
* list_len - Counts the number of elements in a linked list.
* @h: The linked list to be counted.
*
* Return: The number of elements in the list.
*/
size_t list_len(const list_t *h)
{
size_t count = 0;

while (h)
{
count++;
h = h->next;
}

return (count);
}
