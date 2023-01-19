#include "monty.h"
/**
 *add - adds the top two values of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;

	if (stack == NULL || !temp || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	sum = temp->n + temp->prev->n;
	temp->prev->n = sum;
	temp->prev->next = NULL;

	free(temp);
}


/**
 *sub - subtraccion two values of the top of the stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub;

	if (stack == NULL || !temp || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	sub = temp->prev->n - temp->n;
	temp->prev->n = sub;
	temp->prev->next = NULL;

	free(temp);
}


/**
 *_div - divide two values of the top of stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int div;

	if (stack == NULL || !temp || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = temp->prev->n / temp->n;
	temp->prev->n = div;
	temp->prev->next = NULL;

	free(temp);
}


/**
 *mul - multiplies  two values of the top of stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mul;

	if (stack == NULL || !temp || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	mul = temp->n * temp->prev->n;
	temp->prev->n = mul;
	temp->prev->next = NULL;

	free(temp);
}


/**
 *mod -module of two values of the top of stack
 *@stack: pointer to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mod;

	if (stack == NULL || !temp || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = temp->prev->n % temp->n;
	temp->prev->n = mod;
	temp->prev->next = NULL;

	free(temp);
}
