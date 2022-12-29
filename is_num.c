#include "monty.h"

/**
 * is_num - checks if a string is a number
 * @s: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int is_num(char *s)
{
	if (var.opcode && var.argum == NULL)
	{
		return (0);
	}

	if (s == NULL || strlen(s) == 0)
		return (0);

	if (*s == '-' && *(s + 1) != '\0')
		s++;

	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
		{
			return (0);
		}
		s++;
	}

	return (1);
}
