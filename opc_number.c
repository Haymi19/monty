#include "monty.h"

/**
 * _itoa - converts an integer to string
 * @n: integer
 *
 * Return: string
 */
char *_itoa(int n)
{
	int length;
	char *num;

	length = snprintf(NULL, 0, "%d", n);
	num = malloc(sizeof(char) * (length + 1));
	if (!num)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	sprintf(num, "%d", n);

	return (num);
}

/**
 * check_number - checks if an array of chars is a number
 * @lnum: line number
 *
 * Return: void
 */
void check_number(unsigned int lnum)
{
	int start = 0, i;

	if (s.number[start] == '-' || s.number[start] == '+')
		start++;
	for (i = start; s.number[i]; i++)
	{
		if (s.number[i] < '0' || s.number[i] > '9')
		{
			free_global();
			fprintf(stderr, "L%d: usage: push integer\n", lnum);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * free_stack - frees the stack
 * @head: head of stack
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp = head, *prev;

	while (temp)
	{
		prev = temp;
		temp = temp->next;

		free(prev);
	}
}

/**
 * free_global - frees the global structure
 *
 * Return: void
 */
void free_global(void)
{
	fclose(s.file);
	free(s.buf);
	free_stack(s.stack);
}
