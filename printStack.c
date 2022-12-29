#include "monty.h"
/**
 * printStack - Prints a doubly linked list.
 * @h:              Head of the list.
 * Return:          Number of items in the linked list.
 */

size_t printStack(const stack_t *h)
{
	size_t n;

	if (h == NULL)
		return (0);
	n = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		n++;
	}
	return (n);
}
