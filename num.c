#include "monty.h"
/**
 * is_number - checks if the push command has a number
 * @commands: character to be checked
 *
 * Return: 0 on failure, 1 on success
 */
int is_number(char *commands)
{
	if (!commands)
		return (0);

	if (*commands == 45)
		commands++;

	while (*commands != '\0')
	{
		if (!isdigit(*commands))
			return (0);
		commands++;
	}
	return (1);
}
