#include "monty.h"

/**
 * add - add top two elements on stack
 * @stark: given stack
 * @line_num: line number
 * Return: void
 *
 **/

void add(stack_t **stark, unsigned int line_num)
{
	int addition;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}

	addition = variables.holder;
	pop(stark, line_num);
	addition += variables.holder;
	pop(stark, line_num);
	variables.holder = addition;
	push(stark, line_num);
}
