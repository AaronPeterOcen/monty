#include "monty.h"

void mpush(stack_t **stk, unsigned int ln);
void mpall(stack_t **stk, unsigned int ln);

/**
 * mpush - Pushes a value to a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mpush(stack_t **stk, unsigned int ln)
{
	stack_t *tmp, *new;
	int i = 0;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(ln));
		return;
	}

	for (; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(ln));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stk) == STACK)
	{
		tmp = (*stk)->next;
		new->prev = *stk;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stk)->next = new;
	}
	else
	{
		tmp = *stk;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * mpall - Prints the values of a stack_t linked list.
 * @stk: A pointer to the top mode node of a stack_t linked list.
 * @ln: The current working line number of a Monty bytecodes file.
 */
void mpall(stack_t **stk, unsigned int ln)
{
	stack_t *tmp = (*stk)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)ln;
}
