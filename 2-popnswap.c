#include "monty.h"

void mpop(stack_t **stk, unsigned int ln);
void mswap(stack_t **stk, unsigned int ln);

/**
 * mpop - Removes the top value element of a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mpop(stack_t **stk, unsigned int ln)
{
	stack_t *next = NULL;

	if ((*stk)->next == NULL)
	{
		set_op_error(pop_error(ln));
		return;
	}

	next = (*stk)->next->next;
	free((*stk)->next);
	if (next)
		next->prev = *stk;
	(*stk)->next = next;
}

/**
 * mswap - Swaps the top two value elements of a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mswap(stack_t **stk, unsigned int ln)
{
	stack_t *tmp;

	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_error(short_stack_error(ln, "swap"));
		return;
	}

	tmp = (*stk)->next->next;
	(*stk)->next->next = tmp->next;
	(*stk)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stk)->next;
	tmp->next = (*stk)->next;
	tmp->prev = *stk;
	(*stk)->next = tmp;
}
