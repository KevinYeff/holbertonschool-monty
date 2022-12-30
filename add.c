#include "monty.h"

/**
 * add_op - adds top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */

void add_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *new_node;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", var.line_num);
		freeStack();
		fclose(var.fp);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
                freeStack();
                fclose(var.fp);
                exit(EXIT_FAILURE);
	}

	top = *stack;
	new_node->n = top->n + (top->next)->n;
	new_node->prev = NULL;
	new_node->next = (top->next)->next;
	if ((top->next)->next != NULL)
		((top->next)->next)->prev = new_node;

	(top->next)->next = NULL;
	*stack = new_node;
	
	while (top != NULL)
	{
		free(top->next);
		*stack = NULL;
	}
}

