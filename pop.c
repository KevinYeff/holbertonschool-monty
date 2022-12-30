#include "monty.h"
/**
 * pop_op -      Function that removes the top element of the stack.
 * @stack:       Head of the stack.
 * @line_number: Current line.
*/
void pop_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeStack();
		fclose(var.fp);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}
