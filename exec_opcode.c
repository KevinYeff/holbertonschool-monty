#include "monty.h"

/**
 * exec_opcode - executes opcode
 * @opcode: opcode to execute
 *
 * Return: void
 */

void exec_opcode(char *opcode)
{
	unsigned int counter = 0;

	instruction_t opcode_list[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"swap", swap_op},
		{NULL, NULL}
	};

	while ((opcode_list[counter].opcode != NULL))
	{
		if (strcmp(opcode, opcode_list[counter].opcode) == 0)
		{
			opcode_list[counter].f(&var.head, var.line_num);
			return;
		}
		counter++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", var.line_num, opcode);
	fclose(var.fp);
	exit(EXIT_FAILURE);
}
