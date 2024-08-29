#include "main.h"

/**
 * struct sep_list - Singly linked list for storing command separators
 * @separator: The separator character (; | &)
 * @next: Pointer to the next node
 *
 * Description: This structure is used to store command separators
 * in a linked list, which is useful for parsing complex command lines.
 */
typedef struct sep_list
{
    char separator;
    struct sep_list *next;
} sep_list;

/**
 * add_sep_node_end - Adds a separator node at the end of a sep_list
 * @head: Pointer to the head of the linked list
 * @sep: Separator character to be added (; | &)
 *
 * Description: This function creates a new node containing the given
 * separator and adds it to the end of the sep_list. If the list is empty,
 * the new node becomes the head of the list.
 *
 * Return: Pointer to the head of the list, or NULL if memory allocation fails
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
    sep_list *new, *temp;

    new = malloc(sizeof(sep_list));
    if (new == NULL)
        return (NULL);

    new->separator = sep;
    new->next = NULL;
    temp = *head;

    if (temp == NULL)
    {
        *head = new;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    return (*head);
}

/**
 * free_sep_list - Frees all nodes in a separator list
 * @head: Pointer to the pointer of the head of the linked list
 *
 * This function iterates through the separator list and frees all allocated
 * memory for each node. It's crucial for preventing memory leaks when the
 * list is no longer needed. After freeing all nodes, it sets the head
 * pointer to NULL to indicate an empty list.
 *
 * @head: Double pointer to allow modification of the original head pointer
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - Adds a new command line node at the end of a line_list
 *
 * This function creates a new node containing a command line and appends it
 * to the end of the linked list. If the list is empty, the new node becomes
 * the head of the list.
 *
 * @head: Pointer to the head of the linked list
 * @line: String containing the command line to be added
 *
 * Return: Pointer to the head of the updated list, or NULL if memory allocation fails
 */
line_list *add_line_node_end(line_list **head, char *line)
{
    line_list *new, *temp;

    new = malloc(sizeof(line_list));
    if (new == NULL)
        return (NULL);

    new->line = line;
    new->next = NULL;
    temp = *head;

    if (temp == NULL)
    {
        *head = new;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }

    return (*head);
}

/**
 * free_line_list - Frees all nodes in a line_list and sets the head to NULL
 * @head: Pointer to the head of the linked list
 *
 * This function iterates through the line_list, freeing each node
 * and its associated memory. It's crucial for preventing memory leaks
 * when the list is no longer needed. After freeing all nodes, it sets
 * the head pointer to NULL to indicate an empty list.
 *
 * @head: Double pointer to the head of the list, allowing modification
 *        of the original head pointer
 *
 * Return: void
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
