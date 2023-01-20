#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void op_add(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_global();
		fprintf(stderr, "L%d: can't add, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	num = _itoa(temp->n + temp->next->n);

	op_pop(stack, lnum);
	op_pop(stack, lnum);

	s.number = num;
	prev_is_stack = s.is_stack;
	s.is_stack = 1;
	op_push(stack, lnum);
	s.is_stack = prev_is_stack;

	free(num);
}

/**
 * op_nop - does nothing to the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void op_nop(stack_t **stack, unsigned int lnum)
{
	(void)stack;
	(void)lnum;

	/*
	 * Do nothing
	 */
}

/**
 * op_sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_global();
		fprintf(stderr, "L%d: can't sub, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	num = _itoa(temp->n - temp->next->n);

	op_pop(stack, lnum);
	op_pop(stack, lnum);

	s.number = num;
	prev_is_stack = s.is_stack;
	s.is_stack = 1;
	op_push(stack, lnum);
	s.is_stack = prev_is_stack;

	free(num);
}

/**
 * op_div - divides the second top element of the stack from
 * the top element of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void op_div(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_global();
		fprintf(stderr, "L%d: can't div, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	if (temp->next->n == 0)
	{
		free_global();
		fprintf(stderr, "L%d: division by zero\n", lnum);
		exit(EXIT_FAILURE);
	}

	num = _itoa(temp->n / temp->next->n);

	op_pop(stack, lnum);
	op_pop(stack, lnum);

	s.number = num;
	prev_is_stack = s.is_stack;
	s.is_stack = 1;
	op_push(stack, lnum);
	s.is_stack = prev_is_stack;

	free(num);
}

/**
 * op_mul - multiplies the top element of the stack by
 * the second top element of the stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;
	char *num;
	int prev_is_stack;

	if (!(*stack) || !(*stack)->next)
	{
		free_global();
		fprintf(stderr, "L%d: can't mul, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}

	for (; temp->next->next; temp = temp->next)
		;
	num = _itoa(temp->n * temp->next->n);

	op_pop(stack, lnum);
	op_pop(stack, lnum);

	s.number = num;
	prev_is_stack = s.is_stack;
	s.is_stack = 1;
	op_push(stack, lnum);
	s.is_stack = prev_is_stack;

	free(num);
}
