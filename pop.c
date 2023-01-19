#include "monty.h"
/**
 *pop - deletes the top value off of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->prev != NULL)
	{
		temp->prev->next = NULL;
	}
	else
	{
		*stack = NULL;
	}
	free(temp);
}
