#include "monty.h"

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
