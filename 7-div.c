#include "monty.h"

/**
 * _div - divides second top element of the stack by top element of stack
 * @stark: given stack
 * @line_num: line number
 * Return: Void
 *
 **/
void _div(stack_t **stark, unsigned int line_num)
{
	int divide;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}

	if (variables.holder == 0)
	{
		printf("L%d: division by zero\n", line_num);
		free_stark(stark, line_num);
		exit(EXIT_FAILURE);
	}

	divide = variables.holder;
	pop(stark, line_num);
	divide = variables.holder / divide;
	pop(stark, line_num);
	variables.holder = divide;
	push(stark, line_num);
}
