#include "monty.h"

global_t s;

/**
 * get_op_func - gets the function associated to an opcode
 * @opcode: the opcode
 * @line: line number
 *
 * Return: function of opcode
 */
void (*get_op_func(char *opcode, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push}, {"pall", op_pall}, {"mul", op_mul},
		{"pint", op_pint}, {"pop", op_pop}, {"div", op_div},
		{"swap", op_swap}, {"add", op_add}, {"mod", op_mod},
		{"nop", op_nop}, {"sub", op_sub}, {"pchar", op_pchar},
		{"pstr", op_pstr}, {"rotl", op_rotl}, {"rotr", op_rotr},
		{"stack", op_stack}, {"queue", op_queue}, {NULL, NULL}
	};
	int i, cmp;

	for (i = 0; ops[i].opcode; i++)
	{
		cmp = strcmp(opcode, ops[i].opcode);
		if (cmp == 0)
			return (ops[i].f);
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

/**
 * set_global - sets the global structure
 * @filename: file
 * @st: stack
 * @num: number
 * @buff: buffer
 * @stk: stack or queue
 *
 * Return: void
 */
void set_global(FILE *filename, stack_t *st, char *num, char *buff, int stk)
{
	s.file = filename;
	s.stack = st;
	s.is_stack = stk;
	s.number = num;
	s.buf = buff;
}

/**
 * read_file - reads the file and carry out commands
 * @path: file path to read
 * @stack: the stack
 *
 * Return: void
 */
void read_file(char *path, stack_t *stack)
{
	FILE *file;
	char *r, *command, *value;
	unsigned int line = 0;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	file = fopen(path, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}

	set_global(file, stack, NULL, NULL, 1);

	while (1)
	{
		line++;
		s.buf = malloc(sizeof(char) * SIZE);
		if (!s.buf)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		r = fgets(s.buf, SIZE, s.file);
		if (!r)
			break;

		command = strtok(s.buf, " \t\n");
		value = strtok(NULL, " \t\n");
		if (command && command[0] != '#')
		{
			op_func = get_op_func(command, line);
			s.number = value;
			op_func(&s.stack, line);
		}
		free(s.buf);
	}
	free_global();
}

/**
 * main - monty intepreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], stack);

	return (0);
}
