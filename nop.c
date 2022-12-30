#include "monty.h"
/**
 * nop_op - Function that does nothing but exists.
 * @stack:  Head of the stack.
 * @line_number: current line.
*/
/*
 * #\define __attribute__((unused)) UNUSED
 * Does not work with the given flags or the compiler.
 * tested without the '\' escaping character.
 */

void nop_op(__attribute__((unused))stack_t **stack,
	    __attribute__((unused))unsigned int line_number)
{}
