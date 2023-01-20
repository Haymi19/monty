#include "monty.h"


/**
 * queue_push - pushes to queue
 * @queue: queue
 * @num: num to push
 *
 * Return: void
 */
void queue_push(stack_t **queue, int num)
{
	stack_t *new, *temp = *queue;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->prev = NULL;
	new->next = temp;

	if (*queue)
		temp->prev = new;
	*queue = new;
}

/**
 * op_stack -sets the format of data to stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void op_stack(stack_t **stack, unsigned int lnum)
{
	s.is_stack = 1;

	(void)stack;
	(void)lnum;
}

/**
 * op_queue - sets the format of data to queue
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void op_queue(stack_t **stack, unsigned int lnum)
{
	s.is_stack = 0;

	(void)stack;
	(void)lnum;
}
