#include "monty.h"

/**
 * _free - free allocated memory
 * @head: argument to free
 * @n: number of line readed
 */
void _free(stack_t **head, unsigned int n)
{
	stack_t *tmp;
	(void) n;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	exit(EXIT_FAILURE);
}
