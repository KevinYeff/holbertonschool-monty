#include "monty.h"

/**
 * swap_op - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top_next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", var.line_num);
		freeStack();
		fclose(var.fp);
		exit(EXIT_FAILURE);
	}

	top_next = (*stack)->next;
	(*stack)->next = top_next->next;
	(*stack)->prev = top_next;
	top_next->prev = NULL;
	if (top_next->next != NULL)
		(top_next->next)->prev = *stack;
	top_next->next = *stack;

	*stack = top_next;
}
