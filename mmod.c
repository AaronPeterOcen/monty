#include "monty.h"

/**
 * mmod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mmod(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_error(short_stack_error(ln, "mod"));
		return;
	}

	if ((*stk)->next->n == 0)
	{
		set_op_error(div_error(ln));
		return;
	}

	(*stk)->next->next->n %= (*stk)->next->n;
	mpop(stk, ln);
}
