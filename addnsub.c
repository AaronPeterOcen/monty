#include "monty.h"

/**
 * madd - Adds the top two values of a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void madd(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln, "add"));
		return;
	}

	(*stk)->next->next->n += (*stk)->next->n;
	mpop(stk, ln);
}

/**
 * msub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void msub(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln, "sub"));
		return;
	}

	(*stk)->next->next->n -= (*stk)->next->n;
	mpop(stk, ln);
}
