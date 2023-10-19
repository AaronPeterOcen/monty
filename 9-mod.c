#include "monty.h"

/**
 * mod - find the remainder of top two elements on the stack
 * @stark: given stack
 * @line_num: line number
 * Return: void
 *
 **/

void mod(stack_t **stark, unsigned int line_num)
{
	int remainder;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
	{
		printf("L%d: can't mod, stack tpp short", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}
	if (variables.holder == 0)
	{
		printf("L%d: division by zero\n", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}

	remainder = variables.holder;
	pop(stark, line_num);
	remainder = variables.holder % remainder;
	pop(stark, line_num);
	variables.holder = remainder;
	push(stark, line_num);
}
