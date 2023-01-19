#include "monty.h"

/**
 * get_line - get a string from the stdin
 * @file: file to be read
 * Return: on success returne the number of characters read
 */
char *get_line(char *file)
{
	FILE *fptr;
	char *line = NULL;
	char **commands = NULL;
	unsigned int line_number = 1;
	size_t n = 0;
	stack_t *head = NULL;

	fptr = fopen(file, "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fptr) != -1)
	{
		commands = split_line(line);

		if (commands)
			checker(line_number, commands, &head, fptr);

		free(commands);
		line_number++;
	}
	free(line);
	_sfree(head);
	fclose(fptr);
	return (line);
}
