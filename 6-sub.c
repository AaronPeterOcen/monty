#include "monty.h"

/**
 * sub - subtracts the top element of the stackfrom 2nd top element
 * @stark: the given stack
 * @line_num: line number
 * Return: void
 *
 **/

void sub(stack_t **stark, unsigned int line_num)
{
	int subtract;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}

	subtract = variables.holder;
	pop(stark, line_num);
	subtract = variables.holder - subtract;
	pop(stark, line_num);
	variables.holder = subtract;
	push(stark, line_num);
}
