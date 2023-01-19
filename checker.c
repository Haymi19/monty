#include "monty.h"
/**
 * checker - Function that verifies if the command and the
 * arguments are valid, if so it returns the integer of push converted.
 * @stack: the header of the list
 * @line: current line of the document
 * @commands: commands found on the document
 * @fptr: file opened
 * Return: Integer of commands converted if success and EXIT_FAILURE
 * if the number doesn't exist and returns 1 if is another function
 */
int checker(unsigned int line, char **commands, stack_t **stack, FILE *fptr)
{
	if (is_number(commands[1]) == 1)
	{
		glob_vars.glob_int = atoi(commands[1]);
		_commands(commands[0], line)(stack, line);
	}
	else if (strcmp(commands[0], "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free(commands);
		_sfree(*stack);
		fclose(fptr);
		exit(EXIT_FAILURE);
	}
	else
		_commands(commands[0], line)(stack, line);
	return (0);
}
