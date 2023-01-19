#include "monty.h"
/**
 *push - adds the top two values of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;
	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;

	if (tmp)
	{
		new->n = glob_vars.glob_int;
		new->next = NULL;
		tmp->next = new;
		new->prev = tmp;
	}
	else
	{
		*stack = new;
		new->n = glob_vars.glob_int;
		new->next = NULL;
		new->prev = NULL;
	}
}
