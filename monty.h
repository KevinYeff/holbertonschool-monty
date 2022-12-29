#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* errors */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* typedef Stack */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* typedef instructions*/
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - doubly linked list representation of a stack (or queue)
 * @type: integer
 * @fp: document
 * @head: DLL head
 * @opcode: opcode
 * @argum: argument@
 * @ndata: DLL data
 * @line_num: line number
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct info_s
{
	int type;
	FILE *fp;
	stack_t *head;
	char *opcode;
	char *argum;
	int ndata;
	unsigned int line_num;
} info_t;

extern info_t var;

/*prototypes*/
void exec_opcode(char *opcode);
void push_op(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
size_t printStack(const stack_t *h);

#endif
