#include "monty.h"

void mpchar(stack_t **stk, unsigned int ln);
/**
 * mpchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mpchar(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL)
	{
		set_op_tok_error(pchar_error(ln, "stack empty"));
		return;
	}
	if ((*stk)->next->n < 0 || (*stk)->next->n > 127)
	{
		set_op_tok_error(pchar_error(ln, "value out of range"));
		return;
	}

	printf("%c\n", (*stk)->next->n);
}
