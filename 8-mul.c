#include "monty.h"

/**
 * mul - multiplies top two elements on stack
 * @stark: given stack
 * @line_num: line number
 * Return: void
 *
 **/

void mul(stack_t **stark, unsigned int line_num)
{
	int multiply;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}

	multiply = variables.holder;
	pop(stark, line_num);
	multiply = variables.holder * multiply;
	pop(stark, line_num);
	variables.holder = multiply;
	push(stark, line_num);
}
