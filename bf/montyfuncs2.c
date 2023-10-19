/*
 * File: monty_funcs_2.c
 * Auth: Bennett Dixon
 *       Brennan D Baraban
 */
#include "monty.h"

void monty_add(stack_t **stk, unsigned int ln);
void monty_sub(stack_t **stk, unsigned int ln);
void monty_div(stack_t **stk, unsigned int ln);
void monty_mul(stack_t **stk, unsigned int ln);
void monty_mod(stack_t **stk, unsigned int ln);

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_add(stack_t **stk, unsigned int ln)
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
 * monty_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_sub(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln, "sub"));
		return;
	}

	(*stk)->next->next->n -= (*stk)->next->n;
	mpop(stk, ln);
}

/**
 * monty_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_div(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln, "div"));
		return;
	}

	if ((*stk)->next->n == 0)
	{
		set_op_tok_error(div_error(ln));
		return;
	}

	(*stk)->next->next->n /= (*stk)->next->n;
	mpop(stk, ln);
}

/**
 * monty_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_mul(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln, "mul"));
		return;
	}

	(*stk)->next->next->n *= (*stk)->next->n;
	mpop(stk, ln);
}

/**
 * monty_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_mod(stack_t **stk, unsigned int ln)
{
	if ((*stk)->next == NULL || (*stk)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(ln, "mod"));
		return;
	}

	if ((*stk)->next->n == 0)
	{
		set_op_tok_error(div_error(ln));
		return;
	}

	(*stk)->next->next->n %= (*stk)->next->n;
	mpop(stk, ln);
}
