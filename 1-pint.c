#include "monty.h"

/**
 * mpint - Prints the top value of a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mpint(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL)
	{
		set_op_error(pint_error(ln));
		return;
	}

	printf("%d\n", (*stk)->next->n);
}
