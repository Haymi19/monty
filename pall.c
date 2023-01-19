#include "monty.h"
/**
 *pall - prints all values starting from the top of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (*stack == NULL)
		return;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
