#include "monty.h"
/**
 * pint_op -     Function that prints the value at the top of stack.
 * @stack:       Head of the stack.
 * @line_number: File's line number.
*/
void pint_op(stack_t **stack, unsigned int line_number)
{
	stack_t *h = NULL;

	h = *stack;

	if (h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(var.argum);
		fclose(var.fp);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", h->n);

}
