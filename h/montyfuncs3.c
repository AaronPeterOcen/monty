#include "monty.h"

void mpstr(stack_t **stk, unsigned int ln);
void mnop(stack_t **stk, unsigned int ln);

/**
 * mnop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mnop(stack_t **stk, unsigned int ln)
{
	(void)stk;
	(void)ln;
}

/**
 * mpstr - Prints the string contained in a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mpstr(stack_t **stk, unsigned int ln)
{
	stack_t *tmp = (*stk)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)ln;
}
