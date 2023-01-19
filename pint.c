#include "monty.h"
/**
 *pint -  prints the value at the top of the stack.
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	printf("%d\n", temp->n);
}
