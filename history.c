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
		return(new);
	}
	copy = *head;
	while(copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
	return (new);
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
	history_t *tmp2  = vars->history;
	int i = 0, z = 1;

	unsigned int counter = 0;
	char *count;

	while (tmp)
	{
		
		tmp = tmp->next;
		i++;
	}
	
	while (z < i)
	{
		counter++;
		count = integer_converter(counter);
		print_message(count);
		print_message("     ");
		_puts3(tmp2->str);

		tmp2 = tmp2->next;
		z++;
		free(count);
	}
	tmp2 = tmp2->next;
	vars->invert = tmp2;
	free_listint(tmp);
	free_listint(tmp2);
	free(tmp2);
	return;
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

void print_message(char *str)
{
	long num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)

	{
		perror("fatal error");
		exit(1);
	}
}