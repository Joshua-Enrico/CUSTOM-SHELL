#include "holberton.h"

/**
 * *add_nodeint - Add node in the beginning
 * @head: The pointer of the history list.
 * @str: The string received.
 *
 * Return: On success 1
 */

void *add_nodeint(history_t **head, char *str)
{

	history_t *new = malloc(sizeof(history_t));
	history_t *copy = *head;

	if (!new)
	{
		free_listint(*head);
	}

	new->str = _strdup(str);
	if (new->str == NULL)
	{
		free_listint(*head);
	}

	new->next = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		new->next = copy;
		*head = new;
	}

	return (0);
}

/**
 * free_listint - Print the list of a single list
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
 */

void free_listint(history_t *head)
{
	history_t *delete;

	if (!head)
		return;
	while (head)
	{
		delete = head->next;
		free(head->str);

		free(head);
		head = delete;
	}
	free(delete);
}

/**
 * print_listint - Print the list of a single list
 * @h: The pointer of the list.
 *
 * Return: The number of elements in the list
 */

void new_history(vars_t *vars)
{
	history_t *tmp = vars->history;
	int i;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = vars->history;
	while(tmp)
	{
		_puts3(tmp->str);

		tmp = tmp->next;
	}
}

ssize_t _puts3(char *str)
{
	ssize_t i, len;
	for (i = 0; str[i]; i++)
		;

	
	len = write(1, str, i);
	if (len != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
