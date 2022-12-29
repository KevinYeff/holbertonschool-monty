#include "monty.h"
/**
 * freeStack - Checks if *head exists and calls another free function.
 */

void freeStack(void)
{
	if (var.head)
		free_dlistint(var.head);
}
